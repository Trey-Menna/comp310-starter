#include <stdio.h>
#include <stdlib.h>

int main(){
    
    double x;
    double y;
    double sum;
    double difference;
    double product;
    double quotient;
    printf("Enter First Number: ");
    scanf("%lf", &x);
    printf("\nEnter Second Number: ");
    scanf("%lf", &y);
    
    sum = x + y;
    printf("\nSum: %lf", sum);

    difference = x - y;
    printf("\nDifference: %lf", difference);

    product = x * y;
    printf("\nProduct: %lf", product);

    quotient = x / y;
    printf("\nQuotient: %lf", quotient);
}