#include <stdio.h>
#include <string.h>

int IsPasswordOk() {
	char pswd[12];

	gets(pswd);
	return 0 == strcmp(pswd, "goodpass");
}

int main() {
	int pwStatus;

	puts("Enter password:");
	pwStatus = IsPasswordOk();
	if(pwStatus == 0) {
		puts("Access Denied");
		return -1;
	}
	puts("Access Granted");
	return 0;
}
