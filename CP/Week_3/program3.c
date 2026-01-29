#include <stdio.h>
#include <ctype.h>

char peek(){
    char c = getchar();
    ungetc(c, stdin);
    return c;
}
int fixedWidthFormating(int n){
    int c;
    int printed_char=0;
    int nr_spaces=0;
    while((c=getchar())!=EOF){

        if(nr_spaces && printed_char>0){
            putchar(' ');
            nr_spaces=0;
            printed_char ++;
        }
        if(c == ' ')
            nr_spaces++;
         //           |
            ////    of 
        if(!isspace(c)){
            if( printed_char == n-2 && peek()!= EOF){
                if(!isspace(peek()) && peek()!='-'){
                    putchar(c);
                    if(ispunct(peek())) {
                        putchar(peek());
                        c = getchar(); //skip punctuation
                    }
                    else putchar('-');
                    //printf(" %i", count);
                    putchar('\n');
                    printed_char = 0;
                }
                else{
                    putchar(c);
                    putchar(peek());
                    putchar('\n');
                  //  printf("%i", count);
                    //printf("char is %c\n" ,c);
                    c = getchar(); // skip the hyphen or space
                    //printf("char is %c\n" ,c);
                    printed_char = 0;
                }
            }
            else if( printed_char == n-1) {
                /*
                n=6
                Ex 1:
                    nes. A
                    we can print 'A', still has space on the line
                Ex 2:
                    aph, 
                    the n-
                    because there is a space after the comma, we cannot begin the word "the"->
                    we wouldnt have space for the hypthen
                */
                if(!isspace(peek())){
                    putchar('\n');
                    ungetc(c,stdin);
                }
                else{
                    putchar(c);
                    putchar('\n');
                }
                printed_char = 0;
            }
            else {
                putchar(c);
                printed_char++;
            }
            // else if(count < n-1){
            //     putchar(c);
            //     count++;
            // }
            // else {
            //     printf("HEREEE %i", count);
            //     putchar('\n');
            //     putchar(c);
            //     count =1;
            // }
            nr_spaces=0;
        }
        if(c=='\n') {
            putchar(c);
            printed_char = 0;
            nr_spaces = 0;
        }
    }
    return 1;
}
int main(){
    int is_formatted = fixedWidthFormating(25);
}