#include <stdio.h>
#include <string.h>

#define MAX 100

struct Buku {
    char kode[10];
    char judul[50];
    char penulis[50];
    int tahun;
    int stok;
};

void tambahBuku(struct Buku b[], int *n);
void tampilBuku(struct Buku b[], int n);
void cariBuku(struct Buku b[], int n);
void pinjamBuku(struct Buku b[], int n);
void kembalikanBuku(struct Buku b[], int n);
void hapusBuku(struct Buku b[], int *n);

int main() {
    struct Buku buku[MAX];
    int n = 0;
    int pilihan;

    do {
        printf("\n=== SISTEM PERPUSTAKAAN ===\n");
        printf("1. Tambah Buku\n");
        printf("2. Tampil Buku\n");
        printf("3. Cari Buku\n");
        printf("4. Pinjam Buku\n");
        printf("5. Kembalikan Buku\n");
        printf("6. Hapus Buku\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);
        getchar();

        switch(pilihan) {
            case 1: tambahBuku(buku, &n); break;
            case 2: tampilBuku(buku, n); break;
            case 3: cariBuku(buku, n); break;
            case 4: pinjamBuku(buku, n); break;
            case 5: kembalikanBuku(buku, n); break;
            case 6: hapusBuku(buku, &n); break;
            case 0: printf("Keluar...\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }

    } while(pilihan != 0);

    return 0;
}

void tambahBuku(struct Buku b[], int *n) {
    int jumlah;
    printf("Jumlah buku yang ingin ditambah: ");
    scanf("%d", &jumlah);
    getchar();

    for(int i = 0; i < jumlah; i++) {
        printf("\nData buku ke-%d\n", *n + 1);

        printf("Kode: ");
        fgets(b[*n].kode, sizeof(b[*n].kode), stdin);
        b[*n].kode[strcspn(b[*n].kode, "\n")] = 0;

        printf("Judul: ");
        fgets(b[*n].judul, sizeof(b[*n].judul), stdin);
        b[*n].judul[strcspn(b[*n].judul, "\n")] = 0;

        printf("Penulis: ");
        fgets(b[*n].penulis, sizeof(b[*n].penulis), stdin);
        b[*n].penulis[strcspn(b[*n].penulis, "\n")] = 0;

        printf("Tahun: ");
        scanf("%d", &b[*n].tahun);

        printf("Stok: ");
        scanf("%d", &b[*n].stok);
        getchar();

        (*n)++;
    }
}

void tampilBuku(struct Buku b[], int n) {
    if(n == 0) {
        printf("Data kosong!\n");
        return;
    }

    printf("\n=== DAFTAR BUKU ===\n");
    for(int i = 0; i < n; i++) {
        printf("\nBuku ke-%d\n", i+1);
        printf("Kode    : %s\n", b[i].kode);
        printf("Judul   : %s\n", b[i].judul);
        printf("Penulis : %s\n", b[i].penulis);
        printf("Tahun   : %d\n", b[i].tahun);
        printf("Stok    : %d\n", b[i].stok);
    }
}

void cariBuku(struct Buku b[], int n) {
    char cari[50];
    printf("Masukkan judul buku: ");
    fgets(cari, sizeof(cari), stdin);
    cari[strcspn(cari, "\n")] = 0;

    for(int i = 0; i < n; i++) {
        if(strstr(b[i].judul, cari) != NULL) {
            printf("\nDitemukan!\n");
            printf("Kode  : %s\n", b[i].kode);
            printf("Judul : %s\n", b[i].judul);
            printf("Stok  : %d\n", b[i].stok);
            return;
        }
    }
    printf("Buku tidak ditemukan!\n");
}

void pinjamBuku(struct Buku b[], int n) {
    char kode[10];
    printf("Masukkan kode buku: ");
    fgets(kode, sizeof(kode), stdin);
    kode[strcspn(kode, "\n")] = 0;

    for(int i = 0; i < n; i++) {
        if(strcmp(b[i].kode, kode) == 0) {
            if(b[i].stok > 0) {
                b[i].stok--;
                printf("Buku berhasil dipinjam!\n");
            } else {
                printf("Stok habis!\n");
            }
            return;
        }
    }
    printf("Buku tidak ditemukan!\n");
}

void kembalikanBuku(struct Buku b[], int n) {
    char kode[10];
    printf("Masukkan kode buku: ");
    fgets(kode, sizeof(kode), stdin);
    kode[strcspn(kode, "\n")] = 0;

    for(int i = 0; i < n; i++) {
        if(strcmp(b[i].kode, kode) == 0) {
            b[i].stok++;
            printf("Buku berhasil dikembalikan!\n");
            return;
        }
    }
    printf("Buku tidak ditemukan!\n");
}

void hapusBuku(struct Buku b[], int *n) {
    char kode[10];
    printf("Masukkan kode buku yang ingin dihapus: ");
    fgets(kode, sizeof(kode), stdin);
    kode[strcspn(kode, "\n")] = 0;

    for(int i = 0; i < *n; i++) {
        if(strcmp(b[i].kode, kode) == 0) {
            for(int j = i; j < *n - 1; j++) {
                b[j] = b[j+1];
            }
            (*n)--;
            printf("Buku berhasil dihapus!\n");
            return;
        }
    }
    printf("Buku tidak ditemukan!\n");
}