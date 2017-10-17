#include <stdio.h>
#include <string.h>
#include "ASA.h"
#include "AnalisadorLexico.h"
#include "AnalisadorSintatico.h"
#include "GerenciadorErro.h"
#include "VisitanteImpressao.h"

/** \brief Destr�i objetos alocados durante a execu��o do programa
 *  Fun��o chamada na saida do programa
 */
void finalizaPrograma();

/** \brief Ponto de entrada do programa
 */
int main(int argc, char** args){
    FILE* arquivo = stdin;
    if ( argc == 2 ) {
        char caminhoArquivo[strlen(args[1])+5];
        strcpy(caminhoArquivo, args[1]);
        // Se n�o tiver a exten��o .cpm, adicione
        if(strstr(caminhoArquivo, ".cpm") == NULL ){
            strcat(caminhoArquivo, ".cpm");
        }
        arquivo = fopen(caminhoArquivo, "r");
        if(!arquivo){
            fprintf(stderr, "Arquivo invalido!");
            exit(1);
        }
    } else if( argc > 2){
               fprintf(stderr, "Argumento invalido!\nExemplo de uso:\n\tKindaC teste.cpm\n\tKindaC teste\n\tKindaC\n");
               exit(1);
           }

    // Fun��o chamada na sa�da do programa, garante que mem�ria ser� desalocada
    atexit(finalizaPrograma);
    inicializaGerenciadorErro();
    iniciaAnalisadorLexico(arquivo);
    NoPrograma* programa = Programa();
    // Imprime a ASA
    VisitanteImpressao vp;
    vp.visita(programa);
    imprimeListaErros();
    delete programa; // Destroi a ASA
    return 0;
}

/** \brief Destr�i objetos alocados durante a execu��o do programa
 */
void finalizaPrograma(){
    imprimeListaErros();
    destruirAnalizadorLexico();
    destruirGerenciadorErro();
}

