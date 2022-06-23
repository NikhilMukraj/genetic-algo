#include <stdio.h>
#include <stdlib.h>
#include "layers.c"


struct nn {
    struct layer *layers;
    int len;
}; // array of layers

double *feedforward(struct nn network, double *inputs) {
    // get prediction based on inputs
    return;
}