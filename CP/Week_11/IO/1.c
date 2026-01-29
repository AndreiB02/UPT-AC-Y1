#include <stdio.h>
#include <string.h>


int NthNumber (char *s, int N){
    //printf("%s\n", s);
    int counter = 0;
    int number;
    if(sscanf(s,"%i", &number) == 1){
            //printf("%i\n", number);
            counter++;
    }
    while(strchr(s,',') && s[0] !='\0' && counter != N){
        s = strchr(s, ',');
        s = s + 1;
        if(sscanf(s,"%i", &number) == 1){
            //printf("%i\n", number);
            counter++;
        }
        else
            printf("Input format error\n");
    }

    if(counter == N)
        return number;
    else
        return 0;
}

int main(){ 
    int number;
    // while(scanf("%i,", &number) == 1)
    //     printf("%i\n", number);
    
    // printf("Input format error\n");

    // fgets()
    char buffer[100];
    int N =2;
    while(fgets(buffer, 100 ,stdin)){
        //printf("%s\n", buffer);
        printf("%i\n", NthNumber(buffer , N));
    }
    return 0;
}