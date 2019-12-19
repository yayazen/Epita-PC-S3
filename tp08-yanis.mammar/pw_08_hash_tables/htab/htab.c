#include <err.h>
#include <string.h>

#include "htab.h"

uint32_t hash(char *key)
{
    uint32_t hkey = 0;

	for (size_t i = 0; key[i]; i++) 
	{
		hkey += key[i];
		hkey += (hkey << 10);
		hkey ^= (hkey >> 6);
	}

	hkey += (hkey << 3);
	hkey ^= (hkey >> 11);
	hkey += (hkey << 15);

	return hkey;
}

struct htab *htab_new()
{
    struct htab *ht = malloc(sizeof(struct htab));

	*ht = (struct htab) {
		.capacity = 4,
		.size = 0,
		.data = calloc(4, sizeof(struct pair)),
	};

	if (!ht->data)
		errx(-1, "Not enough memory");

	return ht;
}

void double_capacity(struct htab *ht) {
    if (!(ht->data = realloc(ht->data, sizeof(struct pair) * ht->capacity * 2)))
        errx(-1, "Not enough memory");
    memset(ht->data + ht->capacity, 0, sizeof(struct pair) * ht->capacity);

    struct pair *prev, *current;
    size_t i, j;
    for (i = 0; i < ht->capacity; i++) {
        prev = ht->data + i;

        while((current = prev->next)) {
            j = current->hkey % (ht->capacity * 2);

            if (j != i) {
                prev->next = current->next;
               
                if (!ht->data[i].next)
                   ht->size--;

                if (!ht->data[j].next)
                    ht->size++;
                
                current->next = ht->data[j].next;
                ht->data[j].next = current;
            }

            else
                prev = current;
        }
    }
     
    ht->capacity *= 2;
}

void htab_clear(struct htab *ht)
{
    struct pair *p, *tmp;
    for (size_t i = 0; i < ht->capacity; i++) {
        p = ht->data[i].next;

        while (p) {
            tmp = p->next;
            free(p);
            p = tmp;
        }

        ht->data[i].next = NULL;
    }
    
    ht->size = 0;
}

void htab_free(struct htab *ht)
{
    htab_clear(ht);

    free(ht->data);
    free(ht);
}

struct pair *htab_get(struct htab *ht, char *key)
{
    uint32_t hkey = hash(key);

    struct pair *p = ht->data + (hkey % ht->capacity);
    while ((p = p->next)) {
        if (p->hkey == hkey && !strcmp(p->key, key))
            break;
    }

    return p;
}

int htab_insert(struct htab *ht, char *key, void *value)
{
    if (htab_get(ht, key))
        return 0;
    
    struct pair *p = malloc(sizeof(struct pair));
    if (!p)
        errx(-1, "Not enough memory!");

    uint32_t hkey = hash(key);
    size_t i = (size_t) hkey % ht->capacity;

    *p = (struct pair) {
        .hkey = hkey,
        .key = key,
        .value = value,
        .next = ht->data[i].next,
    };

    if (!ht->data[i].next)
        ht->size++;

    ht->data[i].next = p;

    if (100 * ht->size / ht->capacity > 75)
        double_capacity(ht);

    return 1;
}

void htab_remove(struct htab *ht, char *key)
{
    uint32_t hkey = hash(key);
    
    struct pair *current, *prev = ht->data + (hkey % ht->capacity);
    while ((current = prev->next)) {
        
        if (!strcmp(current->key, key)){
            prev->next = current->next;
            free(current);

            if (!ht->data[hkey % ht->capacity].next)
                ht->size--;
            break;
        }

        prev = current;
    } 
}
