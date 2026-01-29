/*
4. Base 32 
We can write a number in base 32, continuing to use letters after 'F'. 
Write a function that takes an unsigned and prints it in base 32.
*/
/*
    in base32, each char would be represented on 5 bits(base 2)
    0001100011
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
void toBase32(uint16_t number){ // prints them in reverse order...
    while(number){
        if(number % 32 <= 9) 
            printf("%c", number % 32 + '0');
        else
            printf("%c", number % 32 - 10 + 'A');
        number/=32;
    }
    printf("\n");
}
void toBase32Bits( uint32_t number){
    int nickel = 0; /// 5 bits
    int j = sizeof(number) * 8 / 5;
    //printf("j: %i\n" , j);
    for(int i = 0 ; i < sizeof(number) * 8 && number; ){
        //  printBits(0X1F << (j*5));
        nickel = number & (0X1F << (j*5));
        nickel = nickel >> j*5;
        //printf("%i\n", nickel );
        if(nickel <= 9) 
            printf("%c", nickel + '0');
        else
            printf("%c", nickel- 10 + 'A');
        j-=1;
        i += 5; 
    }
    printf("\n");
}
int main(){
    uint16_t number = 63;
    //toBase32(number);
    printBits(number);
    toBase32Bits(number);
    return 0;
}