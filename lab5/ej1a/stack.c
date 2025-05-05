#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack {
    stack_elem elem;
    struct _s_stack * next;
};

stack stack_empty() {
    stack s = NULL;
    return s;
}

stack stack_push(stack s, stack_elem e) {
    stack s_aux;
    s_aux = malloc(sizeof(struct _s_stack));
    s_aux->elem = e;
    if (s == NULL){
        s_aux->next = NULL;
        s = s_aux;
    }
    else {
        s_aux->next = s;
        s = s_aux;
    }
    return s;
}

stack stack_pop(stack s) {
    assert(!stack_is_empty(s));
    stack s_aux = s;
    s = s->next;
    free(s_aux);
    return s;
}

unsigned int stack_size(stack s) {
    unsigned int size = 0;
    stack s_aux = s;
    while (s_aux != NULL) {
        ++size;
        s_aux = s_aux->next;
    }
    return size;
}

stack_elem stack_top(stack s) {
    assert(!stack_is_empty(s));
    return (s->elem);
}

bool stack_is_empty(stack s) {
    return (s == NULL);
}

stack_elem *stack_to_array(stack s) {
    stack s_aux = s;
    unsigned int size = stack_size(s);
    stack_elem * array = calloc(size, sizeof(stack_elem));
    for (int i = size-1; i >= 0; --i) {
        array[i] = s_aux->elem;
        s_aux = s_aux->next;
    }
    return array;
}

stack stack_destroy(stack s) {
    stack s_aux;
    while (s != NULL) {
        s_aux = s;
        s = s->next;
        free(s_aux);
    }
    free(s);
    return s;
}