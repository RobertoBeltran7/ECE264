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
  // This is the same function from HW20
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
  // In this function, in addition to the last assignment, you will also decode the rest of the file.
  // After getting the Huffman tree and number of character from the header file as in last assignment,
  // we will decode the rest the file as explained in README and will print each character in the `outfile`.
  // Thus, this function have 3 prints into the outfile - printing Huffman tree using Tree_print function
  // (same as in last assignment), then printing number of characters using PrintNumberChar
  // function (same as in previous assignment using) and then printing each decoded character into
  // the outfile.

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

  unsigned char whichbit = 0;
  unsigned char onebit = 0;
  unsigned char curbyte = 0;

  while (numChar != 0)
    {
      TreeNode * tn = root;
      while ((tn->left) != NULL)
	{
	  readBit(infptr, &onebit, &whichbit, &curbyte);
	  if (onebit == 0)
	    {
	      tn = tn ->left;
	    }
	  else
	    {
	      tn = tn->right;
	    }
	}
      fprintf(outfptr, "%c", tn->value);
      numChar--;
    }

  Tree_destroy(root);
  fclose(infptr);
  fclose(outfptr);
  return 1;

}
#endif
