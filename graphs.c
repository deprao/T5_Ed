#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"listaPontos.h"
#include"lista.h"
#include"graphs.h"

typedef struct g{
    int size;
    int Vnum;
    int Anum;
    void **vertices;
}grafo;

typedef struct{
    listaPonto ponto;
    double d;
    char id[50];
    listaStruct adjlist;
    vertice dnext;
}vertice;

typedef struct{
    char idv1[50], idv2[50];
    char cepleft[50], cepright[50];
    char rua[70];
    int posv1, posv2;
    double length;
    double spe;
}aresta;

listaGrafo criaGrafo(int tam){
    grafo *G = (grafo*)malloc(sizeof(grafo));
    G->size = tam;
    G->Anum = 0;
    G->Vnum = 0;
    G->vertices=malloc(sizeof(vertice)*tam);

    for(int i=0;i<tam;i++)
        G->vertices[i]=NULL;

    return G;
}

listaVertice criaVertice(char *id, double x, double y){
    vertice *v = (vertice*)malloc(sizeof(vertice));
    strcpy(v->id,id);

    v->ponto = criaPonto(x,y);
    v->adjlist = criaLista();

    return v;
}

listaAresta criaAresta(char *v1, char *v2, char *lesq, char *ldir, char *nome, double cmp, double vm){
    aresta *A = (aresta*)malloc(sizeof(aresta));
    strcpy(A->idv1,v1);
    strcpy(A->idv2,v2);
    strcpy(A->cepleft,lesq);
    strcpy(A->cepright,ldir);
    strcpy(A->rua,nome);
    A->length = cmp;
    A->spe = vm;
    A->posv1 = -1;
    A->posv2 = -1;

    return A;
}

int getGrafoNumVertices(listaGrafo g){
    grafo *G = (grafo*)g;

    return G->size;
}

int getGrafoNumAtualVertices(listaGrafo g){
    grafo *G = (grafo*)g;

    return G->Vnum;
}

int getGrafoNumArestas(listaGrafo g){
    grafo *G = (grafo*)g;

    return G->Anum;
}

int getVerticeIndice(listaGrafo g, listaVertice v){

    grafo *G = (grafo*)g;
    void **GraphVertexes = G->vertices;

    for(int i=0;i<G->Vnum;i++){
        
        if(GraphVertexes[i] == v)
            return i;

    }

    return -1;
}

char *getVerticeId(listaVertice lista){
    vertice *v = (vertice*)lista;

    return v->id;
}

double getVerticeX(listaVertice lista){
    vertice *v = (vertice*)lista;

    return getXPonto(v->ponto);
}

double getVerticeY(listaVertice lista){
    vertice *v = (vertice*)lista;

    return getYPonto(v->ponto);
}

char *getVertexI(listaAresta lista){
    aresta *a = (aresta*)lista;

    return a->idv1;
}

char *getVertexJ(listaAresta lista){
    aresta *a = (aresta*)lista;

    return a->idv2;
}

int getIndexI(listaAresta lista){
    aresta *a = (aresta*)lista;

    return a->posv1;
}

int getIndexJ(listaAresta lista){
    aresta *a = (aresta*)lista;

    return a->posv2;
}

void setArestaIndexI(listaAresta lista, int ind){
    aresta *a = (aresta*)lista;

    a->posv1 = ind;
}

void setArestaIndexJ(listaAresta lista, int ind){
    aresta *a = (aresta*)lista;

    a->posv2 = ind;
}

char *getLeftSide(listaAresta lista){
    aresta *a = (aresta*)lista;

    return a->cepleft;
}

char *getRightSide(listaAresta lista){
    aresta *a = (aresta*)lista;

    return a->cepright;
}

char *getStreetName(listaAresta lista){
    aresta *a = (aresta*)lista;

    return a->rua;
}

double getStreetLength(listaAresta lista){
    aresta *a = (aresta*)lista;

    return a->length;
}

double getSpeed(listaAresta lista){
    aresta *a = (aresta*)lista;

    return a->spe;
}

double getDuration(listaAresta lista){
    aresta *a = (aresta*)lista;

    return a->length/a->spe;
}

void insereVertice(listaGrafo g, listaVertice v){
    grafo *G = (grafo*)g;

    vertice **vertexlist = (vertice**)G->vertices;
    int k = G->Vnum;

    if(k<G->size){
        vertexlist[k] = v;
        G->Vnum++;
    }
    else printf("O grafo esta em sua capacidade maxima!\n");
}

int buscarVertice(listaGrafo g, char *id){
    grafo *G = (grafo*)g;

    for(int i=0;i<G->Vnum;i++){
        if(strcmp(id,getVerticeId(G->vertices[i]))==0){
            return i;
            break;
        }
    }
    return -1;
}

void insereAresta(listaGrafo g, listaAresta a){
    grafo *G = (grafo*)g;

    vertice **vertexlist = (vertice**)G->vertices;
    int index1, index2;

    index1 = buscarVertice(G, getVertexI(a));

    if(index1 != -1){
        setArestaIndexI(a, index1);
        insertElemento(vertexlist[index1]->adjlist, a);
    }else printf("vertice de inicio da aresta nao encontrado\n");

    index2 = buscarVertice(G, getVertexJ(a));

    if(index2 != -1){
        setArestaIndexJ(a, index2);
    }else printf("vertice de final da aresta nao encontrado\n");

    G->Anum++;
}

void printG(listaGrafo g){
    grafo *G = (grafo*)g;
    vertice **vertexlist = (vertice**)G->vertices;

    for(int i=0;i<G->size;i++){
        if(vertexlist[i] != NULL){
            printf("%s\n", getVerticeId(vertexlist[i]));

            Node aux;
            aux = getFirst(vertexlist[i]->adjlist);

            while(aux != NULL){
                printf("%s\n", getStreetName(getElemento(aux)));
                    
                aux = getNext(aux);
            }

        }
    }

}

void setDijkstra(listaGrafo g, listaVertice v){
    grafo *G = (grafo*)g;
    vertice *V = (vertice*)v;
    vertice **list = (vertice**)G->vertices;

    for(int i=0;i<G->size;i++){
        list[i]->d = 99999;
        list[i]->dnext = NULL;
    }
    V->d=0;
    G->vertices = (void**)list;
}

/*void *adjacente(listaGrafo g, int i, int j){
    grafo *G=g;
    aresta *a;

    vertice *v=G->vertices[i];

    void *list = getFirst(v->adjlist);

    

    
}
double costType(listaVertice u, vertice *v, int type){
    aresta *a;
}*/