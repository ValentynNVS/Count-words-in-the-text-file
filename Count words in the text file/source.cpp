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

/*Function prototype*/
int takeOffLastFunction(char* str);

int main(int argc, char* argv[]) {

    printf("hhelo world");
    printf("hello world");
    char filename[kCharSize] = "";
    char wordName[kCharSize] = "";
    char lineInfo[kCharSize] = "";
    int wordCount = 0;
    int index = 0;

    FILE* filePointer = NULL;

    if (argc != 2) {

        printf("Not enough parameters provided.\n");
        return 0;

    }

    /*Assigns the user input to the variable*/
    strcpy(filename, argv[1]);

    /*Opens the file and checks for an errors*/
    filePointer = fopen(filename, "r");
    if (filePointer == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter the word you would like to check: \n");
    fgets(wordName, kCharSize, stdin);
    takeOffLastFunction(wordName);

    while (!feof(filePointer)) {

        int result = 0;
        char empty[kCharSize] = "";
        /*Add 1 letter from a string to form a word*/
        lineInfo[index] = fgetc(filePointer);

        /*Checks if the charachter is a letter and if not then it compares the word and in case
        the word mathces then it adds +1 to the count of words*/
        if (!isalpha(lineInfo[index])) {
            takeOffLastFunction(lineInfo);
            result = strcmp(lineInfo, wordName);
            if (result == 0) {
                wordCount++;
            }
            memset(lineInfo, '\0', sizeof(lineInfo));
            index = 0;
            continue;
        }
        else {
            index++;
        }
       
    }

    fclose(filePointer);
    if (filePointer == NULL) {

        printf("Could not close the file. \n");
        return 0;

    }

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
