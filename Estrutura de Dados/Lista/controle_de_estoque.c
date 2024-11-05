#include <stdio.h>
#include <string.h>

#define MIN 5

//vetor de inteiros para armazenar a quantidade disponível em estoque de cada produto
int stockQuantity[3];

//vetor de strings para armazenar o nome de cada produto
char productName[3][50];

//função que permite adicionar produtos ao vetor
void addProduct(){
    for(int i = 0; i < 3; i++){
        printf("\nDigite o nome do produto %d: ", i + 1);
        scanf("%s", productName[i]);
        printf("Digite a quantidade do produto %d: ", i + 1);
        scanf("%d", &stockQuantity[i]);
        printf("======================================================\n");


    }

}

//função que procura o produto pesquisado no vetor que contém o registro dos produtos
int searchProduct(char product[]){
    

    for(int i = 0; i < 3; i++){
        if(strcmp (productName[i], product) == 0){
            return i;
        }
    }
    return -1;
    
}

// Uma função que recebe o nome do produto e a quantidade a ser adicionada ou removida
void updateStock(){
    char productNameInput[50];
    int quantity, option;

    printf("Digite o nome do produto: ");
    scanf("%s", &productNameInput);

    int index = searchProduct(productNameInput);

    if (index == -1){
        printf("Produto não encontrado.\n");
        return;
    }
    
    printf("=====================================\n");
    printf("1.    Adicionar Quantidade no Estoque\n");
    printf("2.      Remover Quantidade no Estoque\n");
    printf("3.            Voltar ao Menu Princial\n");
    printf("=====================================\n");
    printf("Escolha uma das opções: ");
    scanf("%d", &option);

    switch (option){
    case 1:
        printf("Digite a quantidade a ser adicionada: ");
        scanf("%d", &quantity);

        stockQuantity[index] += quantity;

        printf("Foram adicionados %d do produto %s", quantity, productNameInput);
        printf(" total no estoque: %d\n", stockQuantity[index]);        
        
        break;

    case 2:
        printf("Digite a quantidade a ser removida: ");
        scanf("%d", &quantity);
        
        stockQuantity[index] -= quantity;

        printf("Foram removidos %d do produto %s", quantity, productNameInput);
        printf(" total no estoque: %d\n", stockQuantity[index]);
        break;

    case 3:
        return;
        break;
    default:
        printf("[ERROR]");
        break;
    }
}

//Uma função que percorre o vetor e verifica se algum produto tem estoque abaixo de um valor mínimo estabelecido
int lowStock(){
    for(int i = 0; i < 3; i++){
        if(stockQuantity[i] <= MIN){
            printf("=================================================================\n");
            printf("O produto %s está abaixo do limite estabelecido\n", productName[i]);
            printf("Quantidade: %d\n", stockQuantity[i]);
            printf("=================================================================\n");


        }
    }
}

//uma função que exibe todos os itens e suas quantidades em estoque
void listProducts(){
    printf("Produtos em Estoque: \n");

    for(int i = 0; i < 3; i++){
        printf("======================================================\n");
        printf("Produto %d: %s\n", i + 1, productName[i]);
        printf("Quantidade: %d\n", stockQuantity[i]);
        printf("======================================================\n");

    }
}

//página principal do programa com um menu
int main(){
    int option;

    /*do-while é utilizado para que o programa não fialize depois do primeiro loop, 
    fazendo com que o usuário possa fazer mais de uma operação em uma mesma execução*/
    
    do{
        printf("=================Controle de Estoque==================\n");
        printf("\n            1.       Cadastrar Produto\n");
        printf("            2.       Atualizar Estoque\n");
        printf("            3. Verificar Estoque Baixo\n");
        printf("            4.         Listar Produtos\n");
        printf("            5.                    Sair\n");
        printf("\n======================================================\n");
        printf("Escolha uma das opções do Menu: ");
        scanf("%d", &option);
        printf("======================================================\n");

        switch (option){
        case 1:
            addProduct();
            break;
    
        case 2:
            updateStock();
            break;
    
        case 3:
            lowStock();
            break;

        case 4:
            listProducts();
            break;
    
        case 5:
            printf("Saindo do programa...\n");
            break;

        default:
            printf("[ERROR]");
            break;
        }

    } while (option != 5);
    
    
    return 0;
}