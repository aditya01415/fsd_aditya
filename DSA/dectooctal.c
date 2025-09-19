//wap to convert decimal to octal
#include<stdio.h>
void decimalToOctal(int n) {
    int octal[32]; // Assuming a maximum of 32 digits for the octal representation
    int i = 0;

    while (n > 0) {
        octal[i] = n % 8;
        n = n / 8;
        i++;
    }

    printf("Octal representation: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}

int main() {
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    decimalToOctal(decimal);

    return 0;
}
