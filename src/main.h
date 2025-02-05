#ifndef MAIN_H
#define MAIN_H

#include "neuron.h"


/**
 * @brief A function to use the neural network again but asking for different entries
 * 
 * @param neural_network a neural network
 * @param layers_infos layers parameters
 */
void Try_Again(Neural_Network neural_network, Layer_Parameters *layers_infos);

/**
 * @brief A function to create an AND neural network
 * 
 */
void And_N_N();

/**
 * @brief A function to create an OR neural network
 * 
 */
void Or_N_N();

/**
  * @brief A function to create a NOT neural network
  * 
  */
void Not_N_N();

/**
 * @brief A function to create a neural network with multiple layers
 * 
 */
void Multiple_Layers_N_N();

/**
 * @brief A function to create a new neural network
 * 
 */
void Create_N_N();

/**
 * @brief A function to redirect the user to the chosen program
 * @param input the number of the chosen program
 * 
 */
void Redirection(int input);



#endif