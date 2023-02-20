#include <stdio.h>

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

  if( *(word) == '\0' || space_char(*word)== 1)

    return word-=1;

  else if( *(word+1) == '\0')

    return word-=1;

  return (word_terminator((word + 1)));

}



/* Counts the number of words in the string argument. */

int count_words(char *str)

{

  if(*str == '\0')

    return 0;

  if(*str == NULL)

    return 0;

  char *first_char = word_start(str);

  char *last_char = word_terminator(first_char) + 1;

  printf("first letter is: %c and last letter is: %c\n", *first_char, *(last_char-1));

  return 1 + count_words(last_char + 1 );

}
