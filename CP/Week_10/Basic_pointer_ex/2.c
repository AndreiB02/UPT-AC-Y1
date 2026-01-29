#include <stdio.h>
#include <stdint.h>
int countAlignedAddresses(int *addr[ ]){
    int counter = 0;
    int i = 0;
    while(addr[i] != NULL){
        i++;
        printf(" %d %p\n",i, addr[i]);
        if(((uint64_t)addr[i] & 0xF) == 0){
            printf("------------------------\n");
            counter++;
        }
    }
    return counter;
}
int main(){

    int *addr[101];
    int v[100] ={0};
    for(int i = 0 ;i < 100; i++){
        v[i] = i;
        addr[i] = &v[i];
    }
    addr[100] = NULL;
    int result = countAlignedAddresses(addr);
    printf("%d\n", result);
    return 0;
}
