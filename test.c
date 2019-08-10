#define CTEST_MAIN

#include <ctest.h>
#include <sort.h>

CTEST(sort, sort_2_words)
{
  char **words = (char **)malloc(sizeof(char *) * 3);

  words[0] = "hello";
  words[1] = "again";
  words[2] = NULL;

  sortWords(words);

	ASSERT_EQUAL(strcmp(words[0], "again"), 0);
  ASSERT_EQUAL(strcmp(words[1], "hello"), 0);
  ASSERT_EQUAL(words[2] == NULL, 1);

  free(words);
}

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
