#include "history.h"

#include "malloc.h"

#include <stdio.h>

#include <stdlib.h>

#include "tokenizer.h"



/* Initialize the linked list to keep the history. */

List* init_history()

{

  List *list = (List*)malloc(sizeof(List));

  list->root = NULL;

  return list;

}


/* Add a history item to the end of the list.

   List* list - the linked list

   char* str - the string to store

*/



void add_history(List *list, char *str)

{



  Item *new_Node = (Item*)malloc(sizeof(Item));

  new_Node->next = NULL;
  
  int length = 0;

  while(str[length] != '\0')
    {
      length++;
    }

  new_Node->str = str_copy(str, length);

  
  if(list->root == NULL)
    {
      list->root = new_Node;
      new_Node->id = 1;
    }
  else{

    Item *current_Node = list->root;

    int id_identifier = 2;

    while(current_Node->next !=NULL)
      {

	id_identifier +=1;
	
       	current_Node = current_Node->next;
      }

    new_Node->id = id_identifier;

    current_Node->next = new_Node;
  }

}

/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char *get_history(List *list, int id)
{

  Item *current_Node = list->root;

  while(current_Node != NULL)
    {
      if(current_Node->id == id)
	{

	  printf("id (%d) found and corresponding string is (%s)\n", current_Node->id, current_Node->str);
	  return current_Node->str;

	}
      current_Node = current_Node->next;
    }

  printf("ID not found\n");
  return 0;

}

/*Print the entire contents of the list. */

void print_history(List *list)
{

  Item *current_Node = list->root;

  if (current_Node == NULL)
    {

      printf("list is empty\n");

    }
  else
    {

      while(current_Node != NULL)
	{
	  printf("ID is: %d and string is: %s\n" ,current_Node->id, current_Node->str);

	  current_Node = current_Node->next;
	}
    }
}



/*Free the history list and the strings it references. */

void free_history(List *list)
{

  Item *current_Node = list->root;

  while(current_Node != NULL)
    {

      Item *temp_Node = current_Node->next;

      free(current_Node);

      current_Node = temp_Node;
    }
  free(list);
}

