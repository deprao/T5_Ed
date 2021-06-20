#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "criaSvg.h"
#include "lista.h"
#include "listaCidades.h"
#include "listaFormas.h"
#include "listaObjUrbanos.h"
#include "listaQuadras.h"
#include "listaPostos.h"
#include "listaCasosCovid.h"
#include "registradores.h"
#include "listaEndereco.h"
#include "listaPessoas.h"

void desenhaSemaforo(FILE *saida, double x, double y, char *cfill, char *cstrk, char *sw){
    double r;
    r = 4;
    fprintf(saida, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n", 
    x, y, r, cfill, cstrk, sw);
}

void desenhaRadio(FILE *saida, double x, double y, char *cfill, char *cstrk, char *sw){
    double r;
    r = 4;
    fprintf(saida, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n", 
    x, y, r, cfill, cstrk, sw);
}

void desenhaQuadra(FILE *saida, double x, double y, double w, double h, char *cfill, char *cstrk, char *sw){
    fprintf(saida, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n"
    , x, y, w, h, cfill, cstrk, sw );
}

void desenhaQuadraSombra(FILE *saida, double x, double y, double w, double h, char *cfill, char *cstrk, char *sw, char *filterSombra){
    fprintf(saida, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" filter=\"url(%s)\"/>\n"
    , x, y, w, h, cfill, cstrk, sw, filterSombra );
}

void desenhaHidrante(FILE *saida, double x, double y, char *cfill, char *cstrk, char *sw){
    double r;
    r = 4;
    fprintf(saida, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n", 
    x, y, r, cfill, cstrk, sw);
}

void desenhaTexto(FILE *saida, double x, double y, char *corb, char *corp, char *text){
    fprintf(saida, "<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" fill=\"%s\">%s</text>\n",
     x, y, corb, corp, text);
}

void desenhaRetangulo(FILE *saida, double x, double y, double w, double h, double rx, double ry, char *corp, char *corb, char *rw){
     fprintf(saida, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height =\"%lf\" rx=\"%lf\" ry=\"%lf\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%s\"/>\n",
     x, y, w, h, rx, ry, corb, corp, rw);
}

void desenhaRetanguloPontilhado(FILE *saida, double x, double y, double w, double h, double rx, double ry, char *corp, char *corb, char *rw){
     fprintf(saida, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height =\"%lf\" rx=\"%lf\" ry=\"%lf\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%s\" stroke-dasharray=\"4\"/>\n",
     x, y, w, h, rx, ry, corb, corp, rw);
}

void desenhaLinha(FILE *saida, double x1, double x2, double y1, double y2, char *corb){
    fprintf(saida, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n",
      x1, y1, x2, y2, corb);
}

void desenhaLinhaTracejada(FILE *saida, double x1, double x2, double y1, double y2, char *corb){
    fprintf(saida, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-width=\"2.0px\" stroke-dasharray=\"4\"/>\n",
      x1, y1, x2, y2, corb);
}

void desenhaCirculo(FILE *saida, double x, double y, double r, char *corp, char *corb, char *cw){
    fprintf(saida, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\"  fill=\"%s\" stroke-width=\"%s\"/>\n",
    x, y, r, corb, corp, cw);
}

void desenhaPostoSaude(FILE *saida, double x, double y){
    double r;
    r = 8;
    fprintf(saida, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" />\n", 
    x, y, r, "whitesmoke", "black", "1.0px");
    fprintf(saida, "<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" fill=\"%s\">%s</text>\n",
     x-6, y+4, "black", "black", "PS");
}

void desenhaCasoCovid(FILE *saida, double xQ, double yQ, double wQ, double hQ, int n, double xT, double yT){
    char string[10];
    if(n == 0){
     fprintf(saida, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height =\"%lf\" rx=\"%lf\" ry=\"%lf\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%s\"/>\n",
     xQ, yQ, wQ, hQ, 0.0, 0.0, "white", "blue", "1.0px");
    }
    else{
     sprintf(string, "%d", n);
     fprintf(saida, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height =\"%lf\" rx=\"%lf\" ry=\"%lf\" stroke=\"%s\" fill=\"%s\" stroke-width=\"%s\"/>\n",
     xQ, yQ, wQ, hQ, 0.0, 0.0, "black", "orange", "1.0px");
     fprintf(saida, "<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" fill=\"%s\">%s</text>\n",
     xT, yT, "white", "white", string);  
    }
}

void desenhaRegistrador(FILE *saida, double x, double y, char*registrador){
    fprintf(saida, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n",
    x, y, x, 0.0, "black");
    fprintf(saida, "<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" fill=\"%s\">%s</text>\n",
    x, y, "black", "black", registrador);
}

void desenhaDm(FILE *saida, double x, double y, char *cpf, char *nome, char *cep, char *complemento, int num){
    fprintf(saida, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n",
    x, y, x, 0.0, "black");
    fprintf(saida, "<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" fill=\"%s\">%s %s\n%s %s %d</text>\n",
    x, y, "black", "black", cep, nome, cep, complemento, num);
}

void svgen(listaCidade listacidade,char *out){
    FILE *svg;
    Node listQ = getListaQuadras(listacidade);
    Node listO = getListaObjetos(listacidade);
    Node listF = getListaFormas(listacidade);
    Node listP = getListaPostos(listacidade);
    Node listC = getListaCasosCovid(listacidade);

    Node Q = getFirst(listQ);
    Node O = getFirst(listO);
    Node F = getFirst(listF);
    Node P = getFirst(listP);
    Node C = getFirst(listC);

    tipo q, o, f, p, c;

    svg = fopen(out,"w+");

    if(svg == NULL){
        perror("nao foi possivel operar arquivo svg");
        exit(1);
    }

    fprintf(svg,"<svg xmlns=\"http://www.w3.org/2000/svg\">\n");
    fprintf(svg, "<defs>\n");
   
    fprintf(svg, "<filter id=\"shadow1\">\n");
    fprintf(svg, "<feDropShadow dx=\"4\" dy=\"4\" stdDeviation=\"0.5\" flood-color=\"#FFFF00\" />\n");
    fprintf(svg, "</filter>\n");


    fprintf(svg, "<filter id=\"shadow2\">\n");
    fprintf(svg, "<feDropShadow dx=\"4\" dy=\"4\" stdDeviation=\"0.5\" flood-color=\"#FF9955\" />\n");
    fprintf(svg, "</filter>\n");


    fprintf(svg, "<filter id=\"shadow3\">\n");
    fprintf(svg, "<feDropShadow dx=\"4\" dy=\"4\" stdDeviation=\"0.5\" flood-color=\"#FF0000\" />\n");
    fprintf(svg, "</filter>\n");


    fprintf(svg, "<filter id=\"shadow4\">\n");
    fprintf(svg, "<feDropShadow dx=\"4\" dy=\"4\" stdDeviation=\"0.5\" flood-color=\"#FF00CC\"  />\n");
    fprintf(svg, "</filter>\n");


    fprintf(svg, "<filter id=\"shadow5\">\n");
    fprintf(svg, "<feDropShadow dx=\"4\" dy=\"4\" stdDeviation=\"0.5\" flood-color=\"#6600FF\" />\n");
    fprintf(svg, "</filter>\n");


    fprintf(svg, "<filter id=\"shadow6\">\n");
    fprintf(svg, "<feDropShadow dx=\"4\" dy=\"4\" stdDeviation=\"0.5\" flood-color=\"#A02C5A\" />\n");
    fprintf(svg, "</filter>\n");

    fprintf(svg, "</defs>\n");

    while(Q!=NULL){
        q = getElemento(Q);
        int testeQ = getShadowFilterQuadra(q);
            if(testeQ == 0){
                desenhaQuadra(svg,getXQuadra(q),getYQuadra(q),getWQuadra(q),getHQuadra(q),getCorpQuadra(q),getCorbQuadra(q),getSwQuadra(q));
            }
            else if(testeQ == 1){
                int testeCQ = getCorShadowFilterQuadra(q);
                    if(testeCQ == 1){
                        desenhaQuadraSombra(svg,getXQuadra(q),getYQuadra(q),getWQuadra(q),getHQuadra(q),getCorpQuadra(q),getCorbQuadra(q),getSwQuadra(q), "#shadow1");
                    }
                    else if(testeCQ == 2){
                        desenhaQuadraSombra(svg,getXQuadra(q),getYQuadra(q),getWQuadra(q),getHQuadra(q),getCorpQuadra(q),getCorbQuadra(q),getSwQuadra(q), "#shadow2");
                    }
                    else if(testeCQ == 3){
                        desenhaQuadraSombra(svg,getXQuadra(q),getYQuadra(q),getWQuadra(q),getHQuadra(q),getCorpQuadra(q),getCorbQuadra(q),getSwQuadra(q), "#shadow3");
                    }
                    else if(testeCQ == 4){
                        desenhaQuadraSombra(svg,getXQuadra(q),getYQuadra(q),getWQuadra(q),getHQuadra(q),getCorpQuadra(q),getCorbQuadra(q),getSwQuadra(q), "#shadow4");
                    }
                    else if(testeCQ == 5){
                        desenhaQuadraSombra(svg,getXQuadra(q),getYQuadra(q),getWQuadra(q),getHQuadra(q),getCorpQuadra(q),getCorbQuadra(q),getSwQuadra(q), "#shadow5");
                    }
                    else if(testeCQ == 6){
                        desenhaQuadraSombra(svg,getXQuadra(q),getYQuadra(q),getWQuadra(q),getHQuadra(q),getCorpQuadra(q),getCorbQuadra(q),getSwQuadra(q), "#shadow6");
                    }               
            }
        Q = getNext(Q);
    }
    while(O!=NULL){
        o = getElemento(O);
        char c = getCharIdObjetos(o);
            if (c == 'h'){
                desenhaHidrante(svg, getXObjetos(o), getYObjetos(o), getCorpObjetos(o), getCorbObjetos(o), getSwObjetos(o));
            }
            else if (c == 's'){
                desenhaSemaforo(svg, getXObjetos(o), getYObjetos(o), getCorpObjetos(o), getCorbObjetos(o), getSwObjetos(o));
            }
            else if (c == 'b'){
                desenhaRadio(svg, getXObjetos(o), getYObjetos(o), getCorpObjetos(o), getCorbObjetos(o), getSwObjetos(o));
            }
        O = getNext(O);
    }
    while(F!=NULL){
        f = getElemento(F);
        char c = getCharIdFormas(f);
            if(c == 'c'){
                desenhaCirculo(svg, getXFormas(f), getYFormas(f), getRFormas(f), getCorpFormas(f), getCorbFormas(f), getCWFormas(f));
            }
            else if(c == 'r'){
                desenhaRetangulo(svg, getXFormas(f), getYFormas(f), getWFormas(f), getHFormas(f), getRxFormas(f), getRyFormas(f), getCorpFormas(f), getCorbFormas(f), getCWFormas(f));
            }
            else if(c == 'x'){
                desenhaRetanguloPontilhado(svg, getXFormas(f), getYFormas(f), getWFormas(f), getHFormas(f), getRxFormas(f), getRyFormas(f), getCorbFormas(f), getCorpFormas(f), getCWFormas(f));
            }
            else if(c == 'l'){
                desenhaLinha(svg, getXFormas(f), getX2Formas(f), getYFormas(f), getY2Formas(f), getCorpFormas(f));
            }
            else if(c == 'a'){
                desenhaLinhaTracejada(svg, getXFormas(f), getX2Formas(f), getYFormas(f), getY2Formas(f), getCorpFormas(f));
            }
            else if(c == 't'){
                desenhaTexto(svg, getXFormas(f), getYFormas(f), getCorbFormas(f), getCorpFormas(f), getTextFormas(f));
            }
        F = getNext(F);

    }
    while(P!=NULL){
        p = getElemento(P);
        desenhaPostoSaude(svg, getXPosto(p), getYPosto(p));
        P = getNext(P);
    }

    while(C!=NULL){
        c = getElemento(C);
        desenhaCasoCovid(svg, getXCasosCovid(c), getYCasosCovid(c), getWCasosCovid(c), getHCasosCovid(c), getNCasosCovid(c), getxTCasosCovid(c), getyTCasosCovid(c));
        C = getNext(C);
    }

    if(reg1[0] != 0 || reg1[1] != 0){
        desenhaRegistrador(svg, reg1[0], reg1[1], "R1");
    }
    if(reg2[0] != 0 || reg2[1] != 0){
        desenhaRegistrador(svg, reg2[0], reg2[1], "R2");
    }
    if(reg3[0] != 0 || reg3[1] != 0){
        desenhaRegistrador(svg, reg3[0], reg3[1], "R3");
    } 
    if(reg4[0] != 0 || reg4[1] != 0){
        desenhaRegistrador(svg, reg4[0], reg4[1], "R4");
    }
    if(reg5[0] != 0 || reg5[1] != 0){
        desenhaRegistrador(svg, reg5[0], reg5[1], "R5");
    }
    if(reg6[0] != 0 || reg6[1] != 0){
        desenhaRegistrador(svg, reg6[0], reg6[1], "R6");
    }
    if(reg7[0] != 0 || reg7[1] != 0){
        desenhaRegistrador(svg, reg7[0], reg7[1], "R7");
    }
    if(reg8[0] != 0 || reg8[1] != 0){
        desenhaRegistrador(svg, reg8[0], reg8[1], "R8");
    }
    if(reg9[0] != 0 || reg9[1] != 0){
        desenhaRegistrador(svg, reg9[0], reg9[1], "R9");
    }
    if(reg10[0] != 0 || reg10[1] != 0){
        desenhaRegistrador(svg, reg10[0], reg10[1], "R10");
    }

    int i = 0;
    while (vetorHashDm[i] != NULL){
        desenhaDm(svg, getXEndereco(vetorHashDm2[i]), getYEndereco(vetorHashDm2[i]), getCpfPessoa(vetorHashDm[i]), getNomePessoa(vetorHashDm[i]), getCepEndereco(vetorHashDm2[i]), getComplementoEndereco(vetorHashDm2[i]), getNumEndereco(vetorHashDm2[i]));
        i = i + 1;
        //printf(" i = %d", i);
    }

    fprintf(svg,"\n</svg>");
    fclose(svg);
}