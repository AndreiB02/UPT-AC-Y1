#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
int readNumber(){
    int ch;
    int number = 0;
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
    if(ch != EOF)
        ungetc(ch, stdin);
    return number * isPositive;
}

double averageOfLine(){
    int ch;
    double avg;
    int a,b,c;
    a = b = c = INT_MIN;
    int counter = 0;
    while((ch = getchar()) != '\n'){
        if(isdigit(ch) || ch =='-' || ch =='+'){
            ungetc(ch,stdin);
            int number = readNumber();
            //printf("Number is:%d\n", number);
            counter++;
            if(number > a){
                c = b;
                b = a;
                a = number;
            }
            else if(number > b){
                c = b;
                b = number;
            }
            else if(number > c){
                c = number;
            }
        }
    }
    avg = (a+b+c)/3.0;
    printf("Average is: %lf\n", avg);
    return avg;
}
int main(){
    int ch;
    double avg;
    double mini = DBL_MAX;
    while((ch = getchar()) != EOF){
        ungetc(ch,stdin);
        avg = averageOfLine();
        if(avg < mini)
            mini = avg;
    }
    printf("Smallest average is %lf\n", mini);
}