#ifndef ARVORE_BIN_H
#define ARVORE_BIN_H

#include "main.h"

typedef struct _no
{
    int ID;                           // Valor de ID do nodo, que indica sua ordem na árvore
    char Tipo_do_Nodo[TAM_TIPO_NODO]; // Tipo do nodo: indica se é um input ou uma porta lógica, e qual porta seria
    float output;                     // Inputs e outputs podem ser 0.0 ou 1.0
    struct _no *esq;                  // Ponteiro para nodo filho a esquerda (Seu conteúdo é o input1)
    struct _no *dir;                  // Ponteiro para nodo filho a direita (Seu conteúdo é o input2)
} No;

typedef No *ArvoreBin;

No *criaNo();
ArvoreBin *criaArvoreBin();
void liberaNo(No *);
void liberaArvBin(ArvoreBin *);
int insereArvoreBin(ArvoreBin *, int, const char *);
No *removeNoAtual(No *);
void alteraValorNoArvBin(ArvoreBin *, int, float);
void montaCircuito(ArvoreBin *);
float OutputRaiz(ArvoreBin *);

#endif // ARVORE_BIN_H