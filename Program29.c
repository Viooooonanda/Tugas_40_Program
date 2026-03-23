#include <stdio.h>

int main() {
    float harga, total, cicilan;
    int jenis;

    printf("=== PROGRAM PEMBAYARAN APARTEMEN ===\n");
    printf("Masukkan harga apartemen: Rp ");
    scanf("%f", &harga);

    printf("\nJenis Pembayaran:\n");
    printf("1. Tunai langsung (Diskon 10%%)\n");
    printf("2. Tunai bertahap 6x (Diskon 5%%)\n");
    printf("3. Kredit pendek 12x (Tanpa diskon)\n");
    printf("4. Kredit menengah 24x (Bunga 10%%)\n");
    printf("5. Kredit panjang 60x (Bunga 25%%)\n");
    printf("Pilih jenis pembayaran (1-5): ");
    scanf("%d", &jenis);

    switch(jenis) {
        case 1:
            total = harga - (0.10 * harga);
            printf("\nTotal bayar: Rp %.2f\n", total);
            break;

        case 2:
            total = harga - (0.05 * harga);
            cicilan = total / 6;
            printf("\nTotal bayar: Rp %.2f\n", total);
            printf("Cicilan per bulan (6x): Rp %.2f\n", cicilan);
            break;

        case 3:
            total = harga;
            cicilan = total / 12;
            printf("\nTotal bayar: Rp %.2f\n", total);
            printf("Cicilan per bulan (12x): Rp %.2f\n", cicilan);
            break;

        case 4:
            total = harga + (0.10 * harga);
            cicilan = total / 24;
            printf("\nTotal bayar (dengan bunga): Rp %.2f\n", total);
            printf("Cicilan per bulan (24x): Rp %.2f\n", cicilan);
            break;

        case 5:
            total = harga + (0.25 * harga);
            cicilan = total / 60;
            printf("\nTotal bayar (dengan bunga): Rp %.2f\n", total);
            printf("Cicilan per bulan (60x): Rp %.2f\n", cicilan);
            break;

        default:
            printf("Pilihan tidak valid!\n");
    }

    return 0;
}