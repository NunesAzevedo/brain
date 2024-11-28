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

// Tipos de Nodo
#define TAM_TIPO_NODO 5 // 4 letras + '\0'
const char AND2[TAM_TIPO_NODO] = "AND2";
const char OR_2[TAM_TIPO_NODO] = "OR-2";
const char XOR_2[TAM_TIPO_NODO] = "XOR2";
const char NOT2[TAM_TIPO_NODO] = "NOT2";
const char INP1[TAM_TIPO_NODO] = "INP1";

#endif // MAIN_H