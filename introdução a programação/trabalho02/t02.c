#include <stdio.h>

//Definições de constantes
#define CURSO_CIENCIA_DA_COMPUTACAO 0
#define CURSO_ENGENHARIA_DE_COMPUTACAO 1
#define CURSO_ANALISE_DE_SISTEMAS 2
#define MAX_CANDIDATOS 40

//Matriz para armazenar os códigos e pontuações dos candidatos
int matriz[3][MAX_CANDIDATOS];

//Variável para controlar o número de candidatos aprovados em cada curso
int numCandidatosAprovados[3] = {0};

//Função para inserir um novo candidato na matriz
void inserirCandidato(int curso, int codigo, int pontuacao) {
    //Verifica se há espaço disponível para mais candidatos
    if (numCandidatosAprovados[curso] < MAX_CANDIDATOS) {
        matriz[curso][numCandidatosAprovados[curso]] = codigo;
        matriz[curso][numCandidatosAprovados[curso] + 1] = pontuacao;
        numCandidatosAprovados[curso]++;
    } else {
        //Se não há espaço, verifica se a nova pontuação é maior que a do último colocado
        if (pontuacao > matriz[curso][MAX_CANDIDATOS - 1]) {
            //Remove o último colocado
            for (int i = MAX_CANDIDATOS - 1; i > numCandidatosAprovados[curso]; i--) {
                matriz[curso][i] = matriz[curso][i - 1];
            }
            //Insere o novo candidato
            matriz[curso][numCandidatosAprovados[curso]] = codigo;
            matriz[curso][numCandidatosAprovados[curso] + 1] = pontuacao;
            numCandidatosAprovados[curso]++;
        }
    }
}

//Função para imprimir os candidatos aprovados
void imprimirCandidatosAprovados(int curso) {
    printf("Candidatos aprovados no curso %s:\n", curso == CURSO_CIENCIA_DA_COMPUTACAO ? "Ciência da Computação" : curso == CURSO_ENGENHARIA_DE_COMPUTACAO ? "Engenharia de Computação" : "Análise de Sistemas");
    for (int i = 0; i < numCandidatosAprovados[curso]; i++) {
        printf("Código: %d, Pontuação: %d\n", matriz[curso][i], matriz[curso][i + 1]);
    }
}

int main() {
    //Declaração de variáveis para armazenar o curso escolhido, o código do candidato e sua pontuação
    int curso;
    int codigo;
    int pontuacao;

    //Loop infinito que só será interrompido quando o usuário decidir parar de inserir candidatos.
    while (1) {
        printf("----------------------------------\n");
        printf("Digite o curso:\n");
        printf("1-Ciência da Computação\n");
        printf("2-Engenharia de Computação\n");
        printf("3-Análise de Sistemas\n");
        printf("----------------------------------\n");
        scanf("%d", &curso);
        
        //Solicita ao usuário que digite o código do candidato.
        printf("Digite o código do candidato: ");
        scanf("%d", &codigo);
        
        //Solicita ao usuário que digite a pontuação obtida pelo candidato.
        printf("Digite a pontuação do candidato: ");
        scanf("%d", &pontuacao);

        /*Chama a função inserirCandidato para adicionar o candidato à lista correspondente ao curso escolhido.
        Subtrai 1 do curso porque os índices dos arrays em C começam em 0,
        enquanto a entrada do usuário começa em 1 para facilitar a compreensão do usuário final.*/
        inserirCandidato(curso - 1, codigo, pontuacao);

        //Pergunta ao usuário se deseja continuar inserindo mais candidatos.
        char continua;
        printf("Deseja continuar inserindo candidatos? (s/n): ");
        scanf(" %c", &continua); //O espaço antes de %c é usado para pular espaços em branco ou novas linhas no buffer.
        
        // Limpa o buffer de entrada para evitar problemas com caracteres residuais na próxima leitura.
        while (getchar() != '\n');

        //Verifica se o usuário digitou 'n' ou 'N' para parar de inserir candidatos.
        //Se sim, interrompe o loop infinito.
        if (continua == 'n' || continua == 'N') {
            break;
        }
    }

    //Após sair do loop, imprime os candidatos aprovados em cada curso.
    imprimirCandidatosAprovados(CURSO_CIENCIA_DA_COMPUTACAO);
    imprimirCandidatosAprovados(CURSO_ENGENHARIA_DE_COMPUTACAO);
    imprimirCandidatosAprovados(CURSO_ANALISE_DE_SISTEMAS);

    return 0;
}

