#include <stdio.h>

int main(){
    float earthWeight, humanWeight, result;
    int planetNumber;
    
    //faz um catálogo dos planetas
    printf("1 = mercúrio \n");
    printf("2 = Vênus \n");
    printf("3 = Marte \n");
    printf("4 = Júpter \n");
    printf("5 = Saturno \n");
    printf("6 = Urano \n");

    //Lê o código do planeta de acordo com o catálogo
    printf("digite um número para escolher um planeta: ");
    scanf("%d", &planetNumber);

    //Lê o peso colocado pelo usuário
    printf("Digite o seu peso em kg: ");
    scanf("%f", &humanWeight);

    //checa o número do planeta e faz o cálculo de acordo com o planeta selecionado
    if (planetNumber == 1){
    result = 0.37 * humanWeight;
    printf("Seu peso em Mercúrio é igual a %.2f", result, "Kg");

    } else if (planetNumber == 2){
        result = 0.88 * humanWeight;
        printf("Seu peso em Vênus é igual a %.2f", result, "Kg");

    } else if (planetNumber == 3){
        result = 0.38 * humanWeight;
        printf("Seu peso em Marte é igual a %.2f", result, "Kg");
    } else if (planetNumber == 4) {
        result = 2.64 * humanWeight;
        printf("Seu peso em Júpter é igual a %.2f", result, "Kg");
    } else if (planetNumber == 5){
        result = 1.15 * humanWeight;
        printf("Seu peso em Saturno é igual a %.2f", result, "Kg");
    } else if (planetNumber == 6) {
        result = 1.17 * humanWeight;
        printf("Seu peso em Urano é igual a %.2f", result, "Kg");
    } else {
        printf("ERROR");
    }

    return 0;
}