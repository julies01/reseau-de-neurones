#ifndef DEBUG_H
#define DEBUG_H

#include "neuron.h"

/**
 * @brief A procedure allowing to see the content of a neuron
 * 
 * @param neuron A neuron
 */
void See_Neur(Neuron *neuron, int i);

/**
 * @brief A procedure allowing to see the content of a weight list
 * 
 * @param list the list of entries
 */
void See_Entry_List(Entry_List list);

/**
 * @brief A procedure allowing to see the content of a layer
 * 
 * @param layer A layer
 * @param i The number of the layer
 */
void See_Layer(Layer *layer, int i);

/**
 * @brief A procedure allowing to see the content of a neural network
 * 
 * @param neural_network A neural network
 */
void See_N_N(Neural_Network neural_network);

#endif

