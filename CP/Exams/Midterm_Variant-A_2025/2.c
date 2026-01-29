#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t filling(uint64_t pattern, uint8_t last_bit){
    int digit;
    uint64_t aux = 0X0;
    int bit = last_bit;
    int number_bits = 0;
    while(pattern){
        digit = pattern%10;
        //printf("%d\n",digit);

        uint64_t segment = 0X0;
        for(int i = 0; i < digit; i++){
            segment = segment | (bit << i);
        }
        aux = aux |  (segment << number_bits);

        number_bits +=digit;

        if(bit == 1) bit = 0;
        else if(bit == 0) bit = 1;

        printBits(aux);
        pattern/=10;
    }
    return aux;
}
void printBits(uint64_t number){
    int bit = 0;
    for(int i = sizeof(uint64_t) * 8 - 1; i >= 0  ; i--){
        bit = (number & (1 << i)) >> i;
        printf("%i", bit);
    }
    printf("\n");
}
int main(){
    int pattern = 12345;
    int last_bit = 1;
    uint64_t result = filling(pattern,last_bit);
    printf("%X", result);
}