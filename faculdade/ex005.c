#include <stdio.h>

int main (){
    int code, price, amount;

    printf("===============MENU=============\n");
    printf("================================\n");
    printf("1. Tapioca (R$18)\n");
    printf("2. X-Salada (R$30)\n");
    printf("3. X-Bacon (R$32)\n");
    printf("4. Suco natural (R$12)\n");
    printf("5. Refrigerante (R$10)\n");
    printf("0. Nenhum \n");
    printf("================================\n");
    printf("digite o código do lanche: ");
    scanf("%d", &code);
    printf("================================\n");
    printf("digite a quantidade que deseja: ");
    scanf("%d", &amount);

    switch (code){
    case 1:
        price = 18 * amount;
        printf ("Total: R$ %d", price);
        break;
    case 2:
        price = 30 * amount;
        printf ("Total: %d R$", price);
        break;
    case 3:
        price = 32 * amount;
        printf ("Total: %d R$", price);
        break;
    case 4:
        price = 12 * amount;
        printf ("Total: %d R$", price);
        break;
    case 5:
        price = 10 * amount;
        printf ("Total: %d R$", price);
        break;
    
    case 0:
    printf("Você não escolheu nenhum lanche");
        break;

    default:
        printf("Códgo inválido");
        break;
    }

    return 0;

}