#include "TabelaSimbolos.h"

Trie *tabelaID;
Trie *tabelaInteiro;
Trie *tabelaReal;
Trie *tabelaLiteral;
Trie *tabelaReservado;

/** \brief inicializaTabelaSimbolos
 *  Fun��o para inst�nciar as tabelas e definir par�metros
 */
void inicializaTabelaSimbolos(){
    tabelaID = new TrieIdentificador();
    tabelaInteiro = new TrieInteiro();
    tabelaLiteral = new TrieLiteral();
    tabelaReal = new TrieReal();
    tabelaReservado = new TrieReservada();
}

/** \brief buscaTabela
 *  Fun��o para fazer a busca de um atributo dentro de uma tabela por um lexema
 * \param
 *  tablela: refer�ncia a qual tabela ser� feita a busca
 * \param
 * \return
 *  Retorna o atributo referente ao lexema buscado
 */
Atributo* buscaTabela(const int tabela, char* entrada){
    switch(tabela){
        case TABELA_ID:
            return tabelaID->busca(entrada);
        break;
        case TABELA_INTEIRO:
            return tabelaInteiro->busca(entrada);
        break;
        case TABELA_REAL:
            return tabelaReal->busca(entrada);
        break;
        case TABELA_LITERAL:
            return tabelaLiteral->busca(entrada);
        break;
        case TABELA_RESERVADA:
            return tabelaReservado->busca(entrada);
    }
    return NULL;
}

/** \brief insereTabela
 *  Fun��o para inserir um lexema com o seu atributo dentro de uma das tabelas
 * \param
 *  tabela: refer�ncia a qual tabela ser� feita a inser��o
 * \param
 */
void insereTabela(const int tabela, char* entrada, Atributo* atr){
    switch(tabela){
        case TABELA_ID:
            tabelaID->insere(entrada,atr);
        break;
        case TABELA_INTEIRO:
            tabelaInteiro->insere(entrada,atr);
        break;
        case TABELA_REAL:
            tabelaReal->insere(entrada,atr);
        break;
        case TABELA_LITERAL:
            tabelaLiteral->insere(entrada,atr);
        break;
        case TABELA_RESERVADA:
            tabelaReservado->insere(entrada,atr);
    }
}

/** \brief imprimeTabela
 *  Fun��o para realizar a impress�o de uma das tabelas
 * \param
 *  tabela: tabela a ser impressa
 * \param
 */
void imprimeTabela(const int tabela){
    switch(tabela){
        case TABELA_ID:
            tabelaID->imprime();
        break;
        case TABELA_INTEIRO:
            tabelaInteiro->imprime();
        break;
        case TABELA_REAL:
            tabelaReal->imprime();
        break;
        case TABELA_LITERAL:
            tabelaLiteral->imprime();
        break;
        case TABELA_RESERVADA:
            tabelaReservado->imprime();
    }
}

/** \brief inicializaTabelaSimbolos
 *  Fun��o para desalocar as tabelas
 */
void destruirTabelaSimbolos(){
    delete tabelaID;
    delete tabelaInteiro;
    delete tabelaLiteral;
    delete tabelaReal;
    delete tabelaReservado;
}
