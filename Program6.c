#include <stdio.h>

// Fungsi Segitiga
float L_segitiga(float alas, float tinggi){
    return 0.5 * alas * tinggi;

}

float K_segitiga(float sisiA, float sisiB, float sisiC){ 
    return sisiA + sisiB + sisiC;
}

// Fungsi Persegi Panjang
float L_persegipanjang(float panjang, float lebar){
    return panjang * lebar;
}

float K_persegipanjang(float panjang, float lebar){
    return 2 * (panjang + lebar);
}

// Fungsi Bujur Sangkar
float L_bujursangkar(float sisi){
    return sisi * sisi;
}

float K_bujursangkar(float sisi){
    return 4 * sisi;
}

// Fungsi Lingkaran
float L_lingkaran(float jari_jari){
    float phi = 3.14;
    return phi * jari_jari * jari_jari;
}

float K_lingkaran(float jari_jari){
    float phi = 3.14;
    return 2 * phi * jari_jari;
}

// Fungsi Jajaran Genjang
float L_jajaran_genjang(float alas, float tinggi){
    return alas * tinggi;
}

float K_jajaran_genjang(float sisiA, float sisiB){
    return 2 * (sisiA + sisiB);
}

// Main Program
int main(){
    int pilihan;
    float alas, tinggi, sisiA, sisiB, sisiC;
    float panjang, lebar, sisi, jari_jari;
    float L, K;

    printf("MENU BANGUN 2 DIMENSI!\n");
    printf("1. Segitiga\n");
    printf("2. Persegi Panjang\n");
    printf("3. Bujur Sangkar\n");
    printf("4. Lingkaran\n");
    printf("5. Jajaran Genjang\n");

    printf("Pilih nomor bangun 2 dimensi: ");
    scanf("%d", &pilihan);

    switch(pilihan){
        case 1:
            printf("Masukkan alas: ");
            scanf("%f", &alas);
            printf("Masukkan tinggi: ");
            scanf("%f", &tinggi);
            printf("Masukkan sisi A: ");
            scanf("%f", &sisiA);
            printf("Masukkan sisi B: ");
            scanf("%f", &sisiB);
            printf("Masukkan sisi C: ");
            scanf("%f", &sisiC);

            L = L_segitiga(alas, tinggi);
            K = K_segitiga(sisiA, sisiB, sisiC);

            printf("Luas segitiga: %.2f\n", L);
            printf("Keliling segitiga: %.2f\n", K);
            break;

        case 2:
            printf("Masukkan panjang: ");
            scanf("%f", &panjang);
            printf("Masukkan lebar: ");
            scanf("%f", &lebar);

            L = L_persegipanjang(panjang, lebar);
            K = K_persegipanjang(panjang, lebar);

            printf("Luas persegi panjang: %.2f\n", L);
            printf("Keliling persegi panjang: %.2f\n", K);
            break;

        case 3:
            printf("Masukkan sisi: ");
            scanf("%f", &sisi);

            L = L_bujursangkar(sisi);
            K = K_bujursangkar(sisi);

            printf("Luas bujur sangkar: %.2f\n", L);
            printf("Keliling bujur sangkar: %.2f\n", K);
            break;

        case 4:
            printf("Masukkan jari-jari: ");
            scanf("%f", &jari_jari);

            L = L_lingkaran(jari_jari);
            K = K_lingkaran(jari_jari);

            printf("Luas lingkaran: %.2f\n", L);
            printf("Keliling lingkaran: %.2f\n", K);
            break;

        case 5:
            printf("Masukkan alas: ");
            scanf("%f", &alas);
            printf("Masukkan tinggi: ");
            scanf("%f", &tinggi);
            printf("Masukkan sisi A: ");
            scanf("%f", &sisiA);
            printf("Masukkan sisi B: ");
            scanf("%f", &sisiB);

            L = L_jajaran_genjang(alas, tinggi);
            K = K_jajaran_genjang(sisiA, sisiB);

            printf("Luas jajaran genjang: %.2f\n", L);
            printf("Keliling jajaran genjang: %.2f\n", K);
            break;

        default:
            printf("Error, input tidak valid!\n");
    }
    return 0;
}