// ***
// *** Please modify this file, as indicated
// ***

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "sort.h"


void printArray(int * arr, int size)
{
  int ind;
  for (ind = 0; ind < size; ind ++)
    {
      fprintf(stdout, "%d\n", arr[ind]);
    }
}



//============================ONLY EDIT BELOW THIS COMMENT============================//
#ifdef TEST_COMP
int comparator(const void *a, const void *b) 
{ 
    //type cast both the parameters to the type const int*) a: 
	//FOR EXAMPLE: const int* ia = (const int *) a;
   
    	//if parameter2 > parameter1; return -1
	//if parameter2 == parameter1; return 0
	//if parameter2 < parameter1; return 1

  const int* ptr1 = (const int *) a;
  const int* ptr2 = (const int *) b;

  const int param1 = * ptr1;
  const int param2 = * ptr2;

  if (param1 < param2)
    {
      return -1;
    }
  if (param1 == param2)
    {
      return 0;
    }

  return 1;
   
} 
#endif


#ifdef TEST_COUNT
int countFromFile(char* file_name)
{
  // open file to read
  FILE * file_pointer = fopen(file_name, "r");
  if (file_pointer == NULL)
    {
      fprintf(stderr, "fopen %s fails\n", file_name);
      return EXIT_FAILURE;
    }

  int value;
  int count = 0;
  while (fscanf(file_pointer, "%d", &value) == 1)
    {
      count++;
    }

  fclose(file_pointer);

  return count;
  // count the number of integers using a loop
  // at the end of the loop close file_pointer

}
#endif

#ifdef TEST_FILL
void fillArray(int* arr, int count, char* file_name)
{
  // open file to read
  FILE * file_pointer = fopen(file_name, "r");
  
  //How to read the file?
	// run a loop, from index = 0 to "count", and use: fscanf(file_pointer, "%d", &arr[index]);
	// at the end of the loop close file_pointer

  int index;

  for (index = 0; index < count; index++)
    {
      fscanf(file_pointer, "%d", &arr[index]);
    }

  fclose(file_pointer);
  
}
#endif

#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
  // input file will be specified from the terminal - test files are made available in inputs folder

  // check for missing input file, if so, "return EXIT_FAILURE;"
  if (argc != 2)
    {
      return EXIT_FAILURE;
    }

  char* file_name = argv[1];
  // use argv[1] to save the file name, you will use this file name to call the countFromFile(), and fillArray() functions
      //FOR EXAMPLE: char* file_name = argv[1];
  
  // call the countFromFile(file_name); and store the number of elements in the file.
  int count = countFromFile(file_name);
  // allocate memory to store the numbers (initialize an array)
  int * arr;
  arr = malloc(sizeof(int) * count);
  if (arr == NULL)
    {
      return EXIT_FAILURE;
    }
  // check for malloc fail, if so, "return EXIT_FAILURE;"
  
  // call the fillArray(arr, count, file_name); and store the values from the file in the array.
  fillArray(arr, count, file_name);
  // Use qsort() function, after defining the comparator() function - "qsort (arr, count, sizeof(int), comparator);"
  qsort(arr, count, sizeof(int), comparator);
  // call the printArray() function provided to you.
  printArray(arr, count);
  free (arr);
  return EXIT_SUCCESS;
}
#endif

