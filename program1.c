#include <stdio.h>
#include <stdlib.h>

int* Ganda_kopi_Array(int array_lama[], int Ukuran_lama, int *Ukuran_baru)
{
    *Ukuran_baru = Ukuran_lama * 2;
    int* array_baru = malloc((*Ukuran_baru) * sizeof(int));

    if(array_baru == NULL)
    {
        printf("Gagal membuat memori!\n");
        return NULL;
    }

    for(int i = 0; i < Ukuran_lama; i++)
    {
        array_baru[i] = array_lama[i];
    }

    for(int i = Ukuran_lama; i < *Ukuran_baru; i++)
    {
        array_baru[i] = 0;
    }

    return array_baru;
}

int main (){
    int arrayA[] = {10, 20, 30, 40, 50};
    int nLama = 5;
    int nBaru;

    printf("Array lama:\n");
    for(int i = 0; i < nLama; i++)
    {
        printf("%d ", arrayA[i]);
    }
    printf("\n");
    printf("------------------------");
    printf("\n");
    int *array_Baru = Ganda_kopi_Array(arrayA, nLama, &nBaru);

    if(array_Baru != NULL) {
        printf("Array baru: \n");
        for(int i = 0; i < nBaru; i++)
        {
            printf("%d ", array_Baru[i]);
    }

    printf("\n");
    printf("\n");
    printf("Belajar Github!");
    return 0;
}
}
