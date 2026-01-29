#include <stdio.h>
#include <stdint.h>

int changeOfBase(int initialBase, int changeBase, int number){
    if(number < initialBase)
        return number;
    else{
        printf("%d\n",number%initialBase);
        printf("r:%i\n", number%initialBase);
        return (number % initialBase) + changeOfBase(initialBase, changeBase, number/initialBase) * changeBase;
    }
}



int main(){
    printf("%d\n",changeOfBase(10,16,110));
    return 0;
}