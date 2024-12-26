#ifndef CIRCUITOS_H
#define CIRCUITOS_H

#include "arvore_bin.h"

// Nodos Lógicos
float and2(No *);
float or2(No *);
float xor2(No *);
float not2(No *);
void input1(No *, float);

// Nodos Aritméticos
float add2(No *);
float sub2(No *);
float mlt2(No *);
float div2(No *);
float mod2(No *);
float perc(No *);
float sqr2(No *);
float pow2(No *);
float bin2(No *);
float mv12(No *);
float mv22(No *);
float mv32(No *);
float cte0();
float cte1();

// Nodos Condicionais
float ifgt(No *);
float iflt(No *);
float ifet(No *);
float ipgt(No *);
float iplt(No *);

#endif // CIRCUITOS_H