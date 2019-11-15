#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "listElement.h"


/************************************************
 * All structures should be initialized			*
 * with the _init function created structs are	*
 * alread initializied!							*
 ************************************************/

typedef struct _list{
    struct _element *head;
    struct _element *tail;
    unsigned int length;

	// NOTE: if a Free function to list is given it will
	// use it on all Elements
	//
	// Free of list overrides default Free of listElement
	void (*FreeElem)(element*);
	element* (*CloneElem)(element*);
} list;


void List_Init(list*);
list* List_Create();
void List_AddHead(list*, void*);
void List_AddTail(list*, void*);
int List_GetLength(list*);
element* List_GetElem(list*, int);

//list* List_Clone(list*);
void List_Delete(list*, int);
void List_Free(list**);

#endif
