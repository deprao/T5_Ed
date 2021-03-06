#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listaEndereco.h"
#include "listaQuadras.h"
#include "lista.h"

typedef struct endereco{
    char cpf[25];
    char cep[25];
    char complemento[25];
    char face;
    int num;
    double x;
    double y;
}Endereco;

listaEndereco criaEndereco(char *cpf, char *complemento, char face, int num, listaQuadra quadra){
    Endereco *e =(Endereco*)malloc(sizeof(Endereco));
    float xe = getXQuadra(quadra);
    float ye = getYQuadra(quadra);
    float we = getWQuadra(quadra);
    float he = getHQuadra(quadra);
    if(face == 'N'){
        e->x = xe + num; 
        e->y = ye + he;
    }
    else if(face == 'S'){
        e->x = xe + num;
        e->y = ye;
    }
    else if(face == 'L'){
        e->x = xe;
        e->y = ye + num;
    }
    else if(face == 'O'){
        e->x = we;
        e->y = ye + num;
    }
    strcpy(e->cpf, cpf);
    strcpy(e->cep, getCepQuadra(quadra));     
    strcpy(e->complemento, complemento);
    e->face = face;
    e->num = num;

    return e;
}

char *getCpfEndereco(listaEndereco lista){
    Endereco *e = (Endereco*)lista;
    return e->cpf;
}

char *getCepEndereco(listaEndereco lista){
    Endereco *e = (Endereco*)lista;
    return e->cep;
}

char *getComplementoEndereco(listaEndereco lista){
    Endereco *e = (Endereco*)lista;
    return e->complemento;
}

char getFaceEndereco(listaEndereco lista){
    Endereco *e = (Endereco*)lista;
    return e->face;
}

int getNumEndereco(listaEndereco lista){
    Endereco *e = (Endereco*)lista;
    return e->num;
}

double getXEndereco(listaEndereco lista){
    Endereco *e = (Endereco*)lista;
    return e->x;
}

double getYEndereco(listaEndereco lista){
    Endereco *e = (Endereco*)lista;
    return e->y;
}

void setCpfEndereco(listaEndereco lista, char *cpf){
    Endereco *e = (Endereco*)lista;
    strcpy (e->cpf, cpf);
}

void setCepEndereco(listaEndereco lista, char *cep){
    Endereco *e = (Endereco*)lista;
    strcpy (e->cep, cep);
}

void setComplementoEndereco(listaEndereco lista, char *complemento){
    Endereco *e = (Endereco*)lista;
    strcpy (e->complemento, complemento);
}

void setFaceEndereco(listaEndereco lista, char face){
    Endereco *e = (Endereco*)lista;
    e->face = face;
}

void setNumEndereco(listaEndereco lista, int num){
    Endereco *e = (Endereco*)lista;
    e->num = num;
}