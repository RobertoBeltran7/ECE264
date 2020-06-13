/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw13.h"

/****************** DO NOT Modify this file above this line *************************/

// Modify the following function
#ifdef TEST_MAIN

int main(int argc, char **argv)
{
	// if argc is less than 2 then, return EXIT_FAILURE
	// input file is specified through the Makefile.
  int count = 0;
  int val;
  
  if (argc < 2)
    {
      fprintf(stderr, "Need at least 2 arguments\n");
      return EXIT_FAILURE;
    }

	// open file to read
  FILE * fpin = fopen(argv[1], "r");
	// check for fopen fail. If so, return EXIT_FAILURE
  if (fpin == NULL)
    {
      fprintf(stderr, "fopen failed\n");
      return EXIT_FAILURE;
    }	
	// count the number of integers in the file.
  while ((fscanf(fpin, "%d", &val))==1)
    {
      count++;
    }

	// allocate memory to store the numbers
  int * array = malloc(sizeof(int)*count);
	
	// check for malloc fail, if so, return EXIT_FAILURE
  if (array == NULL)
    {
      return EXIT_FAILURE;
    }	
	// use fscanf to read the file, and store its contents into an array.
  int i = 0;
  fseek(fpin, 0, SEEK_SET);
  while ((fscanf(fpin, "%d\n", &val)) == 1)
    {
      array[i] = val;
      i++;
    }
	// create head node to store the head of the linked list.
  Node * head;
	// call the appropriate function to create the rest of the linked list, with the values of the array.
  LinkedListCreate(&head, count, array);
	// Divide is a function to break the lists into smaller sublists.
		// You are supposed to find the mid-point of the list, and then break the list into two lists.
		// Then the sub-lists are broken down further into smaller sub-lists.
		// Refer to the example in the README
  Divide(&head);

	// Tip: check for memory errors.
  free(array);
  free(head);
  fclose(fpin);

  return EXIT_SUCCESS;
}

#endif
