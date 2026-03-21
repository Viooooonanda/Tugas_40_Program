#include <stdio.h>

int Digit(char data){
    if(data >= '0' && data <= '9'){
        return 1; 
    } else {
        return 0; 
    }
}

int main(){
    char data;
    int hasil;

    printf("Masukkan sebuah data: ");
    scanf(" %c", &data); 

    hasil = Digit(data);

    if(hasil == 1){
        printf("Hasil merupakan digit 0 - 9\n");
    } else {
        printf("Hasil bukan merupakan digit 0 - 9\n");
    }

    return 0;
}