#include <iostream>
#include <string>

using std::string;

int main() {
	int unusedInt = -1;
	string original = "Hello, there\n";
	string sdirect(original);
	string scopy = original;

	original = "Different\n";
	std::cout << original << scopy << sdirect;
	/*
	signed int n = -1;
	unsigned int p = 5;
	std::cout << "-1 > 5: " << (n > p) << std::endl;*/
	return 0;
}
