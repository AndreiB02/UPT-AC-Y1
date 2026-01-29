#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <errno.h>

int getnumber(char *s){
    int i=0;
    int number = 0;
    while(isdigit(s[i])){
        number = number * 10 + s[i] - '0';
        i++;
    }

    return number;
}
int countDigits(int number){
    int counter = 0;
    if(number == 0)
        return 1;
    while(number){
        counter++;
        number/=10;
    }
    return counter;
}
double constructFloat(int nr_int, int nr_float){
    int nrDigits_float = countDigits(nr_float);
    double number = nr_int + nr_float * 1.0 / pow(10 , nrDigits_float);
    //printf("Number is: %.*f\n",nrDigits_float, number);
    return number;
}
double my_strtod(char *nptr, char **endptr){
    int i=0;
    int number_int = 0;
    int number_float = 0;
    int nrDigits_int = 0;
    int nrDigits_float =0;
    int isZero = 0;
    while(isspace(nptr[i]))
        i++;
    if(isdigit(nptr[i])){
        number_int = getnumber(nptr + i);
        if(number_int == 0)
            isZero = 1;
        nrDigits_int = countDigits(number_int);
         i = i + nrDigits_int;
        //printf("%i\n",number_int);
        //printf("%c", nptr[i]);
        }
        //printf("character before . : %c\n" , nptr[i]);
    if(nptr[i] == '.'){
        if(isdigit(nptr[i+1])){
            number_float = getnumber(nptr + i + 1);
            nrDigits_float = countDigits(number_float);
            i = i + nrDigits_float+1; // +1 is '.'
            //printf("floattt:%d\n",number_float);
        }
    }
    *endptr = nptr + i;
    if(isZero || number_float || number_int){
        //printf("index:%i\n", i);
        return constructFloat(number_int, number_float);
    }
    else{
        return 0.0;
    }
}

int main(){

    char *endptr = NULL;
    char *s = ".1  0   1.3 0.1  67.42    5678.367ffdgg";
    // printf("input string: %s\n", s);
    // my_strtod(s, &endptr);
    // printf("endptr:%s\n" , endptr);

    for (double f = my_strtod(s, &endptr); s != endptr; f = my_strtod(s, &endptr))
    {
        printf("'%.*s' -> ", (int)(endptr - s), s);
        s = endptr;
        if (errno == ERANGE)
        {
            printf("range error, got ");
            errno = 0;
        }
        printf("%f\n", f);
    }
    printf("%s\n", endptr);
    return 0;
}