#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtable.h"
#include "lista.h"
#include "quadtree.h"

#define TAMANHO 1001

typedef struct nodehash{
    listaStruct nodeHstable;
    int key;
}NodeHashtable;

int getKey(char *string){
    int k = 0;
    int tamanhoString = strlen(string);

    for(int i = 0; i < tamanhoString; i++){
        k = k + string[i];
    }
    return k%TAMANHO;
}

hstable iniciaHashtable(){
    NodeHashtable *hash = (NodeHashtable*)malloc(sizeof(NodeHashtable) * TAMANHO);
    for(int i = 0; i < TAMANHO; i++){
        hash[i].key = i + 1;
        hash[i].nodeHstable = criaLista();
    }
    return hash;
}

void insereHashtable(hstable hash, char *elementoKey, Node *elemento){
    NodeHashtable *hashArray = (NodeHashtable*)hash; /*aqui especifica qual hashtable estou trabalhando com*/
    int posHash = getKey(elementoKey);
    hashArray[posHash].nodeHstable = insertElemento(hashArray[posHash].nodeHstable, elemento);
}

int removeHashtable(hstable hash, char *string, int (*op)){
    int posHash = getKey(string);
    NodeHashtable *hashArray = (NodeHashtable*)hash;
    Node elementoLista = hashArray[posHash].nodeHstable;

    if(elementoLista == NULL){
        return;
    }
}

listaStruct getListaHashtable(hstable lista){
    NodeHashtable *list = (NodeHashtable*)lista;
    return list->nodeHstable;
}

void percorreHashtable(hstable hash, void (*op)()){
    NodeHashtable *hashArray = (NodeHashtable*)hash;

    if(hashArray == NULL){
        return;
    }

    for(int i = 0; i < TAMANHO; i++){
        void *no = hashArray[i].nodeHstable;
            while(no != NULL){
                op(getElemento(no));
                no = getNext(no);
            }
    }
}

void percorreComparaHashtable(hstable hash, char *string, void (*op)(), int (*compara)()){
    NodeHashtable *hashArray = (NodeHashtable*)hash;

    if(hashArray == NULL){
        return;
    }

    int posHash = getKey(string);
    void *no = hashArray[posHash].nodeHstable;

    if (getFirst(no) != NULL){
        for(Node noLista = getFirst(no); noLista == getLast(no); noLista = getNext(noLista)){
            if(compara( getElemento(no), string )){
                op(getElemento(no));
            }
        }
    }
}

void liberaHashtable(hstable hash){
    NodeHashtable *hashArray = (NodeHashtable*)hash;

    for(int i = 0; i < TAMANHO; i++){
        liberaLista(hashArray[i].nodeHstable);
    }
    free(hashArray);
}

void imprimeHashtable(hstable hash, char op){
    NodeHashtable *hashArray = (NodeHashtable*)hash;

    if(hashArray == NULL){
        return;
    }

    for(int i = 0; i < TAMANHO; i++){
        void *no = hashArray[i].nodeHstable;
            if (getFirst(no) != NULL){
                switch(op){
                    case 'a':/*Lista de Descricao*/
                    imprimeLista(no, 'a');
                    break;

                    case 'e':
                    imprimeLista(no, 'e');/*Lista de Estabelecimentos*/
                    break;

                    case 'd':/*Lista de Pessoas*/
                    imprimeLista(no, 'd');
                    break;

                    case 'f':
                    imprimeLista(no, 'f');/*Lista de Enderecos*/
                    break;
                }
            }
    }
}

Node comparaHashtableM(hstable hash, char *key, char op, QuadTree qt){
    NodeHashtable *hashArray = (NodeHashtable*)hash;

    if(hashArray == NULL){
        return;
    }

    int posHash = getKey(key);
    
}