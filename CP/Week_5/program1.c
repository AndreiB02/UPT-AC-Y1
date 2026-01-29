/*
    Count how many bits of 1 and how many of 0
*/

#include <stdio.h>
#include <stdint.h>


int main(){
    uint16_t number;
    number = 0xAAFF;
    printf("number in hex: %x\n", number);
    // printf("number in binary: %i", number);
    int position;
    int no_1 = 0, no_0 = 0;
    for(position = 0; position < sizeof(uint16_t) * 8; position++){
        if(number & (1 << position))
            no_1++;
        else 
            no_0++;
    }
    printf("no 0:%i\n", no_0);
    printf("no 1:%i\n", no_1);
    return 0;
}