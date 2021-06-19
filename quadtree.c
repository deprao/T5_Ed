#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "quadtree.h"
#include "listaCidadesQT.h"
#include "listaQuadras.h"
#include "listaObjUrbanos.h"

typedef struct ponto{
    double x;
    double y;
}Ponto;

typedef struct node{
    QuadTreeElemento elemento;
    struct ponto p;
    struct node *sudeste; /*se*/
    struct node *sudoeste; /*so*/
    struct node *nordeste; /*ne*/
    struct node *noroeste; /*no*/
    struct node *ant; 
}NoStruct;

typedef struct arvore{
    NoStruct *raiz;
    char *key;
}QuadTreeStruct;

QuadTree criaQuadTree(char *key){
    QuadTreeStruct *qt = (QuadTreeStruct*)malloc(sizeof(QuadTreeStruct));
    qt->raiz = NULL;
    qt->key = key;
    return qt;
}

QuadTreeNo criaNoQT(){
    NoStruct* node = (NoStruct*)malloc(sizeof(NoStruct));
    node->sudeste = NULL;
    node->sudoeste = NULL;
    node->nordeste = NULL;
    node->noroeste = NULL;

    return node;
}

QuadTree insereElementoQT(QuadTree qt, QuadTreeElemento elemento, double px, double py){
    QuadTreeStruct *arvoreQt = (QuadTreeStruct*)qt; 
    NoStruct* pai = NULL;
    char *quadrante;

        if(arvoreQt->raiz == NULL){
            NoStruct* node = criaNoQT();
            node->elemento = elemento;
            arvoreQt->raiz = node;
            node->p.x = px;
            node->p.y = py;
            node->ant = NULL;
        }
        else{
            NoStruct* qtAux = arvoreQt->raiz;
            while (qtAux != NULL && (comparaPonto(px, py, qtAux->p.x, qtAux->p.y) == 0)){
                pai = qtAux;
                quadrante = getQuadrante(px, py, qtAux->p.x, qtAux->p.y);
            	qtAux = getFilho(qtAux, quadrante);
            }
            
            if(qtAux == NULL){
                NoStruct* node = criaNoQT();
                node->p.x = px;
                node->p.y = py;
                node->ant = qtAux;
                node->elemento = elemento;
                setFilho(pai, node, quadrante);
                
            }

        }
        
    return arvoreQt;
}     

void removeNoQuadTree(QuadTree qt, QuadTreeNo no){
    QuadTreeStruct* Qt = (QuadTreeStruct*)qt;
    NoStruct* node = (NoStruct*)no;
    NoStruct* aux;
    NoStruct* pai;
    tipo elemento;
    char *quadrante; 

    aux = getNoQt(getRaizQuadTree(qt), getXQuadTree(no), getYQuadTree(no));

    if(aux->nordeste == NULL && aux->noroeste == NULL && aux->sudeste == NULL && aux->sudoeste == NULL){
        pai = node->ant; 
        quadrante = getQuadrante(node->p.x, node->p.y, pai->p.x, pai->p.y);
        if(strcmp(quadrante, "SE") == 0){
            pai->sudeste = NULL;
        }
        else if(strcmp(quadrante, "SO") == 0){
            pai->sudoeste = NULL;
        }
        else if(strcmp(quadrante, "NE") == 0){
            pai->nordeste = NULL;
        }
        else if(strcmp(quadrante, "NO") == 0){
            pai->noroeste = NULL;
        }
        free(node->elemento);
        free(node);
    }
    else{

    }
}

void liberaNoQuadTree(QuadTreeNo no){
    NoStruct* node = (NoStruct*)no;

    if(node == NULL){
        return;
    }
        if(node->nordeste != NULL){
            liberaNoQuadTree(node->nordeste);
        }
        else if(node->noroeste != NULL){
            liberaNoQuadTree(node->noroeste);
        }
        else if(node->sudeste != NULL){
            liberaNoQuadTree(node->sudeste);
        }
        else if(node->sudoeste != NULL){
            liberaNoQuadTree(node->sudoeste);
        }
    free(node->elemento);
    free(node);
}

void liberaQuadTree(QuadTree qt){
    QuadTreeStruct *arvoreQt = (QuadTreeStruct*)qt; 
    if(arvoreQt->raiz != NULL){
        liberaNoQuadTree(arvoreQt->raiz);
    }
}

char *getQuadrante(double pAtualX, double pAtualY, double pRaizX, double pRaizY){

    if(pAtualX < pRaizX){
        if(pAtualY < pRaizY){
            return "SO";
        }else{
            return "NO";
        }
    }else {
        if(pAtualY < pRaizY){
            return "SE";
        }else {
            return "NE";
        }
    }

}

int comparaPonto(double pAtualX, double pAtualY, double pRaizX, double pRaizY){
    if(pRaizX == pAtualX  && pRaizY == pAtualY){
        return 1;
    }
    else
        return 0;
}

QuadTreeNo getFilho(QuadTreeNo no, char* quadrante){
    NoStruct* node = (NoStruct*)no;

    if(strcmp("SE", quadrante) == 0){
        return node->sudeste;
    }
    else if(strcmp("SO", quadrante) == 0){
        return node->sudoeste;
    }
    else if(strcmp("NE", quadrante) == 0){
        return node->nordeste;
    }
    else if(strcmp("NO", quadrante) == 0){
        return node->noroeste;
    }
    return NULL;
}

void setFilho(QuadTreeNo pai, QuadTreeNo filho, char *quadrante){
    NoStruct* nodePai = (NoStruct*)pai;
    NoStruct* nodeFilho = (NoStruct*)filho;

    if(strcmp("SE", quadrante) == 0){
         nodePai->sudeste = nodeFilho;
    }
    else if(strcmp("SO", quadrante) == 0){
         nodePai->sudoeste = nodeFilho;
    }
    else if(strcmp("NE", quadrante) == 0){
         nodePai->nordeste = nodeFilho;
    }
    else if(strcmp("NO", quadrante) == 0){
         nodePai->noroeste = nodeFilho;
    }

}

QuadTreeNo getNoQt(QuadTreeNo raiz, double x, double y){
    NoStruct* node = (NoStruct*)raiz;
    NoStruct* filho;
    //printf("\n%lf %lf", node->p.x, node->p.y);
    if(node == NULL){
        return NULL;
    }
    else{ 
        if(node->p.x == x && node->p.y == y){
            return node->elemento;
        }
        else{
            char *quadrante = getQuadrante(x, y, node->p.x, node->p.y);
            filho = getFilho(node, quadrante);
            return getNoQt(filho, x, y);
        }
    }
}

double getXQuadTree(QuadTreeNo no){
    NoStruct* node = (NoStruct*)no;

    return node->p.x;
}

double getYQuadTree(QuadTreeNo no){
    NoStruct* node = (NoStruct*)no;

    return node->p.y;
}

QuadTreeElemento getQuadTreeElemento(QuadTreeNo no){
     NoStruct* node = (NoStruct*)no;

     return node->elemento;
}

QuadTreeNo getRaizQuadTree(QuadTree qt){
    QuadTreeStruct* Qt = (QuadTreeStruct*)qt;
    NoStruct* node = Qt->raiz;
        if(node == NULL){
            return NULL;
        }
    return node;
}

QuadTreeNo comparaIdQt(QuadTree qt, char c, char *id){
    QuadTreeStruct* Qt = (QuadTreeStruct*)qt;

    switch(c){
        case 'q': /*Quadras*/
 
        break;
    }
}

QuadTreeNo getNoQtId_aux(NoStruct* node, char *id, char op, void* retorno){

    if( op == 'q' ){
        //printf("\n%s", getCepQuadra(node->elemento));
        if(strcmp(id, getCepQuadra(node->elemento)) == 0){
            //printf("Achou Quadra");
            retorno = node->elemento;
            return retorno;
        }
    }
    else if (op == 'o'){
        //printf("\n%s", getIdObjetos(node->elemento));
        if(strcmp(id, getIdObjetos(node->elemento)) == 0){
            //printf("Achou Objeto");
            retorno = node->elemento;
            return retorno;
        }
    }

    if(getFilho(node, "SE") != NULL){
        //printf(" entrou se ");
        retorno = getNoQtId_aux(getFilho(node, "SE"), id, op, retorno);
    }
    if(getFilho(node, "SO") != NULL){
        //printf(" entrou so ");
        retorno = getNoQtId_aux(getFilho(node, "SO"), id, op, retorno);
    }
    if(getFilho(node, "NE") != NULL){
        //printf(" entrou ne ");
        retorno = getNoQtId_aux(getFilho(node, "NE"), id, op, retorno);
    }
    if(getFilho(node, "NO") != NULL){
        //printf(" entrou no ");
        retorno = getNoQtId_aux(getFilho(node, "NO"), id, op, retorno);
    }

    return retorno;
}

QuadTreeNo getNoQtId(QuadTreeNo raiz, char *id, char op){

    QuadTreeStruct* node = (QuadTreeStruct*)raiz;

    if(node->raiz == NULL)
        return NULL;

    void* retorno = NULL;

    retorno = getNoQtId_aux(node->raiz, id, op, retorno);

    //printf("\n\n>>achei essa porra aqui %s", getIdObjetos(retorno));

    return retorno;

}