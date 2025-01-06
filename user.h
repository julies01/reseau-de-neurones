#ifndef USER_H
#define USER_H

#include "neuron.h"

int Ask_Bias(int neuron);
int Ask_Nb_Layers();
Layer_Parameters *Ask_Layers_Parameters(int nb_layers);
int *Ask_Weight_List(int nb_entries,int neuron);
int Ask_Nb_Entries();
Entry_List Ask_Entries_List(int nb_entries);


#endif