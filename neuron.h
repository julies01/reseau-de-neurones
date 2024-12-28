#ifndef NEURON_H
#define NEURON_H

typedef struct Weight {
    int value;
    struct Weight *next;
}  Weight ;

typedef struct Weight *Weight_List;

typedef struct Neuron {
   Weight_List weights;
   int bias;
   struct Neuron *next;
} Neuron;

typedef struct Neuron *Layer;

#endif