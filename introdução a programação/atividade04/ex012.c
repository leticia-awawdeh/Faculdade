#include <stdio.h>

int main(){
    int balance, percentage, tax;
    float result;

    printf("Digite o seu saldo médio: ");
    scanf("%d", &balance);

    // verifica o salário médio e faz o cálculo do crédito - 20% da taxa
    if(balance >= 501 && balance <= 1000){
        // +30% = 1.3 -> porcentagem de crédito disponível
        result = balance * 1.3;
        
        //-20% = 0.8 -> taxa 
        tax = result * 0.80;

    } else if (balance >= 1001 && balance <= 3000){
        // +40% = 1.4 -> porcentagem de crédito disponível
        result = balance * 1.4;

        //-20% = 0.8 -> taxa
        tax = result * 0.80;

    } else if (balance >= 3001){
        // +50% = 1.5 -> porcentagem de crédito disponível
        result = balance * 1.5;

        //-20% = 0.8 -> taxa
        tax = result * 0.80;

    } else {

        //caso não esteja dentro do valor necessário para crédito
        printf("O seu saldo médio não é o suficiente para o crédito especial");

    }

printf("O seu saldo médio é de %d: ", balance);
printf("O crédito especial é de %.2f: ", tax);
    
    return 0;

}