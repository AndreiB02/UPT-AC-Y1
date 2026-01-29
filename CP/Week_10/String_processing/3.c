/*

3. Write a function that takes a string and prints all words in the string, each on one line. 
Words are formed of any characters except: 
whitespace, colon, comma, semicolon, period, question mark and exclamation mark. 

Use strspn / strcspn as needed.
*/

#include <stdio.h>
#include <string.h>

void printWords(char *s, char *delimiters){
    int i = 0;
    int wordLenght = 0;  
    while(s[i] != '\0'){
        int skip = strspn(s+i, delimiters);
        i +=skip;
        //printf("%s\n", s + i);
        if(s[i] != '\0'){
            wordLenght = strcspn(s+i,delimiters);
            //printf("wordLenght: %i\n" , wordLenght);
            printf("%.*s\n",wordLenght , s + i);
            i += wordLenght;
        }
    }
}

int main(){

    char *s = " .  .. Ana ? are multe    ?  ;  mere...?";
    char *delimiters = " ',;.?!";
    printf("%s\n", s);
    printWords(s,delimiters);

    return 0;
}