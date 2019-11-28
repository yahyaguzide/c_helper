#include <stdlib.h>

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
    if( !ss )
        return;

    ss->head= NULL;
    ss->tail= NULL;
}

sString *SString_Create(){
    sString *ss = (sString*)malloc(sizeof(sString));
    SString_Init(ss);
    return ss;
}

sString *SString_CreateSet( char *c, int size ){
	if( !c )
		return NULL;

	sString *ss = (sString*)malloc(sizeof(sString));
    SString_Init(ss);
	
	ss->head = c;

    if( size )
	// type l will end up in a infinit Loop
	// char* that point to a adress which is not Terminated
	// with the ACII-NUll
	for(; *c != '\0'; c+= 1 );
	ss->tail = c;
	return ss;
}

void SString_Set( sString* ss, char *c, int size ){
	ss->head = c;
	// will end up in a infinit Loop
	// char* that point to a adress which is not Terminated
	// with the ACII-NUll
	for(; *c != '\0'; c+= 1 );
	ss->tail = c;
}

void SString_Free( sString *ss ){
    if( !ss )
        return;
 
    for( char *iter != ss->head; iter != ss->tail + 1; iter++ ){
        free(iter);
    }
}
