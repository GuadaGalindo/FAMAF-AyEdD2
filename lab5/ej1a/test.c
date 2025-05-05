#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    stack s = stack_empty();
    stack_elem elem0 = 0;
    stack_elem elem1 = 1;
    stack_elem elem2 = 2;
    stack_elem elem3 = 3;

    bool empty = stack_is_empty(s);
    printf("Is empty? %u\n", empty);

    s = stack_push(s, elem0);
    s = stack_push(s, elem1);
    s = stack_push(s, elem2);
    s = stack_push(s, elem3);

    empty = stack_is_empty(s);
    printf("Is empty? %u\n", empty);

    unsigned int size = stack_size(s);
    printf("The stack size is %u\n", size);

    stack_elem * array = stack_to_array(s);
    printf("The array is\n");
    printf("[");
    for(unsigned int i = 0; i < size; ++i) {
        printf(" %d", array[i]);
    }
    printf(" ]\n");

    s = stack_pop(s);
    s = stack_pop(s);
    s = stack_pop(s);
    s = stack_pop(s);

    empty = stack_is_empty(s);
    printf("Is empty? %u\n", empty);

    size = stack_size(s);
    printf("The stack size is %u\n", size);

    array = stack_to_array(s);
    printf("The array is\n");
    printf("[");
    for(unsigned int i = 0; i < size; ++i) {
        printf(" %d", array[i]);
    }
    printf(" ]\n");

    return 0;


}

//Funciona bien stack_pop() para pilas de tamano 1? Si.
//Si la pila queda vacia, puedo volver a insertar elementos? Si.
//La funcion stack_to_array() devuelve NULL para una pila vacia? No, devuleve un arreglo vacio.
//Devuelve los elementos en el orden correcto? Devuelve los elementos en el orden que fueron ingresados a la pila.