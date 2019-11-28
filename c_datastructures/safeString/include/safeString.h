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
// terminated Adress(Without a ASCII-NULL)
//
// Second arg is the length, to give more safety to the user
// n = 0 is consideret as a String with a not fixed size
// NOTE: please be cautios if you decide to use 0 it can end in a infinit Loop
sString *SString_CreateSet(char*, int);
void SString_Set(sString*, char*, int);

void SString_Free(sString*);


#endif
