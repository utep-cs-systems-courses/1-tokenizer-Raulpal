#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


/* Return true (non-zero) if c is a whitespace character

   ('\t' or ' ').

   Zero terminators are not printable (therefore false) */

int space_char(char c)

{

  return ((c == '\t' || c == ' ') && c!= '\0') ? 1: 0;

}



/* Return true (non-zero) if c is a non-whitespace

   character (not tab or space).

   Zero terminators are not printable (therefore false) */

int non_space_char(char c)

{

  return (space_char(c)==0)? 1: 0 ;

}





/* Returns a pointer to the first character of the next

   space-separated word in zero-terminated str.  Return a zero pointer if

   str does not contain any words. */

char *word_start(char *str)

{

  if(*str == NULL)

    return 0;

  if(non_space_char(*str) == 1)

    return str;

  return (word_start((str + 1)));

}


/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  while(*word != '\0' && *(word+1) != '\0')

    {

      if(space_char(*word))

	return word;

      word+=1;

    }

  return word;

}

/* Counts the number of words in the string argument. */

int count_words(char *str)

{

  if(*str == '\0')

    return 0;

  if(*str == NULL)

    return 0;

  char *first_char = word_start(str);

  char *last_char = word_terminator(first_char);

  return 1 + count_words(last_char + 1 );
}

/* Returns a fresly allocated new zero-terminated string

   containing <len> chars from <inStr> */

char * str_copy(char *instr, short len)
{
  char *new_word = malloc(sizeof(char) * len);

  for(int i = 0; i<= len; i++)
    {
      *(new_word + i) = *(instr + i);
    }

  *(new_word + (len +1)) = '\0';

  return new_word;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated

   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string"

     tokens[3] = 0

*/

char **tokenize(char* str)
{
  int length = count_words(str) + 1;

  char **token_vector = malloc(sizeof(char*)* length);
  
  printf("%d\n", length);

  for(int i = 0; i < length; i++)
    {
      str = word_start(str) ;

      char *last_letter = word_terminator(str);

      int word_length = last_letter - str;

      *(token_vector + i) = str_copy(str ,word_length);

      printf("%s\n",*(token_vector + i));

      str = last_letter;

    }
  *(token_vector + length) = NULL;
  
  return token_vector;
}


/* Prints all tokens. */

void print_tokens(char **tokens)
{
  while(*tokens)
    {
      printf("%s\n", *tokens);

      tokens +=1;
    }
}


/* Prints all tokens. */

void free_tokens(char **tokens)
{
  for(int i = 0; *(tokens + i); i++)
    {
      free(*(tokens + i));
    }
  free(tokens);

  printf("Tokens were freed\n");
}
