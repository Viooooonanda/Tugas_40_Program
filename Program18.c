#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

void inputVektor(float v[]);
void tampilVektor(const char *nama, float v[]);
void tambahVektor(float a[], float b[], float hasil[], float k1, float k2);
float dotProduct(float a[], float b[]);
float magnitude(float v[]);
void crossProduct(float a[], float b[], float hasil[]);
float jarak(float a[], float b[]);
float sudutAntarVektor(float a[], float b[]);

int main() {
    float A[3], B[3];
    float hasil1[3], hasil2[3], AxB[3], BxA[3];
    float dot, sudut, jarakAB, magAxB, magBxA;

    printf("=== PROGRAM OPERASI VEKTOR DIMENSI 3 (DENGAN FUNGSI) ===\n");

    printf("\nMasukkan komponen vektor A (Ax Ay Az): ");
    inputVektor(A);
    printf("Masukkan komponen vektor B (Bx By Bz): ");
    inputVektor(B);

    tambahVektor(A, B, hasil1, 5, -3);
    tambahVektor(A, B, hasil2, 4, 7);

    printf("\n(a)\n");
    tampilVektor("5A - 3B", hasil1);
    tampilVektor("4A + 7B", hasil2);

    dot = dotProduct(A, B);
    printf("\n(b) A . B = %.2f\n", dot);

    sudut = sudutAntarVektor(A, B);
    if (sudut < 0)
        printf("(c) Sudut tidak dapat dihitung (vektor nol)\n");
    else
        printf("(c) Sudut antara A dan B = %.2f derajat\n", sudut);

    jarakAB = jarak(A, B);
    printf("(d) Jarak antara A dan B = %.2f\n", jarakAB);

    crossProduct(A, B, AxB);
    printf("\n(e) A x B ");
    tampilVektor("", AxB);

    crossProduct(B, A, BxA);
    printf("(f) B x A ");
    tampilVektor("", BxA);

    magAxB = magnitude(AxB);
    magBxA = magnitude(BxA);

    printf("(g) ||A x B|| = %.2f\n", magAxB);
    printf("(h) ||B x A|| = %.2f\n", magBxA);

    return 0;
}

void inputVektor(float v[]) {
    scanf("%f %f %f", &v[0], &v[1], &v[2]);
}

void tampilVektor(const char *nama, float v[]) {
    if (nama[0] != '\0')
        printf("%s = (%.2f, %.2f, %.2f)\n", nama, v[0], v[1], v[2]);
    else
        printf("(%.2f, %.2f, %.2f)\n", v[0], v[1], v[2]);
}

void tambahVektor(float a[], float b[], float hasil[], float k1, float k2) {
    for (int i = 0; i < 3; i++) {
        hasil[i] = k1 * a[i] + k2 * b[i];
    }
}

float dotProduct(float a[], float b[]) {
    return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}

float magnitude(float v[]) {
    return sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
}

void crossProduct(float a[], float b[], float hasil[]) {
    hasil[0] = a[1]*b[2] - a[2]*b[1];
    hasil[1] = a[2]*b[0] - a[0]*b[2];
    hasil[2] = a[0]*b[1] - a[1]*b[0];
}

float jarak(float a[], float b[]) {
    return sqrt(pow(b[0]-a[0],2) + pow(b[1]-a[1],2) + pow(b[2]-a[2],2));
}

float sudutAntarVektor(float a[], float b[]) {
    float dot = dotProduct(a,b);
    float magA = magnitude(a);
    float magB = magnitude(b);

    if (magA == 0 || magB == 0) return -1; 

    return acos(dot / (magA * magB)) * (180.0 / PI);
}