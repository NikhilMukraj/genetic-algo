#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double w(double *inputs, double *weights, int length) {
    double answer = 0;

    for (int i = 0; i < length; i++) {
        answer += inputs[i] * weights[i];
    }

    return answer;
}

double a_tanh(double *inputs, double *weights, double bias, int length) {
    double z = bias + w(inputs, weights, length);

    return (exp(z) - exp(-1 * z)) / (exp(z) + exp(-1 * z));
}

double a_sigmoid(double *inputs, double *weights, double bias, int length) {
    double P = bias + w(inputs, weights, length);

    return 1 / (1 + exp(P));
}

double a_relu(double *inputs, double *weights, double bias, int length) {
    double P = bias + w(inputs, weights, length);

    return 0.0 > P ? 0.0 : P;
}

struct layer{
    int input_length;
    int amount_of_neurons;
    char activation;
    double *weights;
    double *bias;
};