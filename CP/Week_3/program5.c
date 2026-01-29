#include <stdio.h>
#include <ctype.h>
int peek(){
    int c = getchar();
    ungetc(c, stdin);
    return c;
}
int printCode(){
    int c;
    int comments = 0;
    while((c = getchar()) != EOF){
        if(c == '(' && peek() == '*'){
            comments++;
            //printf("%i",comments);
        }
        else if(c == '*' && peek() == ')'){
            comments--;
            c = getchar(); // skip the last ')'
        }
        else if(comments == 0){
            putchar(c);
        }
    }
    return 1;
}
    
int main(){
    int printed_code = printCode();

}