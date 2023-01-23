#include "list.h"
#include "graph.h"
#include "error.h"

#include <stdio.h>
#include <stdlib.h>

// Allocate memory and append node to end of list.
int append(LIST* target, VERTEX* data) {

    NODE *newLink = malloc(sizeof(NODE));
    newLink->data = data;
    newLink->next = NULL;

    if(target->tail == NULL) {
        target->head = newLink;
        target->tail = newLink;
    }
    else {
        target->tail->next = newLink;
        target->tail = newLink;
    }

    return S_SUCCESS;
}

// De-allocate memory for adjacency list nodes determined through double-ended scrambler. Leaves diagonal board node (List head).
int clean(LIST* target) {
    if(target->head && target->head != target->tail) {
        NODE* current = target->head->next;
        NODE* prev = target->head;
        prev->next = NULL;

        while(current) {
            free(prev);
            prev = current;
            current = current->next;
        }

        target->tail = target->head; 
    }
    
    return S_SUCCESS;
}