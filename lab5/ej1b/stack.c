#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct _s_stack {
    unsigned int size;
    struct _stack_node * top;
};

struct _stack_node {
    stack_elem elem;
    struct _stack_node * next;
};

bool invariant(stack s){
    bool ret = true;
    unsigned int size = 0;
    node n_aux = s->top;
    while (n_aux != NULL) {
        ++size;
        n_aux = n_aux->next;
    }
    ret = (size == s->size);
    return ret;

}

stack stack_empty() {
    stack s;
    s = malloc(sizeof(struct _s_stack));
    s->size = 0;
    s->top = NULL;
    return s;
}

stack stack_push(stack s, stack_elem e) {
    assert(invariant(s));
    node n_aux;
    n_aux = malloc(sizeof(struct _stack_node));
    n_aux->elem = e;
    if (s->top == NULL){
        n_aux->next = NULL;
        s->top = n_aux;
    }
    else {
        n_aux->next = s->top;
        s->top = n_aux;
    }
    ++s->size;
    assert(invariant(s));
    return s;
}

stack stack_pop(stack s) {
    assert(!stack_is_empty(s));
    assert(invariant(s));
    node n_aux = s->top;
    s->top = n_aux->next;
    free(n_aux);
    --s->size;
    assert(invariant(s));
    return s;
}

unsigned int stack_size(stack s) {
    return s->size;
}

stack_elem stack_top(stack s) {
    assert(!stack_is_empty(s));
    assert(invariant(s));
    return (s->top->elem);
}

bool stack_is_empty(stack s) {
    assert(invariant(s));
    return (s->size == 0);
}

stack_elem *stack_to_array(stack s) {
    node n_aux = s->top;
    unsigned int size = stack_size(s);
    stack_elem * array = calloc(size, sizeof(stack_elem));
    for (int i = size-1; i >= 0; --i) {
        array[i] = n_aux->elem;
        n_aux = n_aux->next;
    }
    return array;
}

stack stack_destroy(stack s) {
    node n_aux;
    while (s->top != NULL) {
        n_aux = s->top;
        s->top = n_aux->next;
        free(n_aux);
    }
    free(s->top);
    free(s);
    return s;
}