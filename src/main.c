#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "hipercampo.h"

int main(int argc, char *argv[]) {

    abre_arquivo();

    int qtdpontos = 0, anchorA = 0, anchorB = 0;
    Pontos *pontos;
    Pontos *aux;

    aux = malloc(qtdpontos * sizeof(Pontos));
    monta_hipercampo(aux, &qtdpontos, &anchorA, &anchorB);
    pontos = malloc(qtdpontos * sizeof(Pontos));
    monta_hipercampo(pontos, &qtdpontos, &anchorA, &anchorB);

    int answer = math_func(pontos, qtdpontos, anchorA, anchorB);

    printf("\n A quantidade maxima de pontos eh: %d\n", answer);
   
    free(pontos);
    free(aux);
    
    fecha_arquivo();
}
