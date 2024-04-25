/*
* FILE : source.cpp
* PROJECT : Count words in the text file
* PROGRAMMER : Valentyn Novosydliuk
* FIRST VERSION : 04/20/2024
* DESCRIPTION :
* This C program was developed by me and can be used to count the amount of times the
* word that was entered by the user repeats in the text file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#pragma warning (disable:4996)
const int kCharSize = 100;

/*function prototype*/
int takeOffLastFunction(char* str);

int main(int argc, char* argv[]) {

    char filename[kCharSize] = "";
    char wordName[kCharSize] = "";
    char lineInfo[kCharSize] = "";
    int wordCount = 0;

    FILE* filePointer = NULL;

    if (argc != 2) {
        printf("Not enough parameters provided.\n");
        return 1;
    }

    strcpy(filename, argv[1]);

    filePointer = fopen(filename, "r");
    if (filePointer == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter the word you would like to check:\n");
    fgets(wordName, kCharSize, stdin);
    takeOffLastFunction(wordName);

    int i = 0;
    while (!feof(filePointer)) {
        int result = 0;
        char empty[kCharSize] = "";
        lineInfo[i] = fgetc(filePointer);
        /*checks if the charachter is a letter and if not then it compares the word and in case
        the word mathces then it adds +1 to the count of words*/
        if (!isalpha(lineInfo[i])) {
            takeOffLastFunction(lineInfo);
            result = strcmp(lineInfo, wordName);
            if (result == 0) {
                wordCount++;
            }
            memset(lineInfo, '\0', sizeof(lineInfo));
            i = 0;
            continue;
        }
        else {
            i++;
        }
       
    }
    fclose(filePointer);
    printf("The number of similar words is: %d\n", wordCount);
    return 0;
}


//
// FUNCTION : takeOffLastFunction
// DESCRIPTION : This function takes off last symbol that was add by fgets
// PARAMETERS : char* str : pointer to a string
// RETURNS : return 0 : in case of success
//
int takeOffLastFunction(char* str) {
    size_t len = strlen(str);
    str[len - 1] = '\0';

    return 0;
}
