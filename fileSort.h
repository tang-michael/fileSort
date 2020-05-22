#ifndef FILESORT_H
#define FILESORT_H

/**
Author: Michael Tang
**/

//Libraries
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

//Global variables


int llist_length;
int sizeofFile;


//Linlist structure
typedef struct node
{
	char str[512];
	struct node *next;
}node;

typedef struct
{
	node *head;
}linklist;



//linklist.c functions
void llist_push(linklist *llist, char *word);
void printList(linklist *llist);

//comparator.c functions
int stringCompare(void *string1, void *string2);
int numCompare(void *num1, void *num2);

//sort.c functions
int quickSort( void* toSort, int (*comparator)(void*, void*) );
void insertionSortHelp(linklist *sorted_list, node *new_node, int (*comparator)(void*, void*));
int insertionSort( void* toSort, int (*comparator)(void*, void*)   );
node *getTail(linklist *p_list);
node *partition(node *head, node *end, node **newHead, node **newEnd, int(*comparator)(void*,void*));
node *quickSortRecur(node *head, node *end, int(*comparator)(void*,void*));
node *getTail(linklist *p_list);
node *getTailFromNode(node *head);

#define EMPTY_STR ""

#endif
