#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FPATH "./input.txt"

int main() {
    int totalCharacters = 0, totalLines = 0, totalWords = 0;
    FILE *fp;
    fp = fopen(FPATH, "r");
    int c, prev = 0;

    // Verify if the file exists
    if(!fp) {
        printf("Error opening file %s\n", FPATH);
        return 1;
    }
    printf("File openned sucefully\n");

    // Counting characters and lines
    while ((c=fgetc(fp)) != EOF) {
        if(c != '\r') totalCharacters++;
        if (c == '\n') {
            totalLines++;
            if(prev != '\n')totalWords++;
        } else if (c == ' ') {
            totalWords++;
        }
        prev = c;
    }
    totalLines++; //last line
    totalWords++; //last word
    fclose(fp);

    printf("==============================\n");
    printf("|          TEXT-APP           |\n");
    printf("==============================\n");
    printf("Total Characters: %d\n", totalCharacters);
    printf("Total Lines: %d\n", totalLines);
    printf("Total Words: %d\n", totalWords);
    printf("==============================\n");
    return 0;
}