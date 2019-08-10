#include "sort.h"

void sortWords(char **words) {
  int length = 0;

  for(char **start = words; *start != NULL; start++)
    length++;

  int hasBeenSorted = 1;

  while(hasBeenSorted)
  {
    hasBeenSorted = 0;
    for(int i = 0; i < length - 1; i++) {
      if(strcmp(words[i], words[i + 1]) > 0) {
        hasBeenSorted = 1;
        char *temp = words[i];
        words[i] = words[i + 1];
        words[i + 1] = temp;
      }
    }
  }
}
