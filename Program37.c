#include <stdio.h>

int main(){
    int n, baris, kolom;

    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    for(baris = 1; baris <= n; baris++){
        for(kolom = 1; kolom <= n; kolom++){
            int hasil = baris * kolom;
            printf("%d  ", hasil); 
        }
        printf("\n"); 
    }

    return 0;
}