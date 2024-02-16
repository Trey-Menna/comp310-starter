// main.c

#include "token.h"
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[1024];  // Assuming a maximum input length of 1024 characters

    // Read input from standard input
    printf("Enter FORTH program:\n");
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
        } else if (strchr(":;", token[0]) != NULL) {
            type = SYMBOL;
        } else {
            type = WORD;
        }

        // Create and display the token
        token_t *new_token = create_token(type, token);
        printf("Type: %d, Text: %s\n", new_token->type, new_token->text);

        // Free memory allocated for the token
        free_token(new_token);

        // Get the next token
        token = strtok(NULL, " ");
    }

    return 0;
}
