#ifndef ARVORE_BIN_H
#define ARVORE_BIN_H

typedef struct
{
    int ID;
    char *Tipo_do_Nodo;
    float valor; // Pode ser 0.0 ou 1.0
    No *esq;
    No *dir;
} No;

typedef struct No *ArvoreBin;

ArvoreBin *criaArvoreBin();
void liberaNo(No *);
void liberaRaiz(ArvoreBin *);
int insereArvoreBin(ArvoreBin *, int, char *);
No *removeNoAtual(No *);

#endif // ARVORE_BIN_H