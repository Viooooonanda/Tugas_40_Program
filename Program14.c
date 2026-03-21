#include <stdio.h>

int hitungTotal(int arr[], int n) {
    int total = 0;
    for(int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

void kategoriUmur(int anak, int remaja, int dewasa, int lansia) {
    printf("\n=== Data Berdasarkan Umur ===\n");
    printf("Anak-anak  : %d\n", anak);
    printf("Remaja     : %d\n", remaja);
    printf("Dewasa     : %d\n", dewasa);
    printf("Lansia     : %d\n", lansia);
}

void jenisKelamin(int laki, int perempuan) {
    printf("\n=== Data Berdasarkan Jenis Kelamin ===\n");
    printf("Laki-laki  : %d\n", laki);
    printf("Perempuan  : %d\n", perempuan);
}

void statusNikah(int belum, int menikah, int janda, int duda) {
    printf("\n=== Data Berdasarkan Status ===\n");
    printf("Belum menikah : %d\n", belum);
    printf("Menikah       : %d\n", menikah);
    printf("Janda         : %d\n", janda);
    printf("Duda          : %d\n", duda);
}

int main() {
    int n;

    printf("Masukkan jumlah desa: ");
    scanf("%d", &n);

    int penduduk[n];

    for(int i = 0; i < n; i++) {
        printf("Masukkan jumlah penduduk desa ke-%d: ", i+1);
        scanf("%d", &penduduk[i]);
    }

    int total = hitungTotal(penduduk, n);

    int anak, remaja, dewasa, lansia;
    printf("\nMasukkan jumlah anak-anak: ");
    scanf("%d", &anak);
    printf("Masukkan jumlah remaja: ");
    scanf("%d", &remaja);
    printf("Masukkan jumlah dewasa: ");
    scanf("%d", &dewasa);
    printf("Masukkan jumlah lansia: ");
    scanf("%d", &lansia);

    int laki, perempuan;
    printf("\nMasukkan jumlah laki-laki: ");
    scanf("%d", &laki);
    printf("Masukkan jumlah perempuan: ");
    scanf("%d", &perempuan);

    int belum, menikah, janda, duda;
    printf("\nMasukkan jumlah belum menikah: ");
    scanf("%d", &belum);
    printf("Masukkan jumlah menikah: ");
    scanf("%d", &menikah);
    printf("Masukkan jumlah janda: ");
    scanf("%d", &janda);
    printf("Masukkan jumlah duda: ");
    scanf("%d", &duda);

    printf("\n=== TOTAL PENDUDUK ===\n");
    printf("Total = %d\n", total);

    kategoriUmur(anak, remaja, dewasa, lansia);
    jenisKelamin(laki, perempuan);
    statusNikah(belum, menikah, janda, duda);

    return 0;
}