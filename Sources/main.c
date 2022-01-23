#include <stdio.h>
#include <stdbool.h>
#include "../include/double_pointeur.h"
const int n = 8;
const int k = 3;

//list_count doesn't go under 3
void joseph(){
	element* list = list_create();
    printf("created\n");
    for (int i = 1; i <= n; i++) {
        list = list_insert_after(list, i);
    }
    printf("is list empty: %s", list_empty(list) ? "true\n" : "false\n");

    int count = list_count(list);
    printf("count = %d\n", count);
    printf("Start\n");

    element* next = list;
    while (!list_empty(list)) {
        int c = 0;

        while (c != k) {
            next = next->next;
            c++;
        }
        list_remove(list, next->data);
        //printf("count = %d\n", list_count(list));

        if (next->data == 7) {
            //should be true
            printf("is list empty: %s", list_empty(list) ? "true\n" : "false\n");
            break;
        }
    }
}

void sort(){
    
}


int main(void) {
    joseph();
    
	return 0;
}