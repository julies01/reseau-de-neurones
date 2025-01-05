#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "neuron.h"

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

Entry_List Create_Entries_List(int nb_entries){
    Entry_List entries_list = NULL;
    for (int i = 0; i < nb_entries; i++){
        int value;
        printf("-> Please enter \e[1mthe value\e[0m of the entry number %d : ", i+1);
        char input[10];
        scanf("%9s", input);
        while (strlen(input) != 1 || !isdigit(input[0])) {
            printf("-> Please enter \e[31ma valid number\e[0m for the entry value : ");
            scanf("%9s", input);
        }
        value = input[0] - '0';
        entries_list = E_Add_Elem_Tail(entries_list, value);
    }
    return entries_list;
}



int *Create_Weigth_List(int nb_entries, int value){
    int *weight_list = (int *)malloc(nb_entries*sizeof(int));
    for (int i = 0; i < nb_entries; i++){
        weight_list[i] = value;
    }
    return weight_list;
}

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

Neuron_List N_Add_Elem_Tail(Neuron_List list, Neuron neuron){
    Neuron_List new_elem = (Neuron_List)malloc(sizeof(Neuron));
    if (new_elem == NULL){
        perror("The memory allocation failed for the new element");
        exit(1);
    }

    new_elem = &neuron;
    new_elem->next = NULL;

    if (list == NULL){
        return new_elem;
    }
    else {
        Neuron_List temp = list;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_elem;
        return list;
    }
}

Layer_List L_Add_Elem_Tail(Layer_List list, Layer layer){
    Layer_List new_elem = (Layer_List)malloc(sizeof(Layer));
    if (new_elem == NULL){
        perror("The memory allocation failed for the new element");
        exit(1);
    }
    new_elem = &layer;
    if (list == NULL){
        return new_elem;
    }
    else {
        Layer_List temp = list;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_elem;
        return list;
    }
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
        neuron.weight_list = W_Add_Elem_Tail(neuron.weight_list, weight_list[i]);
    }
    neuron.bias = bias;
    return neuron;
}

int Out_Neur(Neuron neuron, Entry_List ei){
    int x = 0;
    while (ei != NULL){
        x += neuron.weight_list->value * ei->value;
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

int *Ask_Weight_List(int nb_entries){
    int *weight_list = (int *)malloc(nb_entries*sizeof(int));
    printf("\e[3mCreating the weight list ...\e[0m\n");
    for (int i = 0; i < nb_entries; i++){
        int value;
        printf("-> Please enter \e[1mthe weight\e[0m of the entry number %d : ", i+1);
        char input[10];
        scanf("%9s", input);
        while (strlen(input) != 1 || !isdigit(input[0])) {
            printf("-> Please enter \e[31ma valid number\e[0m for the weight value : ");
            scanf("%9s", input);
        }
        value = input[0] - '0';
        weight_list[i] = value;
    }
    return weight_list;
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
        layer.neurons = N_Add_Elem_Tail(layer.neurons, neuron);
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
Entry_List OutCouche(Layer layer, Entry_List ei){
    Entry_List result = NULL;
    while (layer.neurons != NULL){
        int out_neur_result = Out_Neur(*(Neuron *)(layer.neurons), ei);
        result = E_Add_Elem_Tail(result, out_neur_result);
        layer.neurons = layer.neurons->next;
    }
    return result;
    
}

/**
 * @brief A function to ask the user the number of entries that the neuron or neurons will receive
 * 
 * @return int 
 */
int Ask_Nb_Entries(){
    int nb_entries;
    printf("-> Please choose \e[1mthe number of entries\e[0m that your neuron or neurons will receive : ");
    char input[10];
    scanf("%9s", input);

    //check if the input is a number superior to 0
    while (strlen(input) != 1 || !isdigit(input[0]) || (input[0]-'0') <= 0) {
        printf("-> Please enter \e[31ma valid number\e[0m for the number of entries : ");
        scanf("%9s", input);
    }
    nb_entries = input[0] - '0';
    return nb_entries;
}


Neural_Network Creer_Res_Neur(int nb_layers, int *nb_neurons_list){
    Neural_Network neural_network;
    neural_network.Input_layer = NULL;
    neural_network.Output_layer = NULL;

    int nb_entries;
    for (int i = 0; i < nb_layers; i++){
        nb_entries = Ask_Nb_Entries();
        Layer layer = InitCouche(nb_neurons_list[i], nb_entries);
        if (neural_network.Input_layer == NULL){
            neural_network.Input_layer = L_Add_Elem_Tail(neural_network.Input_layer, layer);
        }
        else {
            neural_network.Output_layer = L_Add_Elem_Tail(neural_network.Output_layer, layer);
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

