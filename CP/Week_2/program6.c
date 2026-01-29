/*(wiki)->
Rounding away from zero:
For example, 23.2 gets rounded to 24, and −23.2 gets rounded to −24.
*/
#include <stdio.h>
#include <math.h>

double myround(double number){
    if(number>0)// 35.5
        return floor(number + 0.5); //35.5 + 0.5=36.0, 37.8+0.5=38.3->38
    else if(number<0) // -35.5
        return ceil(number - 0.5); // -35.5 -0.5 = -36
    else
        return number;
}
void compareTest(double x){
    //printf("%f\n", round(x));
    printf("Test for %f", x);
    if(myround(x) == round(x))
        printf(" passed\n");
    else
        printf(" failed\n");
}
int main(){
    double number1 = 23.5;
    double number2 = -23.5;
    //printf("%f ->nearest integer,away from zero is %f\n" , number1, myround(number1));
    //printf("%f ->nearest integer,away from zero is %f\n" , number2, myround(number2));

    compareTest(number1);
    compareTest(number2);
    return 0;
}