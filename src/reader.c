#include "reader.h"

int readFromFileToArray(char **array, char *fileName) {
  FILE *fp = fopen(fileName, "r");
  int arrSize = 100;

  if(fp == NULL) {
    return 0;
  }

  *array = (char *)malloc(sizeof(char) * arrSize);

  int symNumber = 0;

  while(1) {
    char sym = fgetc(fp);

    if(sym == EOF) {
      fclose(fp);
      break;
    }

    (*array)[symNumber] = sym;

    symNumber++;

    if(symNumber >= arrSize) {
      *array = (char *)realloc(*array, arrSize * sizeof(char));
    }
  }

  return symNumber + 1;
} 
