#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

#define MAX 50

int main()
{
  char str[MAX];

  printf("$ ");

  fgets(str,MAX, stdin);

  printf("%s\n", str);

  // Testing if found beginning of a word.
  printf("first none word start is: %c\n ",*word_start(&str[0]));

  // Testing if found end of a word.
  printf("end of word is: %c\n", *(word_terminator(&str[0])-1));

  printf("word is: %d long\n", count_words(&str[0]));
  fflush(stdin);

  return 0;

}
