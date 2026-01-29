#include <stdio.h>
#include <ctype.h>
int peek(){
    int c = getchar();
    ungetc(c, stdin);
    return c;
}
//// code is repetitive
// unsigned readInt(){ 
//     int ch;
//     int number = 0;
//     ch = getchar();
//     if( ch == '0'){
//         if(peek() == 'x' || peek() == 'X' ){ // base 16 case
//             printf("Base 16 case:\n");
//             ch = getchar(); // ch is now X or x
//             ch = getchar();
//             while(isxdigit(ch)){
//                 putchar(ch);
//                 ch = getchar();
//             }
//         }
//         else{  // base 8 case
//             printf("Base 8 case:\n");
//             ch = getchar(); // skip 0 
//             while(isdigit(ch) && ch < '8'){
//                 number  = number * 8 + (ch - '0');
//                 putchar(ch);
//                 ch = getchar();
//             }
//         }
//     }
//     else{  // base 10 case(default)
//         printf("Base 10 case:\n");
//         number = number * 10 + (ch - '0');
//         while(isdigit(ch = getchar())){
//             number = number * 10 + (ch - '0');
//         }
//     }
//     return number;
// }
unsigned readInt(){
    int ch;
    int number = 0;
    int base = 10; // we know the first ch is a digit, we can have base10 as default
    int digitInBase = 1;
    ch = getchar();

    if( ch == '0'){
        if(peek() == 'x' || peek() == 'X' ){ // base 16 case
            base = 16;
            ch = getchar(); // skip the X or x
        }
        else{
            base = 8;
        }
        ch = getchar(); // skip the 0
    }
    int value;
    while(isxdigit(ch) && digitInBase){ // hexa digits also contain base 8 and 10 digits
        if(isalpha(ch))
            value  = 10 + toupper(ch) - 'A';
        else 
            value  = ch - '0';

        if(value < base)
            number = number * base + value; 
        else 
            digitInBase = 0; 

    //    printf("number:%i from base%i\n", number, base);
        ch = getchar();
    }
  //  if(digitInBase)
        return number;
    //else{} ///need error code ....
}


int main(){
    int ch;
    // int number = 015;
    // printf("number:%d",number);
    unsigned number;
    int is_valid = 1;
    while((ch = getchar())!= EOF && is_valid == 1){
        if(isdigit(ch)){
            ungetc(ch,stdin);
            number  = readInt();
            printf("%i\n", number);
        }
        else{
            printf("invalid character found");
            is_valid = 0;
        }
    }
    if(is_valid)
        
    return 0;
}