#include <stdlib.h>
#include <stdio.h>

#include "include/ErrorO.h"

/*****************************************************************
//  safeString
//
// date: 22.11.2019
// name: Yahya Guezide
// An safer string which should prevent data overflow
// its quiet simple, an iterator checks if end is reached
//
*****************************************************************/

void SString_Init( sString *ss ){
    if( !ss ){
        errormsg("safeString Init: Pointer is NULL");
        return;
    }

    ss->head= NULL;
    ss->tail= NULL;
}

sString *SString_Create(){
    sString *ss = (sString*)malloc(sizeof(sString));
    SString_Init(ss);
    return ss;
}

sString *SString_CreateSet( char *c, int size ){
	if( !c || size < 0 )
		return NULL;

	sString *ss = (sString*)malloc(sizeof(sString));
    SString_Init(ss);
	
	ss->head = c;

    if( !size ){
    	// will end up in a infinit Loop
    	// char* that point to a adress which is not Terminated
    	// with the ACII-NUll
	    for(; *c != '\0'; c+= 1 );
    }else{
        for( int i= 0; *c != '\0' && i < size; c+= 1, i+= 1 );
    }
	ss->tail = c;
	return ss;
}

void SString_Set( sString* ss, char *c, int size ){
    if( !ss || !c || size < 0 ){
        errormsg("safeString Set: given Pointer is NULL or index out of bounds");
        return;
    }

	ss->head = c;

    if( !size ){
    	// will end up in a infinit Loop
    	// char* that point to a adress which is not Terminated
    	// with the ACII-NUll
	    for(; *c != '\0'; c+= 1 );
    }else{
        for( int i= 0; *c != '\0' && i < size; c+= 1, i+= 1 );
    }

	ss->tail = c;
}

void SString_Free( sString *ss ){
    if( !ss ){
        errormsg("safeString Free: Pointer is NULL");
        return;
    }
 
    // Here's an example how it can be used
    for( char *iter != ss->head; iter != ss->tail + 1; iter++ ){
        free(iter);
    }
}
