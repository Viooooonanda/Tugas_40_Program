#include <stdio.h>

int main() {
    int angka, i;
    int prima = 1; 


    printf("Masukkan Angka: ");
    scanf("%d", &angka);

    if (angka < 2) {
        prima = 0;
    } else {

        for (i = 2; i <= angka - 1; i++) {
            if (angka % i == 0) {
                prima = 0;
                break;
            }
        }
    }

    if (prima == 1) {
        printf("%d adalah bilangan prima\n", angka);
    } else {
        printf("%d bukan bilangan prima\n", angka);
    }

    return 0;
}