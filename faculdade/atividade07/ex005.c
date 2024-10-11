#include <stdio.h>

int main() {
    int month;
    float monthlyConsumption, totalConsumption = 0;
    const int numberOfMonths = 12;

    for (month = 1; month <= numberOfMonths; month++) {
        printf("Digite o consumo de energia elétrica do mês %d: ", month);
        scanf("%f", &monthlyConsumption);

        totalConsumption += monthlyConsumption;
    }

    float annualAverage = totalConsumption / numberOfMonths;

    printf("A média de consumo de energia elétrica no ano foi de: %.2f\n", annualAverage);

    return 0;
}
