#include <stdio.h>
//Atividade Realizada por Letícia Awawdeh


void torreHanoi(int n, const char* origem, const char* destino, const char* auxiliar) {
    if (n == 1) {
        printf("Mova o disco 1 de %s para %s\n", origem, destino);
        return;
    }
    torreHanoi(n-1, origem, auxiliar, destino);
    printf("Mova o disco %d de %s para %s\n", n, origem, destino);
    torreHanoi(n-1, auxiliar, destino, origem);
}

int main() {
    torreHanoi(3, "A", "C", "B");
    return 0;
}