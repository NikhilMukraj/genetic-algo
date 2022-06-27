#include <stdio.h>
#include <stdlib.h>
#include "neuralnet.c"


void activation_test() {
    /* 
    weights: .5, .4
    inputs: .2, .3
    bias: .1
    len: 2
    */

   int length = 2;

   double *inputs;
   inputs = malloc(length * sizeof(double));
   inputs[0] = .2;
   inputs[1] = .3;

   double *weights;
   weights = malloc(length * sizeof(double));
   weights[0] = .5;
   weights[1] = .4;

   double bias = .1;

   printf("test w output: %f\n", w(inputs, weights, length));
   printf("test sigmoid activation output: %f\n", a_sigmoid(inputs, weights, bias, length));
   printf("test tanh activation output: %f\n", a_tanh(inputs, weights, bias, length));
   printf("test relu activation output: %f\n", a_relu(inputs, weights, bias, length));

   // activations work
}

void test_layer() {
    //activation_test();

    struct layer sheet;
    sheet.input_len = 2;
    sheet.layer_len = 3;
    sheet.activation = 's';
    init_weights(&sheet);
    printf("first weights init\n");
    init_biases(&sheet);
    printf("first bias init\n");

    for (int i = 0; i < sheet.layer_len; i++) {
        sheet.biases[i] = .1;
        printf("bias init\n");
        for (int j = 0; j < sheet.input_len; j++) {
            sheet.weights[i][j] = .1;
            printf("second weights init\n");
            printf("val: %f, ptr: %p\n", sheet.weights[i][j], sheet.weights[i]);
        }
    }

    // need to test layering

    double inputs[] = {.2, .2};

    double *result = output(&sheet, inputs);
    for (int i = 0; i < sheet.layer_len; i++) {
        printf("final result[%i]: %f\n", i, result[i]);
    }

    // equals ~0.465057
    // seems to work
}

void arc_test(char *arc) {
    int size = (int) strlen(arc);
    printf("strlen: %d\n", size);
    
    char *temp_string;
    temp_string = malloc(1 * sizeof(char));
    for (int i = 0; i < size; i++) {
        if (arc[i] >= '0' && arc[i] <= '9') {
            temp_string = (char *) realloc(temp_string, ((int) strlen(temp_string) + 1) * sizeof(char));
            strncat(temp_string, &arc[i], 1);
        } else if (arc[i] == '|') {
            int len_to_use = atoi(temp_string);
            printf("%i\n", len_to_use);
            memset(temp_string, 0, strlen(temp_string));
            if (arc[i-1] != 'i') {
                printf("use last len\n");
            } else {
                printf("special case\n");
            }
        }
    }
    
    free(temp_string);
} 

void test_nn_creation() {
    // next test creating a model
    char arc[] = "3i|4r|6r|6r|2s|";
    struct nn network = create_nn(arc);

    printf("length: %i\n------------------\n", network.len);
    for (int i = 0; i < network.len; i++) {
        printf("input len: %i\n", network.layers[i].input_len);
        printf("layer len: %i\n", network.layers[i].layer_len);
        printf("activation: %c\n", network.layers[i].activation);
        printf("------------------\n");
    }
}

int main(int argc, char *argv[]) {
    // test initialization
    srand(time(NULL));

    char arc[] = "3i|4r|6r|6r|2s|";
    struct nn network = create_nn(arc);

    network_init(&network, 0);

    for (int i = 0; i < network.len; i++) {
        for (int j = 0; j < network.layers[i].layer_len; j++) {
            for (int k = 0; k < network.layers[i].input_len; k++) {
                printf("layer %i and weight %i: %f\n", i, j, network.layers[i].weights[j][k]);
            }
        }
    }
}