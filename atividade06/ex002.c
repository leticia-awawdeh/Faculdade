#include <stdio.h>

int main(){
    float average, number, sum;
    int count = 0;
    
    printf("Digite os números desejados, digite 0 para parar:\n ");

    for (int i = 1; ;i++ ){
        printf("Número %d: ", i);
            scanf("%f", &number);

        if (number == 0){
            break;
        }

        sum += number;
        count++;
    }

    average = sum/count;
    
    printf("A média dos números é igual a %.2f: ", average);
    
    return 0;
}