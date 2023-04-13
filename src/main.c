#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "hipercampo.h"

int main(int argc, char *argv[]) {
    
    abre_arquivo(argv[2]);

    int qtdpontos = 0, anchorA = 0, anchorB = 0;
    get_dados(&qtdpontos, &anchorA, &anchorB);

    Pontos *pontos;
    pontos = malloc(qtdpontos * sizeof(Pontos));
    
    for (int i = 0; i < qtdpontos; i++) {
        pontos[i].x = scan_arquivo();
        pontos[i].y = scan_arquivo();
    }
    
    int answer = math_func(pontos, qtdpontos, anchorA, anchorB);

    printf("\n A quantidade maxima de pontos eh: %d\n", answer);
    
    free(pontos);
    
    fecha_arquivo();
}