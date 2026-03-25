#include <stdio.h>

int main() {
    int N, sisa, jumlah = 0;
    int digit[100]; 
    int i = 0;

    printf("Masukkan sebuah bilangan integer: ");
    scanf("%d", &N);

    while (N > 0) {
        sisa = N % 10;     
        jumlah = jumlah + sisa; 
        digit[i] = sisa;     
        i++;
        N = N / 10;             
    }

    printf("Digit-digit angka: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d ", digit[j]);
    }

    printf("\nJumlah digit = %d\n", jumlah);

    return 0;
}