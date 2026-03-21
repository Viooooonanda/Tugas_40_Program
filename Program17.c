#include <stdio.h>

void hitungModulo() {
    int nilai, mod, hasil;

    printf("\n=== MODULO ===\n");
    printf("Masukkan nilai: ");
    scanf("%d", &nilai);
    printf("Masukkan nilai modulo: ");
    scanf("%d", &mod);

    if (mod == 0) {
        printf("Error: Modulo tidak boleh nol.\n");
    } else {
        hasil = nilai % mod;
        printf("Hasil %d mod %d = %d\n", nilai, mod, hasil);
    }
}

int gcd(int a, int b) {
    while (b != 0) {
        int sisa = a % b;
        a = b;
        b = sisa;
    }
    return a;
}

void hitungGCD() {
    int m, n;

    printf("\n=== PBB / GCD ===\n");
    printf("Masukkan bilangan pertama (m): ");
    scanf("%d", &m);
    printf("Masukkan bilangan kedua (n): ");
    scanf("%d", &n);

    int hasil = gcd(m, n);

    printf("PBB(%d, %d) = %d\n", m, n, hasil);

    printf("Kombinasi linear (contoh sederhana): %d\n", hasil);
}

int main() {
    int pilihan;
    char ulang;

    do {
        printf("\n=== MENU PROGRAM ===\n");
        printf("1. Hitung Modulo\n");
        printf("2. Hitung PBB (GCD)\n");
        printf("Pilih menu (1/2): ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                hitungModulo();
                break;
            case 2:
                hitungGCD();
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }

        printf("\nApakah ingin mengulang? (y/n): ");
        scanf(" %c", &ulang);

    } while (ulang == 'y' || ulang == 'Y');

    printf("Terima kasih!\n");
    return 0;
}