#include <stdio.h>
#include <stdlin.h>
#include "history.h"
#include "tokenizer.h"

#define MAX 100

// UI interface
int main()
{


  char str[MAX];


  // for history list (linked list)

  List *history = inint_history();
  int id_identifier;
  char sequence_command[MAX];

  // UI
  while(1)
    {
      printf("Type (1) to write sentence string,Type (2) to get a certain history,Type (3) to view history, Type (4) to quit\n$ ");

      char options[MAX]; // Users choices

      fgets(options, MAX, stdin);

      fflush(stdin);

      switch(options[0])
	{
	case '1':
	  printf("Enter sentence string:\n$");

	  fgets(str, MAX, stdin);

	  printf("%s\n", str);

	  char **token_vector = tokenize(str);

	  print_tokens(token_vector);

	  add_history(history, str);

	  free_tokens(token_vector);

	  break;
	  
	case '2':
	  printf("Please enter sequence number by using command (!#)\n");

	  fgets(sequence_command, MAX, stdin);

	  id_identifier = atoi(sequence_command + 1);

	  char *found_string = get_history(history, id_identifier);

	  break;

	case '3':
	  printf("Overall history\n");

	  print_history(history);

	  break;
       
	case '4':
	  fflush(stdin);

	  goto done:
	 
	default:
	  printf("PLease select a valid option\n");
	  break;
	}
      fflush(stdin);
    }

 done:
  printf("History freed\n");

  free_history(history);

  printf("You exited the program! Goodbye");
  return 0;
  

  
}
