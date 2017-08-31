#ifndef TRIE_H
#define TRIE_H
#include "No_Trie.h"

class Trie{
    public:
        Trie();
        /** \brief busca
         *  Fun��o que busca um lexema na trie e retorna o atributo associado a ele
         * \param
         *  entrada: lexema a ser buscado
         * \param
         * \return
         *  Atributo associado a esse lexema
         */
        Atributo* busca(char *entrada);
        /** \brief insere
         *  Fun��o para fazer a inser��o de lexemas dentro da tabela de simbolos
         * \param
         *  entrada: lexema a ser inserido na tabela
         *  atributo: atributo associado ao lexema
         * \param
         * \return
         *  vazio
         */
        void insere(char* entrada, Atributo* atributo);
        /** \brief imprime
         *  Fun��o para imprimir todos os lexemas guardados dentro da tabela
         */
        void imprime();
        virtual ~Trie();

    protected:
        int altura;
        No_Trie *raiz;
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
        /** \brief calcularTamanhoLexema
         *  FUn��o para calcular o tamanho de lexemas
         * \param
         * lexema: lexema para ser calculado o seu tamanho
         * \return
         *  Tamanho do lexema
         */
        int calcularTamanhoLexema(char *str);
    private:
        /** \brief imprimeRecursivo
         *  Fun��o recursiva auxiliar para percorrer a trie
         * \param
         *  saida: string parcial que � usada na impress�o
         * \param
         * \return
         *
         */
        void imprimeRecursivo(char* saida, int indice, No_Trie *n);
};

#endif // TRIE_H
