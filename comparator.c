#include "fileSort.h"

/**
Author: Michael Tang
**/

int numCompare(void *num1, void *num2){
  int number1 = atoi(num1);
  int number2 = atoi(num2);

  if(number1 > number2){
    return 1;
  }else if(number1 < number2){
    return -1;
  }else if(number1 == number2){
    return 2;
  }
  return 0;
}

int stringCompare(void *string1, void *string2){
  char word1[sizeofFile];
  char word2[sizeofFile];
  strcpy(word1, (char*)string1);
  strcpy(word2, (char*)string2);
  int i;
  for(i = 0; i <= sizeofFile; i++){
    if(word1[i] > word2[i]){
      return 1;
    }else if(word1[i] < word2[i]){
      return -1;
    }
  }
  return 0;
}
