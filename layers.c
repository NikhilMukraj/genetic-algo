#include <stdio.h>
#include <stdlib.h>
#include "activations.c"


struct layer {
    int input_len;
    int layer_len;
    double **weights; // each neuron has an array of weights attached to it
    double *biases; // each neuron only needs one bias
    char activation;
}; // layer of neurons

void init_weights(struct layer *sheet) {
    // creates 2d array for weights
    struct layer *temp_sheet;
    temp_sheet = (struct layer *) sheet;
    double **arr;
    temp_sheet->weights = malloc(temp_sheet->layer_len * sizeof(*arr));
    for (int i = 0; i < temp_sheet->layer_len; i++) {
        temp_sheet->weights[i] = malloc(temp_sheet->input_len * sizeof(double));
    }
}

void init_biases(struct layer *sheet) {
    // creates 1d array for biases
    struct layer *temp_sheet;
    temp_sheet = (struct layer *) sheet;
    double *biases;
    biases = malloc(temp_sheet->layer_len * sizeof(double));
    temp_sheet->biases = biases;
}

double *output(struct layer *sheet, double *inputs) {
    // calculates result of activation function given inputs and weights
    struct layer *temp_sheet;
    temp_sheet = (struct layer *) sheet;

    double *answer;
    answer = malloc(temp_sheet->layer_len * sizeof(double));

    for (int i = 0; i < temp_sheet->layer_len; i++) {
        switch (temp_sheet->activation) {
        case 't':
            answer[i] = a_tanh(inputs, temp_sheet->weights[i], temp_sheet->biases[i], temp_sheet->input_len);
            break;
        case 's':
            answer[i] = a_sigmoid(inputs, temp_sheet->weights[i], temp_sheet->biases[i], temp_sheet->input_len);
            break;
        case 'r':
            answer[i] = a_relu(inputs, temp_sheet->weights[i], temp_sheet->biases[i], temp_sheet->input_len);
            break;
        }
    }

    return answer;   
}
