#include <stdio.h>
#include <limits.h>

#define INF 1000000000
#define MAXN 260      // Número máximo de cidades (N ≤ 250, com folga)
#define MAX_ADJ 260   // Grau máximo de cada cidade
#define MAX_CASES 1000  // Número máximo de casos

typedef struct {
    int v, cost;
} Edge;

// Variáveis globais para o grafo
Edge adj[MAXN][MAX_ADJ];  // Lista de adjacência para cada cidade
int deg[MAXN];            // Quantidade de arestas de cada cidade

/*
 * Inicializa o grafo para N cidades, definindo o grau de cada cidade como 0.
 */
void initializeGraph(int N) {
    for (int i = 0; i < N; i++){
        deg[i] = 0;
    }
}

/*
 * Lê M arestas e atualiza o grafo (inserindo as arestas de forma bidirecional).
 */
void readEdges(int M) {
    int u, v, p;
    for (int i = 0; i < M; i++){
        scanf("%d %d %d", &u, &v, &p);
        // Insere aresta de u para v
        adj[u][deg[u]].v = v;
        adj[u][deg[u]].cost = p;
        deg[u]++;
        // Insere aresta de v para u (estrada de mão dupla)
        adj[v][deg[v]].v = u;
        adj[v][deg[v]].cost = p;
        deg[v]++;
    }
}

/*
 * Impõe a restrição da rota de serviço:
 * As cidades da rota são 0, 1, ..., C-1. Para cada cidade i (0 ≤ i < C-1),
 * descartamos todas as arestas de saída, exceto a que liga i a i+1.
 */
void applyRouteConstraint(int C) {
    for (int i = 0; i < C - 1; i++){
        int routeCost = -1;
        // Procura a aresta que liga i a i+1
        for (int j = 0; j < deg[i]; j++){
            if (adj[i][j].v == i + 1) {
                routeCost = adj[i][j].cost;
                break;
            }
        }
        // Como a rota é garantida, routeCost deve ter sido encontrado.
        // Forçamos que a única saída de i seja para i+1.
        deg[i] = 0;
        adj[i][deg[i]].v = i + 1;
        adj[i][deg[i]].cost = routeCost;
        deg[i]++;
    }
}

/*
 * Executa o algoritmo de Dijkstra no grafo com N cidades, partindo da cidade K
 * e retorna o menor custo para atingir o destino (target).
 */
int dijkstra(int N, int K, int target) {
    int dist[MAXN], used[MAXN];
    // Inicializa as distâncias e vetor de visitados
    for (int i = 0; i < N; i++){
        dist[i] = INF;
        used[i] = 0;
    }
    dist[K] = 0;
    
    for (int i = 0; i < N; i++){
        int u = -1, best = INF;
        // Seleciona o nó não visitado com menor distância
        for (int j = 0; j < N; j++){
            if (!used[j] && dist[j] < best){
                best = dist[j];
                u = j;
            }
        }
        if(u == -1)
            break;
        used[u] = 1;
        // Relaxa as arestas de u
        for (int j = 0; j < deg[u]; j++){
            int v = adj[u][j].v;
            int cost = adj[u][j].cost;
            if (dist[u] + cost < dist[v])
                dist[v] = dist[u] + cost;
        }
    }
    return dist[target];
}

int main(){
    printf("Código inicializado, por favor, coloque as entradas:\n");
    int N, M, C, K;
    int resultados[MAX_CASES], contRes = 0;
    
    /*
     * Cada caso de teste inicia com: N M C K
     * A entrada termina com "0 0 0 0".
     */
    while (scanf("%d %d %d %d", &N, &M, &C, &K) == 4) {
        if (N == 0 && M == 0 && C == 0 && K == 0)
            break;
        
        // Inicializa o grafo para N cidades.
        initializeGraph(N);
        
        // Lê M arestas e atualiza o grafo.
        readEdges(M);
        
        /*
         * Aplica a restrição da rota de serviço:
         * A rota é formada pelas cidades 0, 1, ..., C-1, e se o veículo entrar em
         * alguma dessas (exceto o destino C-1) deverá seguir estritamente a rota.
         */
        applyRouteConstraint(C);
        
        // Calcula o menor custo para ir da cidade K até o destino (C-1)
        int custo = dijkstra(N, K, C - 1);
        resultados[contRes++] = custo;
    }
    

    printf("\n--Saída--\n");
    //Loop para imprimir a saída
    for (int i = 0; i < contRes; i++){
        printf("%d\n", resultados[i]);
    }
    
    return 0;
}
