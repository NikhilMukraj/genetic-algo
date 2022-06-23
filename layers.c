#include <stdio.h>
#include <stdlib.h>
#include "activations.c"


struct layer {
    int input_len;
    int layer_len;
    double **weights;
    double *biases;
    char activation;
};

void init_weights(struct layer *sheet) {
    struct layer *temp_sheet;
    temp_sheet = (struct layer *) sheet;
    double **arr;
    temp_sheet->weights = malloc(temp_sheet->layer_len * sizeof(*arr));
    for (int i = 0; i < temp_sheet->layer_len; i++) {
        temp_sheet->weights[i] = malloc(temp_sheet->input_len * sizeof(double));
    }
}

double *output(struct layer sheet, double *inputs) {
    double *answer;
    answer = malloc(sheet.layer_len * sizeof(double));

    for (int i = 0; i < sheet.layer_len; i++) {
        switch (sheet.activation) {
        case 't':
            answer[i] = a_tanh(inputs, sheet.weights[i], layer.biases[i])
            break;
        case 's':
            answer[i] = a_sigmoid(inputs, sheet.weights[i], layer.biases[i])
            break;
        case 'r':
            answer[i] = a_relu(inputs, sheet.weights[i], layer.biases[i])
            break;
        }
    }

    return answer;   
}
