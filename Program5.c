#include <stdio.h>

int main() {
    int n, i;
    float uas, uts, tugas, rata;

    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Jumlah mahasiswa tidak valid.\n");
        return 1;
    }

    for (i = 1; i <= n; i++) {
        printf("\nMahasiswa %d:\n", i);
        printf("Masukkan nilai UAS: ");
        scanf("%f", &uas);
        printf("Masukkan nilai UTS: ");
        scanf("%f", &uts);
        printf("Masukkan nilai Tugas: ");
        scanf("%f", &tugas);

        rata = (uas * 0.3) + (uts * 0.3) + (tugas * 0.4);

        printf("Rata-rata nilai mahasiswa %d: %.2f\n", i, rata);
    }

    return 0;
}
