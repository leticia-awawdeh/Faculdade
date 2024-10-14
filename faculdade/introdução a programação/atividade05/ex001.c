#include <stdio.h>

int main(){
    int option, amount;
    float total;

    printf("100. Cachorro Quente (R$1,70)\n");
    printf("101. Bauru Simples (R$2,30)\n");
    printf("102. Bauru com ovo (R$2,60)\n");
    printf("103. Haburguer (R$2,40)\n");
    printf("104. Cheeseburguer (R$2,50)\n");
    printf("105. Refrigerante (R$1,00)\n");
        scanf("%d", &option);

    printf("Digite a quantidade desejada: ");
        scanf("%d", &amount);
    
    switch (option){
    case 100:
        total = amount * 1.70;
        printf("Total: %.2f R$", total);
        break;

     case 101:
        total = amount * 2.30;
        printf("Total: %.2f R$", total);
        break;

     case 102:
        total = amount * 2.60;
        printf("Total: %.2f R$", total);
        break;

     case 103:
        total = amount * 2.40;
        printf("Total: R$%.2f", total);
        break;

     case 104:
        total = amount * 2.50;
        printf("Total: R$%.2f", total);
        break;

     case 105:
        total = amount * 1;
        printf("Total: R$%.2f", total);
        break;

    default:
        printf("Código digitado inválido");
        break;
    }
    return 0;
}