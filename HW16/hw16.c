/****************** Modify this file at specified place *************************/
#include <stdio.h>
#include <stdlib.h>
#include "hw16.h"


/********** Do Not modify the file above this line, you can modify below ***********/
#ifdef TEST_FREETREE
// FreeBinaryTree
// This function frees up the memory from the root node

void FreeBinaryTree(treeNode *root)
{
  if (root == NULL)
    {
      return;
    }
  FreeBinaryTree(root->leftChild);
  FreeBinaryTree(root->rightChild);

  free(root);
}

#endif

#ifdef TEST_SEARCH
// This function recursively searches for a given value in a tree
// and returns the node which has that value
treeNode* search(treeNode * tn, int value)
{
  if (tn == NULL)
    {
      return NULL;
    }
  else if (value == (tn->value))
    {
      return tn;
    }
  else
    {
      if(search(tn->leftChild, value) != NULL)
	{
	  return search(tn->leftChild, value);
	}
      else
	return search(tn->rightChild, value);
    }

}

#endif


#ifdef TEST_SUBTREE
/* This function checks if `needle` is subtree of `haystack`. By subtree, it means that all the values of
*  `needle` are in `haystack`. For example in Example 1 (README),
*  treeNode with value 10 in Tree1 is subtree of Tree2 but Tree1 is not subtree of Tree2 . Please note this function is different from `isContained`,
* as it recursively compares two Trees/subtrees from the treeNodes given as input.
* It is consistent with  strstr function in C i.e. "strstr(const char \*haystack, const char \*needle)"
*/
bool isSubTree(treeNode* haystack, treeNode *needle)
{
  if (haystack == NULL && needle == NULL)
    {
      return true;
    }
  else if (haystack == NULL || needle == NULL)
    {
      return false;
    }
  else if ((haystack->value) != (needle->value))
    {
      return false;
    }
  else
    {
      if (!(isSubTree(haystack->leftChild, needle->leftChild)))
	return isSubTree(haystack->leftChild, needle->leftChild);
      else
	return isSubTree(haystack->rightChild, needle->rightChild);
    }

}
#endif



#ifdef TEST_CONTAINED
// returns true if needle is contained in haystack
// returns false if needle is not contained in haystack
// needle and haystack may NOT be binary search tree
// Please note that order of arguments are important
// It is consistent with  strstr function in C i.e.
// "strstr(const char \*haystack, const char \*needle)"
bool isContained(treeNode * haystack, treeNode * needle)
{
  treeNode * haystck_find_needle = search(haystack, needle->value);

  if (haystck_find_needle == NULL)
    return false;
  
  bool contains_Tree = isSubTree(haystck_find_needle, needle);
  
  if (!contains_Tree)
    return false;

  return true;
}


#endif
