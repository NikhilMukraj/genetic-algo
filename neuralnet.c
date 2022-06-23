#include <stdio.h>
#include <stdlib.h>
#include "layers.c"


struct nn {
    struct layer *layers;
    int len;
}; // array of layers

void network_init(struct nn *network, int randomized) {
    if (randomized == 1) {
        // generate network with weights and biases
        // set to random numbers between -1 and 1
    } else {
        // generate network with weights and biases of 0.0
    }
}

double *feedforward(struct nn *network, double *inputs) {
    // get prediction based on inputs
    return;
}