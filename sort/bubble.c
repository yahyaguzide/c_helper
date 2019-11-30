#include <stdlib.h>
//#include <stdio.h>
#include <string.h>

#include "include/bubble.h"
#include "include/linkedList.h"

/*****************************************************************
//  bubble
//
// date: 30.11.2019
// name: Yahya Guezide
// Bubble sort
// Compares two informations with a given Compare function,
// and switches places if on is smaller/bigger than the other
//
*****************************************************************/

static void _Switch( void *i, void *j,size_t size ){
    if( !i || !j || !size )
        return;

    void *tmp = (void*)malloc(size);

    memcpy( tmp, i, size );

    memcpy( i, j, size );
    memcpy( j, tmp, size );
}


typedef struct _list list;

int BubbleSort( list *l, int (*compare)(void*,void*), _Bool up ){
    if( !l || !compare )
        return -1;
    
    int counter= 0, index = up? 1:-1;

    _Bool sorted= 0;
    while( !sorted ){
        sorted = 1;
        for( int i= 1; i < List_GetLength(l); i+= 1 ){
            if( 0 > index*compare(
                        (void*)List_GetElem(l, i-1),
                        (void*)List_GetElem(l, i)) ){
                _Switch( 
                        (void*)List_GetElem(l, i-1),
                        (void*)List_GetElem(l, i),
                        sizeof( element ));
                sorted = 0;
                counter+= 1;
            }
        }
    }
        return counter;
}
