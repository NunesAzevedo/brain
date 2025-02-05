/*
    Código principal do projeto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore_bin.h"
#include "circuitos.h"
#include "common.h"
#include "main.h"

// *************
// Tipos de Nodo
// *************

// Nodos Lógicos
const char AND2[TAM_TIPO_NODO] = "AND2";
const char OR_2[TAM_TIPO_NODO] = "OR-2";
const char XOR2[TAM_TIPO_NODO] = "XOR2";
const char NOT2[TAM_TIPO_NODO] = "NOT2";
const char INP1[TAM_TIPO_NODO] = "INP1";

// Nodos Aritméticos
const char ADD2[TAM_TIPO_NODO] = "ADD2";
const char SUB2[TAM_TIPO_NODO] = "SUB2";
const char MLT2[TAM_TIPO_NODO] = "MLT2";
const char DIV2[TAM_TIPO_NODO] = "DIV2";
const char MOD2[TAM_TIPO_NODO] = "MOD2";
const char PERC[TAM_TIPO_NODO] = "PERC";
const char SQR2[TAM_TIPO_NODO] = "SQR2";
const char POW2[TAM_TIPO_NODO] = "POW2";
const char BIN2[TAM_TIPO_NODO] = "BIN2";
const char MV12[TAM_TIPO_NODO] = "MV12";
const char MV22[TAM_TIPO_NODO] = "MV22";
const char MV32[TAM_TIPO_NODO] = "MV32";
const char CTE0[TAM_TIPO_NODO] = "CTE0";
const char CTE1[TAM_TIPO_NODO] = "CTE1";

// Nodos Condicionais
const char IFGT[TAM_TIPO_NODO] = "IFGT";
const char IFLT[TAM_TIPO_NODO] = "IFLT";
const char IFEQ[TAM_TIPO_NODO] = "IFEQ";
const char IPGT[TAM_TIPO_NODO] = "IPGT";
const char IPLT[TAM_TIPO_NODO] = "IPLT";

int main()
{
    if (DEBUGGING)
        printaComeco("Iniciando programa");

    // Árvore binária que representa o circuito lógico
    ArvoreBin *circuito = criaArvoreBin();

    FILE *brain = fopen("brain.txt", "rt");
    if (brain == NULL)
        printaErro("Falha ao abrir o arquivo: brain");

    // Devido ao padrão do arquivo, de primeiro ter um número, e em seguida,
    // caso não seja '-1', ser uma string, basta verificar se esse número
    // não é o '-1', e se for o caso, proceder com a leitura do arquivo

    if (DEBUGGING)
        printaComeco("Lendo arquivo da arvore.");

    int id;
    char *tipo_nodo = (char *)malloc(sizeof(char) * TAM_TIPO_NODO);
    if (tipo_nodo == NULL)
        printaErro("Erro ao alocar memória para o tipo de nodo");

    while (fscanf(brain, "%d", &id) == 1)
    {
        if (DEBUGGING)
        {
            printf("\n[DEBUG]: Valor do id lido: %d", id);
        }

        if (id == -1) // Encerra a leitura do arquivo
        {
            if (DEBUGGING)
                printf("\n[DEBUG]: id = -1 (quebra o loop), valor da id: %d", id);
            break;
        }

        if (fscanf(brain, "%s", tipo_nodo) != 1)
        {
            printaErro("Erro ao tentar ler string relativa à última ID");
        }

        if (DEBUGGING)
            printf("\n[DEBUG]: Tipo de nodo lido no arquivo: %s", tipo_nodo);

        if ((strcmp(tipo_nodo, AND2) == 0) ||
            (strcmp(tipo_nodo, OR_2) == 0) ||
            (strcmp(tipo_nodo, XOR2) == 0) ||
            (strcmp(tipo_nodo, NOT2) == 0) ||
            (strcmp(tipo_nodo, INP1) == 0) ||
            (strcmp(tipo_nodo, ADD2) == 0) ||
            (strcmp(tipo_nodo, SUB2) == 0) ||
            (strcmp(tipo_nodo, MLT2) == 0) ||
            (strcmp(tipo_nodo, DIV2) == 0) ||
            (strcmp(tipo_nodo, MOD2) == 0) ||
            (strcmp(tipo_nodo, PERC) == 0) ||
            (strcmp(tipo_nodo, SQR2) == 0) ||
            (strcmp(tipo_nodo, POW2) == 0) ||
            (strcmp(tipo_nodo, BIN2) == 0) ||
            (strcmp(tipo_nodo, MV12) == 0) ||
            (strcmp(tipo_nodo, MV22) == 0) ||
            (strcmp(tipo_nodo, MV32) == 0) ||
            (strcmp(tipo_nodo, CTE0) == 0) ||
            (strcmp(tipo_nodo, CTE1) == 0) ||
            (strcmp(tipo_nodo, IFGT) == 0) ||
            (strcmp(tipo_nodo, IFLT) == 0) ||
            (strcmp(tipo_nodo, IFEQ) == 0) ||
            (strcmp(tipo_nodo, IPGT) == 0) ||
            (strcmp(tipo_nodo, IPLT) == 0))
        {
            insereArvoreBin(circuito, id, tipo_nodo);
        }
        else
        {
            if (DEBUGGING)
            {
                printf("\n[DEBUG]: Tipo de nodo invalido: %s", tipo_nodo);
                printaErro("Tipo de nodo invalido");
            }
            else
            {
                printaFalha();
            }
        }
    }
    if (DEBUGGING)
        printaComeco("Fim da leitura do arquivo: brain");
    free(tipo_nodo);
    fclose(brain);

    FILE *input = fopen("inputs.txt", "rt");
    if (input == NULL)
        printaErro("Falha ao abrir o arquivo: input");

    // Como o arquivo segue o padrão de primeiro fornecer o ID, e após isso, o
    // valor dele, caso não seja '-1', vamos verificar ele primeiro para saber
    // se estamos ou não no fim do arquivo
    if (DEBUGGING)
        printaComeco("Lendo arquivo de inputs");
    id = 0;
    float valor;
    while (1)
    {
        if (DEBUGGING)
            printf("\n[DEBUG] Lendo arquivo com os inputs.");

        if (fscanf(input, "%d", &id) != 1)
        {
            if (DEBUGGING)
            {
                printf("\n[DEBUG]: valor lido nao eh uma entrada valida. Valor lido de 'valor': %d", id);
                printaErro("Valor lido eh invalido");
            }
            else
            {
                printaFalha();
            }
        }

        if (id == -1)
        {
            if (DEBUGGING)
                printf("\n[DEBUG]: Valor '-1' lido, fim do loop");
            break;
        }

        if (fscanf(input, "%f", &valor) != 1)
        {
            if (DEBUGGING)
            {
                printf("\n[DEBUG] Valor lido eh invalido e igual a: %f", valor);
                printaErro("Valor invalido.");
            }
            else
            {
                printaFalha();
            }
        }

        alteraValorNoArvBin(circuito, id, valor);
    }
    fclose(input);
    if (DEBUGGING)
        printaComeco("Fim da leitura do arquivo de inputs");

    // Nesse ponto, o circuito está com as ID's, tipos de nodos e com os inputs
    // das folhas.

    montaCircuito(circuito);
    
    if (DEBUGGING)
        printaComeco("Fim da montagem do circuito");

    float output_final = OutputRaiz(circuito);
    liberaArvBin(circuito);

    if (DEBUGGING)
        printf("\n[DEBUG] Print do output final do circuito\n");

    printf("%.2f\n", output_final);

    return 0;
}