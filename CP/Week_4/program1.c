#include <stdio.h>
#include <ctype.h>

int readInt(){
    int ch;
    int number = 0;
    while(isdigit(ch = getchar())){
        number = number * 10 + (ch - '0');
    }
    return number;
}


int main(){
    int ch;
    int number;
    while((ch = getchar())!= EOF){
        if(isdigit(ch)){
            ungetc(ch,stdin);
            number  = readInt();
        }
    }
    printf("%i", number);
    return 0;
}