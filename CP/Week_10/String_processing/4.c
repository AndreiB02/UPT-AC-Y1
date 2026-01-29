/*
4. 
Implement a function sscanprint with two parameters: 
    the string to read from 
    and the format string (like in sscanf),
which simply prints the fields matched according to the format, one per line. 
Implement the format specifiers %d, %f and %MAXs, regular characters and whitespace. 
Return the same value as sscanf.
*/

#include <stdio.h>
#include <string.h>

int sscanprint(char *input, char *format){
    
}

int main(){
    const char *input = "0xA5 Z";
    int hexValue;
    char character;
    int result = sscanprint(input, "%d %s");
    return 0;
}