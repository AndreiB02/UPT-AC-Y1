/*
5. 
Options first 
Write a program that reorders the command-line argument array argv[],
 placing all strings that start with '-' first, followed by all other strings.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int reorder(char *argv){

    char flags[256] = "";
    char other[256] = "";
    char delimiters[] = " ";
    int i = 0;
    int flagLenght = 0;
    int commandLenght = 0;
    int count_flags = 0;
    while(argv[i] != '\0'){
        //printf("%c", argv[i]);
        if(!isspace(argv[i])){
            //printf("%c\n",argv[i]);
            if(argv[i] == '-'){
                flagLenght = strcspn(argv+i, delimiters);
                //printf("flag lenght:%i\n", flagLenght);
                strncat(flags, argv+i, flagLenght);
                strcat(flags, " ");
                //printf("flags:%s\n", flags);
                i += flagLenght;
                count_flags++;
            }
            else{
                commandLenght = strcspn(argv+i,delimiters);
                strncat(other, argv+i, commandLenght);
                strcat(other, " ");
                //printf("other:%s\n", other);
                i+= commandLenght;
            }
        }
        else    
            i++;
    }
    strcat(flags, other);
    printf("%s\n", flags);
    return count_flags;
}
int main(){

    char *argv = "gcc -o     -Wall                5.c 5.exe  -O";
    // output was : -o -Wall -O gcc 5.c 5.exe 
    int result = reorder(argv);
    printf("%i flags were found\n", result); //3
    return 0;
}