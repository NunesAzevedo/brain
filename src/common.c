/* 
    Funções de uso geral no projeto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

// Gera um print que indica um erro em um determinado padrão pré-definido e
// para a execução do programa gerando um core-dumped
void printaErro(char* mensagem){
    printf("\n\n**************************************************************");
    printf("\n[ERRO]: %s. Encerrando o programa...", mensagem);
    printf("\n\n**************************************************************");
    abort();
}

void printaFalha(){
    printf("\nFAIL");
}
