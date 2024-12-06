/*
    Funções de uso geral no projeto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "main.h"

// Gera um print que indica um erro em um determinado padrão pré-definido e
// para a execução do programa gerando um core-dumped
void printaErro(char *mensagem)
{
    printf("\n\n**************************************************************");
    printf("\n[ERRO]: %s. Encerrando o programa...", mensagem);
    printf("\n\n**************************************************************");
    abort();
}

void printaFalha()
{
    printf("\nFAIL");
}

void printaComeco(char *mensagem)
{
    printf("\n\n**************************************************************");
    printf("\n[DEBUG]: %s", mensagem);
    printf("\n**************************************************************\n");
}

// Gera um breakpoint na execução no terminal, caso a variável DEBUGGING esteja ativada
void printBreakpoint()
{
    if (DEBUGGING)
    {
        printf("\n\n********************");
        printf("\n[DEBUG]: BREAKPOINT");
        printf("\n\n********************");
    }
}
