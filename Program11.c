#include <stdio.h>

void Membagi_Array(float a[], float b[], float hasil[], int n)
{
    int i;
    for(int i = 0; i < n; i++)
    {
        if(b[i] != 0)
        {
            hasil[i] = a[i] / b[i];
        } else {
            hasil[i] = 0;
        }
    }
}
 
int main () {
    int n = 5;
    float hasil[5];
    float arrayA[] = {10.0, 11.0, 12.0, 13.0, 15.0};
    float arrayB[] = {20.0, 21.0, 22.0, 23.0, 24.0};

    Membagi_Array(arrayA, arrayB, hasil, n);

        printf("Hasil pembagian array: \n");
        for(int i = 0; i < n; i++)
        {
            printf("%.2f / %.2f = %.2f\n", arrayA[i], arrayB[i], hasil[i]);
        }
        return 0;
}