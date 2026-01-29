/*
We have 3 cases:
1) we dont need to add any sum of money
2) we need to add funds, but its less than 5.50(2 trips)
3) we need to add funds, and we get a bonus of 5%
*/

#include <stdio.h>
#include <math.h>

double tripsMetroCard(double cardBalance, int numberOfTrips){
    printf("Card balance: %.2fUSD. No. of trips:%d\n", cardBalance, numberOfTrips);
    double priceOfTrip = 2.75;
    double cardAddingStep = 0.05;
    double addAmount;
    if(numberOfTrips * priceOfTrip <= cardBalance){ 
        printf("Sufficient funds for %d trips\n", numberOfTrips);
        addAmount = 0.0;
    }
    else{

        double requiredSum = numberOfTrips * priceOfTrip - cardBalance;
        requiredSum = ceil(requiredSum/cardAddingStep)*cardAddingStep;
        if(requiredSum  < 2 * priceOfTrip){ // if added sum<2trips
            printf("%.2fUSD more needed\n", requiredSum );
            cardBalance += requiredSum;
            addAmount = requiredSum;
        }  
        else{ 
            double sumWithoutBonus = requiredSum*100/105;
            sumWithoutBonus = ceil(sumWithoutBonus/cardAddingStep)*cardAddingStep;
            if(sumWithoutBonus < 5.50) sumWithoutBonus = 5.50; // if we need to add more than 2 trips, then we add for sure 5.50
            double bonus =  round(sumWithoutBonus * 0.05 * 100) / 100;
            // x + 5%100 * x = s | *100
            // 105x = 100s
            // x = 100s / 105
            printf("Required sum:%.2fUSD\n" , requiredSum);
            printf("You need to add %.2fUSD on your card\n", sumWithoutBonus);

            printf("Bonus is %.2fUSD\n", bonus);
            cardBalance += sumWithoutBonus + bonus;
            addAmount = sumWithoutBonus;
        }
        cardBalance -= numberOfTrips * priceOfTrip;
        printf("==========\n");
        printf("Remaining card balance is %.2f\n", cardBalance);
    }
    printf("|---------------------------------\n");

    return addAmount;
}


int main(){
    printf("%.2f\n", tripsMetroCard(2.71, 5)); // we get 5% bonus
    printf("%.2f\n", tripsMetroCard(2.71, 1)); // we dont get 5% bonus, sum<2 trips
    printf("%.2f\n", tripsMetroCard(5.50, 2));

    printf("%.2f\n", tripsMetroCard(0.00, 1)); 
    printf("%.2f\n", tripsMetroCard(0.00, 2)); 
    printf("%.2f\n", tripsMetroCard(2.71, 3));    
    printf("%.2f\n", tripsMetroCard(0.01, 2));  
    printf("%.2f\n", tripsMetroCard(0.03, 2)); 
    printf("%.2f\n", tripsMetroCard(0.00, 10)); 
    return 0;
}