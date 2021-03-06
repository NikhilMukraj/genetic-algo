#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double w(double *inputs, double *weights, int length) {
    // summation of the resulting vector of dot product of inputs and weights
    double answer = 0;

    for (int i = 0; i < length; i++) {
        answer += inputs[i] * weights[i];
    }

    return answer;
}

double a_tanh(double *inputs, double *weights, double bias, int length) {
    // hyperbolic tangent activation
    double z = bias + w(inputs, weights, length);

    return (exp(z) - exp(-1 * z)) / (exp(z) + exp(-1 * z));
}

double a_sigmoid(double *inputs, double *weights, double bias, int length) {
    // sigmoidal activation
    double P = bias + w(inputs, weights, length);

    return 1 / (1 + exp(P));
}

double a_relu(double *inputs, double *weights, double bias, int length) {
    // relu activation
    double P = bias + w(inputs, weights, length);

    return 0.0 > P ? 0.0 : P;
}