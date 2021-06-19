#ifndef LISTAESTABELECIMENTOS_H_
#define LISTAESTABELECIMENTOS_H_

#include "listaQuadras.h"

typedef void *listaEstabelecimento;

typedef void *listaDescricaoEstabelecimento;

listaEstabelecimento criaEstabelecimento(char *cnpj, char *cpf, char *codt, char *cep, char face, int num, char *nome, listaQuadra quadra);

listaDescricaoEstabelecimento criaDescricao(char* descricao, char* codt);

char *getCnpjEstabelecimento(listaEstabelecimento lista);

char *getCpfEstabelecimento(listaEstabelecimento lista);

char *getCodtEstabelecimento(listaEstabelecimento lista);

char *getCepEstabelecimento(listaEstabelecimento lista);

char getFaceEstabelecimento(listaEstabelecimento lista);

int getNumEstabelecimento(listaEstabelecimento lista);

char *getNomeEstabelecimento(listaEstabelecimento lista);

double getXEstabelecimento(listaEstabelecimento lista);

double getYEstabelecimento(listaEstabelecimento lista);

char *getCodtDescEstabelecimento(listaDescricaoEstabelecimento lista);

char *getDescEstabelecimento(listaDescricaoEstabelecimento lista);

void setCnpjEstabelecimento(listaEstabelecimento lista, char *cnpj);

void setCpfEstabelecimento(listaEstabelecimento lista, char *cpf);

void setCodtEstabelecimento(listaEstabelecimento lista, char *codt);

void setCepEstabelecimento(listaEstabelecimento lista, char *cep);

void setFaceEstabelecimento(listaEstabelecimento lista, char face);

void setNumEstabelecimento(listaEstabelecimento lista, char num);

void setNomeEstabelecimento(listaEstabelecimento lista, char *nome);

void setCodtDescEstabelecimento(listaDescricaoEstabelecimento lista, char *codt);

void setDescEstabelecimento(listaDescricaoEstabelecimento lista, char *descricao);

#endif