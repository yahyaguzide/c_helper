#ifndef BUBBLE_H
#define BUBBLE_H

typedef struct _list list;

int BubbleSort(list*, int (*compare)(void*, void*), _Bool up); 

#endif
