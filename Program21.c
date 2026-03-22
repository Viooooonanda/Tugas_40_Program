#include <stdio.h>
#include <string.h>

#define MAX_SISWA 100
#define MAX_NAMA 50
#define MAX_KELAS 5

typedef struct {
    char nama[MAX_NAMA];
    char kk;
    char akte_lahir;
    char ijasah_sd;
    float nilai_ijazah;
} Siswa;

void inputSiswa(Siswa *siswa, int index) {
    printf("Masukkan Nama Siswa ke-%d: ", index + 1);
    scanf(" %[^\n]", siswa[index].nama);
    printf("Apakah KK sudah ada? (y/n): ");
    scanf(" %c", &siswa[index].kk);
    printf("Apakah Akte Lahir sudah ada? (y/n): ");
    scanf(" %c", &siswa[index].akte_lahir);
    printf("Apakah Ijasah SD sudah ada? (y/n): ");
    scanf(" %c", &siswa[index].ijasah_sd);
    
    printf("Masukkan Nilai Rata-rata Ijazah SD: ");
    scanf("%f", &siswa[index].nilai_ijazah);
}

void tampilkanData(Siswa *siswa, int jumlah_siswa) {
    printf("\nData Siswa yang Terdaftar:\n");
    for (int i = 0; i < jumlah_siswa; i++) {
        printf("Siswa %d: %s\n", i + 1, siswa[i].nama);
        printf("  KK: %c, Akte Lahir: %c, Ijasah SD: %c, Nilai Ijazah: %.2f\n",
               siswa[i].kk, siswa[i].akte_lahir, siswa[i].ijasah_sd, siswa[i].nilai_ijazah);

        if (siswa[i].kk == 'y' && siswa[i].akte_lahir == 'y' &&
            siswa[i].ijasah_sd == 'y' && siswa[i].nilai_ijazah >= 75.0) {
            printf("  Status: Lulus\n");
        } else {
            printf("  Status: Tidak Lulus\n");
        }
    }
}

void bagiKelas(int jumlah_siswa) {
    int siswa_per_kelas = jumlah_siswa / MAX_KELAS;
    printf("\nPembagian Kelas:\n");
    for (int i = 0; i < MAX_KELAS; i++) {
        printf("Kelas 7%s: %d siswa\n", "abcde"[i], siswa_per_kelas);
    }
}

int main() {
    Siswa siswa[MAX_SISWA];
    int jumlah_siswa = 0;

    printf("Pendaftaran Calon Siswa SMP Negeri 1 Purba\n");
    while (jumlah_siswa < MAX_SISWA) {
        inputSiswa(siswa, jumlah_siswa);
        jumlah_siswa++;
        
        if (jumlah_siswa >= MAX_SISWA) {
            printf("Jumlah minimum siswa yang dibutuhkan sudah tercapai.\n");
            break;
        }

        char lanjut;
        printf("Apakah Anda ingin mendaftar siswa lain? (y/n): ");
        scanf(" %c", &lanjut);
        if (lanjut != 'y') {
            break;
        }
    }

    tampilkanData(siswa, jumlah_siswa);
    bagiKelas(jumlah_siswa);

    return 0;
}
