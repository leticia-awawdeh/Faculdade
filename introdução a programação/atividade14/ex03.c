#include <stdio.h>
#include <stdlib.h> //para qsort
#include <string.h> //para strcmp

typedef struct {
    char nome[50];
    char endereco[100];
    char telefone[20];
} Pessoa;

int comparar(const void *a, const void *b) {
    Pessoa *pessoaA = (Pessoa *)a;
    Pessoa *pessoaB = (Pessoa *)b;
    
    return strcmp(pessoaA->nome, pessoaB->nome);
}

int main() {
    Pessoa pessoas[5]; 
    
    for(int i = 0; i < 5; i++) {
        printf("Digite o nome da pessoa %d: ", i+1);
        fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);
        
        printf("Digite o endereço da pessoa %d: ", i+1);
        fgets(pessoas[i].endereco, sizeof(pessoas[i].endereco), stdin);
        
        printf("Digite o telefone da pessoa %d: ", i+1);
        fgets(pessoas[i].telefone, sizeof(pessoas[i].telefone), stdin);
    }
    
    qsort(pessoas, 5, sizeof(Pessoa), comparar);
    
    for(int i = 0; i < 5; i++) {
        printf("\nNome: %s", pessoas[i].nome);
        printf("Endereço: %s", pessoas[i].endereco);
        printf("Telefone: %s\n", pessoas[i].telefone);
    }

    return 0;
}
