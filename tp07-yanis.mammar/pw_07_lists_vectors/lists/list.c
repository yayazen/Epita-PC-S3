#include <stdlib.h>
#include "list.h"

void list_init(struct list *list)
{
    *list = (struct list) {.next = NULL, .data = 0};
}

int list_is_empty(struct list *list)
{
    return !list->next;
}

size_t list_len(struct list *list)
{
    size_t len = 0;

    while ((list = list->next))
        len++;

    return len;
}

void list_push_front(struct list *list, struct list *elm)
{
    elm->next = list->next;
    list->next = elm;
}

struct list *list_pop_front(struct list *list)
{
    struct list *pop;
    
    if ((pop = list->next)) {
        list->next = pop->next;
        pop->next = NULL;
    }

    return pop;
}

struct list *list_find(struct list *list, int value)
{
    while ((list = list->next)) {
        if (list->data == value)
            break;
    }

    return list;
}

struct list *list_lower_bound(struct list *list, int value)
{
    struct list *elm = NULL;

    while ((list = list->next)) {
        if (list->data >= value)
            break;
        elm = list;
    }

    return elm;
}

int list_is_sorted(struct list *list)
{
    while ((list = list->next) && list->next) {
        if (list->data > list->next->data)
            return 0;
    }
    return 1;
}

void list_insert(struct list *list, struct list *elm)
{
    while ((list->next)) {
        if (list->next->data >= elm->data)
            break;
        list = list->next;
    }

    elm->next = list->next;
    list->next = elm;
}

void list_rev(struct list *list)
{
    struct list *next, *prev = NULL; 
    struct list *current = list->next;
    
    while (current) { 
        next = current->next;
        
        current->next = prev;

        prev = current;
        current = next;
    }
    list->next = prev;
}

void list_half_split(struct list *list, struct list *second)
{
    for (size_t half = list_len(list) / 2; half > 0; half--)
        list = list->next;

    second->next = list->next;
    list->next = NULL;
}
