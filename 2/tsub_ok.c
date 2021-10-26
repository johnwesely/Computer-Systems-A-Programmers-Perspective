/* Homework 2.74 from CS:APP
 * write a function that returns 1 if x - y does not result in overflow */

#include <stdio.h>
#include <stdlib.h>

int tsub_ok(int x, int y);

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("tsub_ok takes two command line arguments\n");
		return 1;
	}

	int x = atoi(argv[1]);
	int y = atoi(argv[2]);	

	if(tsub_ok(x, y)) {
		printf("x-y does not result in overflow\n");
	}	
	else {
		printf("x-y does result in overflow\n");
	}
			
	return 1;
}

int tsub_ok(int x, int y) {
	// if x is positive and y is negative check for negative overflow 
	if (x >= 0 && y < 0 && x - y < 0) return 0;
	// if x is negative and y positive check for positive overflow
	if (x <= 0 && y > 0 && x - y > 0) return 0;
	// no risk of overflow in other situations 
	return 1;
}
