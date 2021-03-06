#ifndef LEARQ_H_
#define LEARQ_H_

#include "listaCidades.h"
#include "lista.h"
#include "quadtree.h"
#include "hashtable.h"

void escolheRegistrador(char *registrador, double x, double y);

/*Abre o arquivo geo, insere os elementos na lista e gera o svg de .geo*/
void openGeo(listaCidade listacidade, QuadTree qt, char *nomeGeo, char *saidaSvg);

/*Abre o arquivo qry, realiza as alterações necessárias na lista e gera o svg de .qry*/
void openQry(listaCidade listacidade, char *entradaQry, char *saidaQry, QuadTree qt);

/*Abre o arquivo ec, realiza as alteracoes necessarias e cria a hash table
de estabelecimentos*/
void openEc(char *arquivoEc, listaStruct listacidade);

/*Abre o arquivo pm, realiza as alteracoes necessarias e cria a hash 
table de pessoas e moradores*/
void openPm(char *arquivoPm, listaStruct listacidade);

#endif