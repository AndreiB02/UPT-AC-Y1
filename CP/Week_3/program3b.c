#include <stdio.h>
#include <ctype.h>

char peek()
{
    char c = getchar();
    ungetc(c, stdin);
    return c;
}
int fixedWidthFormating(int n)
{
    int c;
    int printed_char = 0;
    int no_spaces = 0;
    int is_space = 0;
    while ((c = getchar()) != EOF)
    {
        if (no_spaces && printed_char > 0)
        {
            putchar(' ');
            no_spaces = 0;
            printed_char++;
        }
        // if(c == ' ')
        //     no_spaces++;
        while(c == ' ') {
            c = getchar();
            no_spaces++;
            is_space = 1;
        }
        if(is_space) {
            is_space = 0;
            ungetc(c, stdin);
            c = ' ';
        }
        if (!isspace(c))
        {
            if (printed_char == n - 1)
            {
                if (ispunct(c) || isspace(peek()))
                {
                    putchar(c);
                    putchar('\n');
                }
                else
                {
                    putchar('-');
                    ungetc(c, stdin);
                    putchar('\n');
                }
                printed_char = 0;
            }
            else if( n == printed_char) {
                ungetc(c, stdin);
                putchar('\n');
                printed_char = 0;
            }
            else
            {
                putchar(c);
                printed_char++;
                // printf("%i",printed_char);
            }
            no_spaces = 0;
        }
        if(isspace(c) && !isspace(peek()) && printed_char == n-2){
            c = getchar();
            
            if(isspace(peek())){ 
                putchar(' ');
                putchar(c);
            }
            else ungetc(c,stdin);
            putchar('\n');
            printed_char = 0;
        }
        if (c == '\n')
        {
            putchar(c);
            printed_char = 0;
            no_spaces = 0;
        }
    }
    return 1;
}

int main()
{
    int is_formatted = fixedWidthFormating(25);
}