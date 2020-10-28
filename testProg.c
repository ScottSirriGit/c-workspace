#include <stdio.h>
#include <math.h>


struct rec {
	int arr[3];
	char c;
};
union un;
void pr(union un* un_ptr);
void byte_rep(unsigned char*, size_t);
void bit_rep(unsigned char*, size_t);
void stack_rep(unsigned char * char_ptr, size_t size, int length);

int main() {
	/*int num = -0x16;
	unsigned char* p = &num;
	bit_rep(p,4);

	float f1 = 4.5;
	unsigned char* c_ptr = &f1;

	const int ARR_LENGTH = 4;
	float arr[ARR_LENGTH] = { 3.14, 1e10, (3.14 + 1e10) - 1e10, 3.14 + (1e10 - 1e10) };

	for(int i = 0; i < ARR_LENGTH; i++) {
		printf("%f:\n", arr[i]);
		f1 = arr[i];
		bit_rep(c_ptr, sizeof(f1));
		printf("\n");
	}*/
	
	//int arr[3][3] = {{ 0xdeadbeef,2,3}, {4,5,6}, {7,8,0xbadf00d}};
	//stack_rep((unsigned char *) arr[0], 4, 9);
	
	struct rec r;
	r.arr[0] = 0xaa0000bb;
	r.arr[1] = 0xcc0000dd;
	r.arr[2] = 0xee0000ff;
	r.c = 0x69;
	stack_rep((unsigned char *) (&r) - 12, 4, 10);
	return 0;
}

void stack_rep(unsigned char * char_ptr, size_t size, int number) {
	int length = number * size;	
	printf("%03u\n\n", sizeof(*char_ptr));
	
	for(int i = length - 1; i >= 0; i -= size) {
		printf("%02d: 0x%p --> 0x ", i, char_ptr + i + size - 1);
		for(int j = 0; j < size; j++) printf("%02x ", *(char_ptr + i - j));
		if(size != 1) printf(" <-- 0x%p", char_ptr + i);
		printf("\n");
	}
}


union un {
	unsigned char c1;
	unsigned short s1;
	unsigned int i;
};

void pr(union un* un_ptr) {
	union un testing = *un_ptr;
	printf("%x %x %x\n", testing.c1, testing.s1, testing.i);
	printf("%u %u %u\n", testing.c1, testing.s1, testing.i);
	unsigned char* char_ptr = un_ptr;
	for(int i = 0; i < 4; ++i) {
		printf("%x ", *(char_ptr + i));
	}
	printf("\n\n");
}

void byte_rep(unsigned char * char_ptr, size_t size) {
	for(int i = size - 1; i >= 0; --i) printf("%02x ", *(char_ptr + i));
	printf("\n");
}


void bit_rep(unsigned char * char_ptr, size_t size) {
	for(int byteInd = size - 1; byteInd >= 0; --byteInd) {
		unsigned char byte = *(char_ptr + byteInd);
		char str[10];
		str[4] = ' ';

		for(int hexDigit = 1; hexDigit >= 0; --hexDigit) {
			for(int bitInd = 3; bitInd >= 0; --bitInd) {
		
				if(byte & 0x1) str[hexDigit + 4*hexDigit + bitInd] = '1';
				else str[hexDigit + 4*hexDigit + bitInd] = '0';
				
				byte >>= 1;
			}
		}

		printf("%s ", str);
	}
	printf("\n");
}	

