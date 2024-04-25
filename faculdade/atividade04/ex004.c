#include <stdio.h>

int main(){
    float imc, weight, height;

    //lê a altura e peso respectivamente
    printf("Digite a sua altura em metros(m): ");
        scanf("%f", &height);

    printf("Digite o seu peso em Kg: ");
        scanf("%f", &weight);

    //faz o cálculo do IMC
    imc = weight / (height * height);

    //verifica o resultado do imc e classifica
    if (imc < 20){
        printf("Abaixo do peso, IMC:%.2f ", imc);

    } else if (imc >= 20 && imc <= 25){
        printf("Peso normal, IMC:%.2f ", imc);

    } else if (imc >= 25 && imc <= 30){
        printf("Sobre peso, IMC:%.2f ", imc);
    
    } else if (imc >= 30 && imc <= 40){
        printf("Obeso(a), imc:%.2f ", imc);
    
    } else {
        printf("Obeso Mórbido, imc:%.2f ", imc);
    
    }
    
    return 0;
}