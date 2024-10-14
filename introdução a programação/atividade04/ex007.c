#include <stdio.h>

int main(){
    int numberA, numberB, result;

    printf ("Digite um número: ");
        scanf("%d", &numberA);

    printf ("Digite um número: ");
        scanf("%d", &numberB);

    //faz o resto da divisão do número A pelo número B
    result = numberA % numberB;

    //verifica se o resto da divisão não deu diferente de 0
    if(result == 0){
        printf("O número %d é divisível pelo número %d", numberA, numberB);

    } else {
        printf("O número %d não é divisível pelo número %d", numberA, numberB);
    }

    return 0;
}