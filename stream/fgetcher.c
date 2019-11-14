#include <stdlib.h>
#include <stdio.h>

/**************************************************
//  fgetcher
//
// date: 04.11.2019
// name: Yahya Guezide
// simple getch for a Stream
//
***************************************************/

#define MAXBUFFER 2
static int bid= 0, buffer[MAXBUFFER];
void Fungetch( int c ){
	if( bid < MAXBUFFER )
		buffer[bid++] = c;
}

int Fgetch( FILE *stream ){
	return 	bid? fgetc(stream): buffer[--bid];
}

void FFlushBuffer(){
	bid = 0;
}

int FgetchLine( FILE *stream, char *buffer, int length ){
	int c, index= 0;
	while( (c= Fgetch(stream)) != '\n' && c != EOF && index < length )
		buffer[index++] = c;

	if( index == 0 && c == EOF )
		return -1;

	buffer[index++] = '\0';

	return index;
}
