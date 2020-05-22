#include "fileSort.h"

/**
Author: Michael Tang
**/

int main(int argc, char *argv[]){
  //Check for command line errors
  if(argc < 3){
    //Less than 2 arguments
    printf("More arguments required\n");
    printf("Format: ./fileSort <flag> <fileName>\n");
    return -1;
  }else if(argc > 3){
    //More than 2 arguments
    printf("Too many arguments\n");
    printf("Format: ./fileSort <flag> <fileName>\n");
    return -1;
  }

  //Check flags
  char sortFlag1 = argv[1][0];
  char sortFlag2 = argv[1][1];

  //Variable to check if its number or letter sort
  int flag[1];
  int flagLength = strlen(argv[1]);
  linklist llist;
  llist.head = NULL;

  //Gets file
  char *fileName = argv[2];
  //Store file descriptor int variable fd
  int fd = open(fileName, O_RDONLY, 0666);

  //Check if file is there
  if(access(fileName, F_OK) == -1){
    printf("Cannot find file %s\n", fileName);
    return -1;
  }
  //Get size of file so we know how much space we need to allocate
  char ch;
  sizeofFile = lseek(fd, 0, SEEK_END);
  lseek(fd, 0, SEEK_SET);
  int index = 0;
  //Word can be whole file
  char *word = malloc(sizeof(char)*sizeofFile);

  // Read file character by character
  while(read(fd, &ch, 1) > 0){
    if((ch <= 'z' && ch >= 'a') || (ch <= '9' && ch >= '0') || ch == ','){
      if(ch <= 'z' && ch >= 'a'){
        flag[0] = 1;
      }
      if(ch <= '9' >= '0'){
        flag[0] = 2;
      }
      if(ch == ','){
        llist_push(&llist, word);
        memset(word, '\0', sizeofFile);
        strcpy(word, EMPTY_STR);
        index = 0;
      }else if(ch == '\n' || ch == ' ' || ch == '\t'){
        continue;
      }else{
        word[index++] = ch;
      }
    }
  }
  llist_push(&llist, word);
  printf("Before Sort: ");
  // printList(&llist);
  // Get flags
  // if(sortFlag1 == '-' && sortFlag2 == 'i' && flagLength == 2){
  //   //Letter Sort
  //   if(flag[0] == 1){
  //     printf("\n");
  //     printf("Letter insertion  sort on file %s\n", fileName);
  //     insertionSort(&llist, stringCompare);
  //     printf("After Sort: ");
  //     printList(&llist);
  //     printf("\n");
  //   }
  //   //Numeric Sort
  //   else if(flag[0] == 2){
  //     printf("Numeric insertion  sort on file %s\n", fileName);
  //     insertionSort(&llist, numCompare);
  //     printf("After Sort: ");
  //     printList(&llist);
  //     printf("\n");
  //   }
  // }
  // if(sortFlag1 == '-' && sortFlag2 == 'q' && flagLength == 2){
  //   //Letter Sort
  //   if(flag[0] == 1){
  //     printf("\n");
  //     printf("Letter quick  sort on file %s\n", fileName);
  //     quickSort(&llist, stringCompare);
  //     printf("After Sort: ");
  //     printList(&llist);
  //     printf("\n");
  //   }
  //   //Numeric Sort
  //   else if(flag[0] == 2){
  //     printf("\n");
  //     printf("Numeric quick  sort on file %s\n", fileName);
  //     quickSort(&llist, numCompare);
  //     printf("After Sort: ");
  //     printList(&llist);
  //     printf("\n");
  //   }
  // }

  close(fd);
}
