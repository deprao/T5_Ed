#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"
#include "lista.h"
#include "listaQuadras.h"
#include "registradores.h"
#include "quadtree.h"
#include "learq.h"
#include "listaEndereco.h"
#include "listaEstabelecimentos.h"
#include "listaCidadesQT.h"
#include "listaObjUrbanos.h"

void registradorM(char *registrador, char *cpf){
    Node testeCpf = buscaEnderecoCpf(hashtablePessoas[2], cpf);

    if(testeCpf != NULL){
        //printf("entrou!");
        tipo elemento;
        elemento = getElemento(testeCpf);
        escolheRegistrador(registrador,getXEndereco(elemento), getYEndereco(elemento));
    }
}

void registradorE(char *registrador, char *cep, char face, int num){
    Node testeCep = buscaEndereco(hashtablePessoas[1], cep, face, num);
    Node testeCep2 = buscaEstabelecimento(hashtableEstabelecimentos[1], cep, face, num);
    if(testeCep != NULL){
        tipo elemento;
        elemento = getElemento(testeCep);
        escolheRegistrador(registrador,getXEndereco(elemento), getYEndereco(elemento));
        //printf("foi endereco\n");
    }
    if(testeCep2 != NULL){
        tipo elemento;
        elemento = getElemento(testeCep);
        escolheRegistrador(registrador,getXEstabelecimento(elemento), getYEstabelecimento(elemento));
        //printf("foi estabelecimento\n");
    }
}

void registradorG(char *registrador, char *id, QuadTree qt){
    Node testeObjeto = getNoQtId(getQuadtreeObjetos(qt), id, 'o');

    if(testeObjeto != NULL){
        escolheRegistrador(registrador, getXObjetos(testeObjeto), getYObjetos(testeObjeto));
        //printf("entrou");
    }
}



