#include <stdio.h>

void Hitung_Pajak_StraightLine(float nilai_awal, int umur){
    float depresiasiTahunan, nilai_sisa, pajak, total_pajak = 0;

    depresiasiTahunan = nilai_awal / umur;

    printf("\n=== Metode Straight Line ===\n");

    for(int tahun = 1; tahun <= umur; tahun++){
        nilai_sisa = nilai_awal - (depresiasiTahunan * (tahun - 1));
        pajak = 0.05 * nilai_sisa;
        total_pajak += pajak;

        printf("Tahun %d : Nilai sisa = %.2f, Pajak = %.2f\n", tahun, nilai_sisa, pajak);
    }

    printf("Total pajak (Straight Line) = %.2f\n", total_pajak);
}

void Hitung_pajak_SYD(float nilai_awal, int umur){
    float jumlah_tahun, nilai_sisa, depresiasi, pajak, total_pajak = 0;

    jumlah_tahun = umur * (umur + 1) / 2.0;
    nilai_sisa = nilai_awal;

    printf("\n=== Metode SYD ===\n");

    for(int tahun = 1; tahun <= umur; tahun++){
        depresiasi = ((umur - tahun + 1) / jumlah_tahun) * nilai_awal;
        nilai_sisa -= depresiasi;
        pajak = 0.05 * nilai_sisa;
        total_pajak += pajak;

        printf("Tahun %d : Nilai sisa = %.2f, Pajak = %.2f\n", tahun, nilai_sisa, pajak);
    }

    printf("Total pajak (SYD) = %.2f\n", total_pajak);
}

int main(){
    float nilai_awal;
    int umur, pilihan;

    printf("=== MENU PERHITUNGAN PAJAK ===\n");
    printf("1. Metode Straight Line\n");
    printf("2. Metode SYD\n");

    printf("Pilih metode (1/2): ");
    scanf("%d", &pilihan);

    printf("Masukkan nilai awal aset: ");
    scanf("%f", &nilai_awal);

    printf("Masukkan umur: ");
    scanf("%d", &umur);

    switch(pilihan){
        case 1:
            Hitung_Pajak_StraightLine(nilai_awal, umur);
            break;

        case 2:
            Hitung_pajak_SYD(nilai_awal, umur);
            break;

        default:
            printf("Pilihan tidak valid!\n");
    }

    return 0;
}