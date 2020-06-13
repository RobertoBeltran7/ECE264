// ***
// *** Please modify this file, as indicated
// ***

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "vector.h"

/*-------------------------------MODIFY BELOW THIS LINE-------------------------------*/

#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
    // input file will be specified from the terminal - test files are made available in inputs folder

    // check for missing input file/output file, if so, "return EXIT_FAILURE;"
  if (argc < 3)
    {
      return EXIT_FAILURE;
    }
    // store the input file name in a variable, from argv[1]. For example, char* in_file = argv[1];
  char* input_file = argv[1];
    // store the output file name in a variable, from argv[2]. For example, char* out_file = argv[2];
  char* output_file = argv[2];

    // call numberOfElements(in_file) to obtain the number of elements in the file.
  int count = numberOfElements(input_file);

    // allocate memory to store the numbers (initialize an array of structures)
            // check for malloc fail, if so, "return EXIT_FAILURE;" 
  Vector * arr;
  arr = malloc(sizeof(Vector) * count);
  if (arr == NULL)
    {
      return EXIT_FAILURE;
    }
  
  
    //call the fillVector(vector, count, in_file); and store the values from the file in the array of strucures.
   fillVector(arr, count, input_file);

    //Use qsort() function, after defining the comparator() function.
            //ENSURE THE COMPARATOR FUNCTION IS USED TO SORT THE ARRAY OF STRUCTURES W.R.T. THE STRUCTURE VARIABLE "x".
  qsort(arr, count, sizeof(Vector), cmp);
  
  output_file = argv[2];

    //call the writeFile(vector,count, out_file); to save the sorted vector into the file.
  writeFile(arr, count, output_file);
  free(arr);

  return EXIT_SUCCESS;
}
#endif
