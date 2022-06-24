#include <stdio.h>
#include <stdlib.h>
#include "layers.c"


struct nn {
    struct layer *layers;
    int len;
}; // array of layers

struct nn create_nn(char *argv) {
    // create nn based on string
    // structure:
    // (int x)(char activation)|repeat
    // example
    // 3r|6r|6r|2s
    // nn with 4 layers, 3 relu neurons, 6 relu neurons, 6 relu neurons, 2 sigmoid neurons

    return;
}

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