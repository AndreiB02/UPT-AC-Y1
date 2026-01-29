/*
    3. Every other bit
    a) Write a function that takes a 32-bit unsigned 
       and returns the 16-bit number formed by the bits in even positions.
    b) The same problem, but place the bits in reverse order.
*/
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
uint16_t evenPositionBits( uint32_t number){
    uint16_t newNumber = 0;
    int bit;
    for(int i = 0; i < sizeof(uint32_t) * 8; i++){
        bit = (number & (1 << i)) >> i;
        if(i % 2 == 0){
            newNumber = newNumber | (bit << i/2);
            //printf("%X\n", newNumber);
        }
    }
    return newNumber;
}
uint16_t evenPositionBitsReverse( uint32_t number){
    uint16_t newNumber = 0;
    int bit;
    for(int i = 0; i < sizeof(uint32_t) * 8; i++){
        bit = (number & (1 << i)) >> i;
        if(i % 2 == 0){
            newNumber = newNumber << 1;
            newNumber = newNumber | bit ;
            //printf("%X\n", newNumber);
        }
    }
    return newNumber;
}

int main(){
    uint32_t number = 0xBACD;
    printBits(number);
    printBits(evenPositionBits(number));
    printf("%X\n", evenPositionBits(number));
    printBits(evenPositionBitsReverse(number));
    printf("%X\n", evenPositionBitsReverse(number));
    return 0;

}