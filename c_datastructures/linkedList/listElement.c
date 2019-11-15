#include <stdlib.h>

#include "include/listElement.h"

/**************************************************
//  listELement
//
// date: 04.11.2019
// name: Yahya Guezide
// Simple Element for a List
//
***************************************************/

typedef struct _element element;

void Element_Init( element *elem ){
	elem->data = NULL;
	elem->next = NULL;
}

element* Element_Create(){
	element *elem= (element*)malloc(sizeof(element));
	Element_Init(elem);
	return elem;
}


void* Element_GetData( element *elem ){
	if( !elem )
		return NULL;

	return elem->data;
}

void Element_Update( element *elem, void *data ){
	if( !elem && !data )
		return;

	if( elem->data )
		free(elem->data);

	elem->data = data;
}

element* Element_Clone( element *elem ){
	element *clone = (element*)malloc(sizeof(element));
	
	clone->data = elem->data;
	clone->next = elem->next;
	return clone;
}

void Element_Free( element *elem ){
	if( !elem )
		return;

	free(elem);
}
