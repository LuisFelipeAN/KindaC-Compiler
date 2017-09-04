#ifndef ANALISADORLEXICO_H
#define ANALISADORLEXICO_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
