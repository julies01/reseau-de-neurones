#include <stdlib.h>
#include <stdio.h>
#include "neuron.h"

/**
 * @brief A function allowing to create a neuron
 * 
 * @param weight_list 
 * @param bias 
 * @param nb_entries 
 * @return Neuron 
 */
Neuron InitNeur(Chained_List weight_list,int bias, int nb_entries){
    Neuron neuron;
    neuron.weight_list = (Chained_List)malloc(sizeof(Chained_List));
    neuron.weight_list = weight_list;
    neuron.bias = bias;
    return neuron;
}

/**
 * @brief A procedure allowing to see the content of a neuron
 * 
 * @param neuron 
 */
void SeeNeur(Neuron neuron){
    printf("Neuron : \n");
    printf("Bias : %d\n",neuron.bias);
    printf("Weight list : ");
    while (neuron.weight_list != NULL){
        printf("%d ",neuron.weight_list->value);
        neuron.weight_list = neuron.weight_list->next;
    }
    printf("\n");
}

int OutNeur(Neuron neuron, int *ei){
    int x;
    int size = sizeof(ei)/sizeof(ei[0]);
    for (int i = 0; i < size; i++){
        x += ei[i] * neuron.weight_list->value;
        neuron.weight_list = neuron.weight_list->next;
    }
    if (x >= neuron.bias){
        return 1;
    }
    else {
        return 0;
    }
}

Layer InitCouche(int nb_neurons, int nb_entries){

}

Chained_List OutCouche(Layer layer, int *ei){
    
}

Neural_Network CreerResNeur(){
    
}