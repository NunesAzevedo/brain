/*
    ******************************************
    Header com as variáveis globais do projeto
    ******************************************
 */

#ifndef MAIN_H
#define MAIN_H

// *************************************
// Variável que diz se será mostrado ou
// não os prints de debugging do projeto
// 1: Será mostrado
// 0: Não será mostrado

// #define DEBUGGING 0
#define DEBUGGING 1
// *************************************

// *************
// Tipos de Nodo
// *************
#define TAM_TIPO_NODO 5 // 4 letras + '\0'

// Nodos Lógicos
extern const char AND2[TAM_TIPO_NODO];
extern const char OR_2[TAM_TIPO_NODO];
extern const char XOR_2[TAM_TIPO_NODO];
extern const char NOT2[TAM_TIPO_NODO];
extern const char INP1[TAM_TIPO_NODO];

// Nodos Aritméticos
extern const char ADD2[TAM_TIPO_NODO];
extern const char SUB2[TAM_TIPO_NODO];
extern const char MLT2[TAM_TIPO_NODO];
extern const char DIV2[TAM_TIPO_NODO];
extern const char MOD2[TAM_TIPO_NODO];
extern const char PERC[TAM_TIPO_NODO];
extern const char SQR2[TAM_TIPO_NODO];
extern const char POW2[TAM_TIPO_NODO];
extern const char BIN2[TAM_TIPO_NODO];
extern const char MV12[TAM_TIPO_NODO];
extern const char MV22[TAM_TIPO_NODO];
extern const char MV32[TAM_TIPO_NODO];
extern const char CTE0[TAM_TIPO_NODO];
extern const char CTE1[TAM_TIPO_NODO];

// Nodos Condicionais
extern const char IFGT[TAM_TIPO_NODO];
extern const char IFLT[TAM_TIPO_NODO];
extern const char IFEQ[TAM_TIPO_NODO];
extern const char IPGT[TAM_TIPO_NODO];
extern const char IPLT[TAM_TIPO_NODO];

#endif // MAIN_H