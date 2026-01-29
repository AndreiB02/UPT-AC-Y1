#include <stdio.h>
#include <stdint.h>

uint32_t returnLastDigit( uint32_t number){
    return number%10;
}
uint32_t digitToHexa ( uint32_t number){
    uint32_t result = 0;
    uint32_t digits = 0;
    while(number){
        //printf("digit %i", returnLastDigit(number));
        // result = result << 4;
        // result = result | returnLastDigit(number);
        digits++;
        result  = result | (returnLastDigit(number) << digits * 4);
        //printf("result: %0X", result);
        number /= 10;
    }
    result = result >> 4;
    return result;
}

int main(){
    uint32_t number = 1234;
    printf("%0X\n", number);
    printf("%0X\n", digitToHexa(number));
    return 0;
}