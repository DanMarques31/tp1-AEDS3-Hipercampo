#ifndef HIPERCAMPO_H
#define HIPERCAMPO_H

struct pontos {

    int x;
    int y;
};

typedef struct pontos Pontos;

void free_points(Pontos [], int );
void monta_hipercampo(Pontos [], int *, int *, int *);
int get_maxY(Pontos [], int);
int math_func(Pontos [], int , int, int);

#endif