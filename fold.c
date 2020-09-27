#include <stdio.h>

#define LINEWIDTH 20
#define MAXLENGTH 500

char * copyToLength(char *, char *, int *);

int main(int argc, char * argv[]) {
	int inputLength;
	char input[MAXLENGTH];
	copyToLength(argv[1], input, &inputLength);
	
	int numLines = 0;
	for(int i = 0; input[i] != 0; i++) {
		if(i == (numLines + 1) * LINEWIDTH) {
			while(input[i] != ' ' && input[i] != '\t') --i;	// After this line, i is the index of the last nonblank character before any spaces (after which should be inserted '\n')
			input[i]='\n';
			int lastBlank = i;
			while(input[lastBlank + 1] == ' ' || input[lastBlank + 1] == 't') lastBlank++;
			if(lastBlank > i) {
				for(int rightShiftIndex = inputLength - (lastBlank - i); rightShiftIndex > i; --rightShiftIndex) input[rightShiftIndex] = input[rightShiftIndex + (lastBlank - i)];
			 	for(int setNullIndex = inputLength - (lastBlank - i) + 1; setNullIndex < inputLength; ++setNullIndex) input[setNullIndex] = 0;
				inputLength -= (lastblank - i)
			}
			++numLines;
		}
	}
	printf("%s\n", input);
}

char * copyToLength(char * array, char * out, int * outputLength) {
	int index  = 0;
	for(; array[index] != 0; ++index) out[index] = array[index];
	out[index] = 0;
	*outputLength = index;
	//printf("outputLength: %d\n", *outputLength);
	return out;
}
