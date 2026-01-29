#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* function(char s[], int capacity_s, double numbers[], int capacity_nr){
    char* aux;
    int i = 0;
    char newString[50] = "";
    char buffer[50];
    int j = 0;
    while((aux = strstr(s + i, "%f")) != NULL){
        //printf("%i:", i);
        strncat(newString, s+i, aux - (s+i));

        sprintf(buffer, "%.*f", 4 , numbers[j]);
        j++;
        /*
        check if overflow
        */
        strcat(newString, buffer);
        i += aux - (s+i) + strlen("%f");
        //printf("%i\n", i);
    }
    if(i < strlen(s)) // check overflow again here
        strcat(newString, s+i);
    printf("%s\n",newString);
}
int main(){
    double numbers[] = { 1.5, 3.14098754};
    function("ana %f are %f multe mere", 50, numbers, 2);
}