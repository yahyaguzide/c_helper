#include <stdlib.h>

/*****************************************************************
//  safeString
//
// date: 22.11.2019
// name: Yahya Guezide
// An safer string which should prevent data overflow
// its quiet simple, an indexer checks if end is reached
//
*****************************************************************/

void SString_Init( sstring *ss ){
    if( !ss )
        return;

    ss->head= NULL;
    ss->tail= NULL;
}

sstring* SString_Create(){
    sstring *ss = (sstring*)malloc(sizeof(sstring));
    SString_Init(ss);
    return ss;
}

void SString_Free( sstring **ss ){
    if( !ss || !*ss )
        return;
 
    for( char *iter (*ss)->head; iter != ((*ss)->tail+1); iter++ ){
        free(iter);
    }
    *ss = NULL;
}
