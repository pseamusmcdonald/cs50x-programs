 /* Welcome to the jungle, we got fun and games.. */

#include <stdio.h>
#include <string.h>
#include <cs50.h>

/* Functions */

int readcalc (string filename);

int main (int filecount, string file[]) {
    float readingDifficulty = readcalc(file[1]);
    if (readingDifficulty > 16) printf("Reading Level: 16+\n");
    else printf("Reading Level: %f\n", readingDifficulty);
    return 0;
}

int readcalc (string filename) {

    float wordcount = 0;
    float lettercount = 0;
    float sencount= 0;
    float readlvl;
    FILE * text = fopen(filename, "r");

    while (!feof(text)) {

        int letter = fgetc(text);

            if (((64 < letter) && (letter < 91)) || (96 < letter && (letter < 123))) {
                lettercount++;
            }
            else if (letter == 33 || letter == 46 || letter == 63) {
                sencount++;
            }
            else if (letter == 32) {
                wordcount++;
            }
            else if (letter == 92) {
                fgetc(text);
                wordcount++;
            }
            else;
    }
    readlvl = ((0.0588 * (lettercount/(wordcount/100))) - (0.296 * (sencount/(wordcount/100))) - 15.8);
    fclose(text);
    return (int) readlvl;
}
