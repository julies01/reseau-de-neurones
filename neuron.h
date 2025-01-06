#ifndef NEURON_H
#define NEURON_H

typedef struct {
    int nb_neurons;
    int nb_entries;
} Layer_Parameters;

typedef struct Weight_Elem {

    int value;
    struct Weight_Elem *next;

} Weight_Elem;

typedef struct Weight_Elem * Weight_List;

typedef struct Entry_Elem {

    int value;
    struct Entry_Elem *next;
    struct Entry_Elem *prev;

}  Entry_Elem ;

typedef struct Entry_Elem * Entry_List;

typedef struct Neuron {

   Weight_List weight_list;
   int bias;
   struct Neuron *next;

} Neuron;

typedef struct Neuron *Neuron_List;

typedef struct Layer {

    Neuron_List neurons;
    struct Layer *next;

} Layer;

typedef struct Layer *Layer_List;

typedef struct Neural_Network {

    Layer *Input_layer;
    Layer *Output_layer;

} Neural_Network;

Entry_List E_Add_Elem_Tail(Entry_List list, int value);


/**
 * @brief 
 * 
 * @param nb_layers 
 * @param nb_neurons_list 
 * @return Neural_Network 
 */
Neural_Network Creer_Res_Neur(int nb_layers, Layer_Parameters *layers_infos);


/**
 * @brief 
 * 
 * @param neural_network 
 * @param ei 
 * @return Linked_List 
 */
Entry_List Forward_Propagation(Neural_Network neural_network, Entry_List ei);

/**
 * @brief 
 * 
 * @param result_list 
 * @return int 
 */
int Get_Final_Output(Entry_List result_list);

Neuron Init_Neur(int *weight_list, int bias, int nb_entries);

Weight_List W_Add_Elem_Tail(Weight_List list, int value);

Neuron_List N_Add_Elem_Tail(Neuron_List list, Neuron neuron);

Layer_List L_Add_Elem_Tail(Layer_List list, Layer layer);

int Out_Neur(Neuron neuron, Entry_List ei);

#endif