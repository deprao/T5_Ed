#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tratamento.h"

int main(int argc, char *argv[]){
    char *diretorio = NULL;
    char *arquivoGeo = NULL;
    char *arquivoQry = NULL;
    char *pastaSaida = NULL;
    char *arquivoPessoas = NULL;
    char *arquivoEstabelecimentos = NULL;
    char *arquivoVia = NULL;

    for (int i = 0; i<argc; i++){ /* Função para captar os caracteres do terminal */
            if ( strcmp(argv[i], "-e") == 0){
                    i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos em -e");
                    exit(1);
                }
                diretorio = (char*)malloc( ( ( strlen (argv[i]) )+1 )*sizeof(char) );
                strcpy(diretorio, argv[i]);
            }

            else if ( strcmp(argv[i], "-f") == 0){
                    i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos -f");
                    exit(1);
                }
                arquivoGeo = (char*)malloc( ( ( strlen (argv[i]) )+1)*sizeof(char) );
                strcpy(arquivoGeo, argv[i]);
            }

            else if ( strcmp(argv[i], "-q") == 0){
                    i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos -q");
                    exit(1);
                }
                arquivoQry = (char*)malloc( ( ( strlen(argv[i]) )+1 )*sizeof(char) );
                strcpy(arquivoQry, argv[i]);
            }

            else if ( strcmp(argv[i], "-o") == 0){
                    i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos -o");
                    exit(1);
                }
                pastaSaida = (char*)malloc( ( ( strlen(argv[i]) )+1 )*sizeof(char) );
                strcpy(pastaSaida, argv[i]);
            }

            else if ( strcmp(argv[i], "-ec") == 0){
                    i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos -ec");
                    exit(1);
                }
                arquivoEstabelecimentos = (char*)malloc( ( ( strlen(argv[i]) )+1 )*sizeof(char) );
                strcpy(arquivoEstabelecimentos, argv[i]);
            }

            else if ( strcmp(argv[i], "-pm") == 0){
                    i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos -pm");
                    exit(1);
                }
                arquivoPessoas = (char*)malloc( ( ( strlen(argv[i]) )+1 )*sizeof(char) );
                strcpy(arquivoPessoas, argv[i]);
            }
             else if ( strcmp(argv[i], "-v") == 0){
                    i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos -v");
                    exit(1);
                }
                arquivoVia = (char*)malloc( ( ( strlen(argv[i]) )+1 )*sizeof(char) );
                strcpy(arquivoVia, argv[i]);
            }
            else if ( strcmp(argv[i], "-k") == 0){
                 i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos -k");
                    exit(1);
                }
            }
            else if ( strcmp(argv[i], "-u") == 0){
                 i++;
                if(argv[i] == NULL){
                    perror("\nSem parametros validos -u");
                    exit(1);
                }
            }
        }

        /*printf("\n %s %s %s %s", diretorio, arquivoGeo, arquivoQry, pastaSaida);*/

        tratamentoString(diretorio, arquivoGeo, arquivoQry, pastaSaida, arquivoEstabelecimentos, arquivoPessoas, arquivoVia);

        free(arquivoVia);
        free(arquivoEstabelecimentos);
        free(arquivoPessoas);
        free(pastaSaida);
        free(arquivoQry);
        free(arquivoGeo);
        free(diretorio);
}