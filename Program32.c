#include <stdio.h>

int main (){
    float tagihan, diskon = 0, pajak, layanan, total;
    int cara;

    printf("Masukkan total tagihan: ");
    scanf("%f", &tagihan);

    printf("Cara pembayaran (1 = Kartu ABC, 2 = Lainnya): ");
    scanf("%d", &cara);

    if (tagihan < 500000){
    printf("Tidak mendapatkan diskon!\n");
    } else {
        if(cara == 1)
            diskon = 0.25 * tagihan;
        else
            diskon = 0.10 * tagihan;
    } 
    float HargaDiskon = tagihan - diskon;
    pajak = 0.11 * HargaDiskon;
    layanan = 0.5 * HargaDiskon;
    total = HargaDiskon + pajak + layanan;

    printf("\n");
    printf("*-* --- TAGIHAN --- *-* \n");
    printf("Tagihan awal : %.2f\n", tagihan);
    printf("Diskon : %.2f\n", diskon);
    printf("Pajak (11%%) : %.2f\n", pajak);
    printf("Layanan (5%%) : %.2f\n", layanan);
    printf("Total semuanya : %.2f\n", total);

    return 0;
}