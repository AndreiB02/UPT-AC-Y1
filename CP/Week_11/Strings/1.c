#include <stdio.h>
#include <string.h>

int myStrcmp(char *string1 , char *string2){
    printf("%s\n%s\n", string1, string2);
    while(string1[0] == string2[0] && string1[0] != '\0'){
        string1 = string1 + 1;
        string2 = string2 + 1;
    }
    printf("%s\n%s\n", string1, string2);
    return (int)(string1[0] - string2[0]);
}

int main(){
    char *string1 = "abcde";
    char *string2 = "abce";
    printf("%i\n", myStrcmp(string1,string2));
    return 0;
}