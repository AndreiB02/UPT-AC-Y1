/*
1. Nibbles A nibble is a group of 4 bits. Write a function that given an unsigned n
a) returns the value with the nibbles placed in reverse order 
(swapping the most significant nibble with the least significant one and so on);
b) returns the value with the bits in each nibble reversed
*/

#include <stdio.h>
#include <stdint.h>

uint16_t reverseNibbleOrder(uint16_t number ){
    uint16_t reverse = 0;
    for( int i = 0 ; i < sizeof(uint16_t) && number; i++ ){
        reverse = reverse << 4;
        reverse = reverse | (number & 0xF);
        number = number >> 4;
    }
    return reverse;
}

uint16_t reverseBitsInNibble( uint16_t number ){
    uint16_t new_number = 0;
    uint16_t new_nibble;
    uint16_t nibble;

    for( int i = 0 ; i < sizeof(uint16_t) && number; i++ ){
        nibble = number & 0xF;
        printf("nibble: %X\n", nibble);
        new_nibble = 0;
        int k=3;
        for(int j = 0; j <= 3 ; j++){
           // printf("%d\n", (nibble & 1 << j) >> j);
            if((nibble & 1 << j) >> j)
                new_nibble = new_nibble | 1 << k;
            k--;
        }
        printf("new_nibble: %X\n", new_nibble);
        number = number >> 4;
        new_number = new_nibble << 4 * (i+1) | new_number;
    }
    new_number = new_number >> 4;

    return new_number;
}
int main(){
    uint16_t number;
    number = 0xAABF;
    printf("number in hex: %X\n", number);

    uint16_t reverse  = reverseNibbleOrder(number);
    // printf("reverse: %X\n", reverse);
    uint16_t reverse_each_nibble = reverseBitsInNibble(number);
    printf("reverse bits in nibble:%X\n", reverse_each_nibble);
    return 0;
}