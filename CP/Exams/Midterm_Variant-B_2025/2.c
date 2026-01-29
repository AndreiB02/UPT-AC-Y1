/*
receives 64bit number
prints "encoded" representation:
0xABF10F
000...0 1010 1011 1111 0001 0000 1111
 40     1111 11   6     3 1  4   4    + at the end 1
(at the end the value of the least significat bit)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void printEncoded(uint64_t number){
    int sequence_counter = 0;
    int bit;
    int last_bit = -1;
    for(int i = sizeof(uint64_t) * 8 - 1; i>=0; i--){
        //printf("%i: %lld\n",i, (number & (1 << i)) >> i);
        bit =  (number & (1 << i)) >> i;
        if(last_bit == -1){
            last_bit = bit;
            sequence_counter = 1;
        } else{
            if(bit == last_bit){
                sequence_counter++;
            }
            else{
                printf("%i ", sequence_counter);
                sequence_counter = 1;
                last_bit = bit;
            }
        }
    }
    if(bit == last_bit){
        printf("%i ", sequence_counter);
    }
    printf("%i\n", last_bit);
}
int main(){
    uint64_t number = 0XABF10F;
    printEncoded(number);
    number = 0XABF10E;
    printEncoded(number);
    number = 0XABF10C; 
    printEncoded(number);
}
// 1100 - C
// 1101 - D
// 1110 - E
// 1111 - F