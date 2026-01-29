#include <stdio.h>
#include <stdint.h>


int isSorted(unsigned t[], unsigned n){
    int increasing = 0;
    if(t[0] < t[1])
        increasing = 1;
    for(int i = 0; i < n-1; i++)
        if(increasing && t[i] > t[i+1])
            return 0;
        else
            if(!increasing && t[i] < t[i+1])
                return 0;
    return 1;
}

int main(){
   
    unsigned t[] = {2,4,3};
    printf("%i\n", isSorted(t, sizeof(t)/sizeof(t[0])));
    return 0;
}