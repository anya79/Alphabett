#define CTEST_MAIN

#include <ctest.h>
#include <sort.h>
#include <parser.h>
#include <reader.h>

CTEST(sort, sort_1_word)
{
  char **words = (char **)malloc(sizeof(char *) * 2);

  words[0] = "hello";
  words[1] = NULL;

  sortWords(words);

	ASSERT_EQUAL(strcmp(words[0], "hello"), 0);
  ASSERT_EQUAL(words[1] == NULL, 1);

  free(words);
}

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

CTEST(parse, parse_string_1_word)
{
  char string[] = "hello";

  char **result = parseWords(string);

  ASSERT_EQUAL(strcmp(result[0], "hello"), 0);

  free(result);
}

CTEST(parse, parse_string_3_words)
{
  char string[] = "hello again everyone!";

  char **result = parseWords(string);

  ASSERT_EQUAL(strcmp(result[0], "hello"), 0);
  ASSERT_EQUAL(strcmp(result[1], "again"), 0);
  ASSERT_EQUAL(strcmp(result[2], "everyone"), 0);

  free(result);
}

CTEST(reader, read_from_file)
{
  char *string;

  readFromFileToArray(&string, "test/test.txt");

  ASSERT_EQUAL(strcmp(string, "hello world!\n"), 0);
}
int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
