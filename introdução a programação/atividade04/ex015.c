#include <stdio.h>

int main (){
    float height, weight;

    printf("digite a sua altura em metros(m): ");
    scanf("%f", &height);

    printf("digite o seu peso: ");
    scanf("%f", &weight);

    //classifica de acordo com a altura e depois de acordo com o peso
    if (height < 1.20){
        if(weight <= 60){
            printf("A %.2f %.2f", height, weight);

        } else if (weight <= 90){
            printf("D %.2f %.2f", height, weight);

        }else {
            printf("G %.2f %.2f", height, weight);

        } 
    
    } else if (height <= 1.70){
        if (weight <= 60){
            printf("B %.2f %.2f", height, weight);

        } else if (weight <= 90){
            printf("E %.2f %.2f", height, weight);

        } else {
            printf("H %.2f %.2f", height, weight);

        }
        
    } else {
        if (weight <= 60){
            printf("C %.2f %.2f", height, weight);

        } else if (weight <= 90){
            printf("F %.2f %.2f", height, weight);

        } else {
            printf ("I %.2f %.2f", height, weight);
        }
        
    }
    
    return 0;
}