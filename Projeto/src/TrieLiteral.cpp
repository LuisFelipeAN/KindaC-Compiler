#include "TrieLiteral.h"

TrieLiteral::TrieLiteral():Trie(){}

/** \brief imprimeLexema
 *  Fun��o para colocar a string associada a um lexema no stdout
 * \param
 *  saida: lexema a ser impresso
 *  atr: atributo do lexema que ser� impresso juntamente com ele
 */
void TrieLiteral::imprimeLexema(char* saida, Atributo *atr){
    fprintf(stdout,"%s\n", saida);
}

/** \brief imprimeCabecalho
 *  Fun��o para colocar no stdout a descri��o da tabela antes de imprimi-la
 */
void TrieLiteral::imprimeCabecalho(){
    fprintf(stdout,"---------------------------------------\n");
    fprintf(stdout,"          TABELA DE LITERAIS           \n");
    fprintf(stdout,"---------------------------------------\n");
}
TrieLiteral::~TrieLiteral() { }
