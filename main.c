#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "neuron.h"
#include "debug.h"
#include <ctype.h>

//ajouter une option pour revenir au menu principal

int Input_Control(int input,int valid_input_list[],int size){
        for(int i = 0; i < size; i++) {
            if (input == valid_input_list[i]) {
                return 1;
            }
        }
        return -1;
}

void And_N_N(){
    int nb_layers = 1;
    int nb_neurons_list[1] = {1};
    Neural_Network and_n_n = Creer_Res_Neur(nb_layers, nb_neurons_list);
    Entry_List result_list = Forward_Propagation(and_n_n, Create_Entries_List(2));
    int final_result = Get_Final_Output(result_list);
    printf("\n\nThe final result is : %d\n\n", final_result);
}

void Or_N_N(){
    /*int nb_entries = Ask_Nb_Entries();
    int *weight_list = Create_Weigth_List(nb_entries, 1);*/
}
 
void not_n_n(){
    /*int nb_entries = Ask_Nb_Entries();
    int *weight_list = Create_Weigth_List(nb_entries, -1);*/

}

void multiple_layers_n_n(){

}

void create_n_n(){
  
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
            /*int nb_layers = 1;
            int nb_neurons_list[1] = {1};
            Neural_Network or_n_n = Creer_Res_Neur(nb_layers, nb_neurons_list);*/
            break;

        case 4:
            printf("\nGreat, you chose to test the \e[1;48;2;118;201;214mNOT\e[0m\e[1m neural network.\e[0m\n\n");
            /*int nb_layers = 1;
            int nb_neurons_list[1] = {1};
            Neural_Network not_n_n = Creer_Res_Neur(nb_layers, nb_neurons_list);*/
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

int main() {
    printf("\n\n \e[1m Hello, and welcome to my neural network maker program ! \e[0m\n\n");
    Menu();
    return 0;
}