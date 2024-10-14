#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 5
#define MAX_NAME 50
#define MAX_CURSO 30

struct Aluno {
    char nome[MAX_NAME];
    int matricula;
    char curso[MAX_CURSO];
};

int main() {
    struct Aluno alunos[MAX_ALUNOS];

    for (int i = 0; i < MAX_ALUNOS; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(alunos[i].nome, MAX_NAME, stdin);
        
        size_t ln = strlen(alunos[i].nome) - 1;
        if (alunos[i].nome[ln] == '\n')
            alunos[i].nome[ln] = '\0';
        
        printf("Digite a matrícula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);
        getchar();

        printf("Digite o curso do aluno %d: ", i + 1);
        fgets(alunos[i].curso, MAX_CURSO, stdin);
        
        ln = strlen(alunos[i].curso) - 1;
        if (alunos[i].curso[ln] == '\n')
            alunos[i].curso[ln] = '\0';
    }

    printf("\nDados dos alunos:\n");
    for (int i = 0; i < MAX_ALUNOS; i++) {
        printf("Aluno %d\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matrícula: %d\n", alunos[i].matricula);
        printf("Curso: %s\n", alunos[i].curso);
        printf("\n");
    }

    return 0;
}
