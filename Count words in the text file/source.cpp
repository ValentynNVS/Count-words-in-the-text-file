#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const int kCharSize = 100;
int takeOfLastFunction(char* str);

int main(int argc, char* argv[]) {


	char filename[kCharSize] = "";
	char wordName[kCharSize] = "";
	char lineInfo[kCharSize] = "";
	int wordCount = 0;

	FILE* filePointer = NULL;

	/*This part check if there is enough parameters to run the code*/
	if (argc == 1) {
		strcpy_s(filename, argv[1]);
	}
	else {
		printf("too many or not enough parameters");
		return 0;
	}
	#pragma warning (disable : 4996);
		filePointer = fopen(filename, "r"); // Open file in read mode
		if (filePointer == NULL) {
			printf("Error opening file. \n");
			return 1; // Return error code
		}

	printf("Enter the word you would like to enter: \n");
	fgets(wordName, kCharSize, stdin);
	takeOfLastFunction(wordName);
	while (!feof(filePointer)) {
		int i = 0;
		int result = 0;
		char empty[kCharSize] = "";
		if (lineInfo[i] == '\n' || lineInfo[i] == '\t' || lineInfo[i] == '\0' || lineInfo[i] == ' ') {

			result = strcmp(lineInfo, wordName);
			if (result) {
				wordCount++;
			}
			strcpy(lineInfo, empty);
			continue;
		}
		else {
			lineInfo[i] = fgetc(filePointer);
			
		}

		


		i++;
	}
	printf("The number of similar words is : %d\n", wordCount);

}

int takeOfLastFunction(char* str) {


	size_t len = strlen(str);
	if ( str[len-1] == '\n') {
		str[len - 1] = '\0';
	}

	return 0;

}