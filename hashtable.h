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

void imprimeHashtable(hstable hash, char op);

#endif