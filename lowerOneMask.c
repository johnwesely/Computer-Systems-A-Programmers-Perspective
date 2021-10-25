// Problem 2.68 from CS:APP
// lowerOneMask returns a mask with the lowest n bits set to one
// Must follow bitwise operator restrictions from page one of text
#include <stdio.h>
#include <stdlib.h>

/* Mask with least significant bits set to 1
 * n = 6 --> 0x3f, n = 17 --> 0x1ffff
 * Assume 1 <= n <= w */
int lowerOneMask(int n);

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("lowerOneMask takes two arguments, a 32 bit integer and the number of LSBs to mask\n");
    return 0;
  }

  int x = atoi(argv[1]);
  int n = atoi(argv[2]);
  printf("%d masked with %d least significant bits is %d\n", x, n, lowerOneMask(n) & x);

  return 1;
}

int lowerOneMask(int n) {
  int bitMasks[] = { 0, 0x1, 0x3, 0x7, 0xf, 
                   0x1f, 0x3f, 0x7f, 0xff,
                   0x1ff, 0x3ff, 0x7ff, 0xfff,
                   0x1fff, 0x3fff, 0x7fff, 0xffff,
                   0x1ffff, 0x3ffff, 0x7ffff, 0xfffff,
                   0x1fffff, 0x3fffff, 0x7fffff, 0xffffff,
                   0x1ffffff, 0x3ffffff, 0x7ffffff, 0xfffffff,
                   0x1fffffff, 0x3fffffff, 0xffffffff, -1 };

  return bitMasks[n];            
}

