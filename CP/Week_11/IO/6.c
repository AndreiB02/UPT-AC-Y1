/*
6. Running times 
Write a program that reads from input a list of finishing times in a race 
(given in increasing order), in the form h:mm:ss, one per line. 

Print the winning time on a line, and for each of the other finishing times, 
the difference with respect to the previous time, and with respect to the winning time. 
For example, for the input

3:51:38
4:05:47
4:11:28
the program should print
3:51:38
+0:14:09  0:14:09
+0:05:41  0:19:50
*/
#include <stdio.h>
#include <ctype.h>
int toSeconds(int hours, int minutes, int seconds){
    return hours*60*60 + minutes * 60 + seconds;
}
void printTimeDifferenceBetween(int currentTime_s, int previousTime_s){
    int difference = currentTime_s - previousTime_s;
    int diff_hour,diff_min, diff_sec;
    diff_hour = difference / 3600;
    diff_min = difference % 3600 / 60;
    diff_sec = difference % 3600 % 60; 
    if(difference > 0)
        printf("+");
    else
        printf("-");
    printf("%d:%02d:%02d", diff_hour,diff_min, diff_sec);

}

int main(){
    int win_hour, win_minute, win_second;
    int hour, minute, second;
    int previousTime_s = 0;
    int currentTime_s;
    if(scanf("%d:%2d:%2d", &win_hour, &win_minute, &win_second) != 3){
        printf("Input format error - win time\n");
        return 0;
    } else {
        /// printing winning time
        printf("%d:%02d:%02d\n", win_hour, win_minute, win_second);
        int winTime_s = toSeconds(win_hour,win_minute,win_second);
        previousTime_s = winTime_s;
        while(scanf("%d:%2d:%2d", &hour, &minute, &second) == 3)
        {
            currentTime_s = toSeconds(hour,minute,second);
            printTimeDifferenceBetween(currentTime_s, previousTime_s);
            printf("    ");
            printTimeDifferenceBetween(currentTime_s, winTime_s);
            printf("\n");
            previousTime_s = currentTime_s;
            //printf("%i : %i : %i\n", win_hour, win_minute, win_second);  
        }
        int c;
    while((c = getchar()) != EOF) {
        if(!isspace(c)) {
            printf("Invalid input format\n");
            break;
        }
    }

    if(c == EOF)
        printf("End of input\n");
    }
}