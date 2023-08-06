#include <stdio.h>
#include <stdlib.h>

void factorize(long long int number) {
    long long int factor1, factor2;

    if (number < 2) {
        printf("%lld=1*%lld\n", number, number);
        return;
    }

    number = llabs(number);

    for (long long int i = 2; i <= number / 2; ++i) {
        if (number % i == 0) {
            factor1 = i;
            factor2 = number / i;
            printf("%lld=%lld*%lld\n", number, factor1, factor2);
            return;
        }
    }

    printf("%lld=%lld*1\n", number, number);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file;
    char *filename = argv[1];
    long long int number;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    while (fscanf(file, "%lld", &number) != EOF) {
        factorize(number);

        char c;
        do {
            c = fgetc(file);
        } while (c != '\n' && c != EOF);
    }

    fclose(file);

    return 0;
}

