#include <stdio.h>

typedef struct {
    char nome[16]; // Nome com máximo de 15 letras + '\0'
    float potencia; 
    float tempoAtivo;
} Eletrodomestico;

void lerEletrodomesticos(Eletrodomestico eletros[5]) {
    for(int i = 0; i < 5; i++) {
        printf("Digite o nome do eletrodomestico %d: ", i+1);
        fgets(eletros[i].nome, sizeof(eletros[i].nome), stdin);
        
        printf("Digite a potencia do eletrodomestico %d em kW: ", i+1);
        scanf("%f", &eletros[i].potencia);
        
        printf("Digite o tempo ativo do eletrodomestico %d por dia em horas: ", i+1);
        scanf("%f", &eletros[i].tempoAtivo);
        getchar(); // Limpa o buffer do teclado
    }
}

void calcularConsumo(Eletrodomestico eletros[5], float tempoEmDias) {
    float consumoTotal = 0;
    
    printf("\nConsumo de energia dos eletrodomesticos:\n");
    for(int i = 0; i < 5; i++) {
        float consumo = eletros[i].potencia * eletros[i].tempoAtivo * tempoEmDias;
        printf("%s: %.2f kWh\n", eletros[i].nome, consumo);
        consumoTotal += consumo;
    }
    
    printf("\nConsumo total na casa: %.2f kWh\n", consumoTotal);
    
    printf("\nConsumo relativo de cada eletrodomestico:\n");
    for(int i = 0; i < 5; i++) {
        float consumo = eletros[i].potencia * eletros[i].tempoAtivo * tempoEmDias;
        float consumoRelativo = (consumo / consumoTotal) * 100;
        printf("%s: %.2f%%\n", eletros[i].nome, consumoRelativo);
    }
}

int main() {
    Eletrodomestico eletros[5];
    
    lerEletrodomesticos(eletros);
    
    float tempoEmDias;
    printf("Digite o tempo em dias: ");
    scanf("%f", &tempoEmDias);
    
    calcularConsumo(eletros, tempoEmDias);
    
    return 0;
}
