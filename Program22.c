#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nama[50];
    int jam_kerja;
    float upah_per_jam;
    int status_perkawinan; 
    int tanggungan;
} Pegawai;

float hitungUpahTotal(Pegawai p) {
    float lembur = 0.0;
    if (p.jam_kerja > 40) {
        lembur = (p.jam_kerja - 40) * (p.upah_per_jam * 1.5);
    }
    return (p.jam_kerja * p.upah_per_jam) + lembur;
}

float hitungPTKP(Pegawai p) {
    float ptkp = 400000; 
    if (p.status_perkawinan == 1) {
        ptkp += 350000; 
    }
    ptkp += p.tanggungan * 300000; 
    return ptkp;
}

float hitungPajak(Pegawai p) {
    float ptkp = hitungPTKP(p);
    float penghasilan_total = hitungUpahTotal(p);
    float pkp = penghasilan_total - ptkp;

    if (pkp <= 0) return 0; 

    if (pkp <= 1000000) return 0;
    else if (pkp <= 2500000) return pkp * 0.05;
    else if (pkp <= 5000000) return pkp * 0.10;
    else if (pkp <= 10000000) return pkp * 0.15;
    else return pkp * 0.20;
}

void cetakSlipGaji(Pegawai p) {
    float upah_total = hitungUpahTotal(p);
    float ptkp = hitungPTKP(p);
    float pajak = hitungPajak(p);

    printf("Slip Gaji Pegawai: %s\n", p.nama);
    printf("Total Upah: Rp. %.2f\n", upah_total);
    printf("PTKP: Rp. %.2f\n", ptkp);
    printf("PKP: Rp. %.2f\n", upah_total - ptkp);
    printf("Pajak Penghasilan yang Dibayarkan: Rp. %.2f\n\n", pajak);
}

int main() {
    FILE *file = fopen("pegawai.txt", "r");
    if (!file) {
        printf("Gagal membuka file\n");
        return 1;
    }

    Pegawai p;
    while (fscanf(file, "%s %d %f %d %d", 
           p.nama, &p.jam_kerja, &p.upah_per_jam, 
           &p.status_perkawinan, &p.tanggungan) != EOF) {
        cetakSlipGaji(p);
    }

    fclose(file);
    return 0;
}
