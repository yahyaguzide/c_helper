#ifndef LISTELEMENT_H
#define LISTELEMENT_H

// TODO: change listElement overall 

typedef struct _element{
	void *data;
	struct _element *next;
}element;

void Element_Init(element*);
element* Element_Create();

void* Element_GetData(element*);

void Element_Update(element*, void* );
// NOTE: this is the default Clone function for
// Elements.
// it only will make a shallow copy of it!
element* Element_ShallowCopy(element*);

// NOTE: this is a default free function for
// Elements.
// As long no Free function in List is given 
// this will be used!
//void Element_Free(element*);

#endif
