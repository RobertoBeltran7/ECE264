#include "hw10.h"
//modify the main() function
#ifdef TEST_MAINFUNC

int main(int argc, char **argv){
  // check the arguments
  if (argc != 3)
    {
      fprintf(stderr, "Wrong arguments\n");
      return EXIT_FAILURE;
    }
  // open the BMP file
  
  if (BMP_Open(argv[1]) == 0)
    {
      fprintf(stderr, "Error opening BMP file\n");
      return EXIT_FAILURE;
    }

  // convert to gray scale
	// check for error in converting to gray scale
  if (ImgToGray(BMP_Open(argv[1])) == 0)
    {
      return EXIT_FAILURE;
    }

	// write the gray image to file
  BMP_Write(argv[2], ImgToGray(BMP_Open(argv[1])));
	// free all the images
  BMP_Free(ImgToGray(BMP_Open(argv[1])));
	return EXIT_SUCCESS;
}

#endif
