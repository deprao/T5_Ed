#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtable.h"
#include "lista.h"
#include "quadtree.h"
#include "listaPessoas.h"
#include "listaEndereco.h"
#include "listaEstabelecimentos.h"

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

Node buscaEndereco(hstable hashEndereco, char *cep, char face, int num){
    NodeHashtable *hashArray = (NodeHashtable*)hashEndereco;
    tipo elemento;

    if(hashArray == NULL){
        return;
    }

    //printf("\n--%s %c %d--", cep, face, num);
    int posHash = getKey(cep);
    void *no = hashArray[posHash].nodeHstable;

     if (getFirst(no) != NULL){
        for(Node i = getFirst(no); i != NULL; i = getNext(i)){
            elemento = getElemento(i);
            //printf("\n%s %c %d", getCepEndereco(elemento), getFaceEndereco(elemento), getNumEndereco(elemento));
            if (strcmp(getCepEndereco(elemento), cep) == 0){
                if(getFaceEndereco(elemento) == face){
                    if(getNumEndereco(elemento) == num){
                        //printf("%s %c %d", getCepEndereco(elemento), getFaceEndereco(elemento), getNumEndereco(elemento));
                        return i;
                    }
                }
            }
        }
    }
    return NULL;
}

Node buscaEstabelecimento(hstable hashEstabelecimento, char *cep, char face, int num){
    NodeHashtable *hashArray = (NodeHashtable*)hashEstabelecimento;
    tipo elemento;

    if(hashArray == NULL){
        return;
    }

    int posHash = getKey(cep);
    void *no = hashArray[posHash].nodeHstable;

     if (getFirst(no) != NULL){
        for(Node i = getFirst(no); i != NULL; i = getNext(i)){
            elemento = getElemento(i);
            if (strcmp(getCepEstabelecimento(elemento), cep) == 0){
                if(getFaceEstabelecimento(elemento) == face){
                    if(getNumEstabelecimento(elemento) == num){
                        return i;
                    }
                }
            }
        }
    }
    return NULL;
}

Node buscaEnderecoCpf(hstable hashEndereco, char *cpf){
    NodeHashtable *hashArray = (NodeHashtable*)hashEndereco;
    tipo elemento;

    if(hashArray == NULL){
        return;
    }

    //printf("\n--%s---", cpf);
    int posHash = getKey(cpf);
    void *no = hashArray[posHash].nodeHstable;

     if (getFirst(no) != NULL){
        for(Node i = getFirst(no); i != NULL; i = getNext(i)){
            elemento = getElemento(i);
            if (strcmp(getCpfEndereco(elemento), cpf) == 0){
                //printf("%s- Achou", getCpfEndereco(elemento));
                return i;
            }
        }
    }
    return NULL;
}