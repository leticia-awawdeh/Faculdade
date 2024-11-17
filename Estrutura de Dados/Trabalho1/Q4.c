#include <stdio.h>

#define LINHA 10
#define COLUNA 10

void VisualizarSala(int sala[LINHA][COLUNA]){
    for(int i = 0; i < LINHA; i++){
        for(int j = 0; j < COLUNA; j++){
            if (sala[i][j] == 0){
                printf("[ ] ");

            } else {
                printf("[X] ");
            }

        }
        printf("\n");
    }

}

int ReservarAssento(int sala[LINHA][COLUNA], int linha, int coluna){
    if(linha < 1 || linha > LINHA || coluna < 1 || coluna > COLUNA) {
        printf("Assento inválido!\n");
        return -1;
    }

    linha--; 
    coluna--;
    
    if (sala[linha][coluna] == 1) {
        printf("Assento já reservado!\n");
        return -1;
    }
    
    sala[linha][coluna] = 1; // Reservar o assento
    printf("Assento reservado com sucesso!\n");
    return 0;
}


int main(){
    int sala[LINHA][COLUNA] = {0};
    int linha, coluna;
    int option;

    do{
    printf("Menu de Controle de Reservas do Cinema\n");
    printf("1.Visualizar mapa da sala\n");
    printf("2.Reservar Assento\n");
    printf("3.Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &option);

    switch (option){
    case 1:
        VisualizarSala(sala);
        break;
    case 2:
        printf("Digite a linha do assento: ");
        scanf("%d", &linha);
        printf("Digite a coluna do assento: ");
        scanf("%d", &coluna);
        ReservarAssento(sala, linha, coluna);
        break;
    case 3:
        printf("Saindo...");
        break;

    default:
        printf("[ERROR]");
        break;

    }

    }while(option != 3);

    return 0;

}