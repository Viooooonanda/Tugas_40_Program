#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int angka_rahasia, tebakan;
    int kesempatan = 10;

    srand(time(NULL));

    angka_rahasia = rand() % 100 + 1;

    printf("=== GAME TEBAK ANGKA ===\n");
    printf("Tebak angka antara 1 - 100\n");
    printf("Anda memiliki %d kesempatan\n\n", kesempatan);

    while (kesempatan > 0) {
        printf("Masukkan tebakan anda: ");
        scanf("%d", &tebakan);

        if (tebakan > angka_rahasia) {
            printf("Tebakan anda terlalu besar. Coba lagi\n");
        } else if (tebakan < angka_rahasia) {
            printf("Tebakan anda terlalu kecil. Coba lagi\n");
        } else {
            printf("Selamat, tebakan anda benar!\n");
            break;
        }

        kesempatan--;
        printf("Sisa kesempatan: %d\n\n", kesempatan);
    }

    if (kesempatan == 0 && tebakan != angka_rahasia) {
        printf("\nKesempatan habis!\n");
        printf("Angka yang benar adalah: %d\n", angka_rahasia);
    }

    return 0;
}