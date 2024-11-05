#include <stdio.h>
//Atividade Realizada por Letícia Awawdeh

int somaDigitos(int n){
    if (n < 10){
        return n;
    } else {
        return (n % 10) + somaDigitos(n / 10);
    }
}

int main(){
    printf("%d\n", somaDigitos(1234));
    return 0;
}