#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter var_count;
    var_count = malloc(sizeof(struct _counter));
    var_count->count = 0;
    return var_count;
}

void counter_inc(counter c) {
    ++c->count;
}

bool counter_is_init(counter c) {
    return (c->count == 0);
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    --c->count;
}

counter counter_copy(counter c) {
    counter s = counter_init();
    s->count = c->count;
    return s;
}

void counter_destroy(counter c) {
    free(c);
}
