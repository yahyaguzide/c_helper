#ifndef SAFESTRING_H
#define SAFESTRING_H

typedef struct _safeString{
    char *head;
    char *tail;
}sstring;

void SString_Init(ssstring* );
sstring *SString_Create();

void SString_Free(sstring*);


#endif
