// Homework 2.61 from CS:APP
// write C expressions that evaluate to 1 when the following conditions are true, and to 0 when they are false
// Assume x is of type int
// A. any bit of x equals 1
// B. any bit of x equals 0
// C. Any bit in the least significant byte equals 1.
// D. Any bit in the most significant byte equals 0.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Test Conditions
#define TC1 1
#define TC2 2
#define TC3 0
#define TC4 -1
#define TC5 0x7fefffff

#define LSB(X) (X & 15)
#define MSB(X) ((X >> 28) & 15)

int A(int x);
int B(int x);
int C(int x);
int D(int x);

int main(void) {
	printf("A(1) = %d\n", A(TC1));
	printf("A(0) = %d\n", A(TC3));
	printf("A(0X7fefffff) = %d\n", A(TC5));
	printf("B(1) = %d\n", B(TC1));
	printf("B(0xffffffff) = %d\n", B(TC4));
	printf("B(0x7fefffff) = %d\n", B(TC5));
	printf("C(1) = %d\n", C(TC1));
	printf("C(0) = %d\n", C(TC3));
	printf("C(16) = %d\n", C(16));
	printf("D(0) = %d\n", D(TC3));
	printf("D(1) = %d\n", D(TC1));
	printf("D(-1) = %d\n", D(-1));
	printf("D(-268435456) = %d\n", D(-268435456));

	return 0;
}	

int A(int x) {
	return ((x | (x + INT_MAX)) >> 31) & 1;
}

int B(int x) {
	return ~((~(x + 1) & ~(x + INT_MAX)) >> 31) & 1;
}

int C(int x) {
	return (LSB(x) | (LSB(x) + 7) >> 3) & 1;
}

int D(int x) {
	return ~((~(MSB(x) + 1) & ~(MSB(x) + 7)) >> 4) & 1;	
}

	
