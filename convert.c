include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

float convertF(float fahrenheit) {
	return (5.0/9.0) * (fahrenheit - 32);
}

int main() {
	for(float f = LOWER; f < UPPER + .05 * STEP; f+= STEP) {
		printf("%f\t%5.1f\n", f, convertF(f));
	}
	
	int c;
	while((c = getchar()) != EOF) printf("%c", (char) c);
	return 0;
}

