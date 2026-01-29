#include <stdio.h>
#include <stdint.h>

int checkNondecreasingNibbles( uint32_t number){
    uint32_t nibble;
    uint32_t nextNibble;
    for(int i = 0; i<sizeof(number) * 8 && number; i++){
        nibble = number & 0XF;
        
        printf("nibble:%0X\n", nibble);
        number = number >> 4;
        nextNibble = number & 0XF;
        printf("Next nibble:%0X\n", nextNibble);
        if(nibble <= nextNibble)
            return 0;
    }
    return 1;
}
int main(){
    uint32_t number = 0XABCD0;
    printf("%0X\n", number);
    printf("%0X\n", checkNondecreasingNibbles(number));
    return 0;
}