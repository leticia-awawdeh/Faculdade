#include <stdio.h>

int main(){
int price, sales, newPrice;

printf("Digite a venda média mensal: ");
scanf("%d", &sales);

printf("Digite o valor do produto: ");
scanf("%d", &price);

//vê a quantitade de vendas e o preço que está o produto e calcula o novo valor
if (sales < 500 && price < 30){
    newPrice = price * 1.10;

}else if(sales >= 500 && sales <1200 && price >= 30 && price < 80){
    newPrice = price * 1.15;

} else if (sales >= 1200 && price >= 80){
    newPrice = price * 0.80;

} else {
    //caso não esteja dentro das condições
    printf("ERROR");

}

printf("O novo preço do produto é: R$ %.2d", newPrice);

    return 0;
}