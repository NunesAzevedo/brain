#ifndef ARVORE_BIN_H
#define ARVORE_BIN_H

typedef struct _no
{
    int ID;             // Valor de ID do nodo, que indica sua ordem na árvore
    char *Tipo_do_Nodo; // Tipo do nodo: indica se é um input ou uma porta lógica, e qual porta seria
    float output;       // Inputs e outputs podem ser 0.0 ou 1.0
    struct _no *esq;    // Ponteiro para nodo filho a esquerda (Seu conteúdo é o input1)
    struct _no *dir;    // Ponteiro para nodo filho a direita (Seu conteúdo é o input2)
} No;

typedef No *ArvoreBin;

ArvoreBin *criaArvoreBin();
void liberaNo(No *);
void liberaArvBin(ArvoreBin *);
int insereArvoreBin(ArvoreBin *, int, char *);
No *removeNoAtual(No *);
float alteraValorNoArvBin(ArvoreBin *, int, float);

#endif // ARVORE_BIN_H