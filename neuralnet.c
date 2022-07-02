#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "layers.c"


struct nn {
    struct layer *layers;
    int len;
}; // array of layers

double rand_double(double min, double max)  {
    double ans = min + (rand() / (RAND_MAX / (max - min)));
    return ans;
}

/*
use network_init(..) in create_nn(..)
*/

void network_init(struct nn *network, int randomized) {
    struct nn *temp_net;
    temp_net = (struct nn *) network;

    if (randomized == 1) {
        // generate network with weights and biases
        // set to random numbers between -1 and 1
        for (int i = 0; i < temp_net->len; i++) {
            init_weights(&temp_net->layers[i]);
            init_biases(&temp_net->layers[i]);

            for (int j = 0; j < temp_net->layers[i].layer_len; j++) {
                temp_net->layers[i].biases[j] = rand_double(-1, 1);
                for (int k = 0; k < temp_net->layers[i].input_len; k++) {
                    temp_net->layers[i].weights[j][k] = rand_double(-1, 1);
                }
            }
        }
    } else if (randomized == 0) {
        // generate network with weights and biases of 0.0
        for (int i = 0; i < temp_net->len; i++) {
            init_weights(&temp_net->layers[i]);
            init_biases(&temp_net->layers[i]);
        }
    } else {
        printf("Invalid randomized argument of '%i\n'", randomized);
    }
}

void layer_init(struct nn *network, int layer_num, int randomized) {
    struct nn *temp_net;
    temp_net = (struct nn *) network;

    if (layer_num >= temp_net->len || layer_num < 0) {
        printf("Invalid layer number\n");
        return;
    }

    if (randomized == 1) {
        // generate layer with weights and biases
        // set to random numbers between -1 and 1
        init_weights(&temp_net->layers[layer_num]);
        init_biases(&temp_net->layers[layer_num]);

        for (int i = 0; i < temp_net->layers[layer_num].layer_len; i++) {
            temp_net->layers[layer_num].biases[i] = rand_double(-1, 1);
            for (int j = 0; j < temp_net->layers[layer_num].input_len; j++) {
                temp_net->layers[layer_num].weights[i][j] = rand_double(-1, 1);
            }
        }
    } else if (randomized == 0) {
        // generate network with weights and biases of 0.0
        init_weights(&temp_net->layers[layer_num]);
        init_biases(&temp_net->layers[layer_num]);
    } else {
        printf("Invalid randomized argument of '%i\n'", randomized);
    }
}

struct nn create_nn(char *arc) {
    // create nn based on string
    // structure:
    // (int x)(char activation)|repeat
    // example
    // 3i|4r|6r|6r|2s|
    // nn with 4 layers, 3 input size, 4 relu neurons, 
    // 6 relu neurons, 6 relu neurons, 2 sigmoid neurons

    int arc_size = (int) strlen(arc);

    struct nn new_nn;
    new_nn.len = -1; // ignore the first and last as they dont indicate layers
    for (int i = 0; i < arc_size; i++) {
        if (arc[i] == '|') {
            new_nn.len++;
        }
    }
    new_nn.layers = malloc((new_nn.len - 1) * sizeof(struct layer));

    char *temp_string;
    temp_string = malloc(1 * sizeof(char));
    int last_len;
    int layer_count;
    for (int i = 0; i < arc_size; i++) {
        if (arc[i] >= '0' && arc[i] <= '9') {
            temp_string = (char *) realloc(temp_string, ((int) strlen(temp_string) + 1) * sizeof(char));
            strncat(temp_string, &arc[i], 1);
        } else if (arc[i] == '|') {
            if (arc[i-1] != 'i') {
                struct layer sheet;
                sheet.activation = arc[i-1];
                sheet.input_len = last_len;

                int layer_len = atoi(temp_string);
                sheet.layer_len = layer_len;

                last_len = layer_len;

                layer_count++;
                
                new_nn.layers[layer_count-1] = sheet;
            } else {
                last_len = atoi(temp_string);
            }
            memset(temp_string, 0, strlen(temp_string));
        }
    }

    return new_nn;
} 

void add_layer(struct nn *network, char *arc_part) {
    // test this and previous void funcs that edit structs
    struct nn *temp_net;
    temp_net = (struct nn *) network;
    
    // using realloc runs an error dont try that 
    struct layer *layers;
    layers = malloc(temp_net->len * sizeof(struct layer));
    for (int i = 0; i < temp_net->len; i++) {
        layers[i] = temp_net->layers[i];
    }
    temp_net->layers = layers;
    
    int arc_p_len = (int) strlen(arc_part);
    char *temp_string;
    temp_string = malloc(1 * sizeof(char));
    for (int i = 0; i < arc_p_len; i++) {
         if (arc_part[i] >= '0' && arc_part[i] <= '9') {
            temp_string = (char *) realloc(temp_string, ((int) strlen(temp_string) + 1) * sizeof(char));
            strncat(temp_string, &arc_part[i], 1);
        } else if (arc_part[i] == '|') {
            struct layer sheet;
            sheet.activation = arc_part[i-1];
            sheet.input_len = temp_net->layers[temp_net->len-1].layer_len;

            int layer_len = atoi(temp_string);
            sheet.layer_len = layer_len;
                
            temp_net->layers[temp_net->len] = sheet;
            
            memset(temp_string, 0, strlen(temp_string));
        }
    }

    temp_net->len++;
    // make sure this all writes to correct struct
}

double *feedforward(struct nn *network, double *inputs) {
    struct nn *temp_net;
    temp_net = (struct nn *) network;

    double *ans = inputs;
    // get prediction based on inputs
    for (int i = 0; i < temp_net->len; i++) {
        ans = output(&temp_net->layers[i], ans);
    }

    return ans;
}