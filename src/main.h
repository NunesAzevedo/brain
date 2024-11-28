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
const int tam_tipo_nodo = 5; // 4 letras + '\0'
const char AND2[tam_tipo_nodo] = "AND2";
const char OR_2[tam_tipo_nodo] = "OR-2";
const char XOR_2[tam_tipo_nodo] = "XOR2";
const char NOT2[tam_tipo_nodo] = "NOT2";
const char INP1[tam_tipo_nodo] = "INP1";

#endif // MAIN_H