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



  if(list->root == NULL)

    {

      new_Node->id = 1;

      new_Node->str = str;



      list->root  = new_Node;

      new_Node->next = NULL;



      printf("the ID is %d, the string is: %s\n", new_Node->id, new_Node->str);

    }


  else{



    Item *current_Node = list->root;





    printf("hello %s\n", str);

    printf("hello %s\n", list->root->str);



    // printf("the root is Id is %d, root string is: %s\n", list->root->id, list->root->str);



    int id_identifier = 2;



    while(current_Node->next !=NULL)

      {

	id_identifier +=1;



	current_Node = current_Node->next;

      }



    printf("the initial root is Id is %d, root string is: %s\n", list->root->id, list->root->str);





    new_Node->id = id_identifier;





    new_Node->str = str;



    printf("the node  is Id is %d, node string is: %s\n", new_Node->id, new_Node->str);



    return;



    current_Node->next = new_Node;



    printf("Id is %d, string is: %s\n", new_Node->id, new_Node->str);



    new_Node->next = NULL;



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

	  printf("id found %d\n", current_Node->id);

	  printf("string is: %s\n", current_Node->str);

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



  while(current_Node != NULL);

  {

    printf("ID is: %d and string is: %s\n" ,current_Node->id, current_Node->str);

    current_Node = current_Node->next;

  }

}
