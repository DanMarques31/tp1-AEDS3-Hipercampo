#ifndef HIPERCAMPO_H
#define HIPERCAMPO_H

struct pontos {

    int x;
    int y;
};

typedef struct pontos Pontos;

void get_dados(int *, int *, int *);
int math_func(Pontos [], int , int, int);

#endif