#include <stdlib.h>
#include <stdio.h>

#include "../include/linkedList.h"

int main(){

	list *l1 = (list*)malloc(sizeof(list));
	List_Init(l1);

	list *l2 = List_Create();

	printf(" Length\n\tl1: %d\tl2: %d\n", List_GetLength(l1), List_GetLength(l2));


	int *i= (int*)malloc(sizeof(int));
	*i = 3;
	List_AddHead(l1, i);
	List_AddTail(l2, i);

	printf(" Length\n\tl1: %d\tl2: %d\n", List_GetLength(l1), List_GetLength(l2));


	printf(" l1: %d l2: %d\n", *((int*)List_GetElem(l2, 0)->data), *((int*)List_GetElem(l2, 0)->data));

	List_Free( &l1 );
	List_Free( &l2 );

	printf( "Pointer\nl1: %p l2: %p\n", l1, l2 );


	return 0;
}
