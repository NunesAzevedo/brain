/*
    Aqui estão as funções relativas às funções lógicas
    dos circuitos elétricos.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "common.h"
#include "main.h"
#include "arvore_bin.h"
#include "circuitos.h"

float and2(No *no)
{
    if (DEBUGGING)
    {
        printf("\n\n*****************************");
        printf("\n[DEBUG]: Ativando chave AND2:");
        printf("\n[DEBUG]: no->esq->output: %f", (no->esq)->output);
        printf("\n[DEBUG]: no->dir->output: %f", (no->dir)->output);
    }

    if ((no->esq)->output == 1.0 && (no->dir)->output == 1.0)
    {
        if (DEBUGGING)
        {
            printf("\n[DEBUG]: Retorno do AND2: 1.0");
            printf("\n*****************************\n");
        }
        return 1.0;
    }
    else
    {
        if (DEBUGGING)
        {
            printf("\n[DEBUG]: Retorno do AND2: 0.0");
            printf("\n*****************************\n");
        }
        return 0.0;
    }
}

float or2(No *no)
{
    if (DEBUGGING)
    {
        printf("\n\n*****************************");
        printf("\n[DEBUG]: Ativando chave OR2:");
        printf("\n[DEBUG]: no->esq->output: %f", (no->esq)->output);
        printf("\n[DEBUG]: no->dir->output: %f", (no->dir)->output);
    }
    if ((no->esq)->output == 0.0 && (no->dir)->output == 0.0)
    {
        if (DEBUGGING)
        {
            printf("\n[DEBUG]: Retorno do OR2: 0.0");
            printf("\n*****************************\n");
        }
        return 0.0;
    }
    else
    {
        if (DEBUGGING)
        {
            printf("\n[DEBUG]: Retorno do OR2: 1.0");
            printf("\n*****************************\n");
        }
        return 1.0;
    }
}

float xor2(No *no)
{
    if (DEBUGGING)
    {
        printf("\n\n*****************************");
        printf("\n[DEBUG]: Ativando chave XOR2:");
        printf("\n[DEBUG]: no->esq->output: %f", (no->esq)->output);
        printf("\n[DEBUG]: no->dir->output: %f", (no->dir)->output);
    }

    if (((no->esq)->output == 0.0 && (no->dir)->output == 0) ||
        ((no->esq)->output == 1.0 && (no->dir)->output == 1.0))
    {
        if (DEBUGGING)
        {
            printf("\n[DEBUG]: Retorno do XOR2: 0.0");
            printf("\n*****************************\n");
        }
        return 0.0;
    }
    else
    {
        if (DEBUGGING)
        {
            printf("\n[DEBUG]: Retorno do XOR2: 1.0");
            printf("\n*****************************\n");
        }
        return 1.0;
    }
}

// Somente o nó "no1" será usado
float not2(No *no)
{
    if (DEBUGGING)
    {
        printf("\n\n*****************************");
        printf("\n[DEBUG]: Ativando chave NOT2:");
        printf("\n[DEBUG]: no->esq->output: %f", (no->esq)->output);
        printf("\n[DEBUG]: no->dir->output: %f", (no->dir)->output);
    }

    if ((no->esq)->output == 0.0)
    {
        if (DEBUGGING)
        {
            printf("\n[DEBUG]: Retorno do NOT2: 1.0");
            printf("\n*****************************\n");
        }
        return 1.0;
    }
    else
    {
        if (DEBUGGING)
        {
            printf("\n[DEBUG]: Retorno do NOT2: 0.0");
            printf("\n*****************************\n");
        }
        return 0.0;
    }
}

void input1(No *no, float valor)
{
    if (DEBUGGING)
    {
        printf("\n\n*****************************");
        printf("\n[DEBUG]: Ativando chave INP1:");
        printf("\n[DEBUG]: valor a ser inserido no No: %f", valor);
    }

    (no->esq)->output = valor;

    if (DEBUGGING)
    {
        printf("\n[DEBUG]: no->esq->output: %f", (no->esq)->output);
        printf("\n*****************************\n");
    }
}

float add2(No *no)
{
    return no->esq->output + no->dir->output;
}

float sub2(No *no)
{
    return no->esq->output - no->dir->output;
}

float mlt2(No *no)
{
    return no->esq->output * no->dir->output;
}

float div2(No *no)
{
    return no->esq->output / no->dir->output;
}

float mod2(No *no)
{
    return (int)no->esq->output % (int)no->dir->output;
}

float perc(No *no)
{
    return no->esq->output * no->dir->output / 100;
}

float sqr2(No *no)
{
    return sqrtf(no->esq->output + no->dir->output);
}

float pow2(No *no)
{
    return pow(no->esq->output + no->dir->output, 2);
}

float bin2(No *no)
{
    if (no->esq->output + no->dir->output == 0)
        return 0.0;
    else
        return 1.0;
}

float memoria1;
float memoria2;
float memoria3;

float mv12(No *no)
{
    if (no->dir->output == 0)
    {
        no->dir->output = memoria1;
    }
    else if (no->dir->output == 1.0)
    {
        memoria1 = no->esq->output;
    }
    else
    {
        if (DEBUGGING)
        {
            printaErro("Entrada do MV12 nao foi 0 nem 1");
        }
        else
        {
            printaFalha();
        }
    }

    return no->dir->output;
}

float mv22(No *no)
{
    if (no->dir->output == 0)
    {
        no->dir->output = memoria2;
    }
    else if (no->dir->output == 1.0)
    {
        memoria2 = no->esq->output;
    }
    else
    {
        if (DEBUGGING)
        {
            printaErro("Entrada do MV12 nao foi 0 nem 1");
        }
        else
        {
            printaFalha();
        }
    }

    return no->dir->output;
}

float mv32(No *no)
{
    if (no->dir->output == 0)
    {
        no->dir->output = memoria3;
    }
    else if (no->dir->output == 1.0)
    {
        memoria3 = no->esq->output;
    }
    else
    {
        if (DEBUGGING)
        {
            printaErro("Entrada do MV12 nao foi 0 nem 1");
        }
        else
        {
            printaFalha();
        }
    }

    return no->dir->output;
}

float cte0()
{
    return 0.0;
}

float cte1()
{
    return 1.0;
}


float ifgt(No *no)
{
    if (no->esq->output > no->dir->output)
    {
        return 1.0;
    }
    else
    {
        return 0.0;
    }
}

float iflt(No *no)
{
    if (no->esq->output < no->dir->output)
    {
        return 1.0;
    }
    else
    {
        return 0.0;
    }
}

float ifet(No *no)
{
    if (no->esq->output == no->dir->output)
    {
        return 1.0;
    }
    else
    {
        return 0.0;
    }
}

float ipgt(No *no)
{
    if (no->esq->output > no->dir->output)
    {
        return no->esq->output;
    }
    else
    {
        return no->dir->output;
    }
}

float iplt(No *no)
{
    if (no->esq->output < no->dir->output)
    {
        return no->esq->output;
    }
    else
    {
        return no->dir->output;
    }
}