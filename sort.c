#include "fileSort.h"

/**
Author: Michael Tang
**/

//Main insertion sort
int insertionSort( void* toSort, int (*comparator)(void*, void*)   ){
  linklist *llist = toSort;
  linklist sorted;

  node *current = llist->head;
  while(current != NULL){
    node *next = current->next;
    insertionSortHelp(&sorted, current, comparator);
    current = next;
  }
  llist->head = sorted.head->next;
}
//Helper function for main insertion sort
void insertionSortHelp(linklist *sorted_list, node *new_node, int (*comparator)(void*, void*)){
  node *current;
  if(sorted_list->head == NULL){
    new_node->next = NULL;
    sorted_list->head = new_node;
  }else if(comparator((void*)sorted_list->head->str, new_node->str) == 1){
    new_node->next = sorted_list->head;
    sorted_list->head = new_node;
  }else{
    current = sorted_list->head;
    while(current->next != NULL && comparator((void*)current->next->str, new_node->str) == -1){
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
}

node *getTail(linklist *p_list){
  node *cur = p_list->head;
  while(cur != NULL && cur->next != NULL){
    cur = cur->next;
  }

  return cur;
}

node *getTailFromNode(node *head){
  node *cur = head;
  while(cur != NULL && cur->next != NULL){
    cur = cur->next;
  }

  return cur;
}

//partitions list into parts and returns pivot
node *partition(node *head, node *end, node **newHead, node **newEnd, int(*comparator)(void*,void*))
{
    node *pivot = end;
    node *prev = NULL;
    node *cur = head;
    node *tail = pivot;

    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot)
    {
        if (comparator(cur->str, pivot->str) == -1)
        {
            // First node that has a value less than the pivot - becomes
            // the new head
            if ((*newHead) == NULL){
               (*newHead) = cur;
             }

            prev = cur;
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change tail
            if (prev){
                prev->next = cur->next;
              }
            node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot data is the smallest element in the current list,
    // pivot becomes the head
    if ((*newHead) == NULL){
        (*newHead) = pivot;
    }
    // Update newEnd to the current last node
    (*newEnd) = tail;

    // Return the pivot node
    return pivot;
}

//Main quickSort algorithm using recursion
node *quickSortRecur(node *head, node *end, int(*comparator)(void*,void*)){
  if(head == NULL || head == end){
    return head;
  }
  node *newHead = NULL;
  node *newEnd = NULL;
  node *pivot = partition(head, end, &newHead, &newEnd, comparator);

  if(newHead != pivot){
    node *tmp = newHead;
    while(tmp->next != pivot) tmp = tmp->next;
    tmp->next = NULL;

    newHead = quickSortRecur(newHead, tmp, comparator);

    tmp = getTailFromNode(newHead);
    tmp->next = pivot;

  }

  pivot->next = quickSortRecur(pivot->next, newEnd, comparator);

  return newHead;
}

//Base quickSort function
int quickSort( void* toSort, int (*comparator)(void*, void*) ){
  linklist *llist = toSort;
  node *head = llist->head;
  llist->head = quickSortRecur(head, getTailFromNode(head), comparator);
}
