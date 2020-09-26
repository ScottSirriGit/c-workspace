#include <stdio.h>

#define MAXLENGTH 1000
int TABLENGTH = 9;
#define DBGSTR(y) printf("char %d\n", y);

int replaceTab(int document[], int * documentLength, int tabIndex);

int main(int argc, char * argv[]) {
	extern int TABLENGTH;
	if(argc > 1) TABLENGTH = *argv[1];
	
	

	int document[MAXLENGTH];
	int character;
	int documentLength = 0;
	while((character = getchar()) != EOF) {
		document[documentLength++] = character;	// Collect input data
	}

	int result;
	for(int charIndex = 0; document[charIndex] != '\0'; ++charIndex) {
		if(document[charIndex] == '\t') {
			if((result = replaceTab(document, &documentLength, charIndex)) != 0) break;	// Replace tab, break if overflowing document MAXLENGTH
		}
	}
	
	if(result != 0) printf("Overflowed document MAXLENGTH\n");

	for(int documentIndex = 0; documentIndex < documentLength; ++documentIndex) putchar((char) document[documentIndex]);
}

int replaceTab(int document[], int * documentLength, int tabIndex) {
	extern int TABLENGTH;
	printf("TABLENGTH: %d", TABLENGTH);
	int var = 3;
	for(int rightShiftIndex = *documentLength + var - 1; rightShiftIndex > tabIndex + var - 1; --rightShiftIndex) {
		if(rightShiftIndex > MAXLENGTH) return 1;	// If overflowing document MAXLENGTH, return error flag
		document[rightShiftIndex] = document[rightShiftIndex - var + 1];	// Shift document characters after (tabIndex + TABLENGTH) to the right by one TABLENGTH
	}
	
	for(int documentIndex = tabIndex; documentIndex < tabIndex + var; ++documentIndex) {
		document[documentIndex] = ' ';
	}
	
	(*documentLength) += (var - 1);
	
	return 0;
}
