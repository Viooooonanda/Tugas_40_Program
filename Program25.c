#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMaxNumber(int level) {
    if (level == 1) return 50;
    if (level == 2) return 100;
    if (level == 3) return 200;
    return 50;
}

int hitungSkor(int percobaan, int max) {
    int skor = (max * 10) - (percobaan * 5);
    if (skor < 0) skor = 0;
    return skor;
}

void mainGame() {
    int level, maxAngka;
    int angkaRahasia, tebakan;
    int percobaan = 0;
    int skor;

    printf("=== GAME TEBAK ANGKA ===\n");
    printf("Pilih Level:\n");
    printf("1. Mudah (1-50)\n");
    printf("2. Sedang (1-100)\n");
    printf("3. Sulit (1-200)\n");
    printf("Pilih: ");
    scanf("%d", &level);

    maxAngka = getMaxNumber(level);

    angkaRahasia = (rand() % maxAngka) + 1;

    printf("\nSaya sudah memilih angka antara 1 - %d\n", maxAngka);
    printf("Silakan tebak!\n");

    do {
        printf("Tebakan kamu: ");
        scanf("%d", &tebakan);
        percobaan++;

        if (tebakan > angkaRahasia) {
            printf("Terlalu besar!\n");
        } else if (tebakan < angkaRahasia) {
            printf("Terlalu kecil!\n");
        } else {
            printf("BENAR!\n");
        }

    } while (tebakan != angkaRahasia);

    skor = hitungSkor(percobaan, maxAngka);

    printf("\nJumlah percobaan: %d\n", percobaan);
    printf("Skor kamu: %d\n", skor);

    if (percobaan <= 3) {
        printf("Hebat sekali!\n");
    } else if (percobaan <= 6) {
        printf("Lumayan!\n");
    } else {
        printf("Coba lagi biar lebih baik!\n");
    }
}

int main() {
    int ulang;

    srand(time(NULL)); 

    do {
        mainGame();

        printf("\nMain lagi? (1 = ya / 0 = tidak): ");
        scanf("%d", &ulang);

    } while (ulang == 1);

    printf("\nTerima kasih sudah bermain!\n");

    return 0;
}