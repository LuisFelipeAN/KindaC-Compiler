#ifndef TRIEIDENTIFICADOR_H
#define TRIEIDENTIFICADOR_H
#include "Trie.h"

class TrieIdentificador:public Trie{
    public:
        TrieIdentificador();
        virtual ~TrieIdentificador();
    protected:
        /** \brief imprimeLexema
         *  Fun��o para colocar a string associada a um lexema no stdout
         * \param
         *  saida: lexema a ser impresso
         *  atr: atributo do lexema que ser� impresso juntamente com ele
         */
        virtual void imprimeLexema(char* entrada, Atributo * atr);
        /** \brief imprimeCabecalho
         *  Fun��o para colocar no stdout a descri��o da tabela antes de imprimi-la
         */
        virtual void imprimeCabecalho();
};

#endif // TRIEIDENTIFICADOR_H
