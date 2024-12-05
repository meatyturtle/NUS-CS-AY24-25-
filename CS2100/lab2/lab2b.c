#include <stdio.h>
#include <string.h>
#include <ctype.h>

int hexToDecimal(char[], size_t);
int hexVal(char);

int main(void) {
	char hex[31];
	size_t len;

	printf("Enter up to 30 hexadecimal digits (eg. 10AB): ");
	fgets(hex, 31, stdin);
	len = strlen(hex);

	/* End-of-Line Check */
	if (hex[len-1] == '\n') {
		len = len - 1;
		hex[len] = '\0';
	}

	printf("You entered: %s\n", hex);
	printf("The value in decimal is: %d\n", hexToDecimal(hex, len));

	return 0;
}

int hexVal(char hex) {
	switch(toupper(hex)) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		case 'A': return 10;
		case 'B': return 11;
		case 'C': return 12;
		case 'D': return 13;
		case 'E': return 14;
		case 'F': return 15;
	}
	return 0;
}

int hexToDecimal(char hex[], size_t size) {
	// complete the function body
	int decimal = 0;
	int base = 1; // 16^0 = 1
	char *ptr = hex + size - 1; // point to the last character in hex array
	
	// Traverse the string from right to left using the pointer
    while (ptr >= hex) {
        decimal += hexVal(*ptr) * base;  // Convert hex digit to decimal and accumulate
        base *= 16;                      // Increase the base (power of 16)
        ptr--;                           // Move the pointer to the previous character
    }

    return decimal;  // Return the final decimal value
}
