#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

//***** YOU NEED TO MODIFY main() FUNCTION BELOW *******//
#ifdef TEST_MAIN
void Free_Tree(treeNode * n);

void Free_Tree(treeNode * n)
{
  if (n == NULL)
    {
      return;
    }
  Free_Tree(n->leftChild);
  Free_Tree(n->rightChild);

  free(n);
}

int main(int argc, char **argv)
{

	/*
	 *  1. Check for number of arguments. If less than 2, do not proceed further.
	 *
	 *  2. The program should create a binary search tree from the numbers in input file. The input file 
	 *  	also contains a number for search query at the end. 
	 *
	 *  3. The input file has one number per line. If there are 'n' lines in the file, the first n-1 numbers 
	 *  	are the elements of the binary search tree and the nth line is the search query. 
	 *  	NOTE: n is not given to you. 
	 *
	 *  4. Create an array of the first n-1 numbers and store the last number in a variable.
	 *
	 *  5. Create a Binary Search Tree. It takes four arguments:
	 *  	1. The array
	 *  	2. the first element of the array
	 *  	3. start index (index of first element of the array)
	 *  	4. end index ( index of last element of the array)
	 *
	 *  6. Print the created tree in Inorder fashion. Quick check if you have created the tree right: the output of
	 *  	will be a sorted array of numbers. 
	 *
	 *  7. Compute the distance of the 'search query' node by passing it to the function.
	 *
	 *  8. Use PrintDistance() function to print the distance of the node from the root node in the right format.
	 *
	 *  9. Free all memory.
	 *
	 */
  if (argc < 2)
    {
      fprintf(stderr,"Need more arguments\n");
      return EXIT_FAILURE;
    }

  FILE * fptr = fopen(argv[1], "r");


  int val;
  int len = 0;
  while(fscanf(fptr, "%d", &val) == 1)
    {
      len++;
    }
  int * arr = malloc(sizeof(int)*len);
  if (arr == NULL)
    {
      fclose(fptr);
      return EXIT_FAILURE;
    }
  fseek(fptr, 0, SEEK_SET);
  for (int cnt = 0; cnt < len - 1; cnt++)
    {
      fscanf(fptr, "%d", &val);
      arr[cnt] = val;
    }
  
  int query;
  fscanf(fptr, "%d", &query);
  int root = arr[0];
  treeNode * bst;
  bst = CreateBST(arr, root, 0, len - 2);

  BinaryTreeInOrderPrint(bst);
  
  int dist = FindDistance(bst, query, 0);

  PrintDistance(dist);

  
  fclose(fptr);
  free(arr);
  Free_Tree(bst);
  return EXIT_SUCCESS;
  


}
#endif
