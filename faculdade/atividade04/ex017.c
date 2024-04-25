#include <stdio.h>

int main(){
    int A, B, C, D, maxVal, minVal;

    //Lê os números
    printf("digite um número: ");
    scanf("%d", &A);

    printf("digite um número: ");
    scanf("%d", &B);

    printf("digite um número: ");
    scanf("%d", &C);

    printf("digite um número: ");
    scanf("%d", &D);

//recebe o valor de um número inicial
maxVal = minVal = A;

//verifica se os valores vão ser maiores ou menores
if (B > maxVal) {
        //caso B for maior, a variável vai receber B
        maxVal = B;
    }
    if (B < minVal) {
        //caso B for menor,  a variável vai receber B
        minVal = B;
    }
    if (C > maxVal) {
        //caso C for maior, a variável vai receber C
        maxVal = C;
    }
    if (C < minVal) {
        //caso C for menor,  a variável vai receber C
        minVal = C;
    }

    if (D > maxVal) {
        //caso D for maior, a variável vai receber D
        maxVal = D;
    }
    if (D < minVal) {
        //caso D for menor,  a variável vai receber D
        minVal = D;
    }
    
    printf("O maior número é: %.d", maxVal);
    printf("O menor valor é: %.d", minVal);
    
    return 0;
}