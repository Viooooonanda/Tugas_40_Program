#include <stdio.h>
#include <stdlib.h>

float hitungTagihan(float pemakaianAir) {
    float tagihan = 0;

    if (pemakaianAir <= 100) {
        tagihan = 200000;
    } else if (pemakaianAir <= 300) {
        tagihan = 200000 + (pemakaianAir - 100) * 2500;
    } else {
        tagihan = 500000 + (pemakaianAir - 300) * 3000;
    }

    return tagihan;
}

void tampilkanSlipTagihan(char* nama, float pemakaianAir, float tagihan) {
    printf("\n--- Slip Tagihan ---\n");
    printf("Nama Pelanggan: %s", nama);
    printf("Jumlah Pemakaian Air: %.2f m3\n", pemakaianAir);
    printf("Jumlah Tagihan: Rp. %.2f\n", tagihan);
}

void inputPelanggan(char* nama, float* meterBulanLalu, float* meterBulanIni) {
    printf("Masukkan nama pelanggan: ");
    fgets(nama, 50, stdin);

    do {
        printf("Masukkan angka meter bulan lalu (harus >= 0): ");
        scanf("%f", meterBulanLalu);
        if (*meterBulanLalu < 0) {
            printf("Input tidak valid. Angka meter bulan lalu tidak boleh negatif.\n");
        }
    } while (*meterBulanLalu < 0);

    do {
        printf("Masukkan angka meter bulan ini (harus >= meter bulan lalu): ");
        scanf("%f", meterBulanIni);
        if (*meterBulanIni < *meterBulanLalu) {
            printf("Input tidak valid. Angka meter bulan ini harus lebih besar atau sama dengan angka meter bulan lalu.\n");
        }
    } while (*meterBulanIni < *meterBulanLalu);
}

int main() {
    char nama[50];
    float meterBulanLalu, meterBulanIni, pemakaianAir, tagihan;

    inputPelanggan(nama, &meterBulanLalu, &meterBulanIni);

    pemakaianAir = meterBulanIni - meterBulanLalu;

    tagihan = hitungTagihan(pemakaianAir);

    tampilkanSlipTagihan(nama, pemakaianAir, tagihan);

    return 0;
}
