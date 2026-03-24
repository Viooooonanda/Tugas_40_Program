#include <stdio.h>

int main() {
    float x, y;

    printf("Masukkan nilai x: ");
    scanf("%f", &x);

    if (x >= 0) {
        if (x == 0 || x == 3) {
            printf("y tidak dapat dihitung (pembagi nol)\n");
        } else {
            y = ((7 + x) / (x - 3)) + ((3 - x) / x);
            printf("Nilai y = %.2f\n", y);
        }
    } 
    else { 
        y = (40 * x / (x - 5)) + 3;
        printf("Nilai y = %.2f\n", y);
    }

    return 0;
}