#include <stdio.h>
#include <stdlib.h>
#include "activations.h"


int main(int argc, char *argv[]) {
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