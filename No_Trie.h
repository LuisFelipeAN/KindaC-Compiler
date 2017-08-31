#ifndef NO_TRIE_H
#define NO_TRIE_H
#include "Atributo.h"
#define TAMANHO_ALFABETO 128

class No_Trie{
    public:
        No_Trie();
        /** \brief pegarCaractere
         *  Fun��o para retornar o filho correspondente � um caractere informado
         * \param
         * c: caractere a ser buscado no vetor de caracteres
         * \return
         *  O filho buscado a partir do caractere informado
         */
        No_Trie *pegarCaractere(char c);
        /** \brief atribuirCaractere
         *  Fun��o para atribuir � posi��o do vetor de caractere um n� informadado
         * \param
         * c: caractere correspondente a posi��o do vetor de caracteres
         * n: n� a ser atribuido nessa posi��o
         * \param
         */
        void atribuirCaractere(char c, No_Trie *n);
        /** \brief pegarAtributo
         *  Retornar o atributo armazenado neste n�
         */
        Atributo *pegarAtributo();
        /** \brief atribuirAtributo
         *  Fun��o para atribuir um atributo passado como par�metro a este n�
         * \param
         * p: atributo a ser armazenado
         * \param
         */
        void atribuirAtributo(Atributo *p);
        /** \brief atribuirChave
         *  Fun��o para definir se o npo eh chave ou n�o
         * \param
         * c: booleano para ser atribuido a variavel da classe 'chave'
         * \param
         */
        void atribuirChave(bool c);
        /** \brief EChave
         * Fun��o que retorna se o n� eh um n� chave ou n�o
         * \param
         * \param
         * \return
         *  Retorna a variavel chave
         *
         */
        bool EChave();
        ~No_Trie();
    private:
        No_Trie *caracteres[TAMANHO_ALFABETO];
        bool chave;
        Atributo *atributos;
};

#endif // NO_TRIE_H
