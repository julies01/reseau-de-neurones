#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#include "neuron.h"
#include "debug.h"

extern int CHOSEN_PROGRAM;

/**
 * @brief A function to control the input of the user to make sure it is valid
 * 
 * @param input the input of the user, a number
 * @param valid_input_list the list of valid inputs
 * @param size the size of the list of valid inputs
 * @return int 
 */
int Input_Control(int input,int valid_input_list[],int size){
        for(int i = 0; i < size; i++) {
            if (input == valid_input_list[i]) {
                return 1;
            }
        }
        return -1;
}

/**
 * @brief A function to ask the user what he wants to do
 * 
 */
void Menu(){
    printf("Here's all \e[1mthe options\e[0m you can choose from:\n\n");
    printf("\e[3mCreate your own neural network ...\n\n\e[0m");
    printf("    \e[47m1.\e[0m Create a new neural network\n\n");
    printf("\e[3mOr test a pre-made one ...\n\n\e[0m");
    printf("    \e[46m2.\e[0m AND neural network\n");
    printf("    \e[45m3.\e[0m OR neural network\n");
    printf("    \e[44m4.\e[0m NOT neural network\n");
    printf("    \e[42m5.\e[0m (A AND (NOT B) AND C) OR (A AND (NOT C)) neural network\n\n\n");
    printf("\e[41m0.\e[0m \e[1mExit\e[0m\n\n");
    printf("-> Please \e[1menter\e[0m the number corresponding to the option you want to choose : ");
    
    char input[10];
    int valid_input_list[7] = {0,1,2,3,4,5,6};
    scanf("%9s", input);
    while (strlen(input) != 1 || !isdigit(input[0]) || Input_Control(input[0] - '0', valid_input_list, 7) == -1) {
        printf("-> Please enter \e[31ma valid number\e[0m for the option : ");
        scanf("%9s", input);
    }
    Redirection(input[0] - '0');
 }

 /**
 * @brief A procedure to free the memory allocated for the layers parameters
 * 
 * @param layers the list of layers parameters
 */
void Free_Layers_Parameters(Layer_Parameters *layers) {
    free(layers);
}

/**
 * @brief A function to ask the user what he wants to do after the neural network has been created
 * 
 * @param neural_network    a neural network
 * @param layers_infos  the parameters of the layers
 */
void Return(Neural_Network neural_network, Layer_Parameters *layers_infos){ 
    printf("\nWould you like to:\n\n");
    printf("    M - Return to Menu\n");
    printf("    T - Try with other entries\n");
    printf("    Q - Quit\n");
    printf("\n-> Please enter your choice : ");
    
    char input[10];
    scanf("%9s", input);
    while (strlen(input) != 1 || (toupper(input[0]) != 'M' && toupper(input[0]) != 'T' && toupper(input[0]) != 'Q')) {
        printf("-> Please enter a valid choice (M, T, or Q): ");
        scanf("%9s", input);
    }

    switch(toupper(input[0])) {
        case 'M':
            Free_Layers_Parameters(layers_infos);
            Free_Neural_Network(neural_network);
            Menu();
            break;
        case 'T':
            Try_Again(neural_network, layers_infos);
            return;
        case 'Q':
            Free_Layers_Parameters(layers_infos);
            Free_Neural_Network(neural_network);
            Redirection(0);
    }
}

/**
 * @brief A function to ask the user the number of layers that the neural network will have
 * 
 * @return int the number of layers
 */
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
 * @brief A function to ask the user the parameters of the layers of the neural network
 * 
 * @param nb_layers the number of layers of the neural network
 * @return Layer_Parameters* 
 */
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
        layers_info[i].nb_neurons = nb_neurons; //store the number of neurons in the layer

        int nb_entries;
        printf("-> Please choose \e[1mthe number of entries\e[0m that your neuron or neurons will receive : ");
        char input_2[10];
        scanf("%9s", input_2);

        while (strlen(input_2) != 1 || !isdigit(input_2[0]) || (input_2[0]-'0') <= 0) {
            printf("-> Please enter \e[31ma valid number\e[0m for the number of entries : ");
            scanf("%9s", input_2);
        }
        nb_entries = input_2[0] - '0';
        layers_info[i].nb_entries = nb_entries; //store the number of entries in the layer
    }
    return layers_info;
}

/**
 * @brief A function to ask the user the bias of a neuron
 * 
 * @param neuron the number of the neuron
 * @return int the bias of the neuron
 */
int Ask_Bias(int nb_neuron){
    int bias;
    printf("\n-> Please write \e[1mthe bias\e[0m of the n°%d neuron : \n",nb_neuron);
    char input[10];
    scanf("%9s", input);
    while (strlen(input) != 1 || !isdigit(input[0])) {    //check if the input is a number 
        printf("\n-> Please enter \e[31ma number\e[0m for the bias of the neuron : ");
        scanf("%9s", input);
    }
    bias = input[0] - '0';//convert the input into an integer
    return bias;
}


/**
 * @brief A Function to ask the user the weight list of a neuron
 * @param nb_entries the number of entries that the neuron will receive
 * @param neuron the number of the neuron
 * @param nb_layer the number of the layer
 * @return int* 
 */
int *Ask_Weight_List(int nb_entries,int nb_neuron,int nb_layer){
    int *weight_list = (int *)malloc(nb_entries*sizeof(int));
    printf("\n\e[3mCreating the weight list ...\e[0m\n");

    for (int i = 0; i < nb_entries; i++){
        if (CHOSEN_PROGRAM == 1){
            int value;
            printf("\n-> Please enter \e[1mthe weight\e[0m of the entry number %d for the neuron n°%d: ", i+1,nb_neuron);
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
        if (CHOSEN_PROGRAM == 5){
            weight_list[i] = Weights_For_M_L(nb_layer, nb_neuron, i+1);
        }
    }
    return weight_list;
}

 
/**
 * @brief A function to ask the user the number of entries that the neuron or neurons will receive
 * 
 * @return int le nombre d'entrées
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

/**
 * @brief A function to ask the user the entries list
 * 
 * @param nb_entries the number of entries
 * @return Entry_List 
 */
Entry_List Ask_Entries_List(int nb_entries){
    Entry_List entries_list = NULL;
    for (int i = 0; i < nb_entries; i++){
        int value;
        printf("\n-> Please enter \e[1mthe value\e[0m of the entry number %d : ", i+1);
        char input[10];
        scanf("%9s", input);
        while (strlen(input) != 1 || !isdigit(input[0])) {
            printf("\n-> Please enter \e[31ma valid number\e[0m for the entry value :");
            scanf("%9s", input);
        }
        value = input[0] - '0';
        entries_list = E_Add_Elem_Tail(entries_list, value);
    }
    return entries_list;
}



/**
 * @brief A procedure to free the memory allocated for the weight list
 * 
 * @param list the entry list
 */
void Free_Entries_List(Entry_List list) {
    Entry_List current = list;
    Entry_List next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}