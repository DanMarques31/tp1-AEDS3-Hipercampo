#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "file.h"
#include "hipercampo.h"

int main(int argc, char *argv[]) {
    
    //Cria as structs para o uso das funções 'gettimeofday' e 'getrusage' respectivamente.

    struct timeval start, end;
    struct rusage usage;

    //Inicio da função 'gettimeofday'.

    gettimeofday(&start, NULL);

    //Chamada da função abre_arquivo, simplesmente abre o arquivo e verifica se está NULL (vazio).

    abre_arquivo(argv[2]);

    //Inicialização das variáveis e chamada da função get_dados,
    //a qual obtém os valores das âncoras e da qtd de pontos.

    int qtdpontos = 0, anchorA = 0, anchorB = 0;
    get_dados(&qtdpontos, &anchorA, &anchorB);

    //Aloca memória para o array de pontos e em seguida obtém os valores de x,y de cada ponto.

    Pontos *pontos;
    pontos = malloc(qtdpontos * sizeof(Pontos));

    for (int i = 0; i < qtdpontos; i++) {
        pontos[i].x = scan_arquivo();
        pontos[i].y = scan_arquivo();
    }
    
    //Cria o inteiro 'answer' para obter o retorno da função math_func,
    //a qual retorna o valor da quantidade máxima de pontos que se intercectam apenas nas âncoras.

    int answer = math_func(pontos, qtdpontos, anchorA, anchorB);

    printf("\nA quantidade maxima de pontos eh: %d\n", answer);
    
    //Liberação da memória alocada para os pontos (x,y).

    free(pontos);
    
    //Fechamento do arquivo.

    fecha_arquivo();

    //Fim da função 'gettimeofday' e uso da função 'getrusage'.

    gettimeofday(&end, NULL);
    getrusage(RUSAGE_SELF, &usage);

    //Impressão dos tempos de execução.

    printf("Tempo de execução: %ld microsegundos\n", (((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec)));
    printf("Tempo de usuário: %ld microsegundos\n", usage.ru_utime.tv_usec);
    printf("Tempo de sistema: %ld microsegundos\n", usage.ru_stime.tv_usec);

}