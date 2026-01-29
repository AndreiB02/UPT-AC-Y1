#include <stdio.h>
#include <stdint.h>
void printBits(uint32_t number){
    int bit = 0;
    for(int i = sizeof(uint32_t) * 8 - 1; i >= 0  ; i--){
        bit = (number & (1 << i)) >> i;
        printf("%i", bit);
    }
    printf("\n");
}
uint16_t onlyEvenBits(uint32_t number){
    uint16_t new_number = 0;
    for(int i = 0; i < sizeof(number) * 8 && number; i++){
        new_number = new_number | ((number & 1) << i);
        printBits(new_number);
        number = number >> 2;
    }
    return new_number;
}


int main(){

    uint32_t number = 0X12345678;
    printBits(number);
    uint16_t number_even_bits = onlyEvenBits(number);
    printf("%X\n", number_even_bits);
    return 0;
}