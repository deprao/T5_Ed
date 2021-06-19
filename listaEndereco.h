#ifndef _LISTAENDERECO_H
#define _LISTAENDERECO_H

#include "listaQuadras.h"

typedef void *listaEndereco;

listaEndereco criaEndereco(char *cpf, char *complemento, char face, int num, listaQuadra quadra);

char *getCpfEndereco(listaEndereco lista);

char *getCepEndereco(listaEndereco lista);

char *getComplementoEndereco(listaEndereco lista);

char getFaceEndereco(listaEndereco lista);

int getNumEndereco(listaEndereco lista);

double getXEndereco(listaEndereco lista);

double getYEndereco(listaEndereco lista);

void setCpfEndereco(listaEndereco lista, char *cpf);

void setCepEndereco(listaEndereco lista, char *cep);

void setComplementoEndereco(listaEndereco lista, char *complemento);

void setFaceEndereco(listaEndereco lista, char face);

void setNumEndereco(listaEndereco lista, int num);

#endif