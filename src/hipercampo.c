#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "hipercampo.h"

void get_dados(int *qtdpontos, int *anchorA, int *anchorB) {
    
    *qtdpontos = scan_arquivo();
    *anchorA = scan_arquivo();
    *anchorB = scan_arquivo();
}

int math_func(Pontos *pontos, int qtdpontos, int anchorA, int anchorB) {
    int pconect = 0;
    
    for (int i = 0; i < qtdpontos; i++) {
        int cont = 0;
        for (int j = 0; j < qtdpontos; j++) {
            if (j != i) {
                int xn = pontos[i].x, yn = pontos[i].y;
                int xsimetrico = 2 * xn - anchorA - anchorB;
                int ysimetrico = 2 * yn;
                int xrotacao = xn + yn - ysimetrico;
                int xreflexao = anchorA + anchorB - xrotacao;

                if ((xn < anchorA && xsimetrico < anchorA && xrotacao < anchorA && xreflexao < anchorA) ||
                    (xn > anchorB && xsimetrico > anchorB && xrotacao > anchorB && xreflexao > anchorB)) {
                    continue;
                }

                if ((xn < anchorA && xsimetrico < anchorA && xrotacao >= anchorA && xreflexao >= anchorA) ||
                    (xn > anchorB && xsimetrico > anchorB && xrotacao <= anchorB && xreflexao <= anchorB)) {
                    continue;
                }

                if ((xn < anchorA && xsimetrico >= anchorA && xrotacao < anchorA && xreflexao >= anchorA) ||
                    (xn > anchorB && xsimetrico <= anchorB && xrotacao > anchorB && xreflexao <= anchorB)) {
                    continue;
                }

                if ((xn < anchorA && xsimetrico >= anchorA && xrotacao >= anchorA && xreflexao >= anchorA) ||
                    (xn > anchorB && xsimetrico <= anchorB && xrotacao <= anchorB && xreflexao <= anchorB)) {
                    continue;
                }

                // Verifica se o ponto j intersecta apenas nas âncoras
                int intersecta_apenas_ancoras = 1;
                for (int k = 0; k < qtdpontos; k++) {
                    if (k != i && k != j) {
                        int xk = pontos[k].x, yk = pontos[k].y;
                        if ((yk > yn && yk > ysimetrico) || (yk < yn && yk < ysimetrico)) {                            
                            if ((xk < xn && xk < xsimetrico) || (xk > xn && xk > xsimetrico)) {
                                intersecta_apenas_ancoras = 0;
                                break;
                            }
                        }
                    }
                }

                if (intersecta_apenas_ancoras) {
                    cont++;
                }
            }
        }

        if (cont > pconect) {
            pconect = cont;
        }
    }

    return pconect;
}