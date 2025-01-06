
# Algorithmes des sous-programmes du projet Réseaux de Neurones

## Table des matières

[Partie 1 : Neurone Artificiel](#partie-1--neurone-artificiel) </br>
[Partie 2 : Couche de Neurones](#partie-2--couche-de-neurones) </br>
[Partie 3 : Construction d'un réseau de neurones artificiel](#partie-3--construction-dun-réseau-de-neurones-artificiel) </br>
[Partie 4 : Principe de fonctionnement simplifié d'un réseau de neurones](#partie-4--principe-de-fonctionnement-simplifié-dun-réseau-de-neurones)


## Partie 1 : Neurone Artificiel

### InitNeur

**Lexique**</br> 
neurone <Neurone> : représente un neurone contenant une liste de poids et un biais. </br>
poids_liste <Liste d'entiers> : représente la liste initiale des poids à associer au neurone. </br>
biais <Entier> : représente la valeur du biais associée au neurone. </br>
nb_entrees <Entier> : indique le nombre d'éléments dans la liste des poids. </br>
temp_liste_poids <Liste de poids> : une liste chaînée utilisée pour ajouter successivement les poids au neurone. </br>
W_Add_Elem_Tail <Fonction> : fonction qui ajoute un élément à la fin d'une liste chaînée de poids. </br>


**Algorithmique** </br>
*Données :* </br>
poids_liste : Liste <Entiers> représentant les poids
biais : <Entier> un entier représentant le biais.
nb_entrees : <Entier> un entier représentant le nombre d'entrées.

*Résultat :* </br>
neurone : <Neurone>

````
Fonction InitNeur(poids_liste : Liste <Entiers>, biais : <Entier>, nb_entrees : <Entier>): neurone : <Neurone>
    Début
        
        neuron ← créer_un_objet_de_type_Neuron()
        liste_poids(neuron) ← NULL
        
       
        Pour i allant de 0 à nb_entrees - 1 faire
            liste_poids(neuron) ← W_Add_Elem_Tail(liste_poids(neuron), poids_liste[i])
        Fin Pour
        
        biais(neuron) ← biais
        
        Libérer(poids_liste)

        Retourner neuron
    Fin


````

### OutNeurone

**Lexique**</br>
neurone <Neurone> : représente un neurone contenant une liste de poids et un biais. </br>
ei <Liste d'entrées (Entry_List)> :  Représente une liste chaînée contenant les valeurs des entrées au neurone. </br>
temp < Liste de poids (Weight_List)> : Variable temporaire utilisée pour parcourir la liste des poids associée au neurone. </br>
x <Entier> : compteur représentant la somme pondérée des poids et des entrées. </br>


**Algorithmique**</br>
*Données :* </br>
neurone <objet de type Neuron> </br>
ei <liste d'entrées>

*Résultat :* </br>
un entier (1 ou 0)

````
Fonction OutNeur(neurone : <Neurone>, ei <liste d'entrées>) : <Entier> (1 ou 0)
Début
        x ← 0
        temp ← liste_poids(neurone)
        
        Si temp = NULL Alors
            Afficher("Erreur : La liste des poids est vide")
            Quitter le programme
        Fin Si
        
        Si ei = NULL Alors
            Afficher("Erreur : La liste des entrées est vide")
            Quitter le programme
        Fin Si
        
        Tant que ei ≠ NULL et temp ≠ NULL Faire
            x ← x + (valeur(temp) * valeur(ei))
            ei ← suivant(ei)
            temp ← suivant(temp)
        Fin Tant que
        
        Si x ≥ biais(neurone) Alors
            Retourner 1
        Sinon
            Retourner 0
        Fin Si
    Fin
````

## Partie 2 : Couche de Neurones

### InitCouche

**Lexique**</br>
couche <Layer> : représente une couche contenant une liste chaînée de neurones. </br>
neurone <Neuron> : représente un neurone contenant une liste de poids et un biais. </br>
poids_liste <Liste d'entiers> : tableau temporaire utilisé pour stocker les poids d'un neurone avant son initialisation. </br>
biais <Entier> : valeur du biais associée à un neurone, déterminée par le programme choisi. </br>
N_Add_Elem_Tail <Fonction> : ajoute un neurone à la fin de la liste chaînée des neurones d'une couche. </br>
Ask_Bias <Fonction> : demande à l'utilisateur d'entrer la valeur du biais pour un neurone donné. </br>
Ask_Weight_List <Fonction> : demande à l'utilisateur d'entrer la liste des poids pour un neurone donné. </br>
Init_Neur <Fonction> : initialise un neurone avec une liste de poids, un biais et un nombre d'entrées. </br>
CHOSEN_PROGRAM <Constante> : détermine le programme en cours pour calculer la valeur du biais. </br>
j <Entier> : numéro de la couche en cours de création. </br>
nb_neurones <Entier> : nombre de neurones à inclure dans la couche. </br>
nb_entrees <Entier> : nombre d'entrées pour chaque neurone de la couche. </br

**Algorithmique**</br>
*Données : </br>*
nb_neurones <Entier> : nombre de neurones dans la couche. </br>
nb_entrees <Entier> : nombre d'entrées pour chaque neurone. </br>
j <Entier> : numéro de la couche en cours de création. </br>

*Résultat* : 
Une couche (objet de type Layer) contenant une liste de neurones initialisés. </br>

````
Fonction InitCouche(nb_neurones : <Entier>, nb_entrees : <Entier>, j : <Entier> ) : couche <Layer>
Début
    couche ← créer_Layer()
    liste_neurones(couche) ← NULL
    
    Afficher("\nCréation de la couche n°", j, "...")
    
    Pour i allant de 0 à nb_neurones - 1 Faire
        Si CHOSEN_PROGRAM = 1 Alors
            biais ← Ask_Bias(i + 1)
        Sinon Si CHOSEN_PROGRAM = 2 Alors
            biais ← nb_entrees
        Sinon Si CHOSEN_PROGRAM = 3 Alors
            biais ← 1
        Sinon Si CHOSEN_PROGRAM = 4 Alors
            biais ← 0
        Fin Si
        
        poids_liste ← Ask_Weight_List(nb_entrees, i + 1)
        neurone ← Init_Neur(poids_liste, biais, nb_entrees)
        liste_neurones(couche) ← N_Add_Elem_Tail(liste_neurones(couche), neurone)
    Fin Pour
    
    Retourner couche
Fin

````

### OutCouche


**Lexique**</br>
couche (<Layer>) : représente une couche contenant une liste chaînée de neurones. </br>
ei (<Liste d'entrées>) : une liste chaînée contenant les valeurs d'entrée pour chaque neurone de la couche. </br>
resultat (<Liste d'entrées>) : une liste chaînée contenant les sorties de chaque neurone après traitement des entrées. </br>
liste_neurones (<Liste de neurones>) : une liste chaînée contenant tous les neurones de la couche. </br>
sortie_neurone (<Entier>) : la sortie calculée pour un neurone donné à partir de ses entrées et de ses poids. </br>
Out_Neur (<Fonction>) : calcule la sortie d'un neurone en fonction de ses entrées et de son biais. </br>
E_Add_Elem_Tail (<Fonction>) : ajoute un élément à la fin d'une liste chaînée de sorties. </br>
suivant(liste_neurones) (<Fonction>) : retourne le prochain neurone dans la liste chaînée des neurones de la couche. </br>
neurone_courant(liste_neurones) (<Neuron>) : retourne le neurone courant de la liste chaînée en cours de traitement. </br>

**Algorithmique** </br>
*Données :*</br>
couche (<Layer>) : une couche contenant une liste de neurones. </br>
ei (<Liste d'entrées>) : une liste chaînée contenant les entrées pour chaque neurone de la couche. </br>

*Résultat :* </br>
resultat (<Liste d'entrées>) : une liste chaînée contenant les sorties de chaque neurone de la couche. </br>


````
Fonction OutCouche(couche : <Layer>, ei : <Liste d'entrées>) : resultat <Liste d'entrées>
Début
    resultat ← INDEFINI
    liste_neurones ← liste_neurones(couche)
    
    Si liste_neurones = INDEFINI Alors
        Afficher("Erreur : liste_neurones(couche) est vide")
        Retourner NULL
    Fin Si
    
    Tant que liste_neurones ≠ ALORS Faire
        sortie_neurone ← Out_Neur(neurone_courant(liste_neurones), ei)
        resultat ← E_Add_Elem_Tail(resultat, sortie_neurone)
        liste_neurones ← suivant(liste_neurones)
    Fin Tant que
    
    Retourner resultat
Fin
````


## Partie 3 : Construction d'un réseau de neurones artificiel

### CreeResNeur

**Lexique**</br>
reseau_neural (<Neural_Network>) : représente un réseau de neurones constitué de couches d'entrées, intemédiaires et de sorties. </br>
Input_layer (<Layer>) : la couche d'entrée du réseau neuronal, la première couche traitant les données d'entrée. </br>
Output_layer (<Layer>) : la couche de sortie du réseau neuronal, la dernière couche produisant les résultats. </br>
current (<Layer_List>) : un pointeur utilisé pour parcourir la liste des couches pendant la création du réseau. </br>
layer (<Layer>) : une couche contenant des neurones et représentant un ensemble d'opérations à effectuer sur les données. </br>
L_Add_Elem_Tail (<Fonction>) : ajoute une couche à la fin d'une liste chaînée de couches. </br>
InitCouche (<Fonction>) : initialise une couche de neurones avec les paramètres spécifiés. </br>
layers_infos (<Layer_Parameters>) : un tableau contenant les informations de chaque couche (nombre de neurones, nombre d'entrées) utilisées pour initialiser les couches. </br>
nb_layers (<Entier>) : nombre total de couches dans le réseau de neurones. </br>

**Algorithmique**</br>
*Données :* </br>
nb_layers (<Entier>) : nombre de couches à créer dans le réseau. </br>
layers_infos (<Tableau de Layer_Parameters>) : tableau contenant les informations de chaque couche à initialiser (nombre de neurones, nombre d'entrées). </br>

*Résultat : </br>*
reseau de neurones (<Neural_Network>) : un réseau de neurones avec une couche d'entrée et une couche de sortie initialisées. </br>

````
Fonction Creer_Res_Neur(nb_layers : <Entier>, layers_infos : <Tableau de Layer_Parameters> ) : reseau de neurones :<Neural_Network>
Début
    reseau_neural ← créer_Neural_Network()
    Input_layer(reseau_neural) ← NULL
    Output_layer(reseau_neural) ← NULL
    current ← NULL
    
    Pour i allant de 0 à nb_layers - 1 Faire
        couche ← InitCouche(layers_infos[i].nb_neurons, layers_infos[i].nb_entries, i + 1)
        
        Si Input_layer(reseau_neural) = NULL Alors
            // La première couche devient la couche d'entrée
            Input_layer(reseau_neural) ← L_Add_Elem_Tail(NULL, couche)
            current ← Input_layer(reseau_neural)
        Sinon
            // Ajouter les couches suivantes à la chaîne
            current->next ← L_Add_Elem_Tail(NULL, couche)
            current ← current->next
            // La dernière couche devient la couche de sortie
            Output_layer(reseau_neural) ← current
        Fin Si
    Fin Pour
    
    Retourner reseau_neural
Fin
````
                                                                                                                
## Partie 4 : Principe de fonctionnement simplifié d'un réseau de neurones

### Propagation avant

**Lexique**</br>
neural_network (<Neural_Network>) : représente un réseau de neurones complet, avec des couches d'entrées, cachées et de sorties. </br>
Input_layer (<Layer>) : la première couche du réseau neuronal, la couche d'entrée traitant les données initiales. </br>
temp_layer (<Layer_List>) : un pointeur utilisé pour parcourir la liste des couches dans le réseau, commençant par la couche d'entrée. </br>
result (<Entry_List>) : une liste chaînée contenant les résultats des calculs successifs effectués par chaque couche. </br>
ei (<Entry_List>) : une liste chaînée contenant les entrées initiales du réseau neuronal. </br>
OutCouche (<Fonction>) : fonction qui calcule la sortie de chaque couche en fonction des entrées données. </br>
Forward_Propagation (<Fonction>) : fonction qui exécute la propagation avant dans le réseau neuronal, calculant les sorties à travers toutes les couches. </br>
Layer_List (<Liste de couches>) : une liste chaînée contenant toutes les couches du réseau, du plus bas niveau (entrée) au plus haut niveau (sortie). </br>

**Algorithmique**</br>
*Données :*</br>

reseau_neural <Neural_Network> : un réseau de neurones comprenant une couche d'entrée et d'autres couches cachées et de sortie. </br>
ei <Entry_List> : une liste d'entrées à transmettre dans le réseau neuronal pour la propagation avant. </br>

*Résultat :* </br>
result (<Entry_List>) : une liste contenant les résultats obtenus après la propagation des entrées à travers toutes les couches du réseau. </br>

````
Fonction Forward_Propagation(reseau_neural :<Neural_Network> , ei : Entry_List ) : result <Entry_List>
Début
    result ← ei
    temp_layer ← Input_layer(reseau_neural)
    
    Tant que temp_layer ≠ NULL Faire
        result ← OutCouche(temp_layer, result)
        temp_layer ← suivant(temp_layer)
    Fin Tant que
    
    Retourner result
Fin
````
