#include <stdio.h>

void Tampilan() {
    printf("*=* ===== Pekan Olahraga(Basket) ===== *=*\n");
    printf("Diselenggarakan: 08.00 - selesai, 25 April 2026\n");
    printf("Tempat         : Gelora Bung Karno (GBK)\n");
    printf("Tujuan         : Perlombaan basket ini diadakan guna mempererat hubungan antar Mahasiswa/i\n");
    printf("                 dan untuk melihat siapa saja Mahasiswa yang mampu bermain basket.\n");
    printf("Tidak dipungut biaya apapun!\n");
    printf("\n");
}

void Data_Kampus_dan_Tim(char Nama_Kampus[], char nama_Tim[], char email[]) {
    printf("Disclamer: Setiap data yang dimasukkan bersifat permanen / tidak bisa diubah-ubah\n");
    printf("Masukkan data dengan hati-hati, Harap untuk mengecek kembali!\n");
    printf("Masukkan Nama Kampus asal: ");
    scanf("%s", Nama_Kampus);
    printf("Masukkan Nama Tim Basket: ");
    scanf("%s", nama_Tim);
    printf("Masukkan email: ");
    scanf("%s", email);
}

void DataPemain(char Nama[][50], int *jumlah, int umur[], char gender[], int maxPlayers) {
    printf("Disclamer: Setiap data yang dimasukkan bersifat permanen / tidak bisa diubah-ubah\n");
    printf("Masukkan data dengan hati-hati, Harap untuk mengecek kembali!\n");

    printf("Masukkan jumlah pemain (maks 12): ");
    scanf("%d", jumlah);
    
    if (*jumlah > maxPlayers) {
        printf("Jumlah pemain tidak boleh lebih dari %d!\n", maxPlayers);
        return;
    }

    for (int i = 0; i < *jumlah; i++) {
        printf("Masukkan nama pemain %d: ", i + 1);
        scanf("%s", Nama[i]);
        printf("Masukkan umur pemain %d: ", i + 1);
        scanf("%d", &umur[i]);
        printf("Masukkan jenis kelamin pemain %d: ", i + 1);
        scanf(" %c", &gender[i]); 
    }
}

int main() {
    char Nama_Kampus[100], nama_Tim[100], email[100];
    char Nama[12][50];
    int jumlah, umur[12]; 
    char gender[12]; 
    int maxPlayers = 12;

    Tampilan();
    printf("\n");
    Data_Kampus_dan_Tim(Nama_Kampus, nama_Tim, email);
    printf("\n");
    DataPemain(Nama, &jumlah, umur, gender, maxPlayers);
    printf("\n");
    
    return 0;
}
