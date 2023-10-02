#include <stdio.h>

int main() {
    char symbol = 'A';
    int stringLength = 8;
    char output[9]; // make sure the output buffer is large enough to accommodate the formatted string and null terminator

    snprintf(output, stringLength + 1, "%.*s", stringLength, &symbol);

    printf("Formatted string: %s\n", output);

    return 0;
}
