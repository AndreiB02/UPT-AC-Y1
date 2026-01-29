/*
5. Bitwise addition 
Write a function that adds two unsigned numbers, bit by bit, 
using the elementary school algorithm with carry (from LSB to MSB).
*/
#include <stdio.h>
#include <stdint.h>
uint16_t addNumbers( uint16_t number1, uint16_t number2){
    int carry = 0;
    uint32_t result = 0;
    int i, bit1, bit2, sumBit;
    for (int i = 0; i < sizeof(number1) * 8; i++) {
        bit1 = (number1 >> i) & 1;
        bit2 = (number2 >> i) & 1;

        sumBit = bit1 ^ bit2 ^ carry;
        carry = (bit1 & bit2) | (bit1 & carry) | (bit2 & carry);

        result |= (sumBit << i);
    }
    if(carry){
        result |= (carry << i);
    }
    return result;
}
int main(){
    printf("%i\n", addNumbers(0XAA,0XFF));
    return 0;
}
