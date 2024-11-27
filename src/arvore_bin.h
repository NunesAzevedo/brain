#ifndef ARVORE_BIN_H
#define ARVORE_BIN_H

typedef struct No;
typedef struct No *ArvoreBin;

ArvoreBin *criaArvoreBin();
void liberaNo(No *);
void liberaRaiz(ArvoreBin *);

#endif // ARVORE_BIN_H