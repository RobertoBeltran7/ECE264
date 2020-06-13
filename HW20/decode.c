// Modify this file at said locations
#include "decode.h"
#include "list.h"
#include "utility.h"


/*
------------------------------------------------------------------------------
You Can Modify below, Do Not modify above this
------------------------------------------------------------------------------
*/

#ifdef TEST_READHEADER

TreeNode * readHeader(FILE * infptr)
{
	/* This function should have the following logic
	 * The first bit is a command bit and it is always 1.
	 * If a command is 1, then the next 8 bits(for this assignment) are the value stored
	 	 in a leaf node. Create a tree node to store this value. Add this tree node to the
		 beginning of the linked list (basically, LinkedList is acting like a stack here).
     This tree node is a single-node tree.  
	 * If a command is 0 and the list has two or more nodes, then take the first two nodes from
	 	 the list, create a tree node as the parent. Add this parent node to the linked list.
   * If a command is 0 and the list has only one node, then the complete tree has been built.
	 * After the tree is completely built, then read one more bit. If this is not the last
	 	 (rightmost) bit of the byte, discard the remaining bits in the byte.
	*/
  int done = 0;
  unsigned char whichbit = 0;
  unsigned char curbyte = 0;
  unsigned char onebit = 0;
  ListNode * head = NULL;

  while (done == 0)
    {
      readBit(infptr, &onebit, &whichbit, &curbyte);
      if (onebit == 1)
	{
	  int bitcount;
	  unsigned char value = 0;
	  for (bitcount = 0; bitcount < 8; bitcount++)
	    {
	      value <<= 1;
	      readBit(infptr, &onebit, &whichbit, &curbyte);
	      value |= onebit;
	    }
	  TreeNode * tn = TreeNode_create(value, 0);
	  ListNode * ln = ListNode_create(tn);
	  head = List_insert(head, ln);
	}
      else
	{
	  if (head == NULL)
	    {
	      return NULL;
	    }
	  
	  if ((head->next) == NULL)
	    {
	      done = 1;
	    }
	  else
	    {
	      head = MergeListNode(head);
	    }
	}
    }

  TreeNode * root = head->tnptr;
  free(head);
  return root;
}

#endif


#ifdef TEST_DECODE

int decode(char * infile, char * outfile)
{
	// read the header from the input file  by calling readHeader function
	// the generated tree from the header generated should be printed in outfile
	// to print the tree into the file use Tree_print function given to you.
  // After reading the header till codebook, read the next 4 bytes from the header,
  // these 4 bytes represent number of characters in the file.
  // Print the number of characters obtained by using the PrintNumberChar function
	// Do not use your own print functions
	// free up the memory
  FILE * infptr = fopen(infile, "r");
  if (infptr == NULL)
    {
      return 0;
    }

  FILE * outfptr = fopen(outfile, "w");
  
  TreeNode * root = readHeader(infptr);
  Tree_print(root, outfptr);
  
  unsigned int numChar = 0;
  fread(&numChar, sizeof(unsigned int), 1, infptr);
  PrintNumberChar(numChar, outfptr);

  unsigned char newline;
  fread(&newline, sizeof(unsigned char), 1, infptr);
  if (newline != '\n')
    {
      printf("ERROR!\n");
    }

  Tree_destroy(root);
  fclose(infptr);
  fclose(outfptr);
  return 1;
}
#endif
