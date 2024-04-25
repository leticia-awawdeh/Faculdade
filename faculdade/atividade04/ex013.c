#include <stdio.h>

int main (){
    float weight, medication;
    int prescription, age;

    printf("Digite a idade do paciente: ");
    scanf("%d", &age);

    printf("Digite o peso do paciente: ");
    scanf("%f", &weight);
    
// verifica a idade e o peso do paciente e imprime o tanto de gotas que é necessária para o paciente
if (age >= 12){
    if (weight >= 60){
        printf("40 gotas");

    } else {
        printf("35 gotas");
    }
} else {
    if (weight >= 5 || weight == 9){
        printf("5 gotas");

    } else if (weight >= 9.1 || weight == 16){
        printf("10 gotas");

    } else if (weight >= 16.1 || weight == 24){
        printf("15 gotas");

    } else if (weight >= 24.1 || weight == 30){
        printf("20 gotas");

    } else {
        printf("30 gotas");
        
    }
    

}

    return 0;
}