#include <stdio.h>
#include <stdint.h>

void readLetters(){
    int ch = getchar();
    if (ch == EOF || ch == '\n') {
        //printf("stop");
        return;
    }
    else{
       // printf("%c", ch);
        int counter = 1;
        int ch2 = getchar();
        while (ch2 == ch && ch2 != EOF) {
            counter++;
            ch2 = getchar();
        }
        printf("%i%c",counter, ch);                
        ungetc(ch2, stdin);
        readLetters();
    }
}

int main() {
    readLetters();
    return 0;
}
