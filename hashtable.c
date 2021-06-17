#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtable.h"
#include "lista.h"

#define TAMANHO 301

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
    int i = 0;
    NodeHashtable *hash = (NodeHashtable*)malloc(sizeof(NodeHashtable) * TAMANHO);
    for(int i = 0; i < TAMANHO; i++){
        hash[i].key = i + 1;
        hash[i].nodeHstable = criaLista();
    }
    return hash;
}

void insereHashtable(hstable hash, char *elementoKey, Node *elemento){
    NodeHashtable *arrayHash = (NodeHashtable*)hash; /*aqui especifica qual hashtable estou trabalhando com*/
    int posHash = getKey(elementoKey);
    arrayHash[posHash].nodeHstable = insertElemento(arrayHash[posHash].nodeHstable, elemento);
}

int removeHashtable(hstable hash, char *string, int (*op)){
    int posHash = getKey(string);
    NodeHashtable *arrayHash = (NodeHashtable*)hash;
    Node elementoLista = arrayHash[posHash].nodeHstable;

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

void imprimeHashtable(hstable hash, char op){
    NodeHashtable *hashArray = (NodeHashtable*)hash;

    if(hashArray == NULL){
        return;
    }

    for(int i = 0; i < TAMANHO; i++){
        void *no = hashArray[i].nodeHstable;
            if (getFirst(no) != NULL){
                switch(op){
                    case 'a':
                    imprimeLista(no, 'a');
                    break;

                    case 'e':
                    imprimeLista(no, 'e');
                    break;
                }
            }
    }
}
