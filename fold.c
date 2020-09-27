#include <stdio.h>

#define LINEWIDTH 20

int main(int argc, char * argv[]) {
	char * input = argv[1];
	int inputLength = 0;
	for(;input[inputLength] != 0; ++inputLength) ;	// Evaluate input string length

	int numLines = 0;
	for(int i = 0; input[i] != 0; i++) {
		if(i == (numLines + 1) * LINEWIDTH) {
			for(;input[i] == ' ' || input[i] == '\t'; --i) ;	// After this line, i is the index of the first nonblank character (after which should be inserted '\n')
			for(int rightShiftIndex = inputLength + 1; rightShiftIndex > i; --rightShiftIndex) input[rightShiftIndex] = input[rightShiftIndex - 1]; 
			input[i + 1] = '\n';
			++numLines;
		}
	}
	printf("%s\n", input);
}
