#include <stdio.h>

void convertSeconds(int totalSeconds, int *hours, int *minutes, int *seconds) {
    *hours = totalSeconds / 3600;
    totalSeconds %= 3600; 
    
    *minutes = totalSeconds / 60; 
    *seconds = totalSeconds % 60;
}

int main() {
    int totalSeconds, hours, minutes, seconds;
    
    printf("Digite o valor em segundos: ");
    scanf("%d", &totalSeconds);
    
    convertSeconds(totalSeconds, &hours, &minutes, &seconds);
    
    printf("%d segundos correspondem a %02d:%02d:%02d\n", totalSeconds, hours, minutes, seconds);
    
    return 0;
}
