#include "array_helpers.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {
    FILE *file;
    int elem;
    int scanfres;
    file = fopen (filepath, "r");
    fscanf (file, "%u", &max_size);
    for (unsigned int i = 0; i < max_size; i++) {
        scanfres = fscanf (file, "%d", &elem);
        if (scanfres != EOF) {
            array[i] = elem;
        }
        else {
            printf ("invalid format\n");
            exit(EXIT_FAILURE);
        }
    }
    fclose (file);
    return max_size;
}

void array_dump(int a[], unsigned int length) {
    printf ("[");
    if (length != 0) {
        printf ("%d", a[0]);
        for (unsigned int i = 1; i < length; ++i) {
            printf (", %d", a[i]);
        }
    }
    printf ("]\n");
}

bool array_is_sorted(int a[], unsigned int length) {
    bool sorted = true;
    for (unsigned int i = 1; i < length; i++) {
        if (a[i-1] > a[i]) {
            sorted = false;
            break;
        }
    }
    return sorted;
}