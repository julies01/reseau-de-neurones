#include <stdio.h>
#include <stdlib.h>
#include "neuron.h"

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

/**
 * @brief A procedure allowing to see the content of a linked list
 * 
 * @param list 
 */
void See_Linked_List(Weight_List list){
    while (list != NULL){
        printf("%d ",*(int *)(list->value));
        list = list->next;
    }
    printf("\n");
}
