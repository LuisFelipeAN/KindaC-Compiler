#ifndef TABELASIMBOLOS_H_INCLUDED
#define TABELASIMBOLOS_H_INCLUDED

#include "TrieReal.h"
#include "TrieIdentificador.h"
#include "TrieInteiro.h"
#include "TrieLiteral.h"
#include "TrieReservada.h"
#include "Tokens.h"

#define TABELA_ID 1
#define TABELA_REAL 2
#define TABELA_INTEIRO 3
#define TABELA_LITERAL 4
#define TABELA_RESERVADA 5

/** \brief inicializaTabelaSimbolos
 *  Fun��o para inst�nciar as tabelas e definir par�metros
 */
void inicializaTabelaSimbolos();
/** \brief buscaTabela
 *  Fun��o para fazer a busca de um atributo dentro de uma tabela por um lexema
 * \param
 * tablela: refer�ncia a qual tabela ser� feita a busca
 * \param
 * \return
 * Retorna o atributo referente ao lexema buscado
 */
Atributo* buscaTabela(const int tabela, char* entrada);
/** \brief insereTabela
 *  Fun��o para inserir um lexema com o seu atributo dentro de uma das tabelas
 * \param
 * tabela: refer�ncia a qual tabela ser� feita a inser��o
 * \param
 */
void insereTabela(const int tabela, char* entrada, Atributo* atr);
/** \brief imprimeTabela
 *  Fun��o para realizar a impress�o de uma das tabelas
 * \param
 * tabela: tabela a ser impressa
 * \param
 */
void imprimeTabela(const int tabela);
/** \brief inicializaTabelaSimbolos
 *  Fun��o para desalocar as tabelas
 */
void destruirTabelaSimbolos();

#endif // TABELASIMBOLOS_H_INCLUDED
