#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "neuron.h"
#include "debug.h"

extern int CHOSEN_PROGRAM;

int Ask_Bias(int neuron){
    int bias;
    printf("\n-> Please write \e[1mthe bias\e[0m of the n°%d neuron : \n",neuron);
    char input[10];
    scanf("%9s", input);

    //check if the input is a number 
    while (strlen(input) != 1 || !isdigit(input[0])) {
        printf("\n-> Please enter \e[31ma number\e[0m for the bias of the neuron : ");
        scanf("%9s", input);
    }
    bias = input[0] - '0';
    return bias;
}

Layer_Parameters *Ask_Layers_Parameters(int nb_layers){
    Layer_Parameters *layers_info = (Layer_Parameters *)malloc(nb_layers*sizeof(Layer_Parameters));
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

        int nb_entries;
        printf("-> Please choose \e[1mthe number of entries\e[0m that your neuron or neurons will receive : ");
        char input_2[10];
        scanf("%9s", input_2);

        while (strlen(input_2) != 1 || !isdigit(input_2[0]) || (input_2[0]-'0') <= 0) {
            printf("-> Please enter \e[31ma valid number\e[0m for the number of entries : ");
            scanf("%9s", input_2);
        }
        nb_entries = input_2[0] - '0';
        layers_info[i].nb_entries = nb_entries;
    }
    return layers_info;
    free(layers_info);
}

int *Ask_Weight_List(int nb_entries,int neuron){

    int *weight_list = (int *)malloc(nb_entries*sizeof(int));
    printf("\n\e[3mCreating the weight list ...\e[0m\n");

    for (int i = 0; i < nb_entries; i++){
        if (CHOSEN_PROGRAM == 1){
            int value;
            printf("\n-> Please enter \e[1mthe weight\e[0m of the entry number %d for the neuron n°%d: ", i+1,neuron);
            char input[10];
            scanf("%9s", input);

            while (!(isdigit(input[0]) || (input[0] == '-' && strlen(input) > 1 && isdigit(input[1])))) {
                printf("-> Please enter \e[31ma valid number\e[0m for the weight value : ");
                scanf("%9s", input);
            }
            if (input[0] == '-') {
                value = -(input[1] - '0');
            } else {
                value = input[0] - '0';
            }
            weight_list[i] = value;
        }
        if (CHOSEN_PROGRAM == 2 || CHOSEN_PROGRAM == 3){
            weight_list[i] = 1;
        }
        if (CHOSEN_PROGRAM == 4){
            weight_list[i] = -1;
        }
    }
    return weight_list;
}

int Ask_Nb_Layers(){
    int nb_layers;
    printf("-> Please choose \e[1mthe number of layers\e[0m that your neural network  will have : ");
    char input[10];
    scanf("%9s", input);

    //check if the input is a number superior to 0
    while (strlen(input) != 1 || !isdigit(input[0]) || (input[0]-'0') <= 0) {
        printf("-> Please enter \e[31ma valid number\e[0m for the number of layers : ");
        scanf("%9s", input);
    }
    nb_layers = input[0] - '0';
    return nb_layers;
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
    printf("number of entries : %d\n", nb_entries);
    return nb_entries;
}

Entry_List Ask_Entries_List(int nb_entries){
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
