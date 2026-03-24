#include <stdio.h>

int main() {
    char nama[50];
    float harga, total, diskon = 0, bayar, uang, kembalian;
    int jumlah;

    printf("Nama barang: ");
    scanf(" %c", nama);

    printf("Harga satuan: ");
    scanf("%f", &harga);

    printf("Jumlah barang: ");
    scanf("%d", &jumlah);

    total = harga * jumlah;

    if (jumlah >= 100)
        diskon = 0.20 * total;
    else if (jumlah >= 50)
        diskon = 0.15 * total;
    else if (jumlah >= 25)
        diskon = 0.10 * total;
    else if (jumlah >= 10)
        diskon = 0.05 * total;

    bayar = total - diskon;

    printf("\n===== SLIP PEMBAYARAN =====\n");
    printf("Nama Barang : %s\n", nama);
    printf("Total Harga : %.2f\n", total);
    printf("Diskon      : %.2f\n", diskon);
    printf("Total Bayar : %.2f\n", bayar);

    printf("Uang dibayar: ");
    scanf("%f", &uang);

    if (uang > bayar) {
        kembalian = uang - bayar;
        printf("Kembalian   : %.2f\n", kembalian);
    } else if (uang == bayar) {
        printf("Uang pas.\n");
    } else {
        printf("Uang tidak cukup!\n");
    }

    return 0;
}