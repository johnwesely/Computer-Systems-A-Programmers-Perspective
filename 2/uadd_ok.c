#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int uadd_ok(unsigned x, unsigned y);

int main(void) {
	printf("adding 1 and 2 is %d\n", uadd_ok(1,2));
	printf("adding 1 and UINT_MAX is %d\n", uadd_ok(1, UINT_MAX));
	printf("adding 4200000000 and 100000000 is %d\n", uadd_ok(4200000000, 100000000));
}

int uadd_ok(unsigned x, unsigned y) {
	unsigned maxX = UINT_MAX - x;
	unsigned maxY = UINT_MAX - y;

	return y < maxX && x < maxY;
}

