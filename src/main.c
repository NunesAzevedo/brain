#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int teste(int numero){
    if (numero > 3)
    {
        perror("\nErro: seu numero eh maior que 3\n");
        abort();
    } 
}

int main()
{
    int numero;
    scanf("%d", &numero);
    teste(numero);
    for (int i = 0; i < 5; i++){
        printf("\ntestezinho\n");
    }
    return 0;
}