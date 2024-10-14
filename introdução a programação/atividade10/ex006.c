#include <stdio.h>

#define SIZE 10

int main() {
    int X[SIZE], Y[SIZE];
    int unioN[2*SIZE], differenceXY[SIZE], sum[SIZE], resultMult[SIZE], intersection[SIZE];
    int indexUnion = 0, indexDifference = 0, indexIntersection;

  
    printf("Digite os %d valores do vetor X:\n", SIZE);
    for(int i = 0; i < SIZE; i++) {
        scanf("%d", &X[i]);
    }
    
    printf("Digite os %d valores do vetor Y:\n", SIZE);
    for(int i = 0; i < SIZE; i++) {
        scanf("%d", &Y[i]);
    }

    // a) união de X com Y
    for(int i = 0; i < SIZE; i++) {
        int found = 0;
        for(int j = 0; j < indexUnion; j++) {
            if(unioN[j] == X[i]) {
                found = 1;
                break;
            }
        }
        if(!found) {
            unioN[indexUnion++] = X[i];
        }
    }
    for(int i = 0; i < SIZE; i++) {
        int found = 0;
        for(int j = 0; j < indexUnion; j++) {
            if(unioN[j] == Y[i]) {
                found = 1;
                break;
            }
        }
        if(!found) {
            unioN[indexUnion++] = Y[i];
        }
    }

    // b) diferença entre X e Y
    for(int i = 0; i < SIZE; i++) {
        int found = 0;
        for(int j = 0; j < SIZE; j++) {
            if(X[i] == Y[j]) {
                found = 1;
                break;
            }
        }
        if(!found) {
            int duplicate = 0;
            for(int k = 0; k < indexDifference; k++) {
                if(differenceXY[k] == X[i]) {
                    duplicate = 1;
                    break;
                }
            }
            if(!duplicate) {
                differenceXY[indexDifference++] = X[i];
            }
        }
    }

    // c) soma entre X e Y
    for(int i = 0; i < SIZE; i++) {
        sum[i] = X[i] + Y[i];
    }

    // d) o produto entre X e Y
    for(int i = 0; i < SIZE; i++) {
        resultMult[i] = X[i] * Y[i];
    }

    // e) a interseção entre X e Y
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(X[i] == Y[j]) {
                int duplicate = 0;
                for(int k = 0; k < indexIntersection; k++) {
                    if(intersection[k] == X[i]) {
                        duplicate = 1;
                        break;
                    }
                }
                if(!duplicate) {
                    intersection[indexIntersection++] = X[i];
                }
            }
        }
    }


    
    printf("\nUnião de X com Y:\n");
    for(int i = 0; i < indexUnion; i++) {
        printf("%d ", unioN[i]);
    }

    printf("\nDiferença entre X e Y:\n");
    for(int i = 0; i < indexDifference; i++) {
        printf("%d ", differenceXY[i]);
    }

    printf("\nSoma entre X e Y:\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", sum[i]);
    }

    printf("\nProduto entre X e Y:\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", resultMult[i]);
    }

    return 0;
}
