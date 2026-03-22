#include <stdio.h>

#define HARGA_PER_KG 7000
#define HARGA_SPREE 10000
#define HARGA_SELIMUT 15000

typedef enum {
    LAUNDRY_BIASA,
    LAUNDRY_EKPRESS
} JenisLaundry;

typedef struct {
    int jenis_laundry; 
    float berat;     
    int jumlah_sprei;
    int jumlah_selimut;
} Laundry;

float hitungTotalTagihan(Laundry laundry) {
    float total = 0.0;

    total += laundry.jumlah_sprei * HARGA_SPREE;
    total += laundry.jumlah_selimut * HARGA_SELIMUT;
    total += laundry.berat * HARGA_PER_KG;

    if (laundry.jenis_laundry == LAUNDRY_EKPRESS) {
        total += 5000; 
    }

    return total;
}

void cetakSlip(Laundry laundry) {
    printf("----- Slip Laundry -----\n");
    printf("Jenis Laundry: %s\n", laundry.jenis_laundry == LAUNDRY_EKPRESS ? "Ekspres" : "Biasa");
    printf("Berat Laundry: %.2f kg\n", laundry.berat);
    printf("Jumlah Sprei: %d\n", laundry.jumlah_sprei);
    printf("Jumlah Selimut: %d\n", laundry.jumlah_selimut);
    
    float total = hitungTotalTagihan(laundry);
    printf("Total Tagihan: Rp. %.2f\n", total);
}

int main() {
    Laundry laundry;

    printf("Masukkan jenis laundry (0 untuk biasa, 1 untuk ekspres): ");
    scanf("%d", &laundry.jenis_laundry);
    printf("Masukkan berat laundry (dalam kg): ");
    scanf("%f", &laundry.berat);
    printf("Masukkan jumlah sprei: ");
    scanf("%d", &laundry.jumlah_sprei);
    printf("Masukkan jumlah selimut: ");
    scanf("%d", &laundry.jumlah_selimut);

    cetakSlip(laundry);

    return 0;
}
