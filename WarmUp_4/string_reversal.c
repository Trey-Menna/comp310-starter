#include <stdio.h>

void reverseString(char str[]) {
    // Find the length of the string
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    // Swap characters from the beginning and end of the string
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char str[] = "Hello";
    
    // Call the function to reverse the string
    reverseString(str);
    
    // Print the reversed string
    printf("%s\n", str);

    return 0;
}
