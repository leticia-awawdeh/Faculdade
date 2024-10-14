#include <stdio.h>
#include <math.h>

int main() {
    int number, originalNumber, remainder, result = 0, n = 0 ;
    
    printf("Digite um número: ");
    scanf("%d", &number);

    originalNumber = number;

    //vai executar quando o número for diferente de zero
    //esta parte conta quantos dígitos tem o número
    while (originalNumber != 0) {

        //vai removendo os digitos para contar quantos são
        originalNumber /= 10;

        //icrementa até o original number for = 0
        n++;

        //printf("número original: %d n: %d\n", originalNumber, n);
    }

    //reinicia o originalNumber para o seu valor inicial
    originalNumber = number;

   while (originalNumber != 0) {

        //resto da divisão -> pega o último dígito
        remainder = originalNumber % 10;

        //faz a potência do último dígito elevado ao valor n armazenado
        result += pow(remainder, n);

        //remove o último dígito
        originalNumber /= 10;

        //printf("Resto da divisão: %d, resultado: %d, número original: %d\n", remainder, result, originalNumber);

    }

    //verifica se o resultado do cálculo é igual ao número inserido
    if(result == number){
        printf("%d é um número narcisista", number);
    } else {
        printf("%d não é um número narcisista", number);
    }
    
    return 0;
}