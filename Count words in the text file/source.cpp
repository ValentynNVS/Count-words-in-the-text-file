#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const int kCharSize = 100;

int main(int argc, char* argv[]) {


	char filename[kCharSize] = "";

	/*This part check if there is a=enough parameters to run the code*/
	if (argc == 1) {
		strcpy_s(filename, argv[1]);
	}
	else {
		printf("Not enough parameters to run the program");
		return 0;
	}
}