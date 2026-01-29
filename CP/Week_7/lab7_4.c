#include <stdio.h>
#include <stdint.h>

double f(double x){
    return 3*x+2;
}


double rootOfFunction(double a, double b, double precision){
    printf("a:%f b: %f m: %f\n", a,b , (a+b)/2);
    if( b - a < precision)
        return (a+b)/2;
    else{
        double m = (a+b)/2;
        double left, right;
        printf("f(a): %f , f(b): %f\n", f(a), f(b));
        if(f(a)*f(m) <= 0){
            left = a;
            right = m;
        }
        else{
            left = m;
            right = b;
          }
        return rootOfFunction(left,right, precision);
    }
}



int main(){
    printf("%f\n",rootOfFunction(-1,6,0.000001));
    return 0;
}