#include <stdio.h>

int main() {
    char nama[50];
    int pilihan, lama;
    float harga_per_malam, total, pajak, total_bayar;

    printf("=== PROGRAM WISMA TENANG ===\n");

    printf("Masukkan nama tamu: ");
    scanf(" %[^\n]", nama);

    printf("\nJenis Kamar:\n");
    printf("1. Single (Rp 200000)\n");
    printf("2. Double (Rp 350000)\n");
    printf("3. Keluarga (Rp 500000)\n");
    printf("4. VIP (Rp 450000)\n");
    printf("5. Bungalow (Rp 750000)\n");
    printf("Pilih kamar (1-5): ");
    scanf("%d", &pilihan);

    printf("Lama menginap (malam): ");
    scanf("%d", &lama);

    switch(pilihan) {
        case 1: harga_per_malam = 200000; break;
        case 2: harga_per_malam = 350000; break;
        case 3: harga_per_malam = 500000; break;
        case 4: harga_per_malam = 450000; break;
        case 5: harga_per_malam = 750000; break;
        default:
            printf("Pilihan tidak valid!\n");
            return 0;
    }

    total = harga_per_malam * lama;
    pajak = 0.15 * total;
    total_bayar = total + pajak;

    printf("\n=== BUKTI PEMBAYARAN ===\n");
    printf("Nama Tamu        : %s\n", nama);
    printf("Lama Menginap    : %d malam\n", lama);
    printf("Harga per malam  : Rp %.0f\n", harga_per_malam);
    printf("Total biaya      : Rp %.0f\n", total);
    printf("Pajak (15%%)     : Rp %.0f\n", pajak);
    printf("Total Bayar      : Rp %.0f\n", total_bayar);

    return 0;
}