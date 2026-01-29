#include <stdio.h>
void equalArg(int a, int b, int index_a, int index_b){
    if(a==b){
        printf("Arguments %d and %d are equal", index_a, index_b);
    }
}
void distinctValues(int a, int b, int c){
    if(a==b && b==c)
        printf("All arguments are equal");
    else if( a!=b && a!=c && b!=c)
        printf("All arguments are distinct");
    else{
        equalArg(a,b,1,2);
        equalArg(b,c,2,3);
        equalArg(a,c,1,3);
    }
}
int main(){

    distinctValues(3,3,2);
    return 0;
}