#include <stdio.h>

int main(){
    float id;

    printf("digite a idade do participante: ");
    scanf("%f", &id);

    //classifica o participante de acordo com a faixa de idade
    if (id == 5 || id <= 7){
        printf("Infantil A");

    } else if (id == 8 || id <= 10){
        printf("Infantil B");

    } else if (id == 11 || id <= 13){
        printf("Juveni A");

    } else if (id == 14 || id <=17){
        printf("Juvenil B");
    } else {
        printf("Sênior");
    };
    
    return 0;
}