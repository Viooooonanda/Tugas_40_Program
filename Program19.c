#include <stdio.h>
#include <string.h>

#define MAX 100

struct Mahasiswa {
    char nama[50];
    char nim[20];
    float nilai;
};

void tambahData(struct Mahasiswa mhs[], int *n);
void tampilData(struct Mahasiswa mhs[], int n);
void cariData(struct Mahasiswa mhs[], int n);
void urutkanData(struct Mahasiswa mhs[], int n);
void hapusData(struct Mahasiswa mhs[], int *n);
float rataRata(struct Mahasiswa mhs[], int n);

void tambahData(struct Mahasiswa mhs[], int *n) {
    printf("\nJumlah data yang ingin ditambah: ");
    int jumlah;
    scanf("%d", &jumlah);
    getchar();

    for(int i = 0; i < jumlah; i++) {
        printf("\nData ke-%d\n", *n + 1);

        printf("Nama: ");
        fgets(mhs[*n].nama, sizeof(mhs[*n].nama), stdin);
        mhs[*n].nama[strcspn(mhs[*n].nama, "\n")] = 0;

        printf("NIM: ");
        fgets(mhs[*n].nim, sizeof(mhs[*n].nim), stdin);
        mhs[*n].nim[strcspn(mhs[*n].nim, "\n")] = 0;

        printf("Nilai: ");
        scanf("%f", &mhs[*n].nilai);
        getchar();

        (*n)++;
    }
}

void tampilData(struct Mahasiswa mhs[], int n) {
    if(n == 0) {
        printf("Data kosong!\n");
        return;
    }

    printf("\n=== DATA MAHASISWA ===\n");
    for(int i = 0; i < n; i++) {
        printf("\nData ke-%d\n", i+1);
        printf("Nama  : %s\n", mhs[i].nama);
        printf("NIM   : %s\n", mhs[i].nim);
        printf("Nilai : %.2f\n", mhs[i].nilai);
    }
}

void cariData(struct Mahasiswa mhs[], int n) {
    char cari[20];
    printf("Masukkan NIM yang dicari: ");
    fgets(cari, sizeof(cari), stdin);
    cari[strcspn(cari, "\n")] = 0;

    for(int i = 0; i < n; i++) {
        if(strcmp(mhs[i].nim, cari) == 0) {
            printf("Data ditemukan!\n");
            printf("Nama  : %s\n", mhs[i].nama);
            printf("Nilai : %.2f\n", mhs[i].nilai);
            return;
        }
    }
    printf("Data tidak ditemukan!\n");
}

void urutkanData(struct Mahasiswa mhs[], int n) {
    struct Mahasiswa temp;

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(mhs[j].nilai > mhs[j+1].nilai) {
                temp = mhs[j];
                mhs[j] = mhs[j+1];
                mhs[j+1] = temp;
            }
        }
    }
    printf("Data berhasil diurutkan!\n");
}

void hapusData(struct Mahasiswa mhs[], int *n) {
    char cari[20];
    printf("Masukkan NIM yang ingin dihapus: ");
    fgets(cari, sizeof(cari), stdin);
    cari[strcspn(cari, "\n")] = 0;

    for(int i = 0; i < *n; i++) {
        if(strcmp(mhs[i].nim, cari) == 0) {
            for(int j = i; j < *n - 1; j++) {
                mhs[j] = mhs[j+1];
            }
            (*n)--;
            printf("Data berhasil dihapus!\n");
            return;
        }
    }
    printf("Data tidak ditemukan!\n");
}

float rataRata(struct Mahasiswa mhs[], int n) {
    if(n == 0) return 0;

    float total = 0;
    for(int i = 0; i < n; i++) {
        total += mhs[i].nilai;
    }
    return total / n;
}

int main() {
    struct Mahasiswa mhs[MAX];
    int n = 0;
    int pilihan;

    do {
        printf("\n=== MENU DATA MAHASISWA ===\n");
        printf("1. Tambah Data\n");
        printf("2. Tampil Data\n");
        printf("3. Cari Data\n");
        printf("4. Urutkan Data (Nilai)\n");
        printf("5. Hapus Data\n");
        printf("6. Rata-rata Nilai\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);
        getchar();

        switch(pilihan) {
            case 1: tambahData(mhs, &n); break;
            case 2: tampilData(mhs, n); break;
            case 3: cariData(mhs, n); break;
            case 4: urutkanData(mhs, n); break;
            case 5: hapusData(mhs, &n); break;
            case 6: printf("Rata-rata = %.2f\n", rataRata(mhs, n)); break;
            case 0: printf("Keluar...\n"); break;
            default: printf("Pilihan salah!\n");
        }

    } while(pilihan != 0);

    return 0;
}