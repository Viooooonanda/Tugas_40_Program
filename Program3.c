#include <stdio.h>

int I, J;

void C(int P, int Q);
void B(int L, int M);

int main(){
    int K;

    K = 7;
    J = 5;
    I = 1;

    B(J, K);

    printf("I = %d, J = %d, K = %d\n", I, J, K);

    return 0;
}


void B(int L, int M){
    J = 2; 

    C(L, M);

    printf("L = %d, M = %d\n", L, M);
}

void C(int P, int Q){
    P = I + J;
    Q = I * P + Q;
    J = Q; 

    printf("Di fungsi C ==> P = %d, Q = %d, I = %d, J = %d\n", P, Q, I, J);
}