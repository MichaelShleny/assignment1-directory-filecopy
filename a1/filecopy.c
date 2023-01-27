#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: filecopy <input file> <output file>\n");
        exit(1);
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        printf("Error creating output file.\n");
        fclose(input);
        exit(1);
    }

    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        if (fwrite(buffer, 1, bytesRead, output) != bytesRead) {
            printf("Error writing to output file.\n");
            fclose(input);
            fclose(output);
            exit(1);
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}