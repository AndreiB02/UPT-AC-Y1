#include <stdio.h>
#include <stdint.h>

int mostSignificantDigit(int n){
    if( n < 10)
        return n;
    else
        return mostSignificantDigit(n/10);
}


int main(){
    printf("%d\n",mostSignificantDigit(1456));
    return 0;
}