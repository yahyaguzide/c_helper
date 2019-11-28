#include <stdlib.h>

#include "include/linkedList.h"
#include "include/listElement.h"

/*****************************************************************
//  linkedlist
//
// date: 24.10.2019
// name: Yahya Guezide
//  Simple Linked List 
//
*****************************************************************/

// NOTE: maybe some kind of ErrMsg on the ErrStream would be good

typedef struct _list list;

void List_Init( list *l ){
	if( !l )
		return;

    l->head = NULL;
    l->tail = NULL;
    l->length = 0;

	// NOTE: Default Free form listElement
    l->FreeElem = Element_Free;
	// NOTE: Default Copy from listElement
	l->CopyElem = Element_ShallowCopy;
}

list* List_Create(){
	list *l = (list*)malloc(sizeof(list));
	List_Init(l);
	return l;
}

void List_AddHead( list *l, void *data ){
    element *elem = (element*)malloc(sizeof(element));

    if( !l || !data || !elem )
        return;

    elem->next = l->head;
    l->head = elem;

    if( l->tail == NULL )
        l->tail = elem;

    elem->data = data; 
    l->length++;
}

void List_AddTail( list *l, void *data ){
    if( !l || !data )
        return;

    element *elem = (element*)malloc(sizeof(element));
    elem->next = NULL;

    if( l->head == NULL )
        l->head = elem;
    else
        l->tail->next = elem;

    elem->data = data;
    l->tail = elem;
    l->length++;
}

int List_GetLength( list *l ){
	return l->length;
}

element* List_GetElem( list *l, int index ){
	if( l->length <= index || !l )
		return NULL;

	element *elem = l->head;
	for(; index > 0; index-- )
		elem = elem->next;
	return elem;
}

/*
list* List_Clone( list *l ){
	if( !l )
		return;
	//TODO: write List_Clone
	//and think if i realy need it
}
*/
void List_Delete( list *l, int i ){
	if( !l || i >= l->length )
		return;

	element *preElem, *tmp;

	preElem = l->head;
	for(; i > 0; i--, preElem = preElem->next );

	// The given Element is the Head
	if( (void*)l->head == preElem ){
		tmp = l->head;

		// only one Element was in the list
		if( tmp == l->tail )
			l->tail = NULL;

		l->head = tmp->next;
	}else{ // Element is in the List but not The Head
		tmp = ((element*)preElem)->next;
		((element*)preElem)->next = tmp->next;
		
		// The given Element is the Tail
		if( tmp == l->tail )
			l->tail = preElem;
	}
	l->length--;

	l->FreeElem(tmp);
}

void List_Free( list *l ){
	while( l->length > 0 ){
		List_Delete( l, l->length-1 );
	}
	
	free(l);
}
