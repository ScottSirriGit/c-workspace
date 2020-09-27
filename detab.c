#include <stdio.h>

#define MAXLENGTH 1000	// Max length of document accepted
int TABLENGTH = 4;	// # spaces substituted for tab

int replaceTab(int document[], int * documentLength, int tabIndex);

int main(int argc, char * argv[]) {
	extern int TABLENGTH;	// I know, but it's good practice

	if(argc > 1) {	// Parse any CML arguments passed to declare the TABLENGTH
		TABLENGTH = 0;
		for(char * i = argv[1]; *i != 0; ++i) {
			TABLENGTH *= 10;
			TABLENGTH += (*i - 48);
		}
	}
	
	// Declarations
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
	for(int rightShiftIndex = *documentLength + TABLENGTH - 1; rightShiftIndex > tabIndex + TABLENGTH - 1; --rightShiftIndex) {
		if(rightShiftIndex > MAXLENGTH) return 1;	// If overflowing document MAXLENGTH, return error flag
		document[rightShiftIndex] = document[rightShiftIndex - TABLENGTH + 1];	// Shift document characters after (tabIndex + TABLENGTH) to the right by one TABLENGTH
	}
	
	for(int documentIndex = tabIndex; documentIndex < tabIndex + TABLENGTH; ++documentIndex) {
		document[documentIndex] = ' ';
	}
	
	(*documentLength) += (TABLENGTH - 1);
	
	return 0;
}
