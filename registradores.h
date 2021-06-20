#ifndef REGISTRADORES_H_
#define REGISTRADORES_H_

    #include "hashtable.h"
    #include "lista.h"
    
    hstable hashtableEstabelecimentos[4];
    /*
    hashtableEstabelecimentos[0] - Descricao de estabelecimentos - chave : CPF
    hashtableEstabelecimentos[1] - Estabelecimentos - chave: CEP
    hashtableEstabelecimentos[2] - Estabelecimentos - chave: CNPJ 
    */
    hstable hashtablePessoas[4];
    /*
    hashtablePessoas[0] - Pessoas - chave: CPF
    hashtablePessoas[1] - Enderecos de Pessoas - chave: CEP
    hashtablePessoas[2] - Enderecos de Pessoas - chave: CPF
    */

    Node vetorHashDm[100];/*Armazena moradores de dm*/
    Node vetorHashDm2[100];/*Armazena endereco de moradores dm*/
    Node vetorHash3[100];
    Node vetorHash4[100];

    double reg1[2];
    double reg2[2];
    double reg3[2];
    double reg4[2];
    double reg5[2];
    double reg6[2];
    double reg7[2];
    double reg8[2];
    double reg9[2];
    double reg10[2];

#endif