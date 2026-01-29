#include <stdio.h>
int mini( int a, int b)
{
    if(a<b) 
        return a;
    else 
        return b;
}
int maxi( int a, int b){
    if (a>b)
        return a;
    else 
        return b;
}
int medianOfThree(int a, int b, int c){
    return a+b+c - mini( mini(a,b), c) -maxi( maxi(a,b) ,c);
}


int main(){
    printf("%d\n", medianOfThree(7,10,9));
    printf("%d\n", medianOfThree(-7,9,10));
    printf("%d\n", medianOfThree(7,-10,9));

    return 0;
}