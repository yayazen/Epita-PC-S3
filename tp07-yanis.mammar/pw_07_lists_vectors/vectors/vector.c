#include <err.h>
#include "vector.h"

struct vector *vector_new()
{
    struct vector *v = malloc(sizeof(struct vector));
	
	*v = (struct vector) {
		.capacity = 1,
		.size = 0,
		.data = calloc(1, sizeof(int))
	};

	if (!v->data)
		errx(-1, "Not enough memory!");

	return v;
}

void vector_free(struct vector *v)
{
    free(v->data);
	free(v);
}

void double_capacity(struct vector *v)
{
	v->data = realloc(v->data, sizeof(int) * v->capacity * 2);
	
	if (!v->data)
		errx(-1, "Not enough memory!");

	v->capacity *= 2;
}

void vector_push(struct vector *v, int x)
{
    if (v->size + 1 > v->capacity)
		double_capacity(v);
	
	*(v->data + v->size) = x;
	v->size++;
}

int vector_pop(struct vector *v, int *x)
{
	if (v->size == 0)
		return 0;

	v->size--;
	*x = *(v->data + v->size);
	return 1;
}

int vector_get(struct vector *v, size_t i, int *x)
{
    if (i < v->size) {
		*x = *(v->data + i);
		return 1;
	}
	
	return 0;
}

void vector_insert(struct vector *v, size_t i, int x)
{
	if (i > v->size)
		return;

    if (v->size + 1 > v->capacity)
		double_capacity(v);
	
	size_t h;
	for (h = v->size; h > i; h--) {
		v->data[h] = v->data[h - 1];
	}
	
	v->data[h] = x;
	v->size++;
}

int vector_remove(struct vector *v, size_t i, int *x)
{
    if (i >= v->size)
        return 0;

    *x = v->data[i];

    for (i += 1; i < v->size; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->size--;

    return 1;
}
