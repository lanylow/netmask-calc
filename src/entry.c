#include <stdio.h>
#include <stdlib.h>

#define MAX_MASK_LENGTH 32
#define MAX_MASK_PATTERN 0xFFFFFFFF

int get_octet(int mask, int octet) {
  return (mask >> (32 - (octet * 8))) & 0xFF;
}

int main(int argc, char** argv) {
  if (*++argv == NULL) {
    printf("You need to provide length of the mask as the first argument.\n");
    return 1;
  }

  int mask_length = atoi(*argv);

  if (mask_length > 32 || mask_length < 0) {
    printf("Mask length has to be a number between 0 and 32.\n");
    return 1;
  }

  int mask = MAX_MASK_PATTERN << (MAX_MASK_LENGTH - mask_length);

  printf("Mask with length of %d bits is: %d.%d.%d.%d\n", 
      mask_length, 
      get_octet(mask, 1), 
      get_octet(mask, 2), 
      get_octet(mask, 3), 
      get_octet(mask, 4));

  return 0;
}
