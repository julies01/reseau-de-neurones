#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "neuron.h"
#include <ctype.h>

//ajouter une option pour revenir au menu principal

int input_control(int input,int valid_input_list[],int size){
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
int ask_nb_entries(){
    int nb_entries;
    printf("Please choose \e[1mthe number of entries\e[0m that your neuron or neurons will receive :");
    char input[10];
    scanf("%9s", input);

    //check if the input is a number superior to 0
    while (strlen(input) != 1 || !isdigit(input[0] || input[0]-'0' > 0)) {
        printf("Please enter \e[31ma valid number\e[0m for the number of entries : ");
        scanf("%9s", input);
    }
    nb_entries = input[0] - '0';
    return nb_entries;
}

void and_n_n(){
    int nb_entries = ask_nb_entries();
    Neuron neuron1 = InitNeur(NULL, nb_entries, nb_entries);
    SeeNeur(neuron1);
}

void or_n_n(){

}
 
void not_n_n(){

}

void multiple_layers_n_n(){

}


void redirection(int input){
    switch (input) {
        case 1:
            printf("\nGreat, you chose to create a new neural network.\n");
            create_n_n();
            break;
        case 2:
            printf("\nGreat, you chose to test the \e[1;48;2;118;201;214mAND\e[0m\e[1m neural network.\e[0m\n\n");
            and_n_n();
            break;
        case 3:
            printf("\nGreat, you chose to test the \e[1;48;2;118;201;214mOR\e[0m\e[1m neural network.\e[0m\n\n");
            or_n_n();
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

void menu(){
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
    while (strlen(input) != 1 || !isdigit(input[0]) || input_control(input[0] - '0', valid_input_list, 7) == -1) {
        printf("-> Please enter \e[31ma valid number\e[0m for the option : ");
        scanf("%9s", input);
    }
    redirection(input[0] - '0');
 }

int main() {
    /*printf("\n\n \e[1m Hello, and welcome to my neural network maker program ! \e[0m\n\n");
    menu();*/

    return 0;
}