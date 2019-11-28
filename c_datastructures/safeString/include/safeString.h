#ifndef SAFESTRING_H
#define SAFESTRING_H

/***************************************
 * Still needs to be used with caution!!
 * 
 * It can be used with a pointer, 
 * to emulate a Iterrator like in C++
 *
 * for( 
 * char *iterC = sString.head; 
 * iterC != sString.tail + 1;
 * iterC++ ){}
 ****************************************/ 

typedef struct _safeString{
    char *head;
    char *tail;
}sString;

void SString_Init(sString* );
sString *SString_Create();

// NOTE: do not give a char* which points to a non
// terminated Adress
sString *SString_CreateSet(char*);

void SString_Set(sString*, char*);

void SString_Free(sString*);


#endif
