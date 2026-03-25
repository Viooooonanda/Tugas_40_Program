#include <stdio.h>

int main(){

    int penjualan[7];
    int i;
    float rata_rata;
    int total = 0;

    for(int i = 0; i <= 7; i++){
        printf("Masukkan penjualan hari %d: ", i + 1);
        scanf("%d", &penjualan[i]);
    }

    for(int i = 0; i <= 7; i++){
    total = total + penjualan[i];
    }

    rata_rata = total/7;
    printf("Total penjulana selama seminggu: %d\n", total);
    printf("Rata-rata penjualan selama seminggu: %.2f\n", rata_rata);
    
    return 0;
}