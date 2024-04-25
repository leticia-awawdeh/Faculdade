#include <stdio.h>

int main(){
    float salary, minWage, dependents, taxPayed, resultSalary12, resultSalary5, tax, plusTax, final;
    
    printf("Digite o salário mínimo em reais (R$): ");
        scanf("%f", &minWage);

    printf("Digite o número de dependentes: ");
        scanf("%f", &dependents);

    printf("Digite o seu salário em reais (R$): ");
        scanf("%f", &salary);

    printf("Digite o valor do imposto já pago R$: ");
        scanf("%f", &taxPayed);

    //calcula se precisa de pagar imposto de renda de acordo com o salário mínimo
    resultSalary12 = minWage * 12;
    resultSalary5 = minWage * 5;

    //verifica se precisa de pagar imposto de renda
    if (salary >= resultSalary12){
        tax = salary * 0.20;

    } else if (salary > resultSalary5){
        tax = salary * 0.08;

    } else {

        printf("Você não precisa pagar o imposto de renda\n");
    }

        //calcula o imposto sob o valor bruto
        plusTax = tax + (tax * 0.04);

        //calcula o imposto a ser pago, descontando o valor já pago
        final = plusTax - taxPayed;

        if(final > 0 ){
            printf("Você necessita de pagar R$ %.2f em impostos", final);

        } else {
            final = final * -1;
            printf("Você será restituído(a) no valor de R$ %.2f", final);

        }
    
    return 0;
}