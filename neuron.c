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
Neuron InitNeur(int *weight_list,int bias, int nb_entries){
    Neuron neuron;
    neuron.weight_list = (Chained_List)malloc(nb_entries*sizeof(Chained_Elem));
    for (int i = 0; i < nb_entries; i++){
        neuron.weight_list = AddElemTail(neuron.weight_list, weight_list[i]);
    }
    neuron.bias = bias;
    return neuron;
}

Chained_List AddElemTail(Chained_List list, int value){
    Chained_List new_elem = (Chained_List)malloc(sizeof(Chained_Elem));
    new_elem->value = value;
    new_elem->next = NULL;

    if (list == NULL){
        return new_elem;
    }
    else {
        Chained_List temp = list;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_elem;
        return list;
    }
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