/*
    Aqui estão as funções relativas às funções lógicas
    dos circuitos elétricos.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "main.h"
#include "arvore_bin.h"
#include "circuitos.h"

float and2(No *no)
{
    if (DEBUGGING)
    {
        printf("\n[DEBUG]: Ativando chave AND2:");
        printf("\n[DEBUG]: no->esq->output: %f", no->esq->output);
        printf("\n[DEBUG]: no->dir->output: %f", no->dir->output);
    }

    if (no->esq->output == 1.0 && no->dir->output == 1.0)
    {
        if (DEBUGGING)
            printf("\n[DEBUG]: Retorno do AND2: 1.0");
        return 1.0;
    }
    else
    {
        if (DEBUGGING)
            printf("\n[DEBUG]: Retorno do AND2: 0.0");
        return 0.0;
    }
}

float or2(No *no)
{
    if (DEBUGGING)
    {
        printf("\n[DEBUG]: Ativando chave OR2:");
        printf("\n[DEBUG]: no->esq->output: %f", no->esq->output);
        printf("\n[DEBUG]: no->dir->output: %f", no->dir->output);
    }
    if (no->esq->output == 0.0 && no->dir->output == 0.0)
    {
        if (DEBUGGING)
            printf("\n[DEBUG]: Retorno do OR2: 0.0");
        return 0.0;
    }
    else
    {
        if (DEBUGGING)
            printf("\n[DEBUG]: Retorno do OR2: 1.0");
        return 1.0;
    }
}

float xor2(No *no)
{
    if (DEBUGGING)
    {
        printf("\n[DEBUG]: Ativando chave XOR2:");
        printf("\n[DEBUG]: no->esq->output: %f", no->esq->output);
        printf("\n[DEBUG]: no->dir->output: %f", no->dir->output);
    }

    if ((no->esq->output == 0.0 && no->dir->output == 0) ||
        (no->esq->output == 1.0 && no->dir->output == 1.0))
    {
        if (DEBUGGING)
            printf("\n[DEBUG]: Retorno do XOR2: 0.0");
        return 0.0;
    }
    else
    {
        if (DEBUGGING)
            printf("\n[DEBUG]: Retorno do XOR2: 1.0");
        return 1.0;
    }
}

// Somente o nó "no1" será usado
float not2(No *no)
{
    if (DEBUGGING)
    {
        printf("\n[DEBUG]: Ativando chave NOT2:");
        printf("\n[DEBUG]: no->esq->output: %f", no->esq->output);
        printf("\n[DEBUG]: no->dir->output: %f", no->dir->output);
    }

    if (no->esq->output == 0.0)
    {
        if (DEBUGGING)
            printf("\n[DEBUG]: Retorno do NOT2: 1.0");
        return 1.0;
    }
    else
    {
        if (DEBUGGING)
            printf("\n[DEBUG]: Retorno do NOT2: 0.0");
        return 0.0;
    }
}

void input1(No *no, float valor)
{
    if (DEBUGGING)
    {
        printf("\n[DEBUG]: Ativando chave INP1:");
        printf("\n[DEBUG]: valor a ser inserido no No: %f", valor);
    }

    no->esq->output = valor;

    if (DEBUGGING)
        printf("\n[DEBUG]: no->esq->output: %f", no->esq->output);
}