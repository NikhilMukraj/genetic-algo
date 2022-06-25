#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "layers.c"


struct nn {
    struct layer *layers;
    int len;
}; // array of layers

struct nn create_nn(char *arc) {
    // create nn based on string
    // structure:
    // (int x)(char activation)|repeat
    // example
    // 3i|3r|6r|6r|2s|
    // nn with 4 layers, 3 input size, 3 relu neurons, 
    // 6 relu neurons, 6 relu neurons, 2 sigmoid neurons

    /*
    this needs extensive testing
    */

    struct nn new_nn;
    for (int i = 0; i < strlen(arc); i++) {
        new_nn.len++;
    }
    new_nn.layers = malloc(new_nn.len * sizeof(struct layer));

    char *temp_string;
    int last_len;
    int layer_count;
    for (int i = 0; i < strlen(arc); i++) {
        if (arc[i] >= '0' && arc[i] <= '9') {
            strncat(temp_string, &arc[i], 1);
        } else if (arc[i] == '|') {
            if (arc[i-1] != 'i') {
                int layer_len = atoi(temp_string);
                struct layer sheet;

                sheet.layer_len = layer_len;
                sheet.input_len = last_len;
                sheet.activation = arc[i-1];

                layer_count++;
                new_nn.layers[layer_count] = sheet;
            } else {
                last_len = atoi(temp_string);
            }
            temp_string = "";
        }
    }

    return new_nn;
} 

/*
maybe swap these two once done creating both
and then add use network_init(..) in create_nn(..)
*/

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
    return 0;
}