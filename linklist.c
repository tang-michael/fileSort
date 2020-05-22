#include "fileSort.h"


/**
Author: Michael Tang
**/

void llist_push(linklist *llist,char *word)
{
	node *new_node=(node*)malloc(sizeof(node));

	if(!new_node){
		printf("ERROR: Could not allocate space with malloc.");
		return ;
  }

	new_node->str = realloc(new_node->str, sizeofFile*sizeof(char));

  strcpy(new_node->str, word);

  if(llist->head == NULL){
    llist->head = new_node;
    llist_length++;
    return;
  }

	new_node->next=NULL;
	new_node->next=llist->head;
	llist->head=new_node;
  llist_length++;
}
void printList(linklist *llist){
  node *ptr = llist->head;

   //start from the beginning
	 printf("\n");
   while(ptr != NULL) {
      printf("%s\n",ptr->str);
      ptr = ptr->next;
   }

}
