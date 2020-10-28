#include <stdio.h>

#define MAXLENGTH 500

char * copyToLength(char *, char *, int *);


int main(int argc, char * argv[]) {
	char LINEWIDTH = 12;
	if(argc == 3) {
		LINEWIDTH = 0;
		for(int i = 0; *(argv[2] + i) != 0; ++i) {
			LINEWIDTH *= 10;
			LINEWIDTH += *(argv[2] + i) - 48;
		}
	}
	int inputLength;
	char input[MAXLENGTH];
	copyToLength(argv[1], input, &inputLength);
	
	int lineStartIndex = 0;
	int numLines = 0;
	for(int i = 0; input[i] != 0; i++) {
		if(i - lineStartIndex >= LINEWIDTH) {
			// Decrement i while input[i] isn't a blank char preceded by a non-blank char
			while((input[i - 1] == ' ' || input[i - 1] == '\t') || (input[i] != ' ' && input[i] != '\t')) --i;	// After this line, i is the index of the last blank character before any spaces (after which should be inserted '\n')
			input[i] = '\n';
			lineStartIndex = i + 1;
			int lastBlank = i;
			while(input[lastBlank + 1] == ' ' || input[lastBlank + 1] == '\t') ++lastBlank;
			int numExtraSpaces;
			if(lastBlank > i) {
				numExtraSpaces = lastBlank - i;
				for(int rightShiftIndex = i + 1; rightShiftIndex < inputLength - numExtraSpaces; ++rightShiftIndex) {
					input[rightShiftIndex] = input[rightShiftIndex + numExtraSpaces];
				}
				input[inputLength - numExtraSpaces] = 0;
				inputLength -= numExtraSpaces;
			}
			++numLines;
		}
	}
	printf("\n%s\n\n", input);
}

char * copyToLength(char * array, char * out, int * outputLength) {
	int index  = 0;
	for(; array[index] != 0; ++index) out[index] = array[index];
	out[index] = 0;
	*outputLength = index;
	return out;
}
