#include <stdio.h>
#include <stdint.h>


void ints_12bits(uint8_t arr[], int n){
    int number1;
    int number2;
    for(int i = 0; i< n/3; i++){
        number1 = 0;
        int nibble1 = arr[i+1] & 0XF;
        number1 = number1 | (nibble1 << 2 * 4); 
        number1 = number1 | (arr[i] & 0XFF);
        //printf("%X\n", number);
        printf("%X\n", number1);

        number2 = 0;
        nibble1 = arr[i+1] & 0XF0;
        nibble1 = nibble1 >> 4; 
        number2 = number2 | nibble1; 
        number2 = number2 | (arr[i+2] & 0XFF) << 4;
        //printf("%X\n", number);
        printf("%X\n", number2);
    }
    return ;
}

int main(){
    uint8_t arr[] ={0xAB,0XCD,0XEF};
    int n = sizeof(arr)/sizeof(arr[0]);
    ints_12bits(arr, n);
    return 0;
}