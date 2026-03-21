#include <stdio.h>
#include <math.h>

int Mencari_akar(float a, float b, float c, float *x1, float *x2){
    float D = b*b - 4*a*c;

    if(D < 0){
        return -1; 
    } 
    else if(D == 0){
        *x1 = -b / (2*a);
        return 0; 
    } 
    else{
        *x1 = (-b + sqrt(D)) / (2*a);
        *x2 = (-b - sqrt(D)) / (2*a);
        return 1; 
    }
}

int main(){
    float a, b, c;
    float x1, x2;
    int hasil;

    printf("Masukkan nilai a: ");
    scanf("%f", &a);

    printf("Masukkan nilai b: ");
    scanf("%f", &b);

    printf("Masukkan nilai c: ");
    scanf("%f", &c);

    hasil = Mencari_akar(a, b, c, &x1, &x2);

    if(hasil == -1){
        printf("Persamaan tidak memiliki akar real\n");
    }
    else if(hasil == 0){
        printf("Akar kembar: %.2f\n", x1);
    }
    else{
        printf("Akar-akar persamaan: %.2f dan %.2f\n", x1, x2);
    }

    return 0;
}