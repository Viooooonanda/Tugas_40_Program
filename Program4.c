#include <stdio.h>
#include <string.h>

float hitung_Asuransi(char jenis_ladang[], float nilaiTanggungan_perHektar, int luas){
    float biaya_standar, biayaAsuransi;

    biaya_standar = 0.035 * nilaiTanggungan_perHektar * luas;

    if(strcmp(jenis_ladang, "Kacang kedelai") == 0 ||
       strcmp(jenis_ladang, "kentang") == 0 ||
       strcmp(jenis_ladang, "bawang merah") == 0 ||
       strcmp(jenis_ladang, "cabai") == 0){
        biayaAsuransi = 2 * biaya_standar;
    }
    else if(strcmp(jenis_ladang, "padi") == 0 ||
            strcmp(jenis_ladang, "singkong") == 0 ||
            strcmp(jenis_ladang, "jagung") == 0){
        biayaAsuransi = 1.5 * biaya_standar;
    }
    else{
        biayaAsuransi = biaya_standar;
    }

    return biayaAsuransi;
}

void cetakSlip(char nama_petani[], char jenis[][50], float biaya[], float total_biaya, int jumlah_ladang){
    printf("\n=== Slip Pembayaran Asuransi ===\n");
    printf("Nama Petani: %s\n", nama_petani);

    for(int i = 0; i < jumlah_ladang; i++){
        printf("Jenis ladang: %s | Biaya Asuransi: %.2f\n", jenis[i], biaya[i]);
    }

    printf("Total asuransi yang harus dibayar: %.2f\n", total_biaya);
}

int main(){
    char nama_petani[100];
    char jenis_ladang[3][50];
    int jumlah_ladang, luas[3];
    float nilaiTanggungan_perHektar[3];
    float biaya[3], total_biaya = 0;

    printf("Masukkan nama Petani: ");
    fgets(nama_petani, sizeof(nama_petani), stdin);
    nama_petani[strcspn(nama_petani, "\n")] = 0;

    printf("Masukkan jumlah ladang (maks 3): ");
    scanf("%d", &jumlah_ladang);
    getchar(); 

    printf("\n");
    for(int i = 0; i < jumlah_ladang; i++){
        printf("Jenis ladang : Kacang Keledai, Kentang, Bawang Merah, Cabai\n");
        printf("Jenis ladang : padi, singkong, jagung");
        printf("\n");
        printf("\nMasukkan jenis ladang ke-%d: ", i+1);
        fgets(jenis_ladang[i], sizeof(jenis_ladang[i]), stdin);
        jenis_ladang[i][strcspn(jenis_ladang[i], "\n")] = 0;

        printf("Masukkan nilai tanggungan per hektar: ");
        scanf("%f", &nilaiTanggungan_perHektar[i]);

        printf("Masukkan luas ladang (hektar): ");
        scanf("%d", &luas[i]);
        getchar();

        printf("\n");

        biaya[i] = hitung_Asuransi(jenis_ladang[i], nilaiTanggungan_perHektar[i], luas[i]);
        total_biaya += biaya[i];
    }

    cetakSlip(nama_petani, jenis_ladang, biaya, total_biaya, jumlah_ladang);

    return 0;
}