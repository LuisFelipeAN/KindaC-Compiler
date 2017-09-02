#include <stdio.h>
#include <string.h>

#include "AnalisadorLexico.h"
#include "TabelaSimbolos.h"
#include "Tokens.h"
#include "GerenciadorErro.h"

/** \brief Destr�i objetos alocados durante a execu��o do programa
 *  Fun��o chamada na saida do programa
 */
void finalizaPrograma();


/** \brief Ponto de entrada do programa
 */
int main(int argc, char** args){
    char* nomeArquivo = NULL;
    if(argc == 1){                  // altera o modo para obter caracteres do stdin
       nomeArquivo = NULL;
    } else if ( argc == 2 ) {       // L� o nome do arquivo da lista de argumento
        nomeArquivo = args[1];
    } else {
        fprintf(stderr, "Argumento invalido!\nExemplo de uso:\n\tKindaC teste.cpm\n\tKindaC teste\n\tKindaC\n");
        exit(1);
    }

    // Fun��o chamada na sa�da do programa, garante que mem�ria ser� desalocada
    atexit(finalizaPrograma);
    inicializaGerenciadorErro();
    inicializaTabelaSimbolos();
    iniciaAnalisadorLexico(nomeArquivo);
    int token = 0;
    while(token != EOF){
        token = proximoToken();
        ImprimeToken(token);
    }
    imprimeTabela(TABELA_LITERAL);
    imprimeTabela(TABELA_ID);
    imprimeTabela(TABELA_INTEIRO);
    imprimeTabela(TABELA_REAL);
    imprimeTabela(TABELA_RESERVADA);
    return 0;
}

/** \brief Destr�i objetos alocados durante a execu��o do programa
 */
void finalizaPrograma()
{
    imprimeListaErros();
    destruirAnalizadorLexico();
    destruirTabelaSimbolos();
    destruirGerenciadorErro();
}

