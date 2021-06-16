#ifndef _LISTAENDERECO_H
#define _LISTAENDERECO_H

#include "listaQuadras.h"

typedef void *listaEndereco;

listaEndereco criaEndereco(char *cpf, char *complemento, char face, int num, listaQuadra quadra);

#endif