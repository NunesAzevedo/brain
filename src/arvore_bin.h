#ifndef ARVORE_BIN_H
#define ARVORE_BIN_H

typedef struct _no
{
    int ID;
    char *Tipo_do_Nodo;
    float valor; // Pode ser 0.0 ou 1.0
    struct _no *esq;
    struct _no *dir;
} No;

typedef No *ArvoreBin;

ArvoreBin *criaArvoreBin();
void liberaNo(No *);
void liberaArvBin(ArvoreBin *);
int insereArvoreBin(ArvoreBin *, int, char *);
No *removeNoAtual(No *);

#endif // ARVORE_BIN_H