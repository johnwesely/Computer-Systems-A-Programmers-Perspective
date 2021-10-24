// practice problem 2.42 from CS:APP
// write a function div16 that preforms division by 16 on twos complement numbers
// using only bit shifts and addition 
#include <stdio.h>
#include <stdlib.h>

int div16(int x);

int main(void) {
	printf("42 / 16 = %d\n", div16(42));
	printf("64 / 16 = %d\n", div16(64));
	printf("69 / 16 = %d\n", div16(69));
	printf("-69 / 16 = %d\n", div16(-69));

	return 0;
}

int div16(int x) {
	int bias = (x>>31 & 0xF);
	x = x + bias; 
	return x >> 4;
}
