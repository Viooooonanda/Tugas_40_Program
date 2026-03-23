#include <stdio.h>
#include <string.h>

#define MAX_MAHASISWA 48
#define NAMA_MAX 100

void tampilkanMenu() {
    printf("\n--- Sistem Absensi Mahasiswa ---\n");
    printf("1. Absen Mahasiswa\n");
    printf("2. Tampilkan Hasil Absensi\n");
    printf("3. Keluar\n");
    printf("Pilih opsi: ");
}

int main() {
    char nama[MAX_MAHASISWA][NAMA_MAX];
    char kehadiran[MAX_MAHASISWA]; 
    int totalMahasiswa = 0;
    int pilihan;

    printf("Masukkan jumlah mahasiswa (maksimal %d): ", MAX_MAHASISWA);
    scanf("%d", &totalMahasiswa);

    if (totalMahasiswa < 1 || totalMahasiswa > MAX_MAHASISWA) {
        printf("Jumlah mahasiswa tidak valid. Harus antara 1 dan %d.\n", MAX_MAHASISWA);
        return 1;
    }

    printf("Masukkan nama mahasiswa:\n");
    getchar(); 
    for (int i = 0; i < totalMahasiswa; i++) {
        printf("Mahasiswa %d: ", i + 1);
        fgets(nama[i], sizeof(nama[i]), stdin);
        nama[i][strcspn(nama[i], "\n")] = 0; 
    }

    do {
        tampilkanMenu();
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1: { 
                for (int i = 0; i < totalMahasiswa; i++) {
                    printf("Absensi untuk %s (H - Hadir, I - Ijin, A - Alpa): ", nama[i]);
                    kehadiran[i] = getchar();
                    getchar(); 
                }
                break;
            }
            case 2: { 
                int hadir = 0, ijin = 0, alpa = 0;

                for (int i = 0; i < totalMahasiswa; i++) {
                    switch (kehadiran[i]) {
                        case 'H':
                        case 'h':
                            hadir++;
                            break;
                        case 'I':
                        case 'i':
                            ijin++;
                            break;
                        case 'A':
                        case 'a':
                            alpa++;
                            break;
                    }
                }
                
                printf("\n--- Hasil Absensi ---\n");
                printf("Jumlah Hadir: %d\n", hadir);
                printf("Jumlah Ijin: %d\n", ijin);
                printf("Jumlah Alpa: %d\n", alpa);
                break;
            }
            case 3:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 3);

    return 0;
}
