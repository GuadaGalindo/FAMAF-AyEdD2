#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

struct _list {
    list_elem elem;
    struct _list * next;
};

list empty() {
    list l = NULL;
    return l;
}

list addl(list l, list_elem e) {
    list l1;
    l1 = malloc(sizeof(struct _list));
    l1->elem = e;
    if (l->next == NULL) {
        l1->next = NULL;
        l = l1;
    }
    else {
        l1->next = l;
        l = l1;
    }
    return l;
}

bool is_empty(list l) {
    return (l == NULL);
}

list_elem head(list l) {
    assert(!is_empty(l));
    return (l->elem);
}

list tail(list l) {
    assert(!is_empty(l));
    list l_aux = l;
    l = l->next;
    free(l_aux);
    return l;
}

list addr(list l, list_elem e) {
    list l1 = malloc (sizeof (struct _list));
    l1->elem=e;
    l1->next=NULL;
    if (l==NULL) {
        l = l1;
    }
    else{
        list aux = l;
        while(aux->next != NULL) {
            aux=aux->next;
        }
        aux->next = l1;
    }
    return l;
}


unsigned int length(list l) {
    unsigned int size = 0;
    list aux = l;

    while (aux != NULL) {
        ++size;
        aux = aux->next;
    }
    return size;
}

list concat(list l1, list l2) {
    list aux1;
    list aux = l1;
    while (aux->next != NULL) {
        aux = aux->next;
    }
    aux1 = l2;
    while (aux1 != NULL) {
        list new = malloc (sizeof(struct _list));
        new->elem = aux1->elem;
        new->next = NULL;
        aux = new;
        aux1 = aux1->next;
    }
    return l1;
}

list_elem index(list l, unsigned int n) {
    assert(length(l) > n);
    list aux = l;
    list_elem res;
    for (unsigned int i = 0; i < n; ++i){
        aux = aux->next;
    }
    res = aux->elem;
    return res;
}

list take(list l, unsigned int n) {
    list aux = l;
    for (unsigned int i = 0; i < n; ++i) {
        aux = aux->next;
    }
    while (aux != NULL) {
        list kill = aux;
        aux = aux->next;
        free(kill);
    }
    return l;
}

list drop(list l, unsigned int n){
    list kill = l;
    for (unsigned int i=0; i<n; ++i) {
        kill = l;
        l = kill->next;
        free(kill);
    }
    return l;
}

list copy_list(list l) {
    list l_aux = empty();
    list aux = l;
    list pre;
    while (aux != NULL) {
        list new = malloc (sizeof(struct _list));
        new->elem = aux->elem;
        new->next = NULL;
        if(l_aux == NULL){
            l_aux = new;
        }
        else{
            pre->next = new;
        }
        pre = new;
        aux = aux->next;
    }
    return l_aux;
}

list destroy(list l) {
    list kill;
    while (!is_empty(l)){
        kill = l;
        l = kill->next;
        free(kill);
    }
    free(l);
    return l;
}