#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "listElement.h"

typedef struct _list{
    struct _element *head;
    struct _element *tail;
    unsigned int length;

	// NOTE: if a Free function to list is given it will
	// use it on all Element -> Free of list overrides
	// Free of every Element
	
	void (*Free)(element*);
} list;


void List_Init(list*);
list* List_Create();
void List_AddHead(list*, void*);
void List_AddTail(list*, void*);
int List_GetLength(list*);
element* List_GetElem(list*, int);

// Returns void pointer to previous Element, 
// if sElem is the Head return void pointer to list.
// Returns NULL if sElem not in list or if any NULL was given
static void* List_InList(list*, element*);

list* List_Clone(list*);
void List_Delete(list*, element*);
void List_Free(list**);

#endif
