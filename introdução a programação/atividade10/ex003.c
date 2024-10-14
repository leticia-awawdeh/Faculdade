#include <stdio.h>

int main() {
    float grades[100];
    float sum = 0, average;

    printf("Digite até 100 notas: \n");
    for(int i =0; i < 100; i++){
        scanf("%f", &grades[i]);
        sum += grades[i];
    }

    average = sum /100;

    printf("notas acima da média:%.2f \n", average);
    for(int i = 0; i < 100; i++){
        if(grades[i] > average){
            printf("%.2f\n", grades[i]);
        }
    }

    return 0;
}