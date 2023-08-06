#include <stdio.h>

void factorize(long long int number) {
    long long int factor1, factor2;

    if (number == 0)
    {
	    printf("0=0*0\n");
	    return;
    }
    if (number == 1)
    {
	    printf("1=1*1\n");
	    return;
    }
    for (long long int i = 2; i <= number / 2; ++i) {
        if (number % i == 0) {
            factor1 = i;
            factor2 = number / i;
            printf("%lld=%lld*%lld\n", number, factor1, factor2);
            return;
        }
    }
    printf("%lld=%lld*%d\n", number, number, 1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file;
    char *filename = argv[1];
    long long int number;

    /* Open the file in read mode */
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    /* Read numbers from the file until the end is reached */
    while (fscanf(file, "%lld", &number) != EOF) {
        factorize(number);

        /* Skip the newline character after reading the number */
        char c;
        do {
            c = fgetc(file);
        } while (c != '\n' && c != EOF);
    }

    /* Close the file */
    fclose(file);

    return 0;
}

