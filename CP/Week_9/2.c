#include <stdio.h>
#include <stdint.h>


int arr(int x[], int nx,int y[], int ny){
    int yindex = 0;
    for(int i = 0 ; i < nx; i++){
        if(x[i] == y[yindex]){
            yindex++;
        }
    }
    if(yindex == ny)
        return 1;
    else
        return 0;
}

int main(){
   
    int x[] = {6,6,7,7,7,9};
    int y[] = {7,6,6,9};
    int nx = sizeof(x)/sizeof(x[0]);
    int ny = sizeof(y)/sizeof(y[0]);
    printf("%i\n", arr(x,nx,y,ny));
    return 0;
}