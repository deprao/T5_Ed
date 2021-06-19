#ifndef GRAPHS_H_
#define GRAPHS_H_

typedef void *listaGrafo;

typedef void *listaAresta;

typedef void *listaVertice;

listaGrafo criaGrafo(int tam);

listaVertice criaVertice(char *id, double x, double y);

listaAresta criaAresta(char *v1, char *v2, char *lesq, char *ldir, char *nome, double cmp, double vm);

int getGrafoNumVertices(listaGrafo g);

int getGrafoNumAtualVertices(listaGrafo g);

int getGrafoNumArestas(listaGrafo g);

int getVerticeIndice(listaGrafo g, listaVertice v);

char *getVerticeId(listaVertice lista);

double getVerticeX(listaVertice lista);

double getVerticeY(listaVertice lista);

char *getVertexI(listaAresta lista);

char *getVertexJ(listaAresta lista);

int getIndexI(listaAresta lista);

int getIndexJ(listaAresta lista);

void setArestaIndexI(listaAresta lista, int ind);

void setArestaIndexJ(listaAresta lista, int ind);

char *getLeftSide(listaAresta lista);

char *getRightSide(listaAresta lista);

char *getStreetName(listaAresta lista);

double getStreetLength(listaAresta lista);

double getSpeed(listaAresta lista);

void insereVertice(listaGrafo g, listaVertice v);

int buscarVertice(listaGrafo g, char *id);

void insereAresta(listaGrafo g, listaAresta a);

void printG(listaGrafo g);


#endif