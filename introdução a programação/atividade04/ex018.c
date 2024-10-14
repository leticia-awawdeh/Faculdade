#include <stdio.h>

int main(){
    float average;
    int laboratory, test2, finalExam;

    printf("Digite a nota de laboratório: ");
    scanf("%d", &laboratory);

    printf("Digite a nota da avaliação semestral: ");
    scanf("%d", &test2);

    printf("Digite a nota do teste final: ");
    scanf("%d", &finalExam);

    //faz a média ponderada
    average = (laboratory * 2 + test2 * 3 + finalExam * 5) / (2 + 3 + 5);

    //condicional para pegar o resultado da média e obter a classificação junto com a nota
    if (average == 8 || average == 10){

        printf("Nota A %.2f", average);

    } else if (average < 8 && average == 7){

        printf("Nota B %.2f", average);

    } else if (average < 7 && average == 6){

        printf("Nota C %.2f", average);

    } else if (average < 6 && average == 5){

        printf("Nota D %.2f", average);

    } else {
        printf ("Nota E %.2f", average);
    }
    
    return 0;
}