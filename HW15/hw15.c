/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw15.h"

#ifdef LINKEDLIST
// Do not modify this function.
void LinkedListPrint(Node * head)
{

	Node *temp = head;

	while(temp!=NULL)
	{
		if(temp->next!=NULL)
		{
			printf("%d,",temp->value);
		}
		else
		{
			printf("%d\n",temp->value);
		}
		temp=temp->next;
	}
}
#endif


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int val)
{
	/*
	Create a new Node with `value` set to `val`. Set `next` to NULL.
	*/
  Node * node = malloc(sizeof(Node));
  node->value = val;
  node->next = NULL;
  
  return node;
}
#endif

#ifdef TEST_LINKEDLISTCREATE

void LinkedListCreate(Node ** head, char* name)
{
	/*
	Create a linked list from the input file referenced by `name`.
	*/  
  FILE * fptr = fopen(name, "r");
  int val;
  int cnt;
  
    while(fscanf(fptr, "%d\n", &val)==1)
    {
      cnt++;
    }

  fseek(fptr,0,SEEK_SET);
  fscanf(fptr, "%d\n", &val);
  Node * new = CreateNode(val);
  Node * head2 = new;
  *head = head2;
   
  while(fscanf(fptr, "%d\n", &val)==1)
    {
      new = CreateNode(val);
      head2->next = new;
      head2 = head2->next;      
    }

    fclose(fptr);
}
#endif
#ifdef TEST_REMOVED
//This function will remove repetitions of a linked list value.

void RemoveDuplicate(Node *headRef)
{
	/*
	This function will remove repetitions from the linked list referenced by headRef.
	Each time we check for a new Node in the linked list, we will check if it is distinct from
	the Nodes already present in the list ( upto the previous Node).
	So for each occurrence after its first, we will be deleting that node.
	To delete a node: we will map the next Node of the previous Node to the Node after the current Node.
	Print the linked list after all repetitions have been removed. Use the function given to you for priniting.
	*/

  Node * ptr = headRef;
  Node * search;
  Node * node_delete;

  if (ptr == NULL)
    return;
  
  while (ptr != NULL && (ptr->next) != NULL)
    {
      search = ptr;
      while (search != NULL && (search->next) != NULL)
	{
	  if ((ptr -> value) == (search->next)->value)
	    {
	      node_delete = search->next;
	      search->next = (search->next)->next;
	      free(node_delete);	      
	    }
	  else
	    {
	      search = search->next;
	    }
	}
      ptr = ptr->next;
    }
  LinkedListPrint(headRef);
}
#endif
