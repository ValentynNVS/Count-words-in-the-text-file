#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const int kCharSize = 100;
char takeOfLastFunction(char str[]);

int main(int argc, char* argv[]) {


	char filename[kCharSize] = "";
	char wordName[kCharSize] = "";
	/*This part check if there is a=enough parameters to run the code*/

	FILE* filePointer = NULL;

	if (argc >= 1) {
		strcpy_s(filename, argv[1]);
		filePointer = fopen(filename, "r"); // Open file in read mode
		if (filePointer == NULL) {
			printf("Error opening file.\n");
			return 1; // Return error code
		}
	}
	
	printf("Enter the word you would like to enter: \n");
	fgets(wordName, kCharSize, stdin);
	//strcspn(wordName, '\n')
	//while (!feof(filePointer)) {



	//}
}

char takeOfLastFunction(char str[]) {


}