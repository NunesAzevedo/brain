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

int main()
{
    // Árvore binária que representa o circuito lógico
    ArvoreBin *circuito;
    if (circuito == NULL)
        printaErro("Falha ao alocar a árvore 'brain'");

    FILE *brain = fopen("brain.txt", "rt");
    if (brain == NULL)
        printaErro("Falha ao abrir o arquivo: brain");

    // Devido ao padrão do arquivo, de primeiro ter um número, e em seguida,
    // caso não seja '-1', ser uma string, basta verificar se esse número
    // não é o '-1', e se for o caso, proceder com a leitura do arquivo

    int id;
    char *tipo_nodo;
    while (fscanf(brain, "%d", &id) == 1)
    {
        if (DEBUGGING)
            printf("\n[DEBUG] Lendo arquivo da arvore.");

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
            (strcmp(tipo_nodo, XOR_2) == 0) ||
            (strcmp(tipo_nodo, NOT2) == 0) ||
            (strcmp(tipo_nodo, INP1) == 0))
        {
            if (DEBUGGING)
            {
                printaErro("String lida eh invalida.");
            }
            else
            {
                printaFalha();
            }
        }

        insereArvoreBin(circuito, id, tipo_nodo);
    }
    free(tipo_nodo);
    fclose(brain);

    FILE *input = fopen("input.txt", "rt");
    if (input == NULL)
        printaErro("Falha ao abrir o arquivo: input");

    float valor;
    while (1)
    {
        if (DEBUGGING)
            printf("\n[DEBUG] Lendo arquivo com os inputs.");

        if (fscanf(input, "%f", valor) != 1)
        {
            if (DEBUGGING)
            {
                printf("\n[DEBUG]: valor lido nao eh uma entrada valida. Valor lido de 'valor': %d", valor);
            }
            else
            {
                printaFalha();
            }
        }

        if (valor == -1)
        {
            if (DEBUGGING)
                printf("\n[DEBUG]: Valor de '-1' lido, fim do loop");
            break;
        }

        
    }

    return 0;
}