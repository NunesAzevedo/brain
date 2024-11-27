/*
    *********************************************
    TAD de Árvore binária para aplicação no BRAIN
    *********************************************

    A função da implementação dessa árvore binária será para ser aplicada
    para a funcionalidade do BRAIN, o que implica que o valor dos nós serão
    do tipo float, e terão também um ID associado a cada nó.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "arvore_bin.h"
#include "main.h"

typedef struct
{
    float valor;
    char *ID;
    No *esq;
    No *dir;
} No;

ArvoreBin *criaArvoreBin()
{
    ArvoreBin *raiz = (ArvoreBin *)malloc(sizeof(ArvoreBin));
    if (raiz == NULL)
    {
        printaErro("Erro ao alocar arvore binaria");
    }
    return raiz;
}

void liberaNo(No *no)
{
    if (no == NULL)
    {
        return NULL;
    }
    liberaNo(no->esq);
    liberaNo(no->dir);
    liberaNo(no->ID);
    free(no);
    no = NULL;
}

void liberaRaiz(ArvoreBin *arv)
{
    if (arv == NULL)
    {
        return NULL;
    }
    liberaNo(arv);
    free(arv);
}

// Para return:
//  0: ERRO
//  1: Tudo certo
int insereArvoreBin(ArvoreBin *raiz, float valor, char *ID)
{
    if (DEBUGGING)
        printf("\n[DEBUG]: Comecando insercao na arvore binaria");
    if (DEBUGGING)
        printf("\n[DEBUG]: valor: %f", valor);
    if (DEBUGGING)
        printf("\n[DEBUG]: ID: %s", ID);

    if (raiz == NULL) // Verifica se a árvore existe
    {
        printaErro("raiz eh um ponteiro NULL.");
    }

    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL)
    {
        printaErro("Erro ao alocar um novo No.");
    }

    novo_no->valor = valor;
    if (DEBUGGING)
        printf("\n[DEBUG]: novo_no->valor: %f", novo_no->valor);

    strcpy(novo_no->ID, ID);
    if (DEBUGGING)
        printf("\n[DEBUG]: novo_no->ID: %s", novo_no->ID);

    novo_no->esq = NULL;
    novo_no->dir = NULL;

    if (*raiz == NULL)
    {
        // Se a árvore não tiver raíz, o novo No passa a ser a raíz
        *raiz = novo_no;
    }
    else // Caso contrário, damos prosseguimento a árvore
    {
        No *atual = *raiz;
        No *ant = NULL;

        // Achar algum "nó" da árvore que esteja vazio para poder preencher
        while (atual != NULL)
        {
            ant = atual;

            // Verifica se o nó a ser inserido já existe
            if (valor == atual->valor &&
                strcmp(ID, atual->ID) == 0)
            {
                free(novo_no);
                return 0;
            }

            // Verifica se o ID do nó inserido é um input e coloca
            // ele na posição de folha
            if (strcmp(ID, INP1) == 0)
            {
                // Se o nó da esquerda estiver livre, coloca ele lá,
                // caso contrário, coloca no nó da direita
                if (atual->esq == NULL)
                {
                    atual = atual->esq;
                }
                else
                {
                    if (atual->dir == NULL)
                    {
                        atual = atual->dir;
                    }
                    else
                    {
                        printaErro("Na verificacao dos Nos das arvores, era para alguma estar livre, mas nao foi o que aconteceu.");
                    }
                }
            }
        }
    }
}