#ifndef DOUBLEP_H
#define DOUBLEP_H

typedef struct element {
    int data;
    struct element* next;
} element;

// Crée une nouvelle liste vide. Renvoie simplement un pointeur NULL
element* list_create();

// Teste si la liste est vide
bool list_empty(element* head);

// Renvoie le nombre d’éléments de la liste
unsigned int list_count(element* head);

// Déplace le pointeur head sur l’élément suivant. Retourne la nouvelle tête de liste
element* list_move(element* head);

//Insère un élément après le pointeur head. Retourne le pointeur sur l’élément inséré
element* list_insert_after(element* head, int data);

//Insère un élément avant le pointeur head. Retourne le pointeur sur l’élément inséré
element* list_insert_before(element* head, int data);

// Recherche un élément dans la liste. Retourne un pointeur sur le 1er élément trouvé ou NULL si l’élément est absent
element* list_search(element* head, int data);

// Supprime un élément de la liste sans libérer l’élément pointé. Renvoie un pointeur sur le 1er élément trouvé à supprimer et l’enlève de la liste, ou NULL si l’élément est absent
element* list_remove(element* head, int data);

// Supprime toute la liste en libérant chaque élément
void list_free(element* head);

// Appel d’une fonction qui modifie tous les éléments de la liste grâce à la fonction action()
void list_process(element* head, int (*action)(int));


#endif