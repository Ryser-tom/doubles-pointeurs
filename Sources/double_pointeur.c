#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../include/double_pointeur.h"

// Crée une nouvelle liste vide. Renvoie simplement un pointeur NULL
element* list_create(){
	return NULL;
}

// Teste si la liste est vide
bool list_empty(element* head){
	if (head == NULL) {
		return true;
	}else{
		return false;
	}
}

// Renvoie le nombre d’éléments de la liste
unsigned int list_count(element* head){
	if (list_empty(head)) {
        return 0;
    }
	int c = 0;
	element *current = head;
	do {
		current = current->next;
		c++;
	}while (current != head);
	return c;

}

// Déplace le pointeur head sur l’élément suivant. Retourne la nouvelle tête de liste
element* list_move(element* head){
	head->next = head;
	return head->next;
}

//Insère un élément après le pointeur head. Retourne le pointeur sur l’élément inséré
element* list_insert_after(struct element* head, int data){
	element* new = malloc(sizeof(element));
	new->data = data;
	if (list_empty(head)) {
        new->next = new;
    } else {
        new->next = head->next;
        head->next = new;
    }
	return new;
}

//Insère un élément avant le pointeur head. Retourne le pointeur sur l’élément inséré
element* list_insert_before(element* head, int data){
	element* new = malloc(sizeof(element));
	new->next = head;
	new->data = data;
	return new;
}

// Recherche un élément dans la liste. Retourne un pointeur sur le 1er élément trouvé ou NULL si l’élément est absent
// TODO: test recursivity
element* list_search(element* head, int data){
	if (head->data == data) {
	return head;
	}
	if (head->next == NULL) {
	return NULL;
	}
	element* new = malloc(sizeof(element));
	new = list_search(head->next, data);
	return new;
}

// Supprime un élément de la liste sans libérer l’élément pointé. Renvoie un pointeur sur le 1er élément trouvé à supprimer et l’enlève de la liste, ou NULL si l’élément est absent
element* list_remove(element* head, int data){
	printf("%d\n", data);
	if (list_empty(head)) {
		printf("list empty\n");
        return NULL;
    }

	element *search = list_search(head, data);
	if (search == NULL) {
        return NULL;
    }
	//get previous 
	element *previous = search;
    while (previous->next != search) {
        previous = previous->next;
    }
	previous->next = search->next;

    return search;


}

// Supprime toute la liste en libérant chaque élément
void list_free(element* head){
	if (head->next != NULL) {
		list_free(head->next);
	}
	free(head);
}

// Appel d’une fonction qui modifie tous les éléments de la liste grâce à la fonction action()
void list_process(element* head, int (*action)(int)){
	if (head->next != NULL) {
		list_process(head->next, *action);
	}else {
		action(head->data);
	}
}