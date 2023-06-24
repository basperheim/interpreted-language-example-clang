#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_SIZE 1000

void interpret(const char* code) {
    const char* delimiter = " \t\n";

    char code_copy[MAX_CODE_SIZE];
    strncpy(code_copy, code, sizeof(code_copy));
    code_copy[sizeof(code_copy) - 1] = '\0';

    char* token = strtok(code_copy, delimiter);
    while (token != NULL) {
        if (strcmp(token, "print") == 0) {
            token = strtok(NULL, delimiter);  // Get the next token after "print"
            if (token != NULL) {
                printf("Printed: %s\n", token);
            } else {
                fprintf(stderr, "Error: Missing argument for print\n");
            }
        }

        token = strtok(NULL, delimiter);  // Get the next token
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./interpreter <filename>\n");
        return 1;
    }

    // Read the code from the file
    const char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open the file '%s'\n", filename);
        return 1;
    }

    // Determine the file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    // Allocate a buffer to store the code
    char* code = (char*)malloc(size + 1);
    if (!code) {
        fprintf(stderr, "Memory allocation error\n");
        fclose(file);
        return 1;
    }

    // Read the code into the buffer
    if (fread(code, 1, size, file) != size) {
        fprintf(stderr, "Failed to read the file '%s'\n", filename);
        free(code);
        fclose(file);
        return 1;
    }

    // Null-terminate the code string
    code[size] = '\0';

    // Interpret the code
    interpret(code);

    // Clean up
    free(code);
    fclose(file);

    return 0;
}