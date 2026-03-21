#include <stdio.h>

void inputMatriks(int baris, int kolom, int A[10][10]) {
    for(int i = 0; i < baris; i++) {
        for(int j = 0; j < kolom; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
}

void tampilMatriks(int baris, int kolom, int A[10][10]) {
    for(int i = 0; i < baris; i++) {
        for(int j = 0; j < kolom; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

void tambahMatriks(int baris, int kolom, int A[10][10], int B[10][10], int C[10][10]) {
    for(int i = 0; i < baris; i++) {
        for(int j = 0; j < kolom; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void kurangMatriks(int baris, int kolom, int A[10][10], int B[10][10], int C[10][10]) {
    for(int i = 0; i < baris; i++) {
        for(int j = 0; j < kolom; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void kaliMatriks(int r1, int c1, int r2, int c2, int A[10][10], int B[10][10], int C[10][10]) {
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for(int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[10][10], B[10][10], C[10][10];
    int r1, c1, r2, c2;

    printf("Masukkan baris dan kolom matriks A: ");
    scanf("%d %d", &r1, &c1);

    printf("Masukkan baris dan kolom matriks B: ");
    scanf("%d %d", &r2, &c2);

    printf("\nInput Matriks A:\n");
    inputMatriks(r1, c1, A);

    printf("\nInput Matriks B:\n");
    inputMatriks(r2, c2, B);

    if(r1 == r2 && c1 == c2) {
        printf("\n=== Penjumlahan Matriks ===\n");
        tambahMatriks(r1, c1, A, B, C);
        tampilMatriks(r1, c1, C);

        printf("\n=== Pengurangan Matriks ===\n");
        kurangMatriks(r1, c1, A, B, C);
        tampilMatriks(r1, c1, C);
    } else {
        printf("\nPenjumlahan & Pengurangan tidak bisa (ukuran berbeda)\n");
    }

    if(c1 == r2) {
        printf("\n=== Perkalian Matriks ===\n");
        kaliMatriks(r1, c1, r2, c2, A, B, C);
        tampilMatriks(r1, c2, C);
    } else {
        printf("\nPerkalian tidak bisa (kolom A != baris B)\n");
    }

    return 0;
}