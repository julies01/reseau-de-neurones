#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "neuron.h"
#include "debug.h"
#include "user.h"
#include "main.h"
#include <ctype.h>

int CHOSEN_PROGRAM;

/**
 * @brief A function to free the memory allocated during the usage of the program
 * 
 * @param neural_network a neural network
 * @param entries_list an entry list
 * @param result_list a result list
 * @param layers_infos a layers parameters list
 */
void Free(Neural_Network neural_network, Entry_List entries_list, Entry_List result_list, Layer_Parameters *layers_infos){
    Free_Neural_Network(neural_network);
    Free_Entries_List(entries_list);
    Free_Entries_List(result_list);
    Free_Layers_Parameters(layers_infos);
}

/**
 * @brief A function to use the neural network again but asking for different entries
 * 
 * @param neural_network a neural network
 * @param layers_infos layers parameters
 */
void Try_Again(Neural_Network neural_network, Layer_Parameters *layers_infos){
    Entry_List entries_list = Ask_Entries_List(layers_infos[0].nb_entries);
    Entry_List result_list = Forward_Propagation(neural_network, entries_list);
    See_N_N(neural_network);
    int final_result = Get_Final_Output(result_list);
    printf("\n\nThe final result is : %d\n\n", final_result);
    Free(neural_network, entries_list, result_list, layers_infos);
    Return(neural_network, layers_infos);
}
/**
 * @brief A function to create an AND neural network
 * 
 */
void And_N_N(){
    CHOSEN_PROGRAM = 2;
    int nb_layers = 1;
    Layer_Parameters *layers_infos = (Layer_Parameters *)malloc(nb_layers*sizeof(Layer_Parameters));
    layers_infos[0].nb_neurons = 1;
    layers_infos[0].nb_entries = Ask_Nb_Entries();
    Neural_Network and_n_n = Creer_Res_Neur(nb_layers, layers_infos);    
    Entry_List entries_list = Ask_Entries_List(layers_infos[0].nb_entries);
    Entry_List result_list = Forward_Propagation(and_n_n, entries_list);
    See_N_N(and_n_n);
    int final_result = Get_Final_Output(result_list);
    printf("\n\nThe final result is : %d\n\n", final_result);
    Return(and_n_n, layers_infos);
    Free(and_n_n, entries_list, result_list, layers_infos);
}

/**
 * @brief A function to create an OR neural network
 * 
 */
void Or_N_N(){
    CHOSEN_PROGRAM = 3;
    int nb_layers = 1;
    Layer_Parameters *layers_infos = (Layer_Parameters *)malloc(nb_layers*sizeof(Layer_Parameters));
    layers_infos[0].nb_neurons = 1;
    layers_infos[0].nb_entries = Ask_Nb_Entries();
    Neural_Network or_n_n = Creer_Res_Neur(nb_layers, layers_infos);
    Entry_List entries_list = Ask_Entries_List(layers_infos[0].nb_entries);
    Entry_List result_list = Forward_Propagation(or_n_n, entries_list);
    See_N_N(or_n_n);
    int final_result = Get_Final_Output(result_list);
    printf("\n\nThe final result is : %d\n\n", final_result);
    Return(or_n_n, layers_infos);
    Free(or_n_n, entries_list, result_list, layers_infos);
}
 
 /**
  * @brief A function to create a NOT neural network
  * 
  */
void Not_N_N(){
    CHOSEN_PROGRAM = 4;
    int nb_layers = 1;
    Layer_Parameters *layers_infos = (Layer_Parameters *)malloc(nb_layers*sizeof(Layer_Parameters));
    layers_infos[0].nb_neurons = 1;
    layers_infos[0].nb_entries = 1;
    Neural_Network not_n_n = Creer_Res_Neur(nb_layers, layers_infos);
    Entry_List entries_list = Ask_Entries_List(layers_infos[0].nb_entries);
    Entry_List result_list = Forward_Propagation(not_n_n, entries_list);
    See_N_N(not_n_n);
    int final_result = Get_Final_Output(result_list);
    printf("\n\nThe final result is : %d\n\n", final_result);
    Return(not_n_n, layers_infos);
    Free(not_n_n, entries_list, result_list, layers_infos);
}

/**
 * @brief A function to create a neural network with multiple layers
 * 
 */
void Multiple_Layers_N_N(){
    CHOSEN_PROGRAM = 5;
    int nb_layers = 3;
    Layer_Parameters *layers_infos = (Layer_Parameters *)malloc(nb_layers*sizeof(Layer_Parameters));
    layers_infos[0].nb_neurons = 4;
    layers_infos[0].nb_entries = 3;
    

    layers_infos[1].nb_neurons = 2;
    layers_infos[1].nb_entries = 4;

    layers_infos[2].nb_neurons = 1;
    layers_infos[2].nb_entries = 2;
    Neural_Network multiple_layers_n_n = Creer_Res_Neur(nb_layers, layers_infos);
    Entry_List entries_list = Ask_Entries_List(3);

    See_N_N(multiple_layers_n_n);
    Entry_List result_list = Forward_Propagation(multiple_layers_n_n, entries_list);
    int final_result = Get_Final_Output(result_list);
    printf("\n\nThe final result is : %d\n\n", final_result);
    Return(multiple_layers_n_n, layers_infos);
    Free(multiple_layers_n_n, entries_list, result_list, layers_infos);
}
    
/**
 * @brief A function to create a new neural network
 * 
 */
void Create_N_N(){

    int nb_layers = Ask_Nb_Layers();
    Layer_Parameters * layers_infos = (Layer_Parameters *)malloc(nb_layers*sizeof(Layer_Parameters));
    layers_infos = Ask_Layers_Parameters(nb_layers);
    Neural_Network neural_network = Creer_Res_Neur(nb_layers, layers_infos);
    int nb_initial_entries = layers_infos[0].nb_entries;
    Entry_List entries_list = Ask_Entries_List(nb_initial_entries);
    See_N_N(neural_network);
    Entry_List result_list = Forward_Propagation(neural_network, entries_list);
    int final_result = Get_Final_Output(result_list);
    printf("\n\nThe final result is : %d\n\n", final_result);
    Return(neural_network, layers_infos);
    Free(neural_network, entries_list, result_list, layers_infos);
}



/**
 * @brief A function to redirect the user to the chosen program
 * @param input the number of the chosen program
 * 
 */
void Redirection(int input){
    switch (input) {
        case 1:
            printf("\nGreat, you chose to create a new neural network.\n\n");
            Create_N_N();
            break;

        case 2:
            printf("\nGreat, you chose to test the \e[1;48;2;118;201;214mAND\e[0m\e[1m neural network.\e[0m\n\n");
            And_N_N();
            break;

        case 3:
            printf("\nGreat, you chose to test the \e[1;48;2;118;201;214mOR\e[0m\e[1m neural network.\e[0m\n\n");
            Or_N_N();
            break;

        case 4:
            printf("\nGreat, you chose to test the \e[1;48;2;118;201;214mNOT\e[0m\e[1m neural network.\e[0m\n\n");
            Not_N_N();
            break;

        case 5:
            printf("\nGreat, you chose to test the \e[1;48;2;118;201;214m(A AND (NOT B) AND C) OR (A AND (NOT C))\e[0m\e[1m neural network.\e[0m\n\n");
            Multiple_Layers_N_N();
            break;
        case 0:
            printf("\n  \e[3mThank you for using \e[3;48;2;206;175;240mmy neural network maker program\e[0m\e[3m !\n\n See you soon !\e[0m\n\n");
            break;
    }
}


int main() {
    printf("\n\n \e[1m Hello, and welcome to my neural network maker program ! \e[0m\n\n");
    Menu();
    return 0;
}

