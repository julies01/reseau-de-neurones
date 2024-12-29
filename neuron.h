#ifndef NEURON_H
#define NEURON_H


typedef struct Linked_Elem {
    void* value;
    struct Linked_Elem *next;
} Linked_Elem;

typedef struct Linked_Elem *Linked_List;

typedef struct DLinked_Elem {
    int value;
    struct DLinked_Elem *next;
    struct DLinked_Elem *prev;
}  DLinked_Elem ;

typedef struct DLinked_Elem *DLinked_List;

typedef struct Neuron {
   Linked_List weight_list;
   int bias;
   struct Neuron *next;
} Neuron;

typedef struct Layer {
    Neuron *neurons;
    struct Layer *next;
} Layer;

typedef struct Neural_Network {
    Layer *Input_layer;
    Layer *Output_layer;
} Neural_Network;

void See_Neur(Neuron neuron);
Neuron Init_Neur(int *weight_list,int bias, int nb_entries);
int Out_Neur(Neuron neuron, DLinked_List ei);
Neural_Network CreerResNeur(int nb_layers, int *nb_neurons_list)

#endif