#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "neuron.h"
#include "user.h"

extern int CHOSEN_PROGRAM;

/**
 * @brief A function to add an entry at the end of an entry list
 * 
 * @param list the entry list
 * @param value the value attribute of the new element we want to add
 * @return Entry_List 
 */
Entry_List E_Add_Elem_Tail(Entry_List list, int value){
    Entry_List new_elem = (Entry_List)malloc(sizeof(Entry_List));
    new_elem->value = value;
    new_elem->next = NULL;

    if (list == NULL){
        new_elem->prev = NULL;
        return new_elem;
    }
    else {
        Entry_List temp = list;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_elem;
        new_elem->prev = temp;
        return list;
    }
}


/**
 * @brief A function to add a weight at the end of a weight list
 * 
 * @param list the weight list
 * @param value the value attribute of the new element we want to add
 * @return Weight_List 
 */
Weight_List W_Add_Elem_Tail(Weight_List list, int value){
    Weight_List new_elem = (Weight_List)malloc(sizeof(Weight_Elem));
    if (new_elem == NULL){
        perror("The memory allocation failed for the new element");
        exit(1);
    }
    new_elem->value = value;
    new_elem->next = NULL;

    if (list == NULL){
        return new_elem;
    }
    else {
        Weight_List temp = list;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_elem;
        return list;
    }
}

/**
 * @brief A function to add a neurone at the end of a neuron list
 * 
 * @param list the neuron list
 * @param neuron the neuron we want to add
 * @return Neuron_List 
 */
Neuron_List N_Add_Elem_Tail(Neuron_List list, Neuron neuron) {
    Neuron_List new_elem = (Neuron_List)malloc(sizeof(Neuron));
    if (new_elem == NULL) {
        perror("The memory allocation failed for the new element");
        exit(1);
    }

    new_elem->weight_list = neuron.weight_list;
    new_elem->bias = neuron.bias;
    new_elem->next = NULL;

    if (list == NULL) {
        return new_elem;
    }
    else {
        Neuron_List temp = list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_elem;
        return list;
    }
}

/**
 * @brief A function to add a layer at the end of a layer list
 * 
 * @param list the layer list
 * @param layer the layer we want to add
 * @return Layer_List 
 */
Layer_List L_Add_Elem_Tail(Layer_List list, Layer layer) {
    Layer_List new_elem = (Layer_List)malloc(sizeof(Layer));
    if (new_elem == NULL) {
        perror("The memory allocation failed for the new element");
        exit(1);
    }
    *new_elem = layer;
    new_elem->next = NULL;

    if (list == NULL) {
        return new_elem;
    } else {
        Layer_List temp = list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_elem;
        return list;
    }
}



/**
 * @brief A function allowing to create a neuron
 * 
 * @param weight_list the list of weights for the neuron
 * @param bias the bias of the neuron
 * @param nb_entries the number of entries for the neuron
 * @return Neuron 
 */
Neuron Init_Neur(int *weight_list, int bias, int nb_entries) {
    Neuron neuron;
    neuron.weight_list = NULL;
    
    for (int i = 0; i < nb_entries; i++) { // Add each weight to the neuron
        neuron.weight_list = W_Add_Elem_Tail(neuron.weight_list, weight_list[i]);
    }
    
    neuron.bias = bias;
    free(weight_list);  
    return neuron;
}

/**
 * @brief A function allowing to get the output of a neuron
 * 
 * @param neuron a Neuron
 * @param ei the list of entries
 * @return int 
 */
int Out_Neur(Neuron neuron, Entry_List ei){
    int x = 0;
    Weight_List temp = neuron.weight_list;
    if (temp == NULL){
        perror("The weight list is empty");
        exit(EXIT_FAILURE);
    }
    if (ei == NULL){
        perror("The entry list is empty");
        exit(EXIT_FAILURE);
    }
    while (ei != NULL && temp != NULL){
        x += temp->value * ei->value;
        ei = ei->next;
        temp = temp->next;
    }
    
    if (x >= neuron.bias){
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * @brief A function to get the weights of a neuron for the 5th program
 * 
 * @param layer the number of the layer
 * @return int* 
 */
int Weights_For_M_L(int nb_layer, int n_neuron, int n_entries) {
    switch(nb_layer) {
        case 1: 
            switch(n_neuron) {
                case 1: 
                    switch(n_entries) {
                        case 1: 
                            return 1;
                        case 2: 
                            return 0;
                        case 3: 
                            return 0;
                    }
                case 2: 
                    switch(n_entries) {
                        case 1: 
                            return 0;
                        case 2: 
                            return -1;
                        case 3: 
                            return 0;
                    }
                case 3:
                    switch(n_entries) {
                        case 1: 
                            return 0;
                        case 2: 
                            return 0;
                        case 3: 
                            return 1;
                    }
                case 4: 
                    switch(n_entries) {
                        case 1: 
                            return 0;
                        case 2: 
                            return 0;
                        case 3: 
                            return -1;
                    }
                
            }  
        case 2: 
            switch(n_neuron) {
                case 1: 
                    switch(n_entries) {
                        case 1: 
                            return 1;
                        case 2: 
                            return 1;
                        case 3: 
                            return 1;
                        case 4: 
                            return 0;
                    }
                case 2: 
                    switch(n_entries) {
                        case 1: 
                            return 1;
                        case 2: 
                            return 0;
                        case 3: 
                            return 0;
                        case 4:
                            return 0;
                    }
            }            
        case 3:  
            return 1;  
            
        default:
            return 0;
    }
}

/**
 * @brief A function to get the bias of a neuron for the 5th program
 * 
 * @param layer the number of the layer
 * @param neuron the number of the neuron
 * @return int 
 */
int Bias_For_M_L(int layer, int neuron) {
    switch(layer) {
        case 1:  
            return 0.5;
            break;

        case 2 : 
            if (neuron == 1) {  
                return 3;
            } else {                
                return 2;
            }
            
        case 3:  
            return 1;   
    }
    return 0;
}


/**
 * @brief Une fonction permettant de créer une couche de neurones
 * 
 * @param nb_neurons le nombre de neurones dans la couche
 * @param nb_entries le nombre d'entrées pour le ou les neurones
 * @param nb_layer le numéro de la couche
 * @return Layer 
 */
Layer Init_Couche(int nb_neurons, int nb_entries,int nb_layer){
    Layer layer;
    layer.neurons = NULL;
    int *weight_list;  
    int bias;
    printf("\n\e[3mCreating the layer n°%d...\e[0m\n",nb_layer);
    for (int i = 0; i < nb_neurons; i++){
        if (CHOSEN_PROGRAM == 1){
            bias = Ask_Bias(i+1);
        }
        if (CHOSEN_PROGRAM == 2){
            bias = nb_entries;
        }
        if (CHOSEN_PROGRAM == 3){
            bias = 1;
        }
        if (CHOSEN_PROGRAM == 4){
            bias = 0;
        }
        if (CHOSEN_PROGRAM == 5){
            bias = bias = Bias_For_M_L(nb_layer, i+1);
        }
        weight_list = Ask_Weight_List(nb_entries, i+1, nb_layer);
        Neuron neuron = Init_Neur(weight_list, bias, nb_entries);
        layer.neurons = N_Add_Elem_Tail(layer.neurons, neuron);
    }
    return layer;
}

/**
 * @brief A function to get the entries list that is the output of a layer
 * 
 * @param layer A layer of the neural network
 * @param ei An entry list
 * @return Linked_List 
 */
Entry_List Out_Couche(Layer layer, Entry_List ei){
    Entry_List result = NULL;
    Neuron_List neuron_list = layer.neurons;
    if (neuron_list == NULL) {
        fprintf(stderr, "Error: layer.neurons is NULL\n");
        return NULL;
    }
    while (neuron_list != NULL){
        int out_neur_result = Out_Neur(*neuron_list, ei);
        result = E_Add_Elem_Tail(result, out_neur_result);
        neuron_list = neuron_list->next;
    }
    return result;
    
}

/**
 * @brief A function to create a neural network
 * 
 * @param nb_layers the number of layers of the neural network
 * @param layers_infos the list of the parameters of the layers
 * @return Neural_Network 
 */
Neural_Network Creer_Res_Neur(int nb_layers, Layer_Parameters *layers_infos) {
    Neural_Network neural_network;
    neural_network.Input_layer = NULL;
    neural_network.Output_layer = NULL;
    Layer_List current = NULL;

    for (int i = 0; i < nb_layers; i++) {
        Layer layer = Init_Couche(layers_infos[i].nb_neurons, layers_infos[i].nb_entries, i+1);
        if (neural_network.Input_layer == NULL) {
            // First layer becomes input layer
            neural_network.Input_layer = L_Add_Elem_Tail(NULL, layer);
            current = neural_network.Input_layer;
        } else {
            // Add subsequent layers to the chain
            current->next = L_Add_Elem_Tail(NULL, layer);
            current = current->next;
            // Last layer becomes output layer
            neural_network.Output_layer = current;
        }
    }
    return neural_network;
}

/**
 * @brief A procedure that implements the forward propagation on a neural network
 * 
 * @param neural_network a neural network
 * @param ei a list of entries
 */

Entry_List Forward_Propagation(Neural_Network neural_network, Entry_List ei){
    Entry_List result = ei;
    Layer_List temp_layer = neural_network.Input_layer;
    while (temp_layer != NULL){
        result = Out_Couche(*temp_layer, result);
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
int Get_Final_Output(Entry_List result_list){
    if (result_list == NULL){
        perror("The result list is empty");
        exit(EXIT_FAILURE);
    }
    if (result_list->next != NULL){
        perror("The result list has more than one element");
        exit(EXIT_FAILURE);
    }
    else {
        return result_list->value;
    }
}

/**
 * @brief A function to free the memory allocated for the weight list
 * 
 * @param weight_list a list of weights
 */
void Free_Weight_List(Weight_List weight_list) {
    Weight_List current = weight_list;
    Weight_List next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
