/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw13.h"

#ifdef LINKEDLIST
// Do not modify this function, we are using this within ifdef block for
// ease of grading.
void LinkedListPrint(Node * * source)
{

	Node *temp = * source;

	while(temp!=NULL)
	{
		if(temp->next!=NULL)
		{
			printf("%d,",temp->value);
		}
		else
		{
			printf("%d",temp->value);
		}
		temp=temp->next;
	}
	printf("\n");
}
#endif


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_CREATENODE

Node * CreateNode(int val)
//val: value of the element of the node to be created
{
	// Define a new variable of type Node
	// Initialize "next", and "value" appropriately
  Node * node = malloc(sizeof(Node));
  node->value = val;
  node->next = NULL;
	//return the newNode
  return node;
}
#endif

#ifdef TEST_LINKEDLISTCREATE
//head: the head of the singly linkedlist.
//len: the length of the array.
//arr: the array with the contents of the input file.

//This function will create and initialize the singly linkedlist with length=len,

void LinkedListCreate(Node * * source, int len, int* arr)
{
	// This function is similar to the one in HW12.
	// Tip: use CreateNode(arr[index])
  Node * head;
  Node * new = CreateNode(arr[0]);
  head = new;
  *source = head;
  for (int i = 1; i < len; i++)
    {
      new = CreateNode(arr[i]);
      head->next = new;
      head = head->next;
    }
}
#endif


#ifdef TEST_SPLIT
// source is the Node corresponding to the head of the list
// head1 is the list corresponding upper half of the list. (After Partition)
// head2 is the list corresponding lower half of the list. (After Partition)
void SplitList(Node* source, Node** head1, Node** head2) 
{
  // Find the mid point of the list.
	
		//in case of an even number of nodes, mid point will be floor(<num_elements>/2)
			//Example: 1,2,3,4
				// The list should split into 1,2 and 3,4
  
		//in case of an odd number of nodes, mid point will be <num_elements>/2
			//Example: 1,2,3,4,5
  // The list should split into 1,2,3 and 4,5
  Node * length = source;
  int count = 1;
  int midpoint;
  while (length->next != NULL)
    {
      length = length->next;
      count++;
    }

  
   midpoint = count-count/2;
  
  
  *head1 = source;

  Node * tmp = source;
  for (int i = 1; i < midpoint; i++)
    {
      tmp = tmp->next;
    }

  *head2 = tmp->next;
  tmp->next= NULL;
    	// Tip: head1 will point to the source node.
	// Tip: head2 will point to the mid-point of the list.
	// Tip: Ensure you break the link between the sub-lists.
} 
#endif


#ifdef TEST_DIV
void Divide(Node** source) 
{ 
	// Declare a node, to hold the current head of source list.
  Node * currhead = *source;
	
	// Declare nodes, to hold the two the heads of the two sub-lists.
  Node * headupper;
  Node * headlower;
	// Check for the base case -- length 0 or 1
		// if so, return;
  if (currhead == NULL || currhead->next == NULL)
    {
      return;
    }
 
	  
	// Use SplitList(...) to partition the list into sub lists.
  SplitList(currhead, &headupper, &headlower);
	// Use LinkedListPrint(...); to print the upper sub-list.
	// Use LinkedListPrint(...); to print the lower sub-list
		// DO NOT USE YOUR OWN PRINT FUNCTION.
  LinkedListPrint(&headupper);
  LinkedListPrint(&headlower);
	
	 // Recursively Divide(...) both sub-lists, to find their respective mid-points
	 // till only one or no elements are left in the sub-lists.
  Divide(&headupper);
  Divide(&headlower);
} 
#endif

