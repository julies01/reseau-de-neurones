#ifndef USER_H
#define USER_H
#include "neuron.h"

/**
 * @brief A function to control the input of the user to make sure it is valid
 * 
 * @param input the input of the user, a number
 * @param valid_input_list the list of valid inputs
 * @param size the size of the list of valid inputs
 * @return int 
 */
int Input_Control(int input,int valid_input_list[],int size);

/**
 * @brief A function to ask the user what he wants to do
 * 
 */
void Menu();


/**
 * @brief A function to ask the user the number of layers that the neural network will have
 * 
 * @return int the number of layers
 */
int Ask_Nb_Layers();

/**
 * @brief A function to ask the user the parameters of the layers of the neural network
 * 
 * @param nb_layers the number of layers of the neural network
 * @return Layer_Parameters* 
 */
Layer_Parameters *Ask_Layers_Parameters(int nb_layers);

/**
 * @brief A function to ask the user the bias of a neuron
 * 
 * @param neuron the number of the neuron
 * @return int the bias of the neuron
 */
int Ask_Bias(int nb_neuron);

/**
 * @brief A Function to ask the user the weight list of a neuron
 * @param nb_entries the number of entries that the neuron will receive
 * @param neuron the number of the neuron
 * @param nb_layer the number of the layer
 * @return int* 
 */
int *Ask_Weight_List(int nb_entries,int nb_neuron, int nb_layer);

/**
 * @brief A function to ask the user the number of entries that the neuron or neurons will receive
 * 
 * @return int le nombre d'entrées
 */
int Ask_Nb_Entries();

/**
 * @brief A function to ask the user the entries list
 * 
 * @param nb_entries the number of entries
 * @return Entry_List 
 */
Entry_List Ask_Entries_List(int nb_entries);

/**
 * @brief A procedure to free the memory allocated for the layers parameters
 * 
 * @param layers the list of layers parameters
 */
void Free_Layers_Parameters(Layer_Parameters *layers);

/**
 * @brief A procedure to free the memory allocated for the weight list
 * 
 * @param list the entry list
 */
void Free_Entries_List(Entry_List list);

/**
 * @brief A function to ask the user what he wants to do after the neural network has been created
 * 
 * @param neural_network    a neural network
 * @param layers_infos  the parameters of the layers
 */
void Return(Neural_Network neural_network, Layer_Parameters *layers_infos);

#endif