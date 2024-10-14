#include <stdio.h>

typedef struct {
    int hora;
    int minutos;
    int segundos;
} Horario;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    Data data;
    Horario horario;
    char descricao[256];
} Compromisso;

int main() {
    Compromisso meuCompromisso;

    meuCompromisso.data.dia = 19;
    meuCompromisso.data.mes = 8;
    meuCompromisso.data.ano = 2024;

    meuCompromisso.horario.hora = 14;
    meuCompromisso.horario.minutos = 30;
    meuCompromisso.horario.segundos = 0;

    snprintf(meuCompromisso.descricao, sizeof(meuCompromisso.descricao), "Reunião com a equipe de desenvolvimento");

    printf("Compromisso:\n");
    printf("Data: %02d/%02d/%d\n", meuCompromisso.data.dia, meuCompromisso.data.mes, meuCompromisso.data.ano);
    printf("Horário: %02d:%02d:%02d\n", meuCompromisso.horario.hora, meuCompromisso.horario.minutos, meuCompromisso.horario.segundos);
    printf("Descrição: %s\n", meuCompromisso.descricao);

    return 0;
}
