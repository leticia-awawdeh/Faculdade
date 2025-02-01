#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEOPLE 2100
#define MAX_FRIENDS 2100

typedef struct {
    char name[25];
    int friendCount;
    int friends[MAX_FRIENDS]; 
    int distance;             
    int visited;              
} Person;

Person people[MAX_PEOPLE];
int peopleCount = 0;

/* ================= Funções de Manipulação de Pessoas ================= */

int findPerson(const char* name) {
    for (int i = 0; i < peopleCount; i++) {
        if (strcmp(people[i].name, name) == 0)
            return i;
    }
    return -1;
}

int addPerson(const char* name) {
    int idx = peopleCount;
    strcpy(people[idx].name, name);
    people[idx].friendCount = 0;
    people[idx].visited = 0;
    people[idx].distance = -1;
    peopleCount++;
    return idx;
}

void readRelationships(int n, int *startIndex) {
    char s1[25], s2[25];
    
    for (int i = 0; i < n; i++){
        if (scanf("%s %s", s1, s2) != 2)
            break;
        
        int idx1 = findPerson(s1);
        if (idx1 == -1) {
            idx1 = addPerson(s1);
            if (i == 0) *startIndex = idx1; // Define o primeiro nome como ponto de partida
        }

        int idx2 = findPerson(s2);
        if (idx2 == -1) {
            idx2 = addPerson(s2);
        }

        people[idx1].friends[people[idx1].friendCount++] = idx2;
        people[idx2].friends[people[idx2].friendCount++] = idx1;
    }
}

/* ================= Função de Busca em Largura (BFS) ================= */

void bfsFromPerson(int start, int G) {
    if (start == -1)
        return;
    
    int queue[MAX_PEOPLE];
    int front = 0, rear = 0;
    
    people[start].visited = 1;
    people[start].distance = 0;
    queue[rear++] = start;
    
    while (front < rear) {
        int cur = queue[front++];
        int curDist = people[cur].distance;
        
        if (curDist >= G)
            continue;

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

void collectInvited(int G, char invitedNames[][25], int *invitedCount, int startIndex) {
    *invitedCount = 0;
    for (int i = 0; i < peopleCount; i++){
        if (i == startIndex) // Não inclui a pessoa inicial
            continue;
        if (people[i].visited && people[i].distance >= 1 && people[i].distance <= G) {
            strcpy(invitedNames[*invitedCount], people[i].name);
            (*invitedCount)++;
        }
    }
}

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

void printInvited(int invitedCount, char invitedNames[][25]) {
    printf("\n --Saída-- \n");
    printf("%d\n", invitedCount);
    for (int i = 0; i < invitedCount; i++){
        printf("%s\n", invitedNames[i]);
    }
}

/* ================= Função Principal ================= */

int main(){
    printf("Código iniciado, por favor, coloque as entradas desejadas: \n");
    int n, G, startIndex = -1;
    
    if (scanf("%d %d", &n, &G) != 2)
        return 1;
    
    peopleCount = 0;
    
    readRelationships(n, &startIndex);

    bfsFromPerson(startIndex, G);
    
    int invitedCount = 0;
    char invitedNames[MAX_PEOPLE][25];
    collectInvited(G, invitedNames, &invitedCount, startIndex);

    sortInvitedNames(invitedNames, invitedCount);
    
    printInvited(invitedCount, invitedNames);
    
    return 0;
}
