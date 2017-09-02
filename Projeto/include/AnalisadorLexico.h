#ifndef ANALISADORLEXICO_H
#define ANALISADORLEXICO_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Tokens.h"

#define TAMANHO_LEXEMA 32
#define TAMANHO_BUFFER 4096
#define MODO_ARQUIVO 77
#define MODO_ENTRADA 7

 /** \brief Aut�mato
  */
typedef struct _Automato{
    char   *lexema;           /**< Vetor de caracteres adicionados ao lexema  */
    int     estado;           /**< Estado atual do aut�mato  */
    int     posicaoLexema;    /**< Posi��o a adicionar um caractere no lexema  */
    int     tamLexema;        /**< Tamanho total do vetor de caracteres lexema  */
    int     linha;            /**< Linha atual do arquivo  */
    int     coluna;           /**< Coluna atual do arquivo  */
    char    caractere;        /**< �ltimo caractere lindo pelo aut�mato*/
    int modo;                 /**< Modo de entrada de caracteres */
} Automato;

 /** \brief Construtor do analisador l�xico
  *
  * \param caminho char* Caminho do arquivo a ser lido
  * \param modo int Modo de como o aut�mato pegara caracteres do leitor ou do terminal
  */
void iniciaAnalisadorLexico(char *caminho);

 /** \brief Fun��o que obt�m um caractere do leitor e incrementa uma coluna no aut�mato
  *
  *  \return caractere obtido
  */

int proximoToken();

 /** \brief Fun��o que obtem um lexema do analisador l�xico
  *
  *  \return lexema obtido
  */
char* pegarLexema();

 /** \brief Destrutor do Analisador L�xico
  *
  */
void destruirAnalizadorLexico();


#endif // ANALISADORLEXICO_H
