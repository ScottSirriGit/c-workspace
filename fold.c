#include <stdio.h>

#define LINEWIDTH 20
#define MAXLENGTH 500

int main(int argc, char * argv[]) {
	int inputLength;
	char * input = copyToLength(argv[1], &inputLength, MAXLENGTH);

	int numLines = 0;
	for(int i = 0; input[i] != 0; i++) {
		if(i == (numLines + 1) * LINEWIDTH) {
			for(;input[i] == ' ' || input[i] == '\t'; --i) ;	// After this line, i is the index of the last nonblank character before any spaces (after which should be inserted '\n')
			for(int rightShiftIndex = inputLength + 1; rightShiftIndex > i; --rightShiftIndex) input[rightShiftIndex] = input[rightShiftIndex - 1]; 
			input[i + 1] = '\n';
			++numLines;
		}
	}
	printf("%s\n", input);
}

int * copyToLength(char * array, int * outputLength, int maxLength) {
	char * out[maxLength];
	int index  = 0;
	for(; array[index] != 0; ++index) out[index] = array[index];
	out[index] = 0;
	*outputLength = index;
	return out;
}
