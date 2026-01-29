/*
2. Searching for words 
Write a program that counts the number 
of nonoverlapping occurrences of a word in the input.

The word is a string constant in the program
    (or you may run the program with a command line argument, 
    define main as int main(int argc, char *argv[]), check if argc == 2 and use argv[1]).

Count also occurrences as substrings in other words.
Handle the case where the words in the input may be arbitrarily long.

An oft-ask question is "what does nonoverlapping mean?". 
Answer: 
The string "ababa" contains two occurrences of the string "aba": 
one starting at index 0, the other one at index 2. 
They overlap: the character 'a' at index 2 is common. 
Nonoverlapping strings are strings that do not overlap.
*/
#include <string.h>
#include <stdio.h>


int countNonOverlap(char str[], char subStr[]){
    int index = strstr(str,subStr) - str;
    int i = 0;
    int previous = -1;
    int subStr_length = strlen(subStr);
    int counter = 0;
    while(str[i] != '\0'){
        if(strstr(str + i,subStr) != NULL){
            index = strstr(str + i,subStr) - str;
            //printf("%i %i\n", previous,index);
            i = index +1;
            if((previous + subStr_length > index) && previous != -1){
                //printf("overlap\n");
                counter--;
            }
            else{
                counter++;
            }
            previous = index;
        }
        else{
            i++;
        }
    }
    return counter;
}   
int main(int argc, char *argv[]){
    // int m, n;
    // printf("Input two numbers: ");
    // while (scanf("%d%d", &m, &n) != 2) { // while not OK
    //     for (int c; (c = getchar()) != '\n';) // skip to end of line
    //         if (c == EOF) {printf("eof");return 0;} // nothing more, done
    //     printf("try again: ");
    // }
    // return 0;


    char word[100];
    if(argc == 2){
        strcpy(word, argv[1]);
    } else{
        strcpy(word, "ana");
    }
    char buffer[101];
    int appear = 0;
    while(fgets(buffer, 100 , stdin)){
        appear += countNonOverlap(buffer, word);
        //printf("%i\n", appear);
    }
    printf("%i\n", appear);
    return 0;
}