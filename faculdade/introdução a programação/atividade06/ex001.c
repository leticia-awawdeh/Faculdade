#include <stdio.h>

int main(){
    int number, flag = 0;

    printf("Digite um número: ");
        scanf("%d", &number);

        for (int i = 2; i <= number /2; i++){
            if (number % i == 0){
                flag = 1;
            }

        }

        if (number == 1){
            printf("O número 1 não é primo");
        } else {
            if (flag == 0)
                printf("%d é primo ", number);
            else
                printf("%d é par ", number);
        }
    return 0;
}