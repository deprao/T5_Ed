#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "listaCidades.h"
#include "listaFormas.h"
#include "listaObjUrbanos.h"
#include "listaQuadras.h"
#include "listaRegioes.h"
#include "listaPostos.h"
#include "criaSvg.h"
#include "opqry.h"
#include "opqry2.h"
#include "listaPontos.h"
#include "envoltoria.h"
#include "listaCidadesQT.h"
#include "listToQuad.h"
#include "hashtable.h"
#include "listaEstabelecimentos.h"
#include "listaPessoas.h"
#include "listaEndereco.h"
#include "opgeo.h"
#include "registradores.h"
#include "opqry3.h"
#include "opHash.h"

void escolheRegistrador(char *registrador, double x, double y){
    if(strcmp(registrador, "R1") == 0){
        reg1[0] = x;
        reg1[1] = y;
    }
    else if(strcmp(registrador, "R2") == 0){
        reg2[0] = x;
        reg2[1] = y;
    }
    else if(strcmp(registrador, "R3") == 0){
        reg3[0] = x;
        reg3[1] = y;
    }
    else if(strcmp(registrador, "R4") == 0){                             
        reg4[0] = x;
        reg4[1] = y;
    }          
    else if(strcmp(registrador, "R5") == 0){
        reg5[0] = x;
        reg5[1] = y;
    }
    else if(strcmp(registrador, "R6") == 0){
        reg6[0] = x;
        reg6[1] = y;
    }
    else if(strcmp(registrador, "R7") == 0){
        reg7[0] = x;
        reg7[1] = y;
    }
    else if(strcmp(registrador, "R8") == 0){
        reg8[0] = x;
        reg8[1] = y;
    }
    else if(strcmp(registrador, "R9") == 0){
        reg9[0] = x;
        reg9[1] = y;
    }
    else if(strcmp(registrador, "R10") == 0){
        reg10[0] = x;
        reg10[1] = y;
    }
}

void iniciaRegistrador(){
    for(int i = 0; i < 2; i++){
        reg1[i] = 0;
        reg2[i] = 0;
        reg3[i] = 0;
        reg4[i] = 0;
        reg5[i] = 0;
        reg6[i] = 0;
        reg7[i] = 0;
        reg8[i] = 0;
        reg9[i] = 0;
        reg10[i] = 0;
    }
}

void openGeo(listaCidade listacidade, QuadTree qt, char *nomeGeo, char *saidaSvg){
    char comando[4];
    char cfillQ[20];
    char cstrkQ[20];
    char cstrkH[20];
    char cfillH[20];
    char cstrkR[20];
    char cfillR[20];
    char cstrkS[20];
    char cfillS[20];
    char corb[20];
    char corp[20];
    char text[50];
    char id[20];
    char cep[20];
    int id_forma;
    int i = 1000;
    int nq = 1000;
    int nh = 1000;
    int ns = 1000;
    int nr = 1000;
    int cont_i = 0;
    int cont_nq = 0;
    int cont_nh = 0;
    int cont_ns = 0;
    int cont_nr = 0;
    double r;
    double x;
    double y;
    double w;
    double h;
    double densidade;
    char sw[8];
    char cw[8];
    char rw[8];
    int totalP = 0;
    int totalR = 0;

        strcpy(sw, "1.0px");
        strcpy(cw, "1.0px");
        strcpy(rw, "1.0px");
        
    tipo elemento;

    FILE *arq;

    arq = fopen(nomeGeo, "r");

        if(arq == NULL){
            printf("Erro ao abrir o arquivo Geo!!");
            system("pause");
            exit(1);
        }

            while(fscanf(arq, "%s", comando) != EOF){
                if(strcmp(comando, "nx") == 0){
                    fscanf(arq, "%d %d %d %d %d\n", &i, &nq, &nh, &ns, &nr);
                }

                else if((strcmp(comando, "c") == 0) && cont_i < i){
                    fscanf(arq, "%d %lf %lf %lf %s %s", &id_forma, &r, &x, &y, corb, corp);
                    elemento = criaCirculo(id_forma, r, x, y, corb, corp, cw);
                    insertElemento(getListaFormas(listacidade), elemento);
                    cont_i += 1;
                }

                else if((strcmp(comando, "r") == 0) && cont_i < i){
                    fscanf(arq, "%d %lf %lf %lf %lf %s %s", &id_forma, &w, &h, &x, &y, corb, corp); 
                    elemento = criaRetangulo(id_forma, w, h, x, y, 0, 0, corb, corp, rw);
                    insertElemento(getListaFormas(listacidade), elemento);
                    cont_i += 1;
                }

                else if(strcmp(comando, "t") == 0){
                    fscanf(arq, "%d %lf %lf %s %s %s", &id_forma, &x, &y, corb, corp, text); 
                    elemento = criaTexto(id_forma, x, y, corb, corp, text);
                    insertElemento(getListaFormas(listacidade), elemento);
                }

                else if((strcmp(comando, "q") == 0) && cont_nq < nq){
                    fscanf(arq, "%s %lf %lf %lf %lf", cep, &x, &y ,&w ,&h);
                    elemento = criaQuadra(cep, x, y, w, h, cstrkQ, cfillQ, sw);
                    insertElemento(getListaQuadras(listacidade), elemento);
                    cont_nq += 1;
                }

                else if((strcmp(comando, "h") == 0) && cont_nh < nh){
                    fscanf(arq, "%s %lf %lf", id, &x, &y);
                    elemento = criaHidrante(id, x, y, cfillH, cstrkH, sw);
                    insertElemento(getListaObjetos(listacidade), elemento);
                    cont_nh += 1;
                }

                else if((strcmp(comando, "s") == 0) && cont_ns < ns){
                    fscanf(arq, "%s %lf %lf", id, &x, &y);
                    elemento = criaSemaforo(id, x, y, cfillS, cstrkS, sw);
                    insertElemento(getListaObjetos(listacidade), elemento);
                    cont_ns += 1;
                }

                else if((strcmp(comando, "rb") == 0) && cont_nr < nr){
                    fscanf(arq, "%s %lf %lf", id, &x, &y);
                    elemento = criaRadio(id, x, y, cfillR, cstrkR, sw);
                    insertElemento(getListaObjetos(listacidade), elemento);
                    cont_nr += 1;
                }

                else if((strcmp(comando, "ps") == 0)){
                    fscanf(arq, "%lf %lf", &x, &y);
                    totalP = totalP + 1;
                    elemento = criaPosto(totalP, x, y);
                    insertElemento(getListaPostos(listacidade), elemento); 
                }

                else if((strcmp(comando, "dd") == 0)){
                    fscanf(arq, "%lf %lf %lf %lf %lf", &x, &y, &w, &h, &densidade);
                    elemento = criaRegiao(x, y, w, h, densidade);
                    insertElemento(getListaRegioes(listacidade), elemento);
                }

                else if(strcmp(comando, "ch") == 0){
                    fscanf(arq, "%s %s %s", sw, cfillH, cstrkH);
                }

                else if(strcmp(comando, "cr") == 0){
                    fscanf(arq, "%s %s %s", sw, cfillR, cstrkR);
                }

                else if(strcmp(comando, "cs") == 0){
                    fscanf(arq, "%s %s %s", sw, cfillS, cstrkS);
                }

                else if(strcmp(comando, "cq") == 0){
                    fscanf(arq, "%s %s %s", sw, cfillQ, cstrkQ);
                }

                else if(strcmp(comando, "sw") == 0){
                    fscanf(arq, "%s %s", cw, rw);
                }
            }

    if (getFirst(getListaRegioes(listacidade)) != NULL){    
        densidadeDemografica(listacidade);
    }

    svgen(listacidade, saidaSvg);

    transformaListaFormas(getListaFormas(listacidade), getQuadtreeFormas(qt));
    transformaListaQuadras(getListaQuadras(listacidade), getQuadtreeQuadras(qt));
    transformaListaRegioes(getListaRegioes(listacidade), getQuadtreeRegioes(qt));
    transformaListaObjetos(getListaObjetos(listacidade), getQuadtreeObjetos(qt));
    transformaListaPostos(getListaPostos(listacidade), getQuadtreePostos(qt));
    transformaListaCovid(getListaCasosCovid(listacidade), getQuadtreeCasosCovid(qt));
    fclose(arq);

}

void openQry(listaCidade listacidade, char *entradaQry, char *saidaQry, QuadTree qt){
  FILE *entrada, *saidaTxt;

    char comando[12];
    char teste[20];
    char id[20];
    char cStrk[20];
    char cFill[20];
    double r;
    double x;
    double y;
    double w;
    double h;
    int j;
    int k;
    char face;
    int num;
    int n_casos;
    int n_postos;
    char cpf[25];
    char cep[25];
    char cnpj[25];
    char complemento[25];
    char t;
    char sufixo[30];
    char tipoEstabelecimento[20];
    char registrador[4];
    char registrador2[4];
    char cmc[20];
    char cmr[20];
    int maxCovid;
    int totalVetorDm = 0;

    char *saidaSvgQry = malloc(strlen(saidaQry)+5);
    char *saidaTxtQry = malloc(strlen(saidaQry)+5);

    sprintf(saidaTxtQry, "%s.txt", saidaQry);
    sprintf(saidaSvgQry, "%s.svg", saidaQry);

    entrada = fopen(entradaQry, "r");
    saidaTxt = fopen(saidaTxtQry, "w+");

    iniciaRegistrador();
    iniciaVetorHash();

    if(entrada == NULL){
            printf("Erro ao abrir o arquivo entradaQry!!");
            system("pause");
            exit(1);
        }

    if(saidaTxt == NULL){
            printf("Erro ao abrir o arquivo saidaTxtQry!!");
            system("pause");
            exit(1);
    }

        while(fscanf(entrada, "%s", comando)!=EOF){

            if(strcmp(comando, "dq") == 0){
                fscanf(entrada, "%s", teste);
                    if(strcmp(teste, "#") == 0){
                        fscanf(entrada, "%s %lf", id, &r);
                        delQuadras(listacidade, saidaTxt, 1, id, r);
                    }
                    else{
                        strcpy(id, teste);
                        fscanf(entrada, "%lf", &r);
                        delQuadras(listacidade, saidaTxt, 0, id, r);
                    }
            }
            else if(strcmp(comando, "del") == 0){
                fscanf(entrada, "%s", id);
                delUrb(listacidade, saidaTxt, id);
            }

            else if(strcmp(comando, "cbq") == 0){
                fscanf(entrada, "%lf %lf %lf %s", &x, &y, &r, cStrk);
                colorBorder(listacidade, saidaTxt, x, y, r, cStrk);
            }

            else if(strcmp(comando, "crd?") == 0){
                fscanf(entrada, "%s", id);
                coord(listacidade, saidaTxt, id);
            }

            else if(strcmp(comando, "car") == 0){
                fscanf(entrada, "%lf %lf %lf %lf", &x, &y, &w, &h); 
                rectArea(listacidade, saidaTxt, x, y, w, h);
            }

            else if(strcmp(comando, "o?") == 0){
                fscanf(entrada, "%d %d", &j, &k);
                sobreposicao(j, k, listacidade, saidaTxt);
            }

            else if(strcmp(comando, "i?") == 0){
                fscanf(entrada, "%d %lf %lf", &j, &x, &y);
                pontoInterno(j, x, y, listacidade, saidaTxt);
            }

            else if(strcmp(comando, "pnt") == 0){
                fscanf(entrada, "%d %s %s", &j, cStrk, cFill);
                pnt(j, cStrk, cFill, listacidade, saidaTxt);
            }

            else if(strcmp(comando, "pnt*") == 0){
                fscanf(entrada, "%d %d %s %s", &j, &k, cStrk, cFill);
                if  (j < k){
                    for(int i = j; i < k; i++){
                        pnt(i, cStrk, cFill, listacidade, saidaTxt);
                    }
                }
                else{
                    for(int i = k; i < j; i++){
                        pnt(i, cStrk, cFill, listacidade, saidaTxt);
                    }
                }
            }

            else if(strcmp(comando, "delf") == 0){
                fscanf(entrada, "%d", &j);
                delf(j, listacidade, saidaTxt);
            }

            else if(strcmp(comando, "delf*") == 0){
                fscanf(entrada, "%d %d", &j, &k);
                if  (j < k){
                    for(int i = j; i < k; i++){
                      delf(i, listacidade, saidaTxt);
                    }
                }
                else{
                    for(int i = k; i < j; i++){
                      delf(i, listacidade, saidaTxt);
                    }
                }
            }

            else if(strcmp(comando, "cv") == 0){
                fscanf(entrada, "%d %s %c %d", &n_casos, id, &face, &num);
                casosCovid(listacidade, n_casos, id, face, num, saidaTxt);
            }

            else if(strcmp(comando, "soc") == 0){
                fscanf(entrada, "%d %s %c %d", &n_postos, id, &face, &num);
                socorro(listacidade, n_postos, id, face, num, saidaTxt);
            }

            else if(strcmp(comando, "ci") == 0){
                fscanf(entrada, "%lf %lf %lf", &x, &y, &r);
            }

            else if(strcmp(comando, "m?") == 0){
                fscanf(entrada, "%s", cep);
            }

            else if(strcmp(comando, "dm?") == 0){
                fscanf(entrada, "%s", cpf);
                imprimeMorador(cpf, saidaTxt, totalVetorDm);
            }

            else if(strcmp(comando, "de?") == 0){
                fscanf(entrada, "%s", cnpj);
            }

            else if(strcmp(comando, "mud") == 0){
                fscanf(entrada, "%s %s %c %d %s", cpf, cep, &face, &num, complemento);
            }

            else if(strcmp(comando, "dmprbt") == 0){
                fscanf(entrada, "%c %s", &t, sufixo);
            }

            else if(strcmp(comando, "eplg?") == 0){
                fscanf(entrada, "%s %lf %lf %lf %lf", tipoEstabelecimento, &x, &y, &w, &h);
            }

            else if(strcmp(comando, "catac") == 0){
                fscanf(entrada, "%lf %lf %lf", &x, &y, &r);
            }

            else if(strcmp(comando, "@m?") == 0){
                fscanf(entrada, "%s %s", registrador, cpf);
                registradorM(registrador, cpf);
        
            }

            else if(strcmp(comando, "@e?") == 0){
                fscanf(entrada, "%s %s %c %d", registrador, cep, &face, &num);
                registradorE(registrador, cep, face, num);
            }

            else if(strcmp(comando, "@g?") == 0){
                fscanf(entrada, "%s %s", registrador, id);
                registradorG(registrador, id, qt);
            }

            else if(strcmp(comando, "@xy?") == 0){
                fscanf(entrada, "%s %lf %lf", registrador, &x, &y);
                escolheRegistrador(registrador, x, y);
            }

            else if(strcmp(comando, "ccv") == 0){  
                 fscanf(entrada, "%s", sufixo);
            }

            else if(strcmp(comando, "p?") == 0){
                fscanf(entrada, "%s %s %s %s %s", sufixo, registrador, registrador2, cmc, cmr);
            }

            else if(strcmp(comando, "bf") == 0){
                fscanf(entrada, "%d", &maxCovid);
            }

            else if(strcmp(comando, "sp?") == 0){
                fscanf(entrada, "%s %s %s %s %s", sufixo, registrador, registrador2, cmc, cmr);
            }
            
            else if(strcmp(comando, "pb?") == 0){
                fscanf(entrada, "%s %s %s %s", sufixo, registrador, registrador2, cmc);
            }
        }
    //getNoQtId(getQuadtreeObjetos(qt), "hnb08.4", 'h');
    fclose(saidaTxt);
    fclose(entrada);
    svgen(listacidade, saidaSvgQry);
    free(saidaSvgQry);
    free(saidaTxtQry);
}

void openEc(char *arquivoEc, listaStruct listacidade){
    FILE *entrada;
    char comando[5];
    char codt[20];
    char descricao[300];
    char cnpj[25];
    char cpf[20];
    char cep[20];
    char face;
    double num;
    char nome[300];
    tipo elemento;

    entrada = fopen(arquivoEc, "r");

    if(entrada == NULL){
            printf("Erro ao abrir o arquivo entradaEc!!");
            system("pause");
            exit(1);
    }

    while(fscanf(entrada, "%s", comando) != EOF){
         if(strcmp(comando, "t") == 0){
            fscanf(entrada ,"%s %s", codt, descricao);
            elemento = criaDescricao(descricao, codt);
            insereHashtable(hashtableEstabelecimentos[0], descricao, elemento);

         }
         else if(strcmp(comando, "e") == 0){
            fscanf(entrada ,"%s %s %s %s %c %lf %s", cnpj, cpf, codt, cep, &face, &num, nome);
            Node quadra = comparaCepQuadra(listacidade, cep);
             if(quadra == NULL){
                 return;
             }
            elemento = criaEstabelecimento(cnpj, cpf, codt, cep, face, num, nome, quadra);
            insereHashtable(hashtableEstabelecimentos[1], cep, elemento);
            insereHashtable(hashtableEstabelecimentos[2], cnpj, elemento);
         }
    }

    //imprimeHashtable(hashEc[0], 'a');
    //imprimeHashtable(hashEc[1], 'e');
    fclose(entrada);
}

void openPm(char *arquivoPm, listaStruct listacidade){
    FILE *entrada;
    char comando[5];
    char cpf[20];
    char nome[150];
    char sobrenome[150];
    char sexo;
    char nasc[15];
    char face;
    double num;
    char comp[25];
    char cep[20];
    tipo elemento;

    entrada = fopen(arquivoPm, "r");

    if(entrada == NULL){
        printf("Erro ao abrir o arquivo entradaPm!!");
        system("pause");
        exit(1);
    }

    while(fscanf(entrada, "%s", comando) != EOF){
        if(strcmp(comando, "p") == 0){
            fscanf(entrada ,"%s %s %s %c %s", cpf, nome, sobrenome, &sexo, nasc);
            elemento = criaPessoa(cpf, nome, sobrenome, sexo, nasc);
            insereHashtable(hashtablePessoas[0], cpf, elemento);
        }
        else if(strcmp(comando, "m") == 0){
             fscanf(entrada ,"%s %s %c %lf %s", cpf, cep, &face, &num ,comp);
             Node quadra = comparaCepQuadra(listacidade, cep);
             if(quadra == NULL){
                 return;
             }
            elemento = criaEndereco(cpf, comp, face, num, quadra);
            insereHashtable(hashtablePessoas[1], cep, elemento);
            insereHashtable(hashtablePessoas[2], cpf, elemento);
        }
    }

    //imprimeHashtable(hashPm[0], 'd');
    //imprimeHashtable(hashtablePessoas[1], 'f');

    fclose(entrada);
}