#include <stdio.h>
#include <stdlib.h>

int main(){
    int numbers[] = {1,2,3,4,5};
    int sum = 0;
    double average = 0;
    /*Calculates Legnth based on bytes*/
    int length = sizeof(numbers) / sizeof(numbers[0]);
    
    int i; 
    for(i = 0; i < length; i++)
    {
        sum = sum + numbers[i];
    }
    average = sum / length;

    printf("\nSum of Array: %d" , sum);
    printf("\nAverage of Array: %lf\n", average);


}