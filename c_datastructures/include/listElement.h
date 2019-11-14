#ifndef LISTELEMENT_H
#define LISTELEMENT_H

typedef struct _element{
	void *data;
	struct _element *next;
	void (*Free)( struct _element **elem );
}element;

void Element_Init(element*);
element* Element_Create();

void* Element_GetData(element*);

void Element_Update(element*, void* );
element* Element_Clone(element*);

void Element_Free(element**);

#endif
