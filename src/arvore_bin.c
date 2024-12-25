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
#include "circuitos.h"
#include "main.h"

No *criaNo()
{
    No *novo_no = (No *)malloc(sizeof(No));
    if (novo_no == NULL)
    {
        if (DEBUGGING)
            printaErro("Erro ao alocar um novo No.");
        else
            printaFalha();
    }
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    return novo_no;
}

void liberaNo(No *no)
{
    if (no == NULL)
        return;
    liberaNo(no->esq);
    liberaNo(no->dir);
    free(no);
    no = NULL;
}

ArvoreBin *criaArvoreBin()
{
    ArvoreBin *raiz = (ArvoreBin *)malloc(sizeof(ArvoreBin));
    if (raiz == NULL)
    {
        if (DEBUGGING)
            printaErro("Erro ao alocar a raiz da arvore binaria.");
        else
            printaFalha();
    }
    *raiz = NULL;
    return raiz;
}

void liberaArvBin(ArvoreBin *raiz)
{
    if (raiz == NULL)
        return;
    liberaNo(*raiz);
    free(raiz);
}

// Insere um novo nó na árvore binária e o ordena conforme o seu ID.
// Para return:
//  0: ERRO
//  1: Tudo certo
int insereArvoreBin(ArvoreBin *raiz, int id, const char *tipo_do_nodo)
{
    if (DEBUGGING)
    {
        printaComeco("Começando a inserção na árvore binária");
        printf("\n[DEBUG]: ID: %d, Tipo_do_Nodo: %s", id, tipo_do_nodo);
    }

    // Verifica se a árvore existe
    if (raiz == NULL)
    {
        if (DEBUGGING)
            printaErro("Ponteiro para a árvore binária é NULL.");
        else
            printaFalha();
        return 0; // ERRO
    }

    // Cria o novo nó para ser inserido
    No *novo_no = criaNo();
    if (novo_no == NULL)
    {
        if (DEBUGGING)
            printaErro("Falha ao alocar memória para o novo nó.");
        else
            printaFalha();
        return 0; // ERRO
    }

    // Inicializa os valores do novo nó
    novo_no->ID = id;
    strcpy(novo_no->Tipo_do_Nodo, tipo_do_nodo);
    novo_no->esq = NULL;
    novo_no->dir = NULL;

    // Se a árvore estiver vazia, o novo nó se torna a raiz
    if (*raiz == NULL)
    {
        *raiz = novo_no;
        if (DEBUGGING)
            printaComeco("Novo nó inserido como raiz.");
        return 1; // Sucesso
    }

    // Percorre a árvore para encontrar a posição correta para inserção
    No *atual = *raiz;
    No *ant = NULL; // Guarda o nó anterior
    while (atual != NULL)
    {
        ant = atual;

        if (id == atual->ID)
        {
            if (DEBUGGING)
                printaErro("ID já existente na árvore.");
            else
                printaFalha();

            free(novo_no); // Libera o nó que não será utilizado
            return 0; // ERRO
        }

        if (id > atual->ID)
        {
            if (DEBUGGING)
                printf("\n[DEBUG]: Descendo para a direita (ID atual: %d)", atual->ID);
            atual = atual->dir;
        }
        else
        {
            if (DEBUGGING)
                printf("\n[DEBUG]: Descendo para a esquerda (ID atual: %d)", atual->ID);
            atual = atual->esq;
        }
    }

    // Insere o novo nó na posição encontrada
    if (id > ant->ID)
    {
        ant->dir = novo_no;
        if (DEBUGGING)
            printf("\n[DEBUG]: Novo nó inserido à direita do ID %d", ant->ID);
    }
    else
    {
        ant->esq = novo_no;
        if (DEBUGGING)
            printf("\n[DEBUG]: Novo nó inserido à esquerda do ID %d", ant->ID);
    }

    if (DEBUGGING)
        printaComeco("Fim da inserção na árvore binária");

    return 1; // Sucesso
}

// Remove um determinado nó da árvore binária
No *removeNoAtual(No *atual)
{
    // No *no1, *no2;
    No *no1 = criaNo();
    No *no2 = criaNo();
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
void alteraValorNoArvBin(ArvoreBin *raiz, int id, float valor)
{
    if (DEBUGGING)
    {
        printaComeco("Alterando valor de um nodo da árvore binária");
        printf("\n[DEBUG] ID: %d", id);
        printf("\n[DEBUG] Valor: %.2f", valor);
    }

    // Verifica se a árvore ou a raiz é nula
    if (raiz == NULL || *raiz == NULL)
    {
        if (DEBUGGING)
            printaErro("Árvore ou raiz nula.");
        else
            printaFalha();
        return;
    }

    // Percorre a árvore em busca do ID fornecido
    No *atual = *raiz;

    while (atual != NULL)
    {
        if (id == atual->ID)
        {
            if (strcmp(atual->Tipo_do_Nodo, INP1) == 0)
            {
                atual->output = valor; // Atualiza o valor do nodo folha
                if (DEBUGGING)
                    printf("\n[DEBUG] Valor atualizado para o nodo com ID %d: %.2f", id, valor);
                return;
            }
            else
            {
                if (DEBUGGING)
                    printaErro("Tentativa de alterar valor de nodo que não é folha.");
                else
                    printaFalha();
                return;
            }
        }

        // Navega para a esquerda ou direita com base no ID
        if (id < atual->ID)
            atual = atual->esq;
        else
            atual = atual->dir;
    }

    // Se o ID não foi encontrado
    if (DEBUGGING)
        printaErro("ID não encontrado na árvore.");
    else
        printaFalha();
}

// Se o nodo não for folha, seu output é determinado palos outputs de seus filhos,
// a depender do seu tipo de nodo (AND2, OR2, XOR2, NOT2, INP1).
// Ela verifica o tipo de nodo de cada nodo, e executa a sua função lógica
// tendo como inputs os valores de output de seus filhos
void montaCircuito(ArvoreBin *raiz)
{
    if (DEBUGGING)
        printaComeco("Montando circuito");

    // Verifica se a raiz ou a árvore binária é nula
    if (raiz == NULL || *raiz == NULL)
    {
        if (DEBUGGING)
            printaErro("Arvore ou raiz invalida.");
        else
        {
            printaFalha();
            return;
        }
    }

    No *atual = *raiz;

    // Verifica se o nodo atual é folha (basta verificar se é INP1)
    if (strcmp(atual->Tipo_do_Nodo, INP1) == 0)
    {
        if (DEBUGGING)
            printf("\n[DEBUG]: Nodo folha encontrado: %s. Output: %.2f", atual->Tipo_do_Nodo, atual->output);
        return; // Não é necessário processar folhas
    }

    // Processa recursivamente os filhos, se existirem
    if (atual->esq != NULL)
    {
        if (DEBUGGING)
            printf("\n[DEBUG]: Descendo para o filho esquerdo. Tipo: %s", atual->esq->Tipo_do_Nodo);
        montaCircuito(&(atual->esq));
    }

    if (atual->dir != NULL)
    {
        if (DEBUGGING)
            printf("\n[DEBUG]: Descendo para o filho direito. Tipo: %s", atual->dir->Tipo_do_Nodo);
        montaCircuito(&(atual->dir));
    }

    // Realiza a operação lógica do nodo atual, com base no tipo do nodo
    if (strcmp(atual->Tipo_do_Nodo, AND2) == 0)
    {
        atual->output = and2(atual);
    }
    else if (strcmp(atual->Tipo_do_Nodo, OR_2) == 0)
    {
        atual->output = or2(atual);
    }
    else if (strcmp(atual->Tipo_do_Nodo, XOR2) == 0)
    {
        atual->output = xor2(atual);
    }
    else if (strcmp(atual->Tipo_do_Nodo, NOT2) == 0)
    {
        atual->output = not2(atual);
    }
    else
    {
        if (DEBUGGING)
            printaErro("Tipo de nodo invalido encontrado na arvore.");
        else
            printaFalha();
    }

    if (DEBUGGING)
    {
        printf("\n[DEBUG]: Output do nodo [%s] com ID %d calculado: %.2f",
               atual->Tipo_do_Nodo, atual->ID, atual->output);
    }
}

// Imprime o valor do output da raiz da arvore
float OutputRaiz(ArvoreBin *raiz)
{
    if (DEBUGGING)
        printaComeco("Obtendo o output da raiz da árvore binária");

    // Verifica se a árvore ou a raiz são nulas
    if (raiz == NULL || *raiz == NULL)
    {
        if (DEBUGGING)
            printaErro("Árvore ou raiz inválida.");
        else
            printaFalha();
        return -1.0; // Valor especial indicando erro
    }

    // Obtém o valor do output da raiz
    No *atual = *raiz;

    if (DEBUGGING)
    {
        printf("\n[DEBUG] Output da raiz com ID %d: %.2f", atual->ID, atual->output);
        printaComeco("Fim da obtenção do output da raiz");
    }

    return atual->output;
}
