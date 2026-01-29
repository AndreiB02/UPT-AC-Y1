#include <stdio.h>
int extractOdds(int v[], int n, int *arr[], int capacity){
    int pos = 0;
    for(int i = 0 ; i < n; i++){
        if(v[i] % 2 == 1){
            printf("%d ", v[i]);
            printf("%p ", &v[i]);
            if(pos == capacity)
                return -1;
            else{
                arr[pos] = &v[i];
                pos++;
            }
        }
    }
    return pos;
}

int main(){

    int v[] = {9,3,2,5,7,6,5,2};
    int *arr[5];
    int capacity = sizeof(arr)/sizeof(arr[0]);
    int result = extractOdds(v,sizeof(v)/sizeof(v[0]), arr, capacity);
    printf("\nresult: %d \n", result);
    if(result != -1){
        for(int i = 0; i < result; i++){
            printf("%d ", *arr[i]);
        }
    }
    printf("\n");
    return 0;
}
//0 1 2 3 4 5 6 7 8 9 a b c d e f