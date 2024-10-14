#include <stdio.h>
#include <string.h>

//Define constantes para o número de produtos e colunas na matriz
#define NUM_PRODUTOS 6
#define NUM_COLUNAS 3

//Função para cadastrar os produtos
void cadastrar_produtos(char descricao[][30], float matriz[NUM_PRODUTOS][NUM_COLUNAS]) {
    //Loop para cadastrar todos os produtos
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        printf("Cadastro do produto %d:\n", i + 1);
        
        //Solicita e armazena a descrição do produto
        printf("Digite a descricao do produto: ");
        scanf(" %[^\n]", descricao[i]); //Lê a descrição até encontrar um '\n'

        //Verificando se a quantidade em estoque é válida
        do {
            printf("Digite a quantidade em estoque: ");
            scanf("%f", &matriz[i][0]);

            printf("Digite a quantidade mínima exigida: ");
            scanf("%f", &matriz[i][1]);

            //Se a quantidade em estoque for menor que a mínima exigida, exibe erro
            if (matriz[i][0] < matriz[i][1]) {
                printf("Erro: a quantidade em estoque não pode ser inferior à quantidade mínima exigida.\n");
            }
        } while (matriz[i][0] < matriz[i][1]); // Repete enquanto a condição for verdadeira

        //Verificando se o valor unitário é válido
        do {
            printf("Digite o valor unitário: ");
            scanf("%f", &matriz[i][2]);

            //Se o valor unitário for menor ou igual a zero, exibe erro
            if (matriz[i][2] <= 0) {
                printf("Erro: o valor unitário deve ser maior que zero.\n");
            }
        } while (matriz[i][2] <= 0); //Repete enquanto a condição for verdadeira
    }
}

//Função para retirar um produto do estoque
void retirar_produto(char descricao[][30], float matriz[NUM_PRODUTOS][NUM_COLUNAS]) {
    char produto[30];
    float quantidade;

    printf("Digite o nome do produto a ser retirado: ");
    scanf(" %[^\n]", produto);
    
    int encontrado = -1; //Variável para indicar se o produto foi encontrado
    //Loop para encontrar o produto na lista
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        //Compara a descrição do produto com o nome digitado
        if (strcmp(descricao[i], produto) == 0) {
            encontrado = i;
            break; //Sai do loop se encontrar o produto
        }
    }

    //Se o produto não foi encontrado, exibe erro e retorna da função
    if (encontrado == -1) {
        printf("Erro: Produto não encontrado.\n");
        return;
    }

    //Solicitando a quantidade a ser retirada
    printf("Digite a quantidade a ser retirada: ");
    scanf("%f", &quantidade);

    //Verificando se há estoque suficiente para a retirada
    if (matriz[encontrado][0] >= quantidade) {
        matriz[encontrado][0] -= quantidade; //Atualiza a quantidade em estoque
        printf("Retirada bem-sucedida. Nova quantidade em estoque: %.2f\n", matriz[encontrado][0]);
    } else {
        printf("Estoque insuficiente.\n"); //Exibe mensagem de erro se o estoque for insuficiente
    }
}

//Função para mostrar produtos com estoque baixo
void mostrar_produtos_estoque_baixo(char descricao[][30], float matriz[NUM_PRODUTOS][NUM_COLUNAS]) {
    printf("Produtos com quantidade em estoque inferior ao mínimo exigido:\n");
    int count = 0; //Contador para produtos com estoque baixo
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        //Verifica se a quantidade em estoque é menor que a mínima exigida
        if (matriz[i][0] < matriz[i][1]) {
            printf("- %s\n", descricao[i]); //Exibe o produto com estoque baixo
            count++; //Incrementa o contador
        }
    }
    //Se nenhum produto tiver estoque baixo, exibe uma mensagem informando isso
    if (count == 0) {
        printf("Nenhum produto com estoque baixo.\n");
    }
}

//Função para calcular e mostrar o valor total dos produtos em estoque
void mostrar_valor_total_estoque(float matriz[NUM_PRODUTOS][NUM_COLUNAS]) {
    float valor_total = 0; //Variável para armazenar o valor total
    for (int i = 0; i < NUM_PRODUTOS; i++) {
        //Calcula o valor total multiplicando a quantidade por seu valor unitário
        valor_total += matriz[i][0] * matriz[i][2];
    }
    //Exibe o valor total dos produtos em estoque
    printf("Valor total dos produtos no estoque: %.2f\n", valor_total);
}

int main() {
    char descricao[NUM_PRODUTOS][30]; //Matriz para armazenar as descrições dos produtos
    float matriz[NUM_PRODUTOS][NUM_COLUNAS]; //Matriz para armazenar dados dos produtos

    int opcao; //Variável para armazenar a opção escolhida pelo usuário
    do {
        printf("---------------------------------------------------\n");
        printf("\nMenu de Opções:\n");
        printf("1. Cadastrar produtos\n");
        printf("2. Retirar produto do estoque\n");
        printf("3. Mostrar produtos com estoque baixo\n");
        printf("4. Mostrar valor total do estoque\n");
        printf("5. Sair\n");
        printf("---------------------------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_produtos(descricao, matriz); 
                break;
            case 2:
                retirar_produto(descricao, matriz); 
                break;
            case 3:
                mostrar_produtos_estoque_baixo(descricao, matriz); 
                break;
            case 4:
                mostrar_valor_total_estoque(matriz); 
                break;
            case 5:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 5); //Repete até que o usuário escolha a opção 5 para sair

    return 0; 
}
