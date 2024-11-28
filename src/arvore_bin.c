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

ArvoreBin *criaArvoreBin()
{
    ArvoreBin *raiz = (ArvoreBin *)malloc(sizeof(ArvoreBin));
    if (raiz == NULL)
    {
        if (DEBUGGING)
        {
            printaErro("Erro ao alocar arvore binaria");
        }
        else
        {
            printaFalha();
        }
    }
    return raiz;
}

void liberaNo(No *no)
{
    if (no == NULL)
    {
        return;
    }
    liberaNo(no->esq);
    liberaNo(no->dir);
    free(no);
    no = NULL;
}

void liberaArvBin(ArvoreBin *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    liberaNo(*raiz);
    free(raiz);
}

// Insere um novo nó na árvore binária e o ordena conforme o seu ID.
// Para return:
//  0: ERRO
//  1: Tudo certo
int insereArvoreBin(ArvoreBin *raiz, int id, char *tipo_do_nodo)
{
    if (DEBUGGING)
    {
        printf("\n[DEBUG]: Comecando insercao na arvore binaria");
        printf("\n[DEBUG]: id: %d", id);
        printf("\n[DEBUG]: tipo_do_nodo: %s", tipo_do_nodo);
    }

    if (raiz == NULL) // Verifica se a árvore existe
    {
        if (DEBUGGING)
        {
            printaErro("raiz eh um ponteiro NULL.");
        }
        else
        {
            printaFalha();
        }
    }

    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL)
    {
        if (DEBUGGING)
        {
            printaErro("Erro ao alocar um novo No.");
        }
        else
        {
            printaFalha();
        }
    }

    novo_no->ID = id;
    if (DEBUGGING)
        printf("\n[DEBUG]: novo_no->id: %d", novo_no->ID);

    strcpy(novo_no->Tipo_do_Nodo, tipo_do_nodo);
    if (DEBUGGING)
        printf("\n[DEBUG]: novo_no->Tipo_do_Nodo: %s", novo_no->Tipo_do_Nodo);

    novo_no->esq = NULL;
    novo_no->dir = NULL;

    if (*raiz == NULL)
    {
        // Se a árvore não tiver raíz, o novo_no No passa a ser a raíz
        *raiz = novo_no;
    }
    else // Caso contrário, damos prosseguimento a árvore
    {
        No *atual = *raiz;
        No *ant = NULL;

        // A seguir, buscamos percorrer a árvore de forma que a inserção
        // do novo nó siga a ordenação pelas ID's
        while (atual != NULL)
        {
            // "ant" guarda a posição anterior a "atual", antes dela percorrer
            // a arvore em busca de uma posição livre
            ant = atual;
            if (id == atual->ID)
            {
                if (DEBUGGING)
                {
                    printaErro("ID ja existente na arvore binaria.");
                }
                else
                {
                    printaFalha();
                }
            }
            if (id > atual->ID)
            {
                atual = atual->dir;
            }
            else
            {
                atual = atual->esq;
            }
        }
        // Após achar uma posição livre, inserimos o novo nó
        if (id > ant->ID)
        {
            ant->dir = novo_no;
        }
        else
        {
            ant->esq = novo_no;
        }
    }
    return 1;
}

// Remove um determinado nó da árvore binária
No *removeNoAtual(No *atual)
{
    No *no1, *no2;
    if (atual->esq == NULL)
    {
        no2 = atual->dir;
        free(atual);
        return no2;
    }

    no1 = atual;
    no2 = atual->esq;
    while (no2->dir != NULL)
    {
        no1 = no2;
        no2 = no2->dir;
    }

    if (no1 != atual)
    {
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }

    no2->dir = atual->dir;
    free(atual);
    return no2;
}

// Permite alterar o valor de um nodo da árvore
// id: Valor do ID do nodo da árvore que desejamos alterar o valor
// valor: valor do output do nodo da arvore que vamos alterar
float alteraValorNoArvBin(ArvoreBin *raiz, int id, float valor)
{
    if (DEBUGGING)
    {
        printf("\n[DEBUG] Alterando valor de um nodo da arvore binaria");
        printf("\n[DEBUG] id: %d", id);
        printf("\n[DEBUG] valor: %f", valor);
    }

    if (raiz == NULL)
    {
        if (DEBUGGING)
        {
            printaErro("Ponteiro da arvore == NULL");
        }
        else
        {
            printaFalha();
            return;
        }

        // Percorre a árvore em busca do ID fornecido
        No *atual = raiz;
        No *ant = NULL;

        if (DEBUGGING){
            printf("\n[DEBUG] Buscando pelo nodo da arvore com mesma ID");
            printf("\n[DEBUG] [Antes do Loop] atual->ID\n", atual->ID);
        }
        while (atual->ID != id)
        {
            if (id < atual->ID)
            {
                if (DEBUGGING){
                    printf("\n[DEBUG] [if( id < atual->ID)]");
                    printf("\n[DEBUG] id: ", id);
                    printf("\n[DEBUG] atual->ID: ", atual->ID);
                }
                atual = atual->esq;
            }
            if (id > atual->ID)
            {
                if (DEBUGGING){
                    printf("\n[DEBUG] [if( id > atual->ID)]");
                    printf("\n[DEBUG] id: ", id);
                    printf("\n[DEBUG] atual->ID: ", atual->ID);
                }
                atual = atual->dir;
            }
        }
        atual->output == valor;
        if (DEBUGGING){
            printf("\n[DEBUG] Término do loop");
            printf("\n[DEBUG] valor: ", valor);
            printf("\n[DEBUG] atual->output: ", atual->output);
        }
    }
}