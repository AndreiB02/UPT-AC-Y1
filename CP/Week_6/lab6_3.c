/*
    2 numbers, 16 and 32 bits

    count how many nibbles from the 16 bit number 
    appear in the 32bit number

*/
#include <stdio.h>
#include <stdint.h>
int checkIfNibble( uint32_t number, uint16_t checkNibble){
    uint16_t nibble;
    for(int i = 0; i<sizeof(number) * 8 && number; i++){
        nibble = number & 0XF;
        if(nibble == checkNibble) 
            return 1;  
        number = number >> 4;
    }
    return 0;
}
int countSameNibble( uint32_t number32, uint32_t number16){
    uint32_t nibble;
    uint16_t checkedNibbles = 0;
    int count = 0;
    int firstTime0 = 1;
    for(int i = 0; i<sizeof(number16) * 8 && number16; i++){
        nibble = number16 & 0XF;
        if(nibble == 0){
            if(firstTime0){
                count += checkIfNibble(number32, nibble);
                firstTime0 = 0; 
            }
        }
        else if(!checkIfNibble(checkedNibbles, nibble)){
            //printf("nibble16:%0X", nibble);
            count += checkIfNibble(number32, nibble);
            checkedNibbles  = checkedNibbles << 4;
            checkedNibbles |= nibble;
            printf("CHECKED_NIBBLES:%0X\n", checkedNibbles);
        }
        number16 = number16 >>4;
    }
    return count;
}
int main(){
    uint32_t number = 0XABCD0;
    uint16_t number16 = 0XA00;
    printf("%0X\n", number);
    printf("%0X\n", number16);
    printf("%0X\n", countSameNibble(number, number16));
    return 0;
}
