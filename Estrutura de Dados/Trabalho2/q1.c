#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEOPLE 2100
#define MAX_FRIENDS 2100

typedef struct {
    char name[25];
    int friendCount;
    int friends[MAX_FRIENDS]; // Armazena os índices dos amigos
    int distance;             // Distância (grau) a partir de "John"
    int visited;              // Flag de visita no BFS
} Person;

Person people[MAX_PEOPLE];
int peopleCount = 0;

/* ================= Funções de Manipulação de Pessoas ================= */

/* Procura por uma pessoa na lista; retorna o índice se encontrada ou -1 caso contrário */
int findPerson(const char* name) {
    for (int i = 0; i < peopleCount; i++) {
        if (strcmp(people[i].name, name) == 0)
            return i;
    }
    return -1;
}

/* Adiciona uma nova pessoa à lista e retorna o índice atribuído */
int addPerson(const char* name) {
    int idx = peopleCount;
    strcpy(people[idx].name, name);
    people[idx].friendCount = 0;
    people[idx].visited = 0;
    people[idx].distance = -1;
    peopleCount++;
    return idx;
}

/* Lê as relações de amizade (n relações) e atualiza a lista de pessoas */
void readRelationships(int n) {
    char s1[25], s2[25];
    for (int i = 0; i < n; i++){
        if (scanf("%s %s", s1, s2) != 2)
            break;
        int idx1 = findPerson(s1);
        if (idx1 == -1) {
            idx1 = addPerson(s1);
        }
        int idx2 = findPerson(s2);
        if (idx2 == -1) {
            idx2 = addPerson(s2);
        }
        // Como a relação é mútua, adiciona cada um como amigo do outro
        people[idx1].friends[ people[idx1].friendCount++ ] = idx2;
        people[idx2].friends[ people[idx2].friendCount++ ] = idx1;
    }
}

/* ================= Função de Busca em Largura (BFS) ================= */

/* Realiza o BFS a partir de "John" considerando o grau máximo G */
void bfsFromJohn(int G) {
    int start = findPerson("John");
    if (start == -1)
        return;  // Caso "John" não esteja presente, nada é feito
    
    // Implementação da fila para BFS
    int queue[MAX_PEOPLE];
    int front = 0, rear = 0;
    
    people[start].visited = 1;
    people[start].distance = 0;
    queue[rear++] = start;
    
    while (front < rear) {
        int cur = queue[front++];
        int curDist = people[cur].distance;
        // Se já atingiu o grau máximo, não propaga mais a partir deste nó
        if (curDist >= G)
            continue;
        // Para cada amigo do atual
        for (int i = 0; i < people[cur].friendCount; i++){
            int nb = people[cur].friends[i];
            if (!people[nb].visited) {
                people[nb].visited = 1;
                people[nb].distance = curDist + 1;
                queue[rear++] = nb;
            }
        }
    }
}

/* ================= Coleta, Ordena e Imprime Convidados ================= */

/* Coleta os nomes das pessoas convidadas (visitadas, com distância entre 1 e G)
   Observação: "John" não deve ser incluído */
void collectInvited(int G, char invitedNames[][25], int *invitedCount) {
    *invitedCount = 0;
    for (int i = 0; i < peopleCount; i++){
        if (strcmp(people[i].name, "John") == 0)
            continue;
        if (people[i].visited && people[i].distance >= 1 && people[i].distance <= G) {
            strcpy(invitedNames[*invitedCount], people[i].name);
            (*invitedCount)++;
        }
    }
}

/* Ordena os nomes em ordem lexicográfica crescente usando Bubble Sort */
void sortInvitedNames(char invitedNames[][25], int invitedCount) {
    for (int i = 0; i < invitedCount - 1; i++){
        for (int j = i + 1; j < invitedCount; j++){
            if (strcmp(invitedNames[i], invitedNames[j]) > 0) {
                char temp[25];
                strcpy(temp, invitedNames[i]);
                strcpy(invitedNames[i], invitedNames[j]);
                strcpy(invitedNames[j], temp);
            }
        }
    }
}

/* Imprime a quantidade e os nomes dos convidados */
void printInvited(int invitedCount, char invitedNames[][25]) {
    printf("\n-- Saída --\n");
    printf("%d\n", invitedCount);
    for (int i = 0; i < invitedCount; i++){
        printf("%s\n", invitedNames[i]);
    }
}

/* ================= Função Principal ================= */

int main(){
    int n, G;

    printf("Código iniciado, coloque as entradas: \n");
    
    // Leitura da quantidade de relações diretas e do grau máximo
    if (scanf("%d %d", &n, &G) != 2)
        return 1;
    
    // Inicializa o contador global de pessoas (para cada caso, deve-se começar do zero)
    peopleCount = 0;
    
    // Lê as relações diretas de amizade
    readRelationships(n);
    
    // Realiza o BFS a partir de "John" para calcular os graus de separação
    bfsFromJohn(G);
    
    // Coleta os nomes das pessoas convidadas (excluindo "John")
    int invitedCount = 0;
    char invitedNames[MAX_PEOPLE][25];
    collectInvited(G, invitedNames, &invitedCount);
    
    // Ordena os nomes em ordem lexicográfica crescente
    sortInvitedNames(invitedNames, invitedCount);
    
    // Imprime o resultado conforme o enunciado
    printInvited(invitedCount, invitedNames);
    
    return 0;
}
