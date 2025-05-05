#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

typedef struct _list * list;
typedef int list_elem;


/* Constructors */
list empty();

list addl(list l, list_elem e);


/* Operations */
bool is_empty(list l);

list_elem head(list l);

list tail(list l);

list addr(list l, list_elem e);

unsigned int length(list l);

list concat(list l1, list l2);

list_elem index(list l, unsigned int n);

list take(list l, unsigned int n);

list drop(list l, unsigned int n);

list copy_list(list l);

list destroy(list l);

#endif
