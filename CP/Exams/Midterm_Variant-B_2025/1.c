/*
read data on char level
for each line, check if has exaclty 3 floating point nr

Question...?
are numbers like 798 counted or not?

(this code counts them :)  )


*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
double readDouble(){
    int ch;
    double number = 0;
    int isPositive = 1;
    ch = getchar();
    if(ch == '-'){
        isPositive = -1;
        ch = getchar();
    }
    if(ch == '+'){
        isPositive = 1;
        ch = getchar(); 
    }
    while(isdigit(ch)){
        number = number * 10 + (ch - '0');
        ch = getchar();
    }

    //printf("real part:%lf" , number);

    //here, if it does not have the point after the real part, dont return it
    if(ch == '.') 
        ch = getchar(); 

    int decimal = 1;
    while(isdigit(ch)){
        number = number + (ch-'0') / pow(10,decimal);
        decimal++;
        ch = getchar();
    }
    if(ch != EOF)
        ungetc(ch, stdin);
    return number * isPositive;
}
int floatingPointNumbersPerLine(){
    int counter = 0;
    int ch;
    ch = getchar();
    double number;
    while((ch != '\n') && (ch != EOF)){
        if(isdigit(ch) || ch =='-' || ch == '+'){
            ungetc(ch, stdin);
            number = readDouble();
            counter ++;
            printf("number is:%lf", number);
        }
        ch = getchar();
    }

    return counter;
}

int main(){
    int ch;

    while((ch = getchar()) != EOF){
        ungetc(ch,stdin);
        if(3 == floatingPointNumbersPerLine()){
            printf("has 3 floating point numbers");
        }
        else {
            printf("does NOT have 3 floating point numbers");
        }
    }


}