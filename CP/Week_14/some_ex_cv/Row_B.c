/*
Row B - Sorting text

Design a data structure that stores a line of text, together with its length
(in characters) and number of words. 

Read all lines of a file named on the command line into an array of such 
structures. 

Sort and print the file with lines in _increasing order of length_, 
breaking ties: 
first in decreasing order of words 
and then in alphabetical order. 

You may consider at most 200 lines of maximum 200 characters each.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct Record {
    char text[200];
    int length; // in char
    int no_words;
} Record_t;

int countWords(char line[]){
    int counter = 0;
    char *aux = (char *)malloc(strlen(line) + 1);
    if (aux == NULL) {
        perror("memory alloc failed");
        return -1;
    }
    strcpy(aux,line);
    char *word = strtok(aux, " \n");
    while(word){
        printf("Found word:%s\n" , word);
        counter++;
        word = strtok(NULL, " \n");
    }
    free(aux);
    return counter;
}
int compareRecords(const void* el1, const void* el2){
    Record_t r1 = *(Record_t *) el1;
    Record_t r2 = *(Record_t *) el2;
    if(r1.length > r2.length) {
        return 1;
    } else if(r1.length < r2.length){
        return -1;


    } else{
        if(r1.no_words > r2.no_words){
            return 1;
        } else if( r1.no_words < r2.no_words){
            return -1;


        }  else{
            return strcmp(r1.text, r2.text);
        }

    }
}
void printRecords(int n, Record_t t[]){
    for ( int i= 0; i < n ; i++){
        printf("%s", t[i].text);
    }
}
int main(int argc, char *argv[]){
    if(argc != 2){
        perror("Provide file name as argument");
        return -1;
    }

    FILE *f = fopen(argv[1], "rt");
    if(!f){
        perror("error opening file");
        return -2;
    }
    Record_t data[200]; // max 200 lines
    int position = 0;
    

    while(fgets(data[position].text, 200, f)){
        printf("%s", data[position].text);

        data[position].length = (int)strlen(data[position].text);
        printf("length:%d\n", data[position].length);

        data[position].no_words = countWords(data[position].text);
        printf("words:%d\n", data[position].no_words);

        position++;
    }

    qsort(data, position, sizeof(Record_t), compareRecords);
    printRecords(position,data);

}

