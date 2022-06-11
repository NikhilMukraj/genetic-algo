#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double w(double *inputs, double *weights, int length) {
    double answer = 0;

    for (int i = 0; i < length; i++) {
        answer += inputs[i] + weights[i];
    }

    return answer
}

double tanh(double *inputs, double *weights, double bias, int length) {

}

double sigmoid(double *inputs, double *weights, double bias, int length) {
    double P = bias;
    P += w(inputs, weights, length);

    return 1 / (1 + exp(-1 * P));
}

double relu(double *inputs, double *weights, double bias, int length) {
    double P = bias;
    P += w(inputs, weights, length);

    return 0.0 > P ? 0.0 : P;
}