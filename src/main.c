#include "reader.h"
#include "parser.h"
#include "sort.h"
#include <wchar.h>

int main(int argc,char *argv[])
{
  char *text;
  int length = 0;

  switch(argc){
  case 2:
{

    length = readFromFileToArray(&text, argv[1]);
    if(length == 0) {
      printf("Невозможно открыть файл!\n");
      return -1;
    }




    char **words = parseWords(text);

sortWords(words);

    while(*words != NULL) {
      printf("%s\n", *words);
      words++;
    }

    break;
}
  default:
    printf("Пожалуйста укажите путь до текста!\n");
    return -1;
  }

  return 0;
}
