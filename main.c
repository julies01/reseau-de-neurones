#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "neuron.h"
#include "debug.h"
#include "user.h"
#include <ctype.h>

int CHOSEN_PROGRAM;

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
}

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
}
 
void not_n_n(){
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
}

void multiple_layers_n_n(){
    CHOSEN_PROGRAM = 5;
    int nb_layers = 3;
    Layer_Parameters *layers_infos = (Layer_Parameters *)malloc(nb_layers*sizeof(Layer_Parameters));
    layers_infos[0].nb_neurons = 4;
    layers_infos[0].nb_entries = 3;
    

    layers_infos[1].nb_neurons = 2;
    layers_infos[1].nb_entries = 4;

    layers_infos[2].nb_neurons = 1;
    layers_infos[2].nb_entries = 2;
    print("here");  
    Neural_Network multiple_layers_n_n = Creer_Res_Neur(nb_layers, layers_infos);
    Entry_List entries_list = Ask_Entries_List(3);

    See_N_N(multiple_layers_n_n);
    Entry_List result_list = Forward_Propagation(multiple_layers_n_n, entries_list);
    int final_result = Get_Final_Output(result_list);
    printf("\n\nThe final result is : %d\n\n", final_result);
}
    

void create_n_n(){

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
    free(layers_infos);
}


void Redirection(int input){
    switch (input) {
        case 1:
            printf("\nGreat, you chose to create a new neural network.\n");
            create_n_n();
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
            not_n_n();
            break;

        case 5:
            printf("\nGreat, you chose to test the \e[1;48;2;118;201;214m(A AND (NOT B) AND C) OR (A AND (NOT C))\e[0m\e[1m neural network.\e[0m\n\n");
            multiple_layers_n_n();
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

