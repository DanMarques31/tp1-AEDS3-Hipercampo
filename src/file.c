#include <stdio.h>
#include "file.h"

FILE *entrada;

 void abre_arquivo() {
    
      entrada = fopen("entrada.txt", "r");

      if (entrada == NULL) {
          printf("Falha na abertura do arquivo.\n");
      } 
  }

 void fecha_arquivo() {

     fclose(entrada);
 }

 int scan_arquivo() {

     int x;
     fscanf(entrada,"%d", &x);
     return x;
 }