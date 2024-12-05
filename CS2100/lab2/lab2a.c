#include <stdio.h>

void display(int);

int main() {
	int ageArray[] = { 2, 15, 4, 5 };
	display(ageArray[0]);
	int sizeArray = sizeof(ageArray) / sizeof(ageArray[0]);
	printf("Size of the array is %d\n", sizeArray);
}

void display(int age) {
	printf("%d\n", age);
}
