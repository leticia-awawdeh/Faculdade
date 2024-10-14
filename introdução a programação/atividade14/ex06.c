#include <stdio.h>

typedef struct{
    int code;
    char name[16]; // name com máximo de 15 letras + '\0'
    float price;
    int amount;
}Product;

void lerProdutos(Product products[5]) {
    for(int i = 0; i < 5; i++) {
        printf("Digite o código do produto %d: ", i+1);
        scanf("%d", &products[i].code);
        
        printf("Digite o nome do produto %d: ", i+1);
        getchar(); // Limpa o buffer do teclado
        fgets(products[i].name, sizeof(products[i].name), stdin);
        
        printf("Digite o preço do produto %d: ", i+1);
        scanf("%f", &products[i].price);
        
        printf("Digite a quantidade do produto %d: ", i+1);
        scanf("%d", &products[i].amount);
    }
}

void processarPedidos(Product products[5]) {
    int codeOrder;
    int quantityDesired;
    
    do {
        printf("\nDigite o código do produto para pedido (0 para sair): ");
        scanf("%d", &codeOrder);
        
        if(codeOrder == 0) break; 
        
        printf("Digite a quantidade desejada: ");
        scanf("%d", &quantityDesired);
        
        for(int i = 0; i < 5; i++) {
            if(products[i].code == codeOrder && products[i].amount >= quantityDesired) {
                products[i].amount -= quantityDesired;
                printf("Pedido atendido com sucesso.\n");
                break;
            } else if(products[i].code == codeOrder && products[i].amount < quantityDesired) {
                printf("amount insuficiente no estoque.\n");
                break;
            }
            
            if(i == 4 && products[i].code != codeOrder) {
                printf("code de Product nao encontrado.\n");
            }
        }
    } while(codeOrder != 0);
}

int main() {
    Product products[5];
    
    lerProdutos(products);
    processarPedidos(products);
    
    return 0;
}
