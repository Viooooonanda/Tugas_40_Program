#include <stdio.h>

int main() {
    int pilihan, bulan;
    float iuran = 0, total;

    printf("===== JENIS KEANGGOTAAN =====\n");
    printf("1. Dewasa (200000)\n");
    printf("2. Anak-anak (150000)\n");
    printf("3. 1 Dewasa & 1 Anak (300000)\n");
    printf("4. Keluarga (500000)\n");

    printf("Pilih keanggotaan: ");
    scanf("%d", &pilihan);

    printf("Lama keanggotaan (bulan): ");
    scanf("%d", &bulan);

    switch (pilihan) {
        case 1: iuran = 200000; break;
        case 2: iuran = 150000; break;
        case 3: iuran = 300000; break;
        case 4: iuran = 500000; break;
        default:
            printf("Pilihan tidak valid!\n");
            return 0;
    }

    total = iuran * bulan;

    printf("\n===== DATA PEMBAYARAN =====\n");
    printf("Iuran per bulan : %.2f\n", iuran);
    printf("Total bayar     : %.2f\n", total);

    return 0;
}