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
	if (argc == 2) {
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

	printf("Enter the word you would like to check: \n");
	fgets(wordName, kCharSize, stdin);
	takeOfLastFunction(wordName);
	int i = 0;
	while (!feof(filePointer)) {
		int result = 0;
		char empty[kCharSize] = "";
		lineInfo[i] = fgetc(filePointer);
		if (lineInfo[i] == '\n' || lineInfo[i] == '\t' || lineInfo[i] == '\0' || lineInfo[i] == ' ') {

			takeOfLastFunction(lineInfo);
			result = strcmp(lineInfo, wordName);
			if (result == 0) {
				wordCount++;
			}
			strcpy(lineInfo, '\0');
			i = 0;
			continue;
		}
		else {
			i++;
		}

	}
	fclose(filePointer);
	printf("The number of similar words is : %d\n", wordCount);

}

int takeOfLastFunction(char* str) {


	size_t len = strlen(str);
	str[len - 1] = '\0';

	return 0;

}