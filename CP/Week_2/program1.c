#include <stdio.h>

unsigned swapLMD(unsigned number){

    unsigned leastSignificantDigit = number %10;
    unsigned mostSignificantDigit = number/100;
    unsigned middleDigit = number/10%10;
    unsigned newNumber = leastSignificantDigit*100 + middleDigit*10 + mostSignificantDigit;
    return newNumber;

}
int main(){

    unsigned number = 234;
    printf("swapLMD for the number %d returns %d\n", number, swapLMD(number));
    return 0;
}