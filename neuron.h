#ifndef NEURON_H
#define NEURON_H


typedef struct Chained_Elem {
    int value;
    struct Chained_Elem *next;
}  Chained_Elem ;

typedef struct Chained_Elem *Chained_List;

typedef struct Neuron {
   Chained_List weight_list;
   int bias;
   struct Neuron *next;
} Neuron;

typedef struct Layer {
    Neuron *neurons;
    struct Layer *next;
} Layer;

typedef struct Layer *Neural_Network;

/**
 * @brief A function allowing to create a neuron
 * 
 * @param weight_list 
 * @param bias 
 * @param nb_entries 
 * @return Neuron 
 */
Neuron InitNeur(Chained_List weight_list,int bias, int nb_entries);

/**
 * @brief A procedure allowing to see the content of a neuron
 * 
 * @param neuron 
 */
void SeeNeur(Neuron neuron);



#endif