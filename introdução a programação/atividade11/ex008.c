#include <stdio.h>

int main() {
    float heights[5][10];
    float maxHeight[5];
    int i, j;

    for (i = 0; i < 5; i++) {
        printf("EDigite as alturas dos atletas da delegação %d:\n", i + 1);
        for (j = 0; j < 10; j++) {
            printf("Altura do atleta %d: ", j + 1);
            scanf("%f", &heights[i][j]);
        }
    }

    for (i = 0; i < 5; i++) {
        maxHeight[i] = heights[i][0];
        for (j = 0; j < 10; j++) {
            if (heights[i][j] > maxHeight[i]) {
                maxHeight[i] = heights[i][j];
            }
        }
    }

    for (i = 0; i < 5; i++) {
        printf("A maior altura da delegação %d é: %.2f\n", i + 1, maxHeight[i]);
    }

    return 0;
}
