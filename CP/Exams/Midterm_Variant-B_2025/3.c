#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define capacity 42
void spell(char s[], int size, char s_spell[]){
    char digit_to_number[][10] = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };

    int ch;
    int i = 0;
    ch = s[i];

    int new_size = 0;
    char new_s[capacity] = "";

    while(ch != '\0'){
        if(isdigit(ch)){
            if(new_size + strlen(digit_to_number[ch-'0']) <= size){
                strcat(new_s, digit_to_number[ch-'0']);
                //printf("%s",digit_to_number[ch-'0'] );
                new_size = strlen(new_s);
                //printf("%c %s %i\n",ch,  new_s, new_size);
            } else { return; }
        } else {
            if(new_size + 1 < size){
                //printf("NEW_SIZE:%i\n", new_size);
                new_s[new_size ] = ch;
                new_s[new_size + 1] = '\0';
                new_size += 1;
                // printf("%c", new_s[new_size + 1]);
            } else { return; }
        }
        i++;
        ch = s[i];
    }
    // printf("%i %i\n", new_size, strlen(new_s));
    strcpy(s_spell, new_s);
}
int main(){

    char s[capacity] = "ana are 12 mere si 13.5 pere";
    char s_spell[capacity];
    spell(s, capacity, s_spell);
    printf("%s", s_spell);
}