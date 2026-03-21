#include <stdio.h>

#define MAX_MAHASISWA 100

void MasukkanJumlahSiswa(int *n) {
    printf("Masukkan jumlah siswa: ");
    scanf("%d", n);
}

void InisialisasiVariabel(float *total_nilai, int *jumlah_A, int *jumlah_B, int *jumlah_C, int *jumlah_D) {
    *total_nilai = 0;
    *jumlah_A = 0;
    *jumlah_B = 0;
    *jumlah_C = 0;
    *jumlah_D = 0;
}

float HitungNilaiAkhir(float Tugas, float UTS, float UAS) {
    return (0.3 * Tugas) + (0.3 * UTS) + (0.4 * UAS);
}

float ProsesRemedial(float nilai_akhir) {
    float remedial;
    if (nilai_akhir < 60) {
        printf("Anda harus remedial. Nilai anda = %.2f\n", nilai_akhir);
        printf("Masukkan nilai remedial: ");
        scanf("%f", &remedial);
        return remedial;
    }
    return nilai_akhir;
}

void UpdateJumlahPredikat(float nilai_akhir, int *jumlah_A, int *jumlah_B, int *jumlah_C, int *jumlah_D) {
    if (nilai_akhir >= 80) {
        (*jumlah_A)++;
    } else if (nilai_akhir >= 70) {
        (*jumlah_B)++;
    } else if (nilai_akhir >= 60) {
        (*jumlah_C)++;
    } else {
        (*jumlah_D)++;
    }
}

void CariMaxMin(float nilai[MAX_MAHASISWA], int n, float *max_nilai, float *min_nilai) {
    *max_nilai = nilai[0];
    *min_nilai = nilai[0];
    for (int i = 1; i < n; i++) {
        if (nilai[i] > *max_nilai) {
            *max_nilai = nilai[i];
        }
        if (nilai[i] < *min_nilai) {
            *min_nilai = nilai[i];
        }
    }
}

float HitungRataRata(float total_nilai, int n) {
    return total_nilai / n;
}

void RekapitulasiHasil(float rata_rata, int jumlah_A, int jumlah_B, int jumlah_C, int jumlah_D, float max_nilai, float min_nilai) {
    printf("Rata-rata nilai kelas: %.2f\n", rata_rata);
    printf("Jumlah Mahasiswa Predikat A: %d\n", jumlah_A);
    printf("Jumlah Mahasiswa Predikat B: %d\n", jumlah_B);
    printf("Jumlah Mahasiswa Predikat C: %d\n", jumlah_C);
    printf("Jumlah Mahasiswa Predikat D: %d\n", jumlah_D);
    printf("Nilai Tertinggi: %.2f\n", max_nilai);
    printf("Nilai Terendah: %.2f\n", min_nilai);
}

int main() {
    int n;
    float total_nilai, max_nilai, min_nilai;
    int jumlah_A, jumlah_B, jumlah_C, jumlah_D;
    float nilai[MAX_MAHASISWA];

    MasukkanJumlahSiswa(&n);
    InisialisasiVariabel(&total_nilai, &jumlah_A, &jumlah_B, &jumlah_C, &jumlah_D);

    for (int i = 0; i < n; i++) {
        float Tugas, UTS, UAS, nilai_akhir;

        printf("Masukkan nilai Tugas, UTS, UAS untuk mahasiswa %d: ", i + 1);
        scanf("%f %f %f", &Tugas, &UTS, &UAS);

        nilai_akhir = HitungNilaiAkhir(Tugas, UTS, UAS);
        nilai_akhir = ProsesRemedial(nilai_akhir);
        nilai[i] = nilai_akhir;

        total_nilai += nilai_akhir;
        UpdateJumlahPredikat(nilai_akhir, &jumlah_A, &jumlah_B, &jumlah_C, &jumlah_D);
    }

    CariMaxMin(nilai, n, &max_nilai, &min_nilai);
    float rata_rata = HitungRataRata(total_nilai, n);
    RekapitulasiHasil(rata_rata, jumlah_A, jumlah_B, jumlah_C, jumlah_D, max_nilai, min_nilai);

    return 0;
}
