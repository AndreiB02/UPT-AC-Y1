#include <string.h>
void printAllNumbers(char *s){
    int i = 0;
    int number;
    while(s[i] != '\0'){
        if(sscanf(s+i, "%i", &number) == 1)
            printf("%i\n",number);
        i++;
    }
}
int main(){

    char s[] = "    56789 s s 6789 545 122";
    void printAllNumbers(s);
    return 0;
}