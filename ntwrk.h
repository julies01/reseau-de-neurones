#ifndef NTWRK_H
#define NTWRK_H

#include "neuron.h"
#include "debug.h"
#include "user.h"

typedef struct {
    int nb_neurons;
    int* nb_entries;
} N_Layer_Parameters;

N_Layer_Parameters *N_Ask_Layers_Parameters(int nb_layers);

Neural_Network N_Creer_Res_Neur(int nb_layers, N_Layer_Parameters *layers_infos);

Entry_List N_Forward_Propagation(Neural_Network neural_network, Entry_List ei);

#endif