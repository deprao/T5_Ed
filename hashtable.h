#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include "lista.h"

typedef void *hstable;
typedef void *elementoHstable;

int getKey(char *string);

hstable iniciaHashtable();

void insereHashtable(hstable hash, char *elementoKey, Node *elemento);

int removeHashtable(hstable hash, char *string, int (*op));

listaStruct getListaHashtable(hstable lista);

void liberaHashtable(hstable hash);

void imprimeHashtable(hstable hash, char op);

Node buscaEndereco(hstable hashEndereco, char *cep, char face, int num);

Node buscaEstabelecimento(hstable hashEstabelecimento, char *cep, char face, int num);

Node buscaEnderecoCpf(hstable hashEndereco, char *cpf);

Node buscaPessoaCpf(hstable hashPessoa, char *cpf);

Node buscaEstabelecimentoCnpj(hstable hashEstabelecimento, char *cnpj);

#endif