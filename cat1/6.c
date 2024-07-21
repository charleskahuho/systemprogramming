#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    FILE *fptr;
    char filename[100], str[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Consume the newline character left by scanf
    getchar(); 

    fptr = fopen(filename, "a");

    if (fptr == NULL) {
        printf("Cannot open file '%s' for appending: %s\n", filename, strerror(errno));
        return 1;
    }

    printf("Enter a string to append to the file: ");
    fgets(str, 100, stdin);

    if (fprintf(fptr, "%s", str) < 0) {
        printf("Error writing to file '%s': %s\n", filename, strerror(errno));
        fclose(fptr);
        return 1;
    }

    fclose(fptr);

    printf("String appended to file successfully.\n");

    return 0;
}
