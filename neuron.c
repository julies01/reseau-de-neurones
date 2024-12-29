#include <stdlib.h>
#include <stdio.h>
#include "neuron.h"

Linked_List L_Add_Elem_Tail(Linked_List list, void* value, size_t value_size){
    Linked_List new_elem = (Linked_List)malloc(sizeof(Linked_Elem));
    if (new_elem == NULL){
        perror("The memory allocation failed for the new element");
        exit(1);
    }
    new_elem->value = malloc(value_size);
    if (new_elem->value == NULL){
        perror("The memory allocation failed for the value of the new element");
        exit(1);
    }
    memcpy(new_elem->value, value, value_size);
    new_elem->next = NULL;

    if (list == NULL){
        return new_elem;
    }
    else {
        Linked_List temp = list;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_elem;
        return list;
    }
}

See_Linked_List(Linked_List list){
    while (list != NULL){
        printf("%d ",*(int *)(list->value));
        list = list->next;
    }
    printf("\n");
}

/**
 * @brief A function allowing to create a neuron
 * 
 * @param weight_list 
 * @param bias 
 * @param nb_entries 
 * @return Neuron 
 */
Neuron Init_Neur(int *weight_list,int bias, int nb_entries){
    Neuron neuron;
    neuron.weight_list = NULL;
    for (int i = 0; i < nb_entries; i++){
        neuron.weight_list = L_Add_Elem_Tail(neuron.weight_list, weight_list[i], sizeof(int));
    }
    neuron.bias = bias;
    return neuron;
}

/**
 * @brief A procedure allowing to see the content of a neuron
 * 
 * @param neuron 
 */
void See_Neur(Neuron neuron){
    printf("Neuron : \n");
    printf("Bias : %d\n",neuron.bias);
    printf("Weight list : ");
    while (neuron.weight_list != NULL){
        printf("%d ",neuron.weight_list->value);
        neuron.weight_list = neuron.weight_list->next;
    }
    printf("\n");
}

int Out_Neur(Neuron neuron, DLinked_List ei){
    int x = 0;
    while (ei != NULL){
        x += *(int *)(ei->value) * *(int *)(neuron.weight_list->value);
        ei = ei->next;
        neuron.weight_list = neuron.weight_list->next;
    }
    
    if (x >= neuron.bias){
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * @brief Une fonction permettant de créer une couche de neurones
 * 
 * @param nb_neurons le nombre de neurones dans la couche
 * @param nb_entries le nombre d'entrées pour le ou les neurones
 * @return Layer 
 */
Layer InitCouche(int nb_neurons, int nb_entries){
    Layer layer;
    layer.neurons = NULL;
    int *weight_list = Ask_Weight_List(nb_entries);
    for (int i = 0; i < nb_neurons; i++){
        Neuron neuron = Init_Neur(weight_list, 1, nb_entries);
        layer.neurons = L_Add_Elem_Tail(layer.neurons, &neuron, sizeof(Neuron));
    }
    return layer;
}

/**
 * @brief 
 * 
 * @param layer 
 * @param ei 
 * @return Linked_List 
 */
Linked_List OutCouche(Layer layer, DLinked_List ei){
    Linked_List result = NULL;
    while (layer.neurons != NULL){
        result = L_Add_Elem_Tail(result, Out_Neur(*(Neuron *)(layer.neurons), ei), sizeof(int));
        layer.neurons = layer.neurons->next;
    }
    return result;
    
}

Neural_Network CreerResNeur(int nb_layers, int *nb_neurons_list){
    Neural_Network neural_metwork;
    neural_metwork.Input_layer = NULL;
    neural_metwork.Output_layer = NULL;

    int nb_entries;
    for (int i = 0; i < nb_layers; i++){
        nb_entries = Ask_Nb_Entries();
        Layer layer = InitCouche(nb_neurons_list[i], nb_entries);
        if (neural_metwork.Input_layer == NULL){
            neural_metwork.Input_layer = L_Add_Elem_Tail(neural_metwork.Input_layer, &layer, sizeof(Layer));
        }
        else {
            neural_metwork.Output_layer = L_Add_Elem_Tail(neural_metwork.Output_layer, &layer, sizeof(Layer));
        }
    }
    return neural_metwork;
}

/**
 * @brief A procedure that implements the forward propagation on a neural network
 * 
 * @param neural_network a neural network
 * @param ei a list of entries
 */

Linked_List Forward_Propagation(Neural_Network neural_network, DLinked_List ei){
    Linked_List result = ei;
    Layer *temp_layer = neural_network.Input_layer;
    while (temp_layer != NULL){
        result = OutCouche(*(Layer *)(temp_layer), result);
        temp_layer = temp_layer->next;
    }
    return result;
}

/**
 * @brief A function that allow to see the final output of the neural network
 * 
 * @param result the list of the result of the output layer
 * @return int 
 */
int See_Final_Output(Linked_List result_list){
    if (result_list == NULL){
        perror("The result list is empty");
        EXIT_FAILURE;
    }
    if (result_list->next != NULL){
        perror("The result list has more than one element");
        EXIT_FAILURE;
    }
    else {
        return *(int *)(result_list->value);
    }
}

