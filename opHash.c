#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"
#include "lista.h"
#include "listaQuadras.h"
#include "registradores.h"
#include "quadtree.h"
#include "learq.h"
#include "listaEndereco.h"
#include "listaEstabelecimentos.h"
#include "listaCidadesQT.h"
#include "listaObjUrbanos.h"
#include "listaPessoas.h"

void iniciaVetorHash(){
    for(int i = 0; i <100; i++){
        vetorHashDm[i] = NULL;
        vetorHashDm2[i] = NULL;
        vetorHash3[i] = NULL;
        vetorHash4[i] = NULL;
    }
}

void imprimeMorador(char *cpf, FILE* saida, int totalVetor){
    Node testeEndereco = buscaEnderecoCpf(hashtablePessoas[2], cpf);
    Node testePessoa = buscaPessoaCpf(hashtablePessoas[0], cpf);

    if(testeEndereco != NULL && testePessoa != NULL){
        tipo pessoa, endereco;
        pessoa = getElemento(testePessoa);
        fprintf(saida, "Morador: %s %s %s %c %s\n", getCpfPessoa(pessoa), getNomePessoa(pessoa), getSobrenomePessoa(pessoa), getSexoPessoa(pessoa), getNascPessoa(pessoa));
        endereco = getElemento(testeEndereco);
        fprintf(saida, "Endereco: %s %s %s %c %d\n", getCpfEndereco(endereco), getCepEndereco(endereco), getComplementoEndereco(endereco), getFaceEndereco(endereco), getNumEndereco(endereco));
        vetorHashDm[totalVetor] = pessoa;
        vetorHashDm2[totalVetor] = endereco;
        totalVetor = totalVetor + 1;
    }
}   

void imprimeEstabelecimento(char *cnpj, FILE* saida){
    Node testeEstabelecimento = buscaEstabelecimentoCnpj(hashtableEstabelecimentos[2], cnpj);

    if(testeEstabelecimento != NULL){
        tipo estabelecimento;
        estabelecimento = getElemento(testeEstabelecimento);
        char *cpf = getCpfEstabelecimento(estabelecimento);
        Node testePessoa = buscaPessoaCpf(hashtablePessoas[2], cpf);
        if(testePessoa != NULL){
            tipo pessoa;
            pessoa = getElemento(testePessoa);
            fprintf(saida, "Estabelecimento Comercial: %s %s %s %s %c %d %s\n", getCnpjEstabelecimento(estabelecimento), getCpfEstabelecimento(estabelecimento), getCodtEstabelecimento(estabelecimento), getCepEstabelecimento(estabelecimento), getFaceEstabelecimento(estabelecimento), getNumEstabelecimento(estabelecimento), getNomeEstabelecimento(estabelecimento));
            fprintf(saida, "Dados do Proprietario: %s %s %s %c %s\n", getCpfPessoa(pessoa), getNomePessoa(pessoa), getSobrenomePessoa(pessoa), getSexoPessoa(pessoa), getNascPessoa(pessoa));
        }
    }
}