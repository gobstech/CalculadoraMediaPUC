#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Função que limpa o buffer de entrada do teclado
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Esta função garante compatibilidade do CLS em Windows, Linux e MacOS
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

float lerNota(char* label) {
    float n;
    int status;
    while (1) {
        printf("%s", label);
        status = scanf("%f", &n);

        if (status != 1) { //Usuário digitou letra
            printf("Erro: Digite apenas números.\n");
            clearBuffer();
        } else if (n < 0 || n > 10) {
            printf("Erro: A nota deve ser entre 0.0 e 10.0.\n");
        } else {
            return n; // Entrada válida!
        }
    }
}

// Função de leitura de opção de disciplina cuja média será calculada
int readOption() {
    int n;
    printf("\n--- Sistema de Cálculo de Médias PUC-Campinas ---\n");
    printf("1 - PI: Projetos de Sistemas Digitais\n");
    printf("2 - Mecânica dos Sólidos\n");
    printf("3 - Cálculo II\n");
    printf("4 - Física do Movimento\n");
    printf("5 - Ética e Antropologia Teológica\n");
    printf("6 - Métodos Experimentais de Física e Tratamento de Dados\n");
    printf("\nDigite o número correspondente: ");

    // O scanf retorna o número de itens lidos com sucesso
    if (scanf("%d", &n) != 1) {
        printf("\n[ERRO] Você digitou letras ou caracteres inválidos!\n");
        clearBuffer(); // Remove o lixo do buffer
        return -1;      // Retorna um valor que cairá no 'default' do switch
    }
    return n;
}

// Funções de cálculo das médias de cada matéria
void PiSistemas() {
    clearScreen();
    float nota = 0, mediaTeorica = 0, mediaPratica = 0, mediaFinal = 0;
    int i;

    for (i = 1; i <= 3; i++) {
        printf("--- %dª PROVA --- ", i); // Agora vai aparecer e ficar parado esperando o lerNota
        nota = lerNota("Digite a nota: ");
        switch (i) {
            case 1:
            case 2:
                nota = nota * 3;
                break;
            case 3:
                nota = nota * 4;
        }
        mediaTeorica = mediaTeorica + nota;
    }

    mediaTeorica /= 10;

    printf("\nMédia Teórica: %.2f\n", mediaTeorica);

    mediaPratica = lerNota("\nDigite sua média prática (média das notas das atividades disponível no Canvas): \n");
    printf("\nMédia Pratica: %.2f\n", mediaPratica);

    mediaFinal = 0.8 * mediaTeorica + 0.2 * mediaPratica;
    printf("\nMédia final: %.2f\n", mediaFinal);

    if (mediaFinal > 5) {
        printf("\nAprovado!\n");
    } else {
        printf("\nReprovado!\n");
    }
}

void MecSol() {
    clearScreen();
    float nota = 0, mediaFinal = 0;
    int i;
    for (i = 1; i <= 3; i++) {
        printf("--- %dª PROVA --- ", i); // Agora vai aparecer e ficar parado esperando o lerNota
        nota = lerNota("Digite a nota: ");
        switch (i) {
            case 1:
                mediaFinal = mediaFinal + nota * 0.3;
                break;
            case 2:
                mediaFinal = mediaFinal + nota * 0.5;
                break;
            case 3:
                mediaFinal = mediaFinal + nota * 0.2;
                break;
        }
    }

    printf("\nMédia final: %.2f\n", mediaFinal);

    if (mediaFinal > 5) {
        printf("\nAprovado!\n");
    } else {
        printf("\nReprovado!\n");
    }
}

void CalculoDois() {
    clearScreen();
    float nota = 0, mediaFinal = 0, mediaTeorica = 0, somaProvas = 0, somaTestes = 0, mediaPratica = 0,
            mediaAtividadesCanvas = 0;
    printf("\nLeitura das notas das provas: \n");
    int i, j, k;
    for (i = 1; i <= 3; i++) {
        printf("--- %dª PROVA --- ", i); // Agora vai aparecer e ficar parado esperando o lerNota
        nota = lerNota("Digite a nota: ");
        switch (i) {
            case 1:
                nota = nota * 0.2;
                break;
            case 2:
                nota = nota * 0.3;
                break;
            case 3:
                nota = nota * 0.35;
                break;
        }
        somaProvas = somaProvas + nota;
    }
    printf("\nLeitura das notas dos testes:\n");
    for (j = 1; j <= 3; j++) {
        printf("\n%dº TESTE: ", j);
        nota = lerNota("Digite a nota no teste em questão: ");
        somaTestes += nota;
    }

    mediaTeorica = somaProvas + 0.15 * (somaTestes / 2);

    printf("\nMédia Teórica: %.2f\n", mediaTeorica);

    printf("\nCálculo da média prática: \n");
    for (k = 1; k <= 2; k++) {
        switch (k) {
            case 1:
                printf("--- MÉDIA DOS PROJETOS --- ", k); // Agora vai aparecer e ficar parado esperando o lerNota
                nota = lerNota("Digite a nota: ");
                nota = nota * 0.6;
                break;
            case 2:
                printf("--- MÉDIA DAS ATIVIDADES TEÓRICAS CANVAS  --- ", k); // Agora vai aparecer e ficar parado esperando o lerNota
                nota = lerNota("Digite a nota: ");
                nota = nota * 0.1;
                break;
        }
        mediaPratica = mediaPratica + nota;
    }

    mediaFinal = cbrt(pow(mediaTeorica, 2) * mediaPratica);
    printf("\nMédia final: %.2f\n", mediaFinal);

    if (mediaFinal > 5) {
        printf("\nAprovado!\n");
    } else {
        mediaAtividadesCanvas = lerNota("\nDigite a média das atividades teóricas Canvas:\n");
        mediaFinal = 1.25 * mediaFinal * (mediaAtividadesCanvas / 10);

        printf("\nMédia final: %.2f\n", mediaFinal);

        if (mediaFinal > 5) printf("\nAprovado!\n");
        else printf("\nReprovado!\n");
    }
}

void FisicaMov() {
    clearScreen();
    float nota = 0, somaProjetos = 0, somaTestes = 0, multProvas = 1, mediaFinal = 0, mediaSincronas = 0;
    int i, k, j;
    printf("\nLeitura das notas das provas: \n");
    for (i = 1; i <= 2; i++) {
        printf("--- %dª PROVA --- ", i); // Agora vai aparecer e ficar parado esperando o lerNota
        nota = lerNota("Digite a nota: ");
        multProvas *= nota;
    }

    printf("\nLeitura das notas dos testes: \n");
    for (k = 1; k <= 3; k++) {
        printf("--- %dª TESTE --- ", k); // Agora vai aparecer e ficar parado esperando o lerNota
        nota = lerNota("Digite a nota: ");
        somaTestes += nota;
    }

    printf("\nLeitura das notas dos projetos práticos: \n");
    for (j = 1; j <= 2; j++) {
        printf("--- %dº PROJETO PRÁTICO --- ", j);
        nota = lerNota("\nDigite a nota do projeto em questão: \n");
        somaProjetos += nota;
    }

    mediaFinal = 0.6 * sqrt(multProvas) + 0.1 * somaTestes + 0.05 * somaProjetos;
    printf("\nMédia final: %.2f\n", mediaFinal);

    if (mediaFinal > 5) {
        printf("\nAprovado!\n");
    } else {
        mediaSincronas = lerNota("\nDigite a média de suas atividades assíncronas (disponível no Canvas ao final do semestre):\n");
        mediaFinal = mediaFinal * (mediaSincronas * 0.05 + 0.75);

        printf("\nMédia final: %.2f\n", mediaFinal);

        if (mediaFinal > 5) {
            printf("\nAprovado com média 5.0!\n");
        } else {
            printf("\nReprovado!\n");
        }
    }
}

void Etica() {
    clearScreen();
    float nota = 0, media = 0;
    int i;
    for (i = 1; i <= 2; i++) {
        printf("--- %dª PROVA --- ", i); // Agora vai aparecer e ficar parado esperando o lerNota
        nota = lerNota("Digite a nota: ");
        media += nota;
    }
    media = media / 2;
    printf("\nMédia: %.2f\n", media);

    if (media > 5) printf("\nAprovado!\n");
    else printf("\nReprovado!\n");
}

void MetodosFisica() {
    clearScreen();
    float nota = 0, multiplicacaoProvas = 1, mediaAtividadesIndividuais = 0, mediaAtividadesGrupo = 0, mediaFinal = 0;

    int i = 1;

    for (i; i <= 2; i++) {
        printf("--- %dª PROVA --- ", i);
        nota = lerNota("Digite a nota: ");
        multiplicacaoProvas *= nota;
    }

    printf("--- MÉDIA DAS ATIVIDADES INDIVIDUAIS --- ");
    mediaAtividadesIndividuais = lerNota("Digite a média: ");

    printf("--- MÉDIA DAS ATIVIDADES EM GRUPO --- ");
    mediaAtividadesGrupo = lerNota("Digite a média: ");

    mediaFinal = 0.5 * sqrt(multiplicacaoProvas) + 0.2 * mediaAtividadesIndividuais + 0.3 * mediaAtividadesGrupo;

    printf("Média Final: %.2f", mediaFinal);

    if (mediaFinal >= 5) printf ("\nAprovado!\n");
    else printf("\nReprovado!\n");
}

// Função principal do programa (chama as funções modularizadas de acordo com o fluxo do programa)
int main(void) {
    clearScreen();
    int runner = 1;
    do {
        int opcaoSelecionada = 0;
        int isValid = 0;

        while (!isValid) {
            opcaoSelecionada = readOption();

            switch (opcaoSelecionada) {
                case 1:
                    isValid = 1;
                    PiSistemas();
                    break;
                case 2:
                    isValid = 1;
                    MecSol();
                    break;
                case 3:
                    isValid = 1;
                    CalculoDois();
                    break;
                case 4:
                    isValid = 1;
                    FisicaMov();
                    break;
                case 5:
                    isValid = 1;
                    Etica();
                    break;
                case 6:
                    isValid = 1;
                    MetodosFisica();
                    break;
                default:
                    if (opcaoSelecionada != -1) printf("\nOpcão inválida!\n");
                    printf("\nTente novamente!\n");
                    break;
            }
        }
        printf("\nGostaria de calcular mais alguma média?\n1 - Sim\n0 - Não\n");
        scanf("%d", &runner);
    } while (runner);
    printf("Obrigado por utilizar o Sistema de Cálculo de Médias da PUC-Campinas! Até breve!");
    return 0;
}
