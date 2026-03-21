#include <stdio.h>

float Depresiasi_tahunanSYD(float aset, float lama_tahun, float tahun_ke){
    float jumlah_tahun, faktor, depresiasi;

    jumlah_tahun = lama_tahun * (lama_tahun + 1) / 2;
    faktor = (lama_tahun - tahun_ke + 1) / jumlah_tahun;
    depresiasi = faktor * aset;

    return depresiasi;
}

int main(){
    float aset, lama_tahun, tahun_sekarang;
    float depresiasi;
    int i;

    printf("Masukkan Nilai Aset: ");
    scanf("%f", &aset);

    printf("Masukkan lama depresiasi (tahun): ");
    scanf("%f", &lama_tahun);

    printf("Masukkan tahun sekarang: ");
    scanf("%f", &tahun_sekarang);

    printf("\n=== Depresiasi Tahunan (Metode SYD) ===\n");

    for(i = 1; i <= lama_tahun; i++){
        depresiasi = Depresiasi_tahunanSYD(aset, lama_tahun, i);
        printf("Tahun %.0f: Depresiasi = %.2f\n", tahun_sekarang + i - 1, depresiasi);
    }

    return 0;
}