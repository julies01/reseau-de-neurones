#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "neuron.h"
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

DLinked_List DL_Add_Elem_Tail(DLinked_List list, int value){
    DLinked_List new_elem = (DLinked_List)malloc(sizeof(DLinked_Elem));
    new_elem->value = value;
    new_elem->next = NULL;

    if (list == NULL){
        new_elem->prev = NULL;
        return new_elem;
    }
    else {
        DLinked_List temp = list;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_elem;
        new_elem->prev = temp;
        return list;
    }
}

DLinked_List Create_Entries_List(int nb_entries){
    DLinked_List entries_list = NULL;
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
        entries_list = DL_Add_Elem_Tail(entries_list, value);
    }
    return entries_list;
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
int *Create_Weigth_List(int nb_entries, int value){
    int *weight_list = (int *)malloc(nb_entries*sizeof(int));
    for (int i = 0; i < nb_entries; i++){
        weight_list[i] = value;
    }
    return weight_list;
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
            int nb_layers = 1;
            int nb_neurons_list[1] = {1};
            Neural_Network and_n_n = CreerResNeur(nb_layers, nb_neurons_list);
            break;

        case 3:
            printf("\nGreat, you chose to test the \e[1;48;2;118;201;214mOR\e[0m\e[1m neural network.\e[0m\n\n");
            int nb_layers = 1;
            int nb_neurons_list[1] = {1};
            Neural_Network or_n_n = CreerResNeur(nb_layers, nb_neurons_list);
            break;

        case 4:
            printf("\nGreat, you chose to test the \e[1;48;2;118;201;214mNOT\e[0m\e[1m neural network.\e[0m\n\n");
            int nb_layers = 1;
            int nb_neurons_list[1] = {1};
            Neural_Network not_n_n = CreerResNeur(nb_layers, nb_neurons_list);
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