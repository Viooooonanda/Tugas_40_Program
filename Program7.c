#include <stdio.h>
#include <string.h>

float hitung_break_even_point(int jumlah_buku, float biaya_tetap, int jumlah_halaman){
    float biayaProduksi, hargaBreakEven;

    biayaProduksi = biaya_tetap + jumlah_buku * (jumlah_halaman * 0.0305);
    hargaBreakEven = biayaProduksi / jumlah_buku;

    return hargaBreakEven;
}

int main(){
    char judul[100];
    int jumlah_buku, jumlah_halaman;
    float biaya_tetap, hargaBreakEven;

    printf("Program Hitung Break Even BUKU\n");

    do{
        printf("\nMasukkan Judul Buku: ");
        fgets(judul, sizeof(judul), stdin);

        judul[strcspn(judul, "\n")] = 0;

        if(strcmp(judul, "End of data") == 0){
            break;
        }

        printf("Masukkan Jumlah Buku: ");
        scanf("%d", &jumlah_buku);

        printf("Masukkan biaya tetap: ");
        scanf("%f", &biaya_tetap);

        printf("Masukkan jumlah halaman: ");
        scanf("%d", &jumlah_halaman);

        getchar();

        hargaBreakEven = hitung_break_even_point(jumlah_buku, biaya_tetap, jumlah_halaman);

        printf("\nJudul Buku: %s\n", judul);
        printf("Harga Jual Break-even per Buku: %.2f\n", hargaBreakEven);

    } while(1);

    return 0;
}