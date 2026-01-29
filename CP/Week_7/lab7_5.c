/*
5. Series Write functions that compute the value of a given series.
    a) Compute the value of 1/1^2 + 1/2^2 + ... + 1/n^2 for some large n. 
        Write versions that start to add from each of the ends. 
        What is the difference in writing the recursion? 
        Is there a difference in the result?
*/

#include <stdio.h>
#include <stdint.h>

double series(int n){
    if(n == 1)
        return 1;
    else 
        return 1.0/(n*n) + series(n-1);
}
/*
when we calculate the series from both ends,
we end up with fewer recursive calls(half)
*/


double seriesFromBothEnds(int n, int left, int right){
    printf("term Left:%f term Right:%f\n",1.0/(left*left) , 1.0/(right * right));
    if(left == right)
        return 1.0/(left*left);
    if(left + 1 == right)
        return 1.0/(left*left) + 1.0/(right * right);
    return 1.0/(left*left) + 1.0/(right * right) + seriesFromBothEnds(n, left+1, right-1);
}

double wrapperSeriesBothEnds(int n){
    return seriesFromBothEnds(n,1,n);
}

int main(){
    int n;
    n = 9;
    printf("%f\n",series(n));
    printf("\n");
    printf("%f\n", wrapperSeriesBothEnds(n));
    return 0;
}