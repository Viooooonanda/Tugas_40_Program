#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char judul[100];
    char penulis[100];
    int tahun;
} Buku;

void tampilkanMenu() {
    printf("\n--- Sistem Pendataan Buku Perpustakaan ---\n");
    printf("1. Tambah Buku\n");
    printf("2. Ubah Buku\n");
    printf("3. Hapus Buku\n");
    printf("4. Tampilkan Daftar Buku\n");
    printf("5. Keluar\n");
    printf("Pilih opsi: ");
}

void tambahBuku(Buku* buku, int* totalBuku) {
    printf("Masukkan ID Buku: ");
    scanf("%d", &buku[*totalBuku].id);
    getchar();
    
    printf("Masukkan Judul Buku: ");
    fgets(buku[*totalBuku].judul, sizeof(buku[*totalBuku].judul), stdin);
    buku[*totalBuku].judul[strcspn(buku[*totalBuku].judul, "\n")] = 0; 

    printf("Masukkan Penulis Buku: ");
    fgets(buku[*totalBuku].penulis, sizeof(buku[*totalBuku].penulis), stdin);
    buku[*totalBuku].penulis[strcspn(buku[*totalBuku].penulis, "\n")] = 0;

    printf("Masukkan Tahun Terbit: ");
    scanf("%d", &buku[*totalBuku].tahun);

    (*totalBuku)++;
    printf("Buku berhasil ditambahkan!\n");
}

void ubahBuku(Buku* buku, int totalBuku) {
    int id, i;
    printf("Masukkan ID Buku yang ingin diubah: ");
    scanf("%d", &id);
    
    for (i = 0; i < totalBuku; i++) {
        if (buku[i].id == id) {
            printf("Masukkan Judul Baru: ");
            getchar(); 
            fgets(buku[i].judul, sizeof(buku[i].judul), stdin);
            buku[i].judul[strcspn(buku[i].judul, "\n")] = 0;

            printf("Masukkan Penulis Baru: ");
            fgets(buku[i].penulis, sizeof(buku[i].penulis), stdin);
            buku[i].penulis[strcspn(buku[i].penulis, "\n")] = 0;

            printf("Masukkan Tahun Terbit Baru: ");
            scanf("%d", &buku[i].tahun);

            printf("Buku berhasil diubah!\n");
            return;
        }
    }
    printf("Buku dengan ID %d tidak ditemukan.\n", id);
}

void hapusBuku(Buku* buku, int* totalBuku) {
    int id, i, found = 0;
    printf("Masukkan ID Buku yang ingin dihapus: ");
    scanf("%d", &id);
    
    for (i = 0; i < *totalBuku; i++) {
        if (buku[i].id == id) {
            found = 1;
            for (int j = i; j < (*totalBuku) - 1; j++) {
                buku[j] = buku[j + 1];
            }
            (*totalBuku)--; 
            printf("Buku dengan ID %d berhasil dihapus!\n", id);
            break;
        }
    }
    if (!found) {
        printf("Buku dengan ID %d tidak ditemukan.\n", id);
    }
}

void tampilkanDaftarBuku(Buku* buku, int totalBuku) {
    if (totalBuku == 0) {
        printf("Tidak ada buku dalam daftar.\n");
        return;
    }
    printf("\n--- Daftar Buku ---\n");
    for (int i = 0; i < totalBuku; i++) {
        printf("ID: %d, Judul: %s, Penulis: %s, Tahun: %d\n", buku[i].id, buku[i].judul, buku[i].penulis, buku[i].tahun);
    }
}

int main() {
    Buku buku[100]; 
    int totalBuku = 0;
    int pilihan;

    do {
        tampilkanMenu();
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahBuku(buku, &totalBuku);
                break;
            case 2:
                ubahBuku(buku, totalBuku);
                break;
            case 3:
                hapusBuku(buku, &totalBuku);
                break;
            case 4:
                tampilkanDaftarBuku(buku, totalBuku);
                break;
            case 5:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 5);

    return 0;
}
