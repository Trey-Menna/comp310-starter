#include <stdio.h>

// Function to calculate factorial using recursion
int factorial(int n) {
// If number is less than or equal to zero return a fail/1, return n!
    if (n <= 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int number = 5;
    printf("Factorial of %d is: %d\n", number, factorial(number));

    return 0;
}
