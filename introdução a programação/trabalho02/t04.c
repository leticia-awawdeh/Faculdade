#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definção das constantes
#define MAX_PACIENTES 100
#define MAX_NOME 50
#define MAX_CONVENIO 30

//Definição da estrutura de dados para um paciente
struct Paciente {
    int codigo;          
    char nome[MAX_NOME]; 
    char convenio[MAX_CONVENIO]; 
    char telefone_fixo[15]; 
    char telefone_celular[15]; 
};

//Definição da estrutura de dados para consulta médica
struct Consulta {
    int codigo_paciente; 
    char data[11];      
    char hora[6];       
    char tipo[8];       
};

// Função para cadastrar um novo paciente
void cadastrarPaciente() {

    //Abre o arquivo para adição de pacientes
    FILE *arquivo = fopen("paciente.dat", "ab"); 

    //Verifica se o arquivo foi aberto corretamente
    if (!arquivo) { 
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    struct Paciente paciente; 
    printf("Digite o código do paciente: "); 
    scanf("%d", &paciente.codigo); 

    //Verifica se o código do paciente já existe no arquivo
    struct Paciente temp;
    FILE *arquivo_temp = fopen("paciente.dat", "rb"); //Abre o arquivo para leitura
    while (fread(&temp, sizeof(struct Paciente), 1, arquivo_temp)) { //Lê todos os pacientes do arquivo
        if (temp.codigo == paciente.codigo) { //Se o código já existe
            printf("Código de paciente já cadastrado. Tente novamente.\n");
            fclose(arquivo_temp); //Fecha o arquivo temporário
            fclose(arquivo); //Fecha o arquivo principal
            return; //Sai da função
        }
    }
    fclose(arquivo_temp); //Fecha o arquivo temporário

    //Solicita e lê as outras informações do paciente
    printf("Digite o nome do paciente: ");
    getchar(); //Limpa o buffer do scanf
    fgets(paciente.nome, MAX_NOME, stdin); 
    paciente.nome[strcspn(paciente.nome, "\n")] = 0; 

    printf("Digite o nome do convênio: ");
    fgets(paciente.convenio, MAX_CONVENIO, stdin); 
    paciente.convenio[strcspn(paciente.convenio, "\n")] = 0; //Remove o caractere de nova linha do convênio

    printf("Digite o telefone fixo [formato: (DDD)4002-8922]: ");
    fgets(paciente.telefone_fixo, 15, stdin);
    paciente.telefone_fixo[strcspn(paciente.telefone_fixo, "\n")] = 0; //Remove o caractere de nova linha do telefone fixo

    printf("Digite o telefone celular [formato: (DDD) 9 3714-9285]: ");
    fgets(paciente.telefone_celular, 15, stdin); 
    paciente.telefone_celular[strcspn(paciente.telefone_celular, "\n")] = 0; //Remove o caractere de nova linha do telefone celular

    fwrite(&paciente, sizeof(struct Paciente), 1, arquivo); //Escreve o paciente no arquivo
    fclose(arquivo);
    printf("Paciente cadastrado com sucesso!\n");
}

//Função que agenda uma nova consulta
void agendarConsulta() {
    FILE *arquivo = fopen("agenda.dat", "ab"); //Abre o arquivo para adição de consultas
    if (!arquivo) { //Verifica se o arquivo foi aberto corretamente
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    struct Consulta consulta; 
    printf("Digite o código do paciente: "); 
    scanf("%d", &consulta.codigo_paciente); 

    //Solicita e lê as outras informações da consulta
    printf("Digite a data da consulta (dd/mm/aaaa): ");
    getchar(); //Limpa o buffer do scanf
    fgets(consulta.data, 11, stdin); //Lê a data da consulta
    consulta.data[strcspn(consulta.data, "\n")] = 0; //Remove o caractere de nova linha da data

    printf("Digite a hora da consulta (hh:mm): ");
    fgets(consulta.hora, 6, stdin); //Lê a hora da consulta
    consulta.hora[strcspn(consulta.hora, "\n")] = 0; //Remove o caractere de nova linha da hora

    printf("Digite o tipo da consulta (Normal ou Retorno): ");
    fgets(consulta.tipo, 8, stdin); //Lê o tipo da consulta
    consulta.tipo[strcspn(consulta.tipo, "\n")] = 0; //Remove o caractere de nova linha do tipo

    //Verifica se já existe uma consulta agendada para a mesma data e hora
    struct Consulta temp;
    FILE *arquivo_temp = fopen("agenda.dat", "rb"); //Abre o arquivo para leitura
    while (fread(&temp, sizeof(struct Consulta), 1, arquivo_temp)) { //Lê todos os pacientes do arquivo
        if (strcmp(temp.data, consulta.data) == 0 && strcmp(temp.hora, consulta.hora) == 0) { //Se a data e a hora coincidirem
            printf("Já existe uma consulta agendada para esta data e hora. Tente novamente.\n");
            fclose(arquivo_temp); //Fecha o arquivo temporário
            fclose(arquivo); //Fecha o arquivo principal
            return; //Sai da função
        }
    }
    fclose(arquivo_temp);

    fwrite(&consulta, sizeof(struct Consulta), 1, arquivo); //Escreve a consulta no arquivo
    fclose(arquivo); //Fecha o arquivo
    printf("Consulta agendada com sucesso.\n");
}

//Função para alterar os dados de um paciente
void alterarPaciente() {
    FILE *arquivo = fopen("paciente.dat", "r+b"); //Abre o arquivo para leitura e gravação
    if (!arquivo) { //Verifica se o arquivo foi aberto corretamente
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int codigo_paciente; //Variável para armazenar o código do paciente a ser alterado
    printf("Digite o código do paciente a ser alterado: ");
    scanf("%d", &codigo_paciente); //Lê o código do paciente

    struct Paciente paciente; //Estrutura para armazenar as informações do paciente
    int encontrado = 0; //indica se o paciente foi encontrado
    while (fread(&paciente, sizeof(struct Paciente), 1, arquivo)) { //Lê todos os pacientes do arquivo
        if (paciente.codigo == codigo_paciente) { //Se o código corresponder
            encontrado = 1; //Atualiza a flag
            //Solicita e lê as novas informações do paciente
            printf("Digite o novo nome do paciente: ");
            getchar(); //Limpa o buffer do scanf
            fgets(paciente.nome, MAX_NOME, stdin); 
            paciente.nome[strcspn(paciente.nome, "\n")] = 0; //Remove o caractere de nova linha

            printf("Digite o novo nome do convênio: ");
            fgets(paciente.convenio, MAX_CONVENIO, stdin); 
            paciente.convenio[strcspn(paciente.convenio, "\n")] = 0; //Remove o caractere de nova linha

            printf("Digite o novo telefone fixo: ");
            fgets(paciente.telefone_fixo, 15, stdin); 
            paciente.telefone_fixo[strcspn(paciente.telefone_fixo, "\n")] = 0; //Remove o caractere de nova linha 

            printf("Digite o novo telefone celular: ");
            fgets(paciente.telefone_celular, 15, stdin); 
            paciente.telefone_celular[strcspn(paciente.telefone_celular, "\n")] = 0; //Remove o caractere de nova linha
            fseek(arquivo, -sizeof(struct Paciente), SEEK_CUR); //Move o ponteiro para o local do paciente na memória
            fwrite(&paciente, sizeof(struct Paciente), 1, arquivo); //Grava as novas informações do paciente no arquivo
            printf("Paciente alterado com sucesso.\n");
            break; //Sai do loop
        }
    }

    if (!encontrado) { //Se o paciente não foi encontrado
        printf("Paciente não encontrado.\n");
    }

    fclose(arquivo); //Fecha o arquivo
}

//Função para visualizar todas as consultas agendadas
void visualizarConsultas() {
    FILE *arquivo_paciente = fopen("paciente.dat", "rb"); //Abre o arquivo de pacientes para leitura
    FILE *arquivo_agenda = fopen("agenda.dat", "rb"); //Abre o arquivo de agenda para leitura
    if (!arquivo_paciente || !arquivo_agenda) { //Verifica se os arquivos foram abertos corretamente
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    struct Paciente paciente; //Estrutura para armazenar as informações do paciente
    struct Consulta consulta; //Estrutura para armazenar as informações da consulta
    while (fread(&consulta, sizeof(struct Consulta), 1, arquivo_agenda)) { //Lê todas as consultas do arquivo de agenda
        fseek(arquivo_paciente, 0, SEEK_SET); //Move o ponteiro para o início do arquivo de pacientes
        while (fread(&paciente, sizeof(struct Paciente), 1, arquivo_paciente)) { //Lê todos os pacientes do arquivo de pacientes
            if (paciente.codigo == consulta.codigo_paciente) { //Se o código do paciente corresponder
                printf("Nome do paciente: %s\n", paciente.nome); 
                printf("Data da consulta: %s\n", consulta.data);
                printf("Hora da consulta: %s\n", consulta.hora); 
                printf("Tipo da consulta: %s\n", consulta.tipo);
                printf("----------------------------\n"); 
                break; 
            }
        }
    }

    fclose(arquivo_paciente); //Fecha o arquivo de pacientes
    fclose(arquivo_agenda); //Fecha o arquivo de agenda
}

//Função para gerar um arquivo auxiliar
void gerarArquivoAuxiliar() {
    /*Abre os arquivos necessários para leitura dos dados dos pacientes e das consultas
    e para escrita no arquivo auxiliar.*/
    FILE *arquivo_paciente = fopen("paciente.dat", "rb");
    FILE *arquivo_agenda = fopen("agenda.dat", "rb");
    FILE *arquivo_auxiliar = fopen("auxiliar.txt", "w");

    //Verifica se os arquivos foram abertos corretamente
    if (!arquivo_paciente || !arquivo_agenda || !arquivo_auxiliar) {
        printf("Erro ao abrir os arquivos.\n");
        return; //Sai da função caso algum arquivo não tenha sido aberto corretamente
    }

    //Estruturas para armazenar as informações lidas dos arquivos
    struct Paciente paciente;
    struct Consulta consulta;

    //Loop que percorre todas as consultas no arquivo de agenda
    while (fread(&consulta, sizeof(struct Consulta), 1, arquivo_agenda)) {
        //Retorna ao início do arquivo de pacientes para cada consulta
        fseek(arquivo_paciente, 0, SEEK_SET);

        //Loop que percorre todos os pacientes no arquivo de pacientes.
        while (fread(&paciente, sizeof(struct Paciente), 1, arquivo_paciente)) {
            /*Se o código do paciente corresponder ao código do paciente na consulta atual
            Escreve as informações no arquivo auxiliar*/
            if (paciente.codigo == consulta.codigo_paciente) {
                fprintf(arquivo_auxiliar, "%s-%s-%s\n", paciente.nome, consulta.data, consulta.hora);
                break; //Sai do loop após encontrar a correspondência
            }
        }
    }

    //Fecha os arquivos após o processo de leitura e escrita concluídos
    fclose(arquivo_paciente);
    fclose(arquivo_agenda);
    fclose(arquivo_auxiliar);

    //Mensagem informando que o arquivo auxiliar foi gerado
    printf("Arquivo auxiliar gerado com sucesso.\n");
}

void exibirMenu() {
    //Exibe o menu de opções disponíveis para o usuário
    printf("\nMenu:\n");
    printf("1. Cadastrar paciente\n");
    printf("2. Agendar consulta\n");
    printf("3. Alterar paciente\n");
    printf("4. Visualizar consultas\n");
    printf("5. Gerar arquivo auxiliar\n");
    printf("0. Sair\n");
    printf("----------------------------\n");
    printf("Escolha uma opção: ");
}

int main() {
    int opcao;
    //Loop que mantém o programa rodando até que o usuário escolha sair
    do {
        exibirMenu();
        scanf("%d", &opcao);

        //Chama a função para a opção selecionada
        switch (opcao) {
            case 1:
                cadastrarPaciente();
                break;
            case 2:
                agendarConsulta();
                break;
            case 3:
                alterarPaciente();
                break;
            case 4:
                visualizarConsultas();
                break;
            case 5:
                gerarArquivoAuxiliar();
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
