#include <stdio.h>
#include <ctype.h>
int add_spaces(int n){
    while(n){
        //putchar('?');
        putchar(' ');
        putchar(' ');
        n--;
    }
}
int prettyPrinting(){
    int c;
    int indent_level = 0;
    int start_line = 1;
    while((c =getchar()) != EOF){
        if( c == '{'){
            indent_level++;
            putchar(c);
            putchar('\n');
            start_line = 1;
            add_spaces(indent_level);
        }
        else if( c == '}'){
            indent_level--;
            putchar('\n');
            add_spaces(indent_level);
            putchar(c);
            putchar('\n');
            start_line = 1;
            add_spaces(indent_level);
        }
        else {

            if(!start_line && isspace(c)){
                if(c == '\n')
                    add_spaces(indent_level);
                else putchar(c);
            }


            // if(c == '\n')
            //     add_spaces(indent_level);
            // // while(c == ' ') c = getchar();
            // else if(isspace(c) && !start_line)
            //     putchar(c);
            if(!isspace(c)){
                putchar(c);
                start_line = 0;
            }
        }
    }
    return 1;
}

int main(){
    int is_formatted = prettyPrinting();
}