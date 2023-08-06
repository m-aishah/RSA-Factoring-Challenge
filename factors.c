#include <stdio.h>
#include <stdlib.h>

void factorize(int number) {
    int factor1, factor2;

    for (int i = 2; i <= number / 2; ++i) {
        if (number % i == 0) {
            factor1 = i;
            factor2 = number / i;
            printf("%d=%d*%d\n", number, factor1, factor2);
            return;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2)
	    exit(EXIT_FAILURE);

    FILE *file;
    char *filename = argv[1];
    int number;

    /* Open the file in read mode*/
    file = fopen(filename, "r");
    if (file == NULL)
	    exit(EXIT_FAILURE);

    /* Read numbers from the file until the end is reached */
    while (fscanf(file, "%d", &number) != EOF) {
        factorize(number);
    }

    // Close the file
    fclose(file);

    return 0;
}

