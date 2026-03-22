#include <stdio.h>

typedef struct {
    char nama[50];
    int meter_bulan_lalu;
    int meter_bulan_ini;
} Pelanggan;

void hitungPemakaianDanTagihan(Pelanggan *p, int *pemakaian, float *tagihan) {
    if (p->meter_bulan_ini < p->meter_bulan_lalu) {
        printf("Error: Meteran bulan ini lebih kecil dari bulan lalu.\n");
        *pemakaian = 0;
        *tagihan = 0.0;
        return;
    }

    *pemakaian = p->meter_bulan_ini - p->meter_bulan_lalu;

    if (*pemakaian <= 100) {
        *tagihan = 200000;
    } else if (*pemakaian <= 300) {
        *tagihan = 200000 + (*pemakaian - 100) * 2500;
    } else {
        *tagihan = 500000 + (*pemakaian - 300) * 3000;
    }
}

void cetakSlipTagihan(Pelanggan p, int pemakaian, float tagihan) {
    printf("Slip Tagihan Pelanggan: %s\n", p.nama);
    printf("Pemakaian Air: %d m3\n", pemakaian);
    printf("Tagihan yang Harus Dibayar: Rp. %.2f\n\n", tagihan);
}

int main() {
    Pelanggan p;
    int pemakaian;
    float tagihan;

    printf("Masukkan Nama Pelanggan: ");
    scanf(" %[^\n]", p.nama);
    printf("Masukkan Meter Bulan Lalu: ");
    scanf("%d", &p.meter_bulan_lalu);
    printf("Masukkan Meter Bulan Ini: ");
    scanf("%d", &p.meter_bulan_ini);

    hitungPemakaianDanTagihan(&p, &pemakaian, &tagihan);

    if (pemakaian > 0) {
        cetakSlipTagihan(p, pemakaian, tagihan);
    }

    return 0;
}
