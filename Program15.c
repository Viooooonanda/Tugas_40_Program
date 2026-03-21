#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float panjang;
    float lebar;
    float tinggi;
} Kotak;

float hitungDiameter(Kotak k) {
    return sqrt(pow(k.panjang, 2) + pow(k.lebar, 2) + pow(k.tinggi, 2));
}

int main() {
    FILE *file;
    Kotak k;
    int count_diameter[4] = {0, 0, 0, 0}; 
    int totalKotak = 0;

    file = fopen("ukuran_kotak.txt", "r");
    if (file == NULL) {
        printf("Error: File tidak dapat dibuka.\n");
        return 1;
    }

    while (fscanf(file, "%f %f %f", &k.panjang, &k.lebar, &k.tinggi) != EOF) {
        float diameter = hitungDiameter(k);
        totalKotak++;

        if (diameter < 10) {
            count_diameter[0]++;
        } else if (diameter < 15) {
            count_diameter[1]++;
        } else if (diameter < 20) {
            count_diameter[2]++;
        } else if (diameter < 25) {
            count_diameter[3]++;
        }
    }

    fclose(file);

    printf("Total kotak: %d\n", totalKotak);
    printf("Jumlah kotak yang memerlukan bola diameter < 10 cm: %d\n", count_diameter[0]);
    printf("Jumlah kotak yang memerlukan bola diameter 10 cm ≤ diameter < 15 cm: %d\n", count_diameter[1]);
    printf("Jumlah kotak yang memerlukan bola diameter 15 cm ≤ diameter < 20 cm: %d\n", count_diameter[2]);
    printf("Jumlah kotak yang memerlukan bola diameter 20 cm ≤ diameter < 25 cm: %d\n", count_diameter[3]);

    return 0;
}
