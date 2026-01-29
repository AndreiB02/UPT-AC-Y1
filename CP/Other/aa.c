
int sqr(int x){
    return x*x;
}

void printLastDigits(int x){
    while(x != 0){
            printf("last digit %i \n", x % 10 );
            x = x /10;
    }
    printf("\n");
    return;
}
int countDigits(int n){
    int counter = 0;
    while(n != 0){
        counter = counter +1; // counter ++;
        n = n/10;
    }
    return counter;

}
int maximum_of_two_numbers(int a, int b){
    if(a > b) 
        return a;
    else    
        return b;
}

int main(){

    
    int number1 = 10;
    int number2 = 55;
    int max = maximum_of_two_numbers(number1,number2);
    printf("the maximum of the numbers is: %i\n", max);
    // unsigned number3 =343;
    // float x = 5.5;
    // double y  = 7.6788908;
    // char letter = 'y';
    int remainder = number1 % number2;
    int c = number1/number2;
    int originalNumber = c * number2 + remainder;
   // printf("Hello %c this \n is a letter\n" , letter);
    printf("this is the sum %i !\n\n", originalNumber);


    // 2613 = 3 + 261 * 10
    int number = 12345;
    int number_of_digits = countDigits(number);
    printf("Number %i has %i digits\n", number, number_of_digits);
    // printf("last digit %i \n", number % 10 );
    // number = number /10;
    // printf("last digit %i \n", number % 10 );
    // number = number /10;
    // printf("last digit %i \n", number % 10 );
    // number = number /10;
    // printf("last digit %i \n", number % 10 );
    // number = number /10;
    // printf("last digit %i \n", number % 10 );
    // number = number /10;
    // printf("last digit %i \n", number % 10 );
                
    //printLastDigits(4567);
    //printLastDigits(12345);
    return 0;
}