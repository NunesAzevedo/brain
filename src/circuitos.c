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

float and2(No *no1, No *no2)
{
    if (DEBUGGING)
    {
        printf("\n[DEBUG]: Ativando chave AND2:");
        printf("\n[DEBUG]: no1->valor: %f", no1->valor);
        printf("\n[DEBUG]: no2->valor: %f", no2->valor);
    }

    if (no1->valor == 1.0 && no2->valor == 1.0)
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

float or2(No *no1, No *no2)
{
    if (DEBUGGING)
    {
        printf("\n[DEBUG]: Ativando chave OR2:");
        printf("\n[DEBUG]: no1->valor: %f", no1->valor);
        printf("\n[DEBUG]: no2->valor: %f", no2->valor);
    }
    if (no1->valor == 0.0 && no2->valor == 0.0)
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

float xor2(No *no1, No *no2)
{
    if (DEBUGGING)
    {
        printf("\n[DEBUG]: Ativando chave XOR2:");
        printf("\n[DEBUG]: no1->valor: %f", no1->valor);
        printf("\n[DEBUG]: no2->valor: %f", no2->valor);
    }

    if ((no1->valor == 0.0 && no2->valor == 0) ||
        (no1->valor == 1.0 && no2->valor == 1.0))
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
float not2(No *no1, No *no2)
{
    if (DEBUGGING)
    {
        printf("\n[DEBUG]: Ativando chave NOT2:");
        printf("\n[DEBUG]: no1->valor: %f", no1->valor);
        printf("\n[DEBUG]: no2->valor: %f", no2->valor);
    }

    if (no1->valor == 0.0)
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

    // Caso não obedeça nenhum dos 2 casos, houve algum erro
}

void input1(No *no, float valor)
{
    if (DEBUGGING)
    {
        printf("\n[DEBUG]: Ativando chave INP1:");
        printf("\n[DEBUG]: valor a ser inserido no No: %f", valor);
    }

    no->valor = valor;

    if (DEBUGGING)
        printf("\n[DEBUG]: no->valor: %f", no->valor);
}