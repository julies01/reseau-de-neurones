#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "neuron.h"
#include "ntwrk.h"


/**
 * @brief 
 * 
 * @param nb_layers 
 * @return N_Layer_Parameters* 
 */
N_Layer_Parameters *N_Ask_Layers_Parameters(int nb_layers){
    N_Layer_Parameters *layers_info = (N_Layer_Parameters *)malloc(nb_layers*sizeof(N_Layer_Parameters));
    for (int i = 0; i < nb_layers; i++){
        printf("\n\e[3mFor the layer n°%d...\e[0m\n",i+1);
        int nb_neurons;
        printf("\n-> Please enter \e[1mthe number of neurons\e[0m for the layer n°%d : ", i+1);
        char input_1[10];
        scanf("%9s", input_1);

        while (strlen(input_1) != 1 || !isdigit(input_1[0])) {
            printf("-> Please enter \e[31ma valid number\e[0m for the number of neurons : ");
            scanf("%9s", input_1);
        }
        nb_neurons = input_1[0] - '0';
        layers_info[i].nb_neurons = nb_neurons;

        for (int j = 0; j < nb_neurons; j++){
            int nb_entries;
            printf("-> Please choose \e[1mthe number of entries\e[0m that your neuron or neurons will receive : ");
            char input_2[10];
            scanf("%9s", input_2);

            while (strlen(input_2) != 1 || !isdigit(input_2[0]) || (input_2[0]-'0') <= 0) {
                printf("-> Please enter \e[31ma valid number\e[0m for the number of entries : ");
                scanf("%9s", input_2);
            }
            nb_entries = input_2[0] - '0';
            layers_info[i].nb_entries[i] = nb_entries;
        }
    }
    return layers_info;
    free(layers_info);
}

int N_Weights_For_M_L(int layer) {
    switch(layer) {
        case 1:  // First layer (NOT neurons)
            return -1;  // NOT neurons have weight -1
            
        case 2: 
            return 1;  // Second layer (AND neurons)
            
        case 3:  // Third layer (OR neuron)
            return 1;   // OR neuron has weight 1
            
        default:
            return 0;
    }
}

int *N_Ask_Weight_List(int nb_entries,int layer){

    int *weight_list = (int *)malloc(nb_entries*sizeof(int));
    printf("\n\e[3mCreating the weight list ...\e[0m\n");
    int value;

    for (int i = 0; i < nb_entries; i++){
         value = N_Weights_For_M_L(layer);
         weight_list[i] = value; 
    }
    return weight_list;
}

int N_Bias_For_M_L(int layer, int neuron) {
    switch(layer) {
        case 1:  // NOT neurons
            switch (neuron){
                case 1:
                    return 1;
                    break;
                case 2:
                    return 0;
                    break;
                case 3:
                    return 1;
                    break;
                case 4:
                    return 0;
                    break;
                default:
                    break;
            }

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

int N_Input_Control(int input,char valid_input_list[],int size){
        for(int i = 0; i < size; i++) {
            if (input == valid_input_list[i]) {
                return 1;
            }
        }
        return -1;
}



Entry_List N_Entry_Mapping(Entry_List *entry_list, Neuron *neuron, int neuron_number){
    printf("\n\e[3mMapping the entries to the neuron n°%d...\e[0m\n",neuron_number);
    int nb_entries_neuron = 0;
    Weight_List temp = neuron->weight_list;
    while (temp != NULL){
        nb_entries_neuron++;
        temp = temp->next;
    }
    printf("\nThe neuron has %d entry/entries.\n", nb_entries_neuron);
    Entry_List final_entry = NULL;
    Entry_List original = *entry_list;  // Save original position

    for (int i = 0; i < nb_entries_neuron; i++){
        *entry_list = original;  // Reset position for each entry
        while (*entry_list != NULL){
            printf("    Would you like to map the entry of value %d to the entry n°%d ? (Y/N) : ", (*entry_list)->value,i+1);
            char input[10];
            char valid_input_list[3] = {"YN"};
            scanf("%9s", input);
            while (strlen(input) != 1 || N_Input_Control(input[0], valid_input_list, 3) == -1) {
                printf("-> Please enter \e[31ma valid letter\e[0m : ");
                scanf("%9s", input);
            }
            if (input[0] == 'Y'){
                final_entry = E_Add_Elem_Tail(final_entry, (*entry_list)->value);
                break;
            }
            *entry_list = (*entry_list)->next;
        }
    }
    *entry_list = original;  // Restore original position
    return final_entry;
}

Layer N_Init_Couche(int nb_neurons, int* nb_entries,int n_layer){
    Layer layer;
    layer.neurons = NULL;
    int *weight_list;  
    int bias;
    printf("\n\e[3mCreating the layer n°%d...\e[0m\n",n_layer);
    for (int i = 0; i < nb_neurons; i++){
        bias = N_Bias_For_M_L(n_layer, i+1);
        weight_list = N_Ask_Weight_List(nb_entries[i], n_layer);
        Neuron neuron = Init_Neur(weight_list, bias, nb_entries[i]);
        layer.neurons = N_Add_Elem_Tail(layer.neurons, neuron);
    }
    return layer;
}

Neural_Network N_Creer_Res_Neur(int nb_layers, N_Layer_Parameters *layers_infos) {
    Neural_Network neural_network;
    neural_network.Input_layer = NULL;
    neural_network.Output_layer = NULL;
    Layer_List current = NULL;

    for (int i = 0; i < nb_layers; i++) {
        Layer layer = N_Init_Couche(layers_infos[i].nb_neurons, layers_infos[i].nb_entries, i+1);
        if (neural_network.Input_layer == NULL) {
            neural_network.Input_layer = L_Add_Elem_Tail(NULL, layer);
            current = neural_network.Input_layer;
        } else {
            current->next = L_Add_Elem_Tail(NULL, layer);
            current = current->next;
            neural_network.Output_layer = current;
        }
    }
    return neural_network;
}

Entry_List N_Out_Couche(Layer layer, Entry_List ei){
    Entry_List result = NULL;
    Neuron_List neuron_list = layer.neurons;
    if (neuron_list == NULL) {
        fprintf(stderr, "Error: layer.neurons is NULL\n");
        return NULL;
    }
    int count_neurons = 1;
    while (neuron_list != NULL){
        Entry_List f_ei = N_Entry_Mapping(&ei, neuron_list,count_neurons);
        int out_neur_result = Out_Neur(*neuron_list, f_ei);
        result = E_Add_Elem_Tail(result, out_neur_result);
        neuron_list = neuron_list->next;
        count_neurons++;
    }
    return result;
    
}

Entry_List N_Forward_Propagation(Neural_Network neural_network, Entry_List ei){
    Entry_List result = ei;
    Layer_List temp_layer = neural_network.Input_layer;
    while (temp_layer != NULL){
        result = N_Out_Couche(*temp_layer, result);
        See_Entry_List(result);
        temp_layer = temp_layer->next;
    }
    return result;
}



