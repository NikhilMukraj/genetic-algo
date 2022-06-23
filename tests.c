#include <stdio.h>
#include <stdlib.h>
#include "layers.c"


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

int main(int argc, char *argv[]) {
    //activation_test();

    struct layer sheet;
    sheet.input_len = 2;
    sheet.layer_len = 3;
    init_weights(&sheet);

    double count;
    for (int i = 0; i < sheet.layer_len; i++) {
        for (int j = 0; j < sheet.input_len; j++) {
            sheet.weights[i][j] = count;
            printf("val: %f, ptr: %p\n", sheet.weights[i][j], sheet.weights[i]);
            count++;
        }
    }

    // need to test layering
}