#ifndef NEURON_H
#define NEURON_H

//Layers Parameters
typedef struct {
    int nb_neurons;
    int nb_entries;
} Layer_Parameters;

//Weights
typedef struct Weight_Elem {

    int value;
    struct Weight_Elem *next;

} Weight_Elem;

typedef struct Weight_Elem * Weight_List;

//Neurons
typedef struct Neuron {

   Weight_List weight_list;
   int bias;
   struct Neuron *next;

} Neuron;

typedef struct Neuron *Neuron_List;

//Layers
typedef struct Layer {

    Neuron_List neurons;
    struct Layer *next;

} Layer;

typedef struct Layer *Layer_List;

//Neural Network
typedef struct Neural_Network {

    Layer *Input_layer;
    Layer *Output_layer;

} Neural_Network;

//Entries
typedef struct Entry_Elem {

    int value;
    struct Entry_Elem *next;
    struct Entry_Elem *prev;

}  Entry_Elem ;

typedef struct Entry_Elem * Entry_List;


/**
 * @brief A function to add an entry at the end of an entry list
 * 
 * @param list the entry list
 * @param value the value attribute of the new element we want to add
 * @return Entry_List 
 */
Entry_List E_Add_Elem_Tail(Entry_List list, int value);

/**
 * @brief A function to add a weight at the end of a weight list
 * 
 * @param list the weight list
 * @param value the value attribute of the new element we want to add
 * @return Weight_List 
 */
Weight_List W_Add_Elem_Tail(Weight_List list, int value);

/**
 * @brief A function to add a neurone at the end of a neuron list
 * 
 * @param list the neuron list
 * @param neuron the neuron we want to add
 * @return Neuron_List 
 */
Neuron_List N_Add_Elem_Tail(Neuron_List list, Neuron neuron);

/**
 * @brief A function to add a layer at the end of a layer list
 * 
 * @param list the layer list
 * @param layer the layer we want to add
 * @return Layer_List 
 */
Layer_List L_Add_Elem_Tail(Layer_List list, Layer layer);

/**
 * @brief A function allowing to create a neuron
 * 
 * @param weight_list the list of weights for the neuron
 * @param bias the bias of the neuron
 * @param nb_entries the number of entries for the neuron
 * @return Neuron 
 */
Neuron Init_Neur(int *weight_list, int bias, int nb_entries);

/**
 * @brief A function allowing to get the output of a neuron
 * 
 * @param neuron a Neuron
 * @param ei the list of entries
 * @return int 
 */
int Out_Neur(Neuron neuron, Entry_List ei);

/**
 * @brief A function to get the weights of a neuron for the 5th program
 * 
 * @param layer the number of the layer
 * @return int* 
 */
int Weights_For_M_L(int layer, int n_neuron, int n_entries);

/**
 * @brief A function to get the bias of a neuron for the 5th program
 * 
 * @param layer the number of the layer
 * @param neuron the number of the neuron
 * @return int 
 */
int Bias_For_M_L(int layer, int neuron);

/**
 * @brief Une fonction permettant de créer une couche de neurones
 * 
 * @param nb_neurons le nombre de neurones dans la couche
 * @param nb_entries le nombre d'entrées pour le ou les neurones
 * @param nb_couche le numéro de la couche
 * @return Layer 
 */
Layer Init_Couche(int nb_neurons, int nb_entries,int nb_couche);

/**
 * @brief A function to get the entries list that is the output of a layer
 * 
 * @param layer A layer of the neural network
 * @param ei An entry list
 * @return Linked_List 
 */
Entry_List Out_Couche(Layer layer, Entry_List ei);

/**
 * @brief A function to create a neural network
 * 
 * @param nb_layers the number of layers of the neural network
 * @param layers_infos the list of the parameters of the layers
 * @return Neural_Network 
 */
Neural_Network Creer_Res_Neur(int nb_layers, Layer_Parameters *layers_infos);

/**
 * @brief A procedure that implements the forward propagation on a neural network
 * 
 * @param neural_network a neural network
 * @param ei a list of entries
 */

Entry_List Forward_Propagation(Neural_Network neural_network, Entry_List ei);

/**
 * @brief A function that allow to see the final output of the neural network
 * 
 * @param result the list of the result of the output layer
 * @return int 
 */
int Get_Final_Output(Entry_List result_list);

/**
 * @brief A function to free the memory allocated for the weight list
 * 
 * @param weight_list a list of weights
 */
void Free_Weight_List(Weight_List weight_list);

/**
 * @brief A procedure to free the memory allocated for a layer
 * 
 * @param layer a layer
 */
void  Free_Layer(Layer layer);

/**
 * @brief A procredure to free the memory allocated for the neural network
 * 
 * @param neural_network a neural network
 */
void Free_Neural_Network(Neural_Network neural_network);

#endif