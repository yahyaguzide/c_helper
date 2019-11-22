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

    // TODO: find a clean way of updating data  maybe with memcpy
    // NOTE: if memcpy is going to be used be warry, could lead to random behavior
	if( elem->data )
//		free(elem->data);

	elem->data = data;
}

element* Element_ShallowCopy( element *elem ){
	element *cp = (element*)malloc(sizeof(element));
	
	cp->data = elem->data;
	cp->next = elem->next;
	return cp;
}

/* Is not used anymore List will provide a Free function for all elements
void Element_Free( element *elem ){
	if( !elem )
		return;

	free(elem);
}
*/
