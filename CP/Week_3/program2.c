#include <stdio.h>
#include <ctype.h>

char nextChar(){
    char c = getchar();
    ungetc(c, stdin);
    return c;
}
int countWords(int paragraph_index){
    char c;
    int number_words=0;
    int number_lines=0;
    while( (c = getchar()) != EOF && ( c!='\n' || nextChar() != '\n')){
        if(!isspace(c) && isspace(nextChar()))
            number_words++;
        if(nextChar() == '\n'){
            number_lines++;
        }
    }

    printf("Paragraph %i:\n", paragraph_index);
    printf("number words:%i\n", number_words);
    printf("number_lines:%i\n\n", number_lines);
}
int main(){
    
    char c;
    int paragraph_index=0;
    while((c=getchar()) != EOF){
        if(!isspace(c)){
            ungetc(c,stdin);
            paragraph_index++;
            countWords(paragraph_index);
        }
    }
   // printf("%i\n",word_count);
    return 0;
}