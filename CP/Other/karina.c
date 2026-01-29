#include <stdio.h>
#include <stdint.h>
/*

    01111111001&
    00000000001

    00000000001
    00000000000
    00000000000
    00000001000



    01011111110
   
    */
void printBits(uint32_t number){
    int bit = 0;
    for(int i = sizeof(uint32_t) * 8 - 1; i >= 0  ; i--){
        bit = (number & (1 << i)) >> i;
        printf("%i", bit);
    }
    printf("\n");
}
int countBits(uint32_t number){
    int count = 0;
    int bit = 0;
    int nrStarted = 0;
    for(int i = sizeof(number) * 8 - 1; i >= 0  ; i--){
        bit = (number & (1 << i)) >> i;
        if(bit && !nrStarted)
            nrStarted = 1;
        if(nrStarted)
            count++;
    }
    return count;
}
uint32_t shiftLeftKBits(uint32_t number, int k){
    uint32_t lastKBits = 0;
    int bits;
    bits = countBits(number); 
    for(int i = 0; i < k; i++){
        lastKBits = lastKBits | (number & (1 << i));
        //printf("bits shift%0X\n",lastKBits);
    }
    //printf("Number bits:%i\n", bits);
    number = number >>k;
    //printBits(number);
    //printBits( (lastKBits << (bits - k))); 
    number |=  (lastKBits << (bits - k));
    return number;
}

int main(){
    
    uint32_t number = 0XB;
    int k = 2;
    printBits(number);
    //printf("shifted by %i bits: %0X\n",k,shiftLeftKBits(number, k));
    printBits(shiftLeftKBits(number,k));

}