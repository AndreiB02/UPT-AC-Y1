#include <stdio.h>

char nextNonSpace(){
    char c;
    while ((c = getchar()) == ' '); 
    return c;
}

int main(){
    char c;
    c = getchar();
    while (c != EOF){
        if (c == '\n'){
            putchar(c);
            c = nextNonSpace();
        }
        else{
            if ( c == ' '){
                putchar(' ');
                c = nextNonSpace();
            }
            else{
                putchar(c);
                c = getchar();
            }
        }
    }
        
    return 0;
}