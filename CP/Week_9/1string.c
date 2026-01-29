#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
uint32_t lowerLetters(char letters[], int n){
    uint32_t appear = 0;
    for(int i = 0 ; i < n && letters[i] != '\0'; i++){
        if(islower(letters[i])){
            int pos = letters[i] - 'a';
            appear = appear | 1 << pos;
        }    
    }
    return appear;
}

int main(){
    char letters[] = {'d', 'c', 'g', '\0'};
    uint32_t lower_appear = lowerLetters(letters, sizeof(letters)/ sizeof(letters[0]));
    for(int i = 0; i < sizeof(lower_appear) * 8 ; i++)
        if(lower_appear & (1 << i))   
            printf("%c", 'a' + i);
    printf("\n");
    return 0;
}

