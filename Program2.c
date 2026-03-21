#include <stdio.h>
#include <string.h>

float hitung_biaya_parkir(int jenis, int lama){
    float Tarif_Dasar = 5000;
    float total;

    if(jenis == 1) total = Tarif_Dasar * lama;        // Mobil
    else if(jenis == 2) total = Tarif_Dasar * 0.5 * lama;  // Motor
    else if(jenis == 3) total = Tarif_Dasar * 2.0 * lama;  // Truk
    else total = 0;

    if (lama > 5){
        total = total - (0.10 * total);
    }

    return total;
}

void mencetak_Struk(char nama[], int jenis[], int lama[], float biaya[], int jumlah, float totalGrand){
    FILE *fptr;
    fptr = fopen("struk_pembayaran.txt","w");

    if (fptr == NULL){
        printf("Gagal membuka file karena Error");
        return;
    }

    printf("\n========= STRUK PEMBAYARAN UNTAR =========\n");
    fprintf(fptr, "========= STRUK PEMBAYARAN UNTAR =========\n");

    printf("Nama Pelanggan: %s\n", nama);
    fprintf(fptr, "Nama Pelanggan: %s\n", nama);

    printf("------------------------------------------\n");
    fprintf(fptr, "------------------------------------------\n");

    for (int i = 0; i < jumlah; i++) {
        char namaJenis[10];
        if (jenis[i] == 1) strcpy(namaJenis, "Mobil");
        else if (jenis[i] == 2) strcpy(namaJenis, "Motor");
        else strcpy(namaJenis, "Truk");

        printf("Kendaraan %d: %-6s | %2d Jam | Rp. %.2f\n",
               i + 1, namaJenis, lama[i], biaya[i]);

        fprintf(fptr, "Kendaraan %d: %-6s | %2d Jam | Rp. %.2f\n",
                i + 1, namaJenis, lama[i], biaya[i]);
    }

    printf("------------------------------------------\n");
    fprintf(fptr, "------------------------------------------\n");

    printf("TOTAL PEMBAYARAN: Rp. %.2f\n", totalGrand);
    fprintf(fptr, "TOTAL PEMBAYARAN: Rp. %.2f\n", totalGrand);

    printf("==========================================\n");
    fprintf(fptr, "==========================================\n");

    fclose(fptr);
    printf("\nStruk telah berhasil disimpan ke 'struk_pembayaran.txt'\n");
}

int main() {
    char nama[50];
    int jmlKendaraan;
    int jenis[3], lama[3];
    float biaya[3];
    float totalSeluruhnya = 0;

    printf("Input Nama Pelanggan: ");
    scanf("%s", nama);

    printf("Jumlah kendaraan (maksimal 3): ");
    scanf("%d", &jmlKendaraan);

    if (jmlKendaraan > 3) jmlKendaraan = 3;

    for (int i = 0; i < jmlKendaraan; i++) {
        printf("\nData Kendaraan ke-%d\n", i + 1);
        printf("Jenis (1:Mobil, 2:Motor, 3:Truk): ");
        scanf("%d", &jenis[i]);

        printf("Lama Parkir (jam): ");
        scanf("%d", &lama[i]);

        biaya[i] = hitung_biaya_parkir(jenis[i], lama[i]);
        totalSeluruhnya += biaya[i];
    }

    mencetak_Struk(nama, jenis, lama, biaya, jmlKendaraan, totalSeluruhnya);

    return 0;
}