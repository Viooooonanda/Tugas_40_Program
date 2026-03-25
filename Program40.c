#include <stdio.h>
#include <string.h>

int main() {
    char nama[50];
    char jenisGaji[20];

    float gajiPokok, upahHarian, uangTransport;
    float hasilPenjualan, nilaiTransaksi;
    float gajiKotor, pajak, gajiBersih;

    int hariKerja;

    printf("Masukkan nama pegawai: ");
    fgets(nama, sizeof(nama), stdin);

    printf("Masukkan jenis gaji [Harian/Bulanan/Komisi/Prestasi]: ");
    scanf("%s", jenisGaji);

    if (strcmp(jenisGaji, "Harian") == 0) {
        printf("Masukkan Hari Kerja: ");
        scanf("%d", &hariKerja);

        printf("Masukkan Upah Harian: ");
        scanf("%f", &upahHarian);

        gajiKotor = hariKerja * upahHarian;

    } else if (strcmp(jenisGaji, "Bulanan") == 0) {
        printf("Masukkan Gaji Pokok: ");
        scanf("%f", &gajiPokok);

        printf("Masukkan Hari Kerja: ");
        scanf("%d", &hariKerja);

        printf("Masukkan Uang Transport: ");
        scanf("%f", &uangTransport);

        gajiKotor = gajiPokok + (hariKerja * uangTransport);

    } else if (strcmp(jenisGaji, "Komisi") == 0) {
        printf("Masukkan Gaji Pokok: ");
        scanf("%f", &gajiPokok);

        printf("Masukkan Hasil Penjualan: ");
        scanf("%f", &hasilPenjualan);

        gajiKotor = gajiPokok + (0.05 * hasilPenjualan);

    } else if (strcmp(jenisGaji, "Prestasi") == 0) {
        printf("Masukkan Gaji Pokok: ");
        scanf("%f", &gajiPokok);

        printf("Masukkan Nilai Transaksi: ");
        scanf("%f", &nilaiTransaksi);

        gajiKotor = gajiPokok + (0.10 * nilaiTransaksi);

    } else {
        printf("Jenis gaji tidak valid!\n");
        return 0;
    }

    if (gajiKotor <= 1500000) {
        pajak = 0;
    } else if (gajiKotor <= 10000000) {
        pajak = 0.05 * gajiKotor;
    } else if (gajiKotor <= 25000000) {
        pajak = 0.10 * gajiKotor;
    } else {
        pajak = 0.15 * gajiKotor;
    }

    gajiBersih = gajiKotor - pajak;

    printf("\n=== DATA GAJI PEGAWAI ===\n");
    printf("Nama Pegawai : %s", nama);
    printf("Jenis Gaji   : %s\n", jenisGaji);
    printf("Gaji Kotor   : %.2f\n", gajiKotor);
    printf("Pajak        : %.2f\n", pajak);
    printf("Gaji Bersih  : %.2f\n", gajiBersih);

    return 0;
}