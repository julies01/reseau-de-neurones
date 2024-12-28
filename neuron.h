#ifndef NEURON_H
#define NEURON_H

typedef struct Neuron {
    double *weights;
    double bias;
    double output;
    double error;
} Neuron;

#endif