/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y) {
    if (x.rank <= y.rank) {
        return true;
    }
    else {
        return false;
    }
}

void swap(player_t a[], unsigned int i, unsigned int j) {
    player_t temp;
    temp = a[i];
    a[i] = a[j];
    a[j]= temp;
}

bool array_is_sorted(player_t a[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(a[i - 1u], a[i])) {
        i++;
    }
    return (i == length);
}

static unsigned int partition(player_t a[], unsigned int izq, unsigned int der) {
    unsigned int i, j, ppiv;
    ppiv = izq;
    i = izq + 1;
    j = der;
    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) {
            i++;
        }
        else if (goes_before(a[ppiv], a[j])) {
            --j;
        }
        else if (goes_before(a[ppiv], a[i]) && goes_before(a[j], a[ppiv])) {
            swap(a, i, j);
            i++;
            --j;
        }
    }
    swap(a, j, ppiv);
    ppiv = j;
    return ppiv;
}

static void quick_sort_rec(player_t a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv;
    if (der > izq) {
        ppiv = partition(a, izq, der);
        quick_sort_rec(a, izq, (ppiv == 0u) ? 0u : ppiv - 1u);
        quick_sort_rec(a, (ppiv + 1), der);
    }
}

void sort(player_t a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}
    