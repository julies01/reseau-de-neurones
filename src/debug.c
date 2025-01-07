#include <stdio.h>
#include <stdlib.h>
#include "neuron.h"

/**
 * @brief A procedure allowing to see the content of a neuron
 * 
 * @param neuron A neuron
 */
void See_Neur(Neuron *neuron, int i){

    printf("    Neuron n°%d: \n",i);
    printf("        Bias : %d\n", neuron->bias);

    printf("        Weight list : ");
    Weight_List temp = neuron->weight_list;
    while (temp != NULL){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * @brief A procedure allowing to see the content of a weight list
 * 
 * @param list the list of entries
 */
void See_Entry_List(Entry_List list){
    printf("\nEntry list : [");
    while (list != NULL){
        printf("%d, ",list->value);
        list = list->next;
    }
    printf("]\n");
    printf("\n");
}

/**
 * @brief A procedure allowing to see the content of a layer
 * 
 * @param layer A layer
 * @param i The number of the layer
 */
void See_Layer(Layer *layer, int i){
    printf("\nLayer n°%d : \n",i);
    Neuron_List temp_neuron = layer->neurons;
    int j = 1;
    while (temp_neuron != NULL){
        See_Neur(temp_neuron, j);
        j++;
        temp_neuron = temp_neuron->next;
    }
}

/**
 * @brief A procedure allowing to see the content of a neural network
 * 
 * @param neural_network A neural network
 */
void See_N_N(Neural_Network neural_network){
    Layer_List temp_layer = neural_network.Input_layer;
    int k = 1;
    while (temp_layer != NULL){
        See_Layer(temp_layer, k);
        k++;
        temp_layer = temp_layer->next;
    }
}