#include "token.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Maximum number of variables
#define MAX_VARIABLES 100

// Structure to hold variables
typedef struct {
    char name[20];  // Assuming maximum variable name length of 20 characters
    int value;
} Variable;

// Array to store variables
Variable variables[MAX_VARIABLES];

// Number of variables currently defined
int num_variables = 0;

// Function to find a variable by name
int find_variable(const char* name) {
    for (int i = 0; i < num_variables; ++i) {
        if (strcmp(variables[i].name, name) == 0) {
            return i;
        }
    }
    return -1;  // Variable not found
}

int main() {
    char input[1024];  // Assuming a maximum input length of 1024 characters

    // Read input from standard input
    printf("Enter R-FORTH program:\n");
    fgets(input, sizeof(input), stdin);

    // Tokenize the input
    char *token = strtok(input, " ");
    while (token != NULL) {
        // Classify each token based on basic checks
        token_type_t type;
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            type = NUMBER;
        } else if (strchr("+-*/", token[0]) != NULL) {
            type = OPERATOR;
        } else if (strcmp(token, "CONSTANT") == 0) {
            type = CONSTANT;
        } else if (strcmp(token, "VARIABLE") == 0) {
            type = VARIABLE;
        } else if (strchr(":;", token[0]) != NULL) {
            type = SYMBOL;
        } else {
            type = WORD;
        }

        // Create and display the token
        token_t *new_token = create_token(type, token);
        printf("Type: %d, Text: %s\n", new_token->type, new_token->text);

        if (type == CONSTANT) {
            // Define a constant
            // Fetch the constant value
            token = strtok(NULL, " ");
            int value = atoi(token);
            // Store the constant
            // For simplicity, assume constant names immediately follow the "CONSTANT" token
            strcpy(variables[num_variables].name, token);
            variables[num_variables].value = value;
            num_variables++;
        } else if (type == VARIABLE) {
            // Define a variable
            // For simplicity, assume variable names immediately follow the "VARIABLE" token
            strcpy(variables[num_variables].name, strtok(NULL, " "));
            num_variables++;
        }

        // Free memory allocated for the token
        free_token(new_token);

        // Get the next token
        token = strtok(NULL, " ");
    }

    return 0;
}
