#include <stdio.h>

int main() {
    // File name
    const char* filename = "example.txt";

    // Create a file and write data into it
    FILE* file = fopen(filename, "w");
    if (file != NULL) {
        fprintf(file, "Hello, World!");
        fclose(file);

        // Read data from the file
        file = fopen(filename, "r");
        if (file != NULL) {
            char buffer[256];
            while (fgets(buffer, sizeof(buffer), file) != NULL) {
                printf("%s", buffer);
            }
            fclose(file);
        } else {
            printf("Error opening file for reading.\n");
        }
    } else {
        printf("Error opening file for writing.\n");
    }

    return 0;
}
