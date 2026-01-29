/*
2. Consecutive bits 
Write a function that given an unsigned n returns the number of segments 
of consecutive equal bits in the binary representation of n. 
Example: 000100 has three segments: 000, 1, 00.
*/

#include <stdio.h>
#include <stdint.h>

uint16_t countSegments(uint16_t number){
    int segments = 1;
    int bit = 0;
    int lastBit = -1;
    int bitsInSegment = 0;
    for(int i = sizeof(uint16_t) * 8 - 1; i >= 0  ; i--){
        bit = (number & (1 << i)) >> i;
        if( lastBit == bit || lastBit == -1){
            bitsInSegment++;
        }
        else{
            printf("Bits in segment: %i\n", bitsInSegment);
            bitsInSegment = 1;
            segments++;
        }
        printf("%i\n", bit);
        lastBit = bit;
    }
    //printf("Bits in segment: %i\n", bitsInSegment);
    return segments;
}

int main(){

    uint16_t number = 0x0101;
    printf("Segments:%i" , countSegments(number));
    return 0;
}