#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;
    int i;
    i = 0;

    while (i < ARRAY_SIZE) {
      if (arr[i] > value) {
        res.is_upperbound = false;
      }
      if (arr[i] < value) {
        res.is_lowerbound = false;
      }
      if (arr[i] == value) {
        res.exists = true;
        res.where = i;
      }
      i++;
    }
    return res;
}

int main(void) {
    int a[ARRAY_SIZE];
    int value, c;
    c = 0;
    
    while (c < ARRAY_SIZE) {
        printf ("Ingrese el valor para la posicion %d del arreglo\n", c);
        scanf ("%d", &a[c]);
        c = c + 1;
    }
    printf ("Ingrese un valor para comparar\n");
    scanf ("%d", &value);

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    if (result.is_upperbound && result.exists) {
        printf ("El valor es maximo\n");
        printf ("El valor se encuentra en la posicion %d del arreglo\n", result.where);
    }
    if (result.is_upperbound && !result.exists) {
        printf ("El valor es cota superior\n");
    }
    if (result.is_lowerbound && result.exists) {
        printf ("El valor es minimo\n");
        printf ("El valor se encuentra en la posicion %d del arreglo\n", result.where);
    }
    if (result.is_lowerbound && !result.exists) {
        printf ("El valor es cota inferior\n");
    }
    return EXIT_SUCCESS;
}