#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"
#include "listaQuadras.h"
#include "listaRegioes.h"
#include "listaCidades.h"

void densidadeDemografica(listaStruct listacidade){
    Node listaR = getListaRegioes(listacidade);
    Node listaQ = getListaQuadras(listacidade);

    Node Regiao = getFirst(listaR);

    tipo r, q;
    double rx, ry, rw, rh, rd;
    double qx, qy;

    while(Regiao != NULL){
        r = getElemento(Regiao);
        rx = getXRegiao(r);
        ry = getYRegiao(r);
        rw = getWRegiao(r);
        rh = getHRegiao(r);
        rd = getDRegiao(r);

        Node Quadra = getFirst(listaQ);
        while(Quadra != NULL){
            q = getElemento(Quadra);
            qx = getXQuadra(q);
            qy = getYQuadra(q);
            if((qx >= rx && qx <= (rx + rw)&&(qy >= ry && qy <= ry + rh))){
                if(rd >= 10 && rd < 500){
                    setFilterQuadra(q, 1);
                    setCorFilterQuadra(q, 1);
                }
                else if(rd >= 50 && rd < 1500){
                    setFilterQuadra(q, 1);
                    setCorFilterQuadra(q, 2);
                }
                else if(rd >= 1500 && rd < 3000){
                    setFilterQuadra(q, 1);
                    setCorFilterQuadra(q, 3);
                }
                else if(rd >= 3000 && rd < 4500){
                    setFilterQuadra(q, 1);
                    setCorFilterQuadra(q, 4);
                }
                else if(rd >= 4500 && rd < 6000){
                    setFilterQuadra(q, 1);
                    setCorFilterQuadra(q, 5);
                }
                else if(rd >6000){
                    setFilterQuadra(q, 1);
                    setCorFilterQuadra(q, 6);
                }
            }
            Quadra = getNext(Quadra);
        }
        Regiao = getNext(Regiao);
    }
}