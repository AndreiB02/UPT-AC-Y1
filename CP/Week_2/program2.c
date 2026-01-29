#include <stdio.h>

void addTime(unsigned h, unsigned m, unsigned dMin){
    printf("Current time: %d : %d. Adding %d minutes.\n" , h, m , dMin);
    printf("New time:");

    if(m + dMin <60) 
        printf("%d : %d \n", h, m+dMin);
    else{
        unsigned minutes = m + dMin;
        unsigned newHours = minutes / 60;
        h = h+ newHours;
        if(h > 23) {
            h = h % 24;
        }
        m = minutes % 60;
        printf("%02d:", h);
        printf("%02d\n", m);
    }
}

// without using if statements
void addTime2(unsigned h, unsigned m , unsigned dMin){
    unsigned    totalMinutes = h*60 + m + dMin;
    unsigned  newHour = totalMinutes / 60 % 24;
    unsigned  newMinute = totalMinutes % 60;

    printf ( "New time is %02d:%02d\n" , newHour, newMinute);
}
int main(){

    addTime(17, 54, 5);
    addTime(17, 59, 5);
    addTime(17, 59, 125);
    addTime(17, 59, 485);

    printf("\nAddTime2 - without using if-statements \n");
    addTime2(17,54,5);
    addTime2(17,59,5);
    addTime2(17,59,125);
    addTime2(17,59,485);

    return 0;
}