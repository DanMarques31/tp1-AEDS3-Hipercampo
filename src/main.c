#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "file.h"
#include "hipercampo.h"

int main(int argc, char *argv[]) {
    
    struct timeval start, end;
    struct rusage usage;

    gettimeofday(&start, NULL);

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

    printf("\nA quantidade maxima de pontos eh: %d\n", answer);
    
    free(pontos);
    
    fecha_arquivo();

    gettimeofday(&end, NULL);
    getrusage(RUSAGE_SELF, &usage);

    printf("Tempo de execução: %ld microsegundos\n", (((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec)));
    printf("Tempo de usuário: %ld microsegundos\n", usage.ru_utime.tv_usec);
    printf("Tempo de sistema: %ld microsegundos\n", usage.ru_stime.tv_usec);

}