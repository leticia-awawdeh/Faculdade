#include <stdio.h>

int main(){
    int number1, number2, sum1 = 0, sum2=0;

    printf("Digite o primeiro número: ");
        scanf("%d", &number1);

    printf("Digite o segundo número: ");
        scanf("%d", &number2);

    //vai tentando número por número para saber seus divisores
    for(int i = 1; i < number1; i++){

        //se o número for divisível, vai somando com os outros divisíveis
        if(number1 % i == 0){
            sum1 += i;
            //printf("Número: %d, Soma: %d, i: %d\n", number1, sum1, i);
        }

        //printf("número: %d, i: %d\n", number1, i);
    }

    //mesma coisa que acontece só que para o segundo número
    for (int i = 1; i < number2; i++){

        if(number2 % i == 0){
            sum2 += i;
        }

    }

    //verifica se os números são amigáveis
    if (sum1 == number2 || sum2 == number1){
        printf("Os números %d e %d são amigáveis", number1, number2);

    } else {
        printf("Os números não são amigáveis");
    }
    
    return 0;
}