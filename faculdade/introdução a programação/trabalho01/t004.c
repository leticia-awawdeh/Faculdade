#include <stdio.h>
#include <math.h>

int main (){
    int wallHeight, ladderHeight;
    float degrees, sine, hipo;

    //introduz o valor de pi, para transformar graus em radianos
    double PI = 3.14159265358979323846;

    printf("Coloque a altura que será colocado o prego em centímetros: ");
        scanf("%d", &wallHeight);
    
    printf("Digite em quantos graus a escada será colocada: ");
        scanf("%f", &degrees);

    //transforma graus em radianos
    float radius = degrees *(PI /180);

    //calculando a função seno (seno = cateto oposto / hipotenusa)
    sine = sin(radius);

    //calculando a hipotenusa (altura pra a escada alcançar a parede)
    hipo = wallHeight / sine;

    //calcula a altura para a escada necessária
    //a função ceil arredonda o valor
    ladderHeight = ceil(hipo/30);

    printf("A escada precisa de aproximadamente %d degraus", ladderHeight);

    return 0;
}