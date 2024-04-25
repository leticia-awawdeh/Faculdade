#include <stdio.h>

int main(){
    int day, month, year;
    int day2, month2, year2;

    //Lê as datas introduzidas pelo usuário
    printf("digite o dia, mês e ano respetivamente: ");
        scanf("%d %d %d", &day, &month, &year);

    printf("digite o dia, mês e ano respetivamente: ");
        scanf("%d %d %d", &day2, &month2, &year2);

    
    //verifica qual data analizando por ano, mês e dia
    if (year > year2){
        if (month > month2){
            printf("A primeira data %02d/%02d/%d é cronologicamente maior", day, month, year);

        } else if (day > day2) {
            printf("A primeira data %02d/%02d/%d é cronologicamente maior", day, month, year);

        } else {
            printf("[ERROR] Datas não compatíveis");

        }
    } else {
        if (year2 > year){
            printf("A segunda data %02d/%02d/%d é cronologicamente maior", day2, month2, year2);

        }else if (month2 > month){
            printf("A segunda data %02d/%02d/%d é cronologicamente maior", day2, month2, year2);

        } else if (day2 > day){
            printf("A segunda data (%02d/%02d/%d) é cronologicamente maior", day2, month2, year2);

        } else {
            printf("ERROR");
        }
    }
    return 0;
}