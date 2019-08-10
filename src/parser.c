#include "parser.h"

char **parseWords(char *string) {
  for(int i = 0; string[i] != '\0'; i++) {
// не получится заменить на isalpha иначе русский язык не работает
    switch (string[i])
    {
    case '\n':
      string[i] = ' ';
      break;
    case '\t':
      string[i] = ' ';
break;
    case '.':
      string[i] = ' ';
      break;
    case ',':
      string[i] = ' ';
      break;
    case '"':
      string[i] = ' ';
      break;
    case '<':
      string[i] = ' ';
      break;
    case '>':
      string[i] = ' ';
      break;
    case '!':
      string[i] = ' ';
      break;
    case '-':
      string[i] = ' ';
      break;
    case '[':
      string[i] = ' ';
      break;
    case ']':
      string[i] = ' ';
      break;

    default:
      break;
    }
  }

  for(int i = 0; i < strlen(string) - 1; i++) {
    if(string[i] == ' ' && string[i + 1] == ' ') {
      int j;
      for(j = i; j < strlen(string) - 1; j++) {
        string[j] = string[j + 1];
      }
      string[j] = '\0';
    }
  }

  int wordsCount = 0;

  for(int i = 0; i < strlen(string); i++) {
    if(string[i] == ' ')
      wordsCount++;
  }

  char **words = (char **)malloc(sizeof(char *) * (wordsCount + 2 ));

  int i = 0;

  words[0] = strtok(string, " ");

  while(words[i]  != NULL) {
    words[i + 1] = strtok(NULL, " ");
    i++;
  }

  return words;
}
