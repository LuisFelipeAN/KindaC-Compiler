#include <stdlib.h>
#include <stdio.h>

#define TAMANHO_ALFABETO 128

#ifndef TABELASIMBOLOS_H
#define TABELASIMBOLOS_H

class AcessoLocal;
class Variavel;

class Atributo{
    public:
        Atributo();
        int pegarToken();
        char *pegarLexema();
        void atribuirToken(int t);
        void atribuirLexema(const char* l);
        virtual void imprime();
        virtual ~Atributo();
    protected:
        int token;
        char* lexema;
};
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
class TabelaSimbolos{
    public:
        TabelaSimbolos();
        /** \brief busca
         *  Fun��o que busca um lexema na Tabela e retorna o atributo associado a ele
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
        void limpa();
        virtual ~TabelaSimbolos();

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
         *  Fun��o recursiva auxiliar para percorrer a Tabela
         * \param
         *  saida: string parcial que � usada na impress�o
         * \param
         * \return
         *
         */
        void imprimeRecursivo(char* saida, int indice, No_Trie *n);
        void deleteTabela(No_Trie *no);
};
class TabelaIdentificador:public TabelaSimbolos{
    public:
        TabelaIdentificador();
        virtual ~TabelaIdentificador();
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
class TabelaInteiro:public TabelaSimbolos{
    public:
        TabelaInteiro();
        virtual ~TabelaInteiro();
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
class TabelaLiteral:public TabelaSimbolos{
    public:
        TabelaLiteral();
        virtual ~TabelaLiteral();
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
class TabelaReal:public TabelaSimbolos{
    public:
        TabelaReal();
        virtual ~TabelaReal();
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
class TabelaReservada:public TabelaSimbolos{
    public:
        TabelaReservada();
        virtual ~TabelaReservada();
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
        void inicializarReservada();
};
class Tipo{
    public:
        Tipo(int tipo);
        ~Tipo();
        int pegaTipo();
        void atribuirTipo(int tipo);
    private:
        int tipo;
};
class TipoId:public Tipo{
    public:
        TipoId(char* lexema, int tipo);
        char* pegarLexema();
        void atribuirLexema(char* lexema);
        ~TipoId();
    private:
        char* lexema;
};
class AtributoVariavel:public Atributo{
    public:
        AtributoVariavel();
        virtual ~AtributoVariavel();
        void atribuirTipo(Tipo *tipo);
        void atribuiPonteiro(bool ponteiro);
        void atribuiArranjo(int arranjo);
        void atribuiAcesso(AcessoLocal *acesso);
        void atribuirVariavel(Variavel *variavel);
        void atribuirEscapa(bool escapa);
        void atribuiTamanho(int tamBytes);
        void atribuirDeslocamento(int deslocamento);
        int pegarTamanho();
        bool pegarEscapa();
        int pegarArranjo();
        bool pegarPonteiro();
        Tipo* pegarTipo();
        AcessoLocal *pegarAcesso();
        Variavel *pegarVariavel();
        int pegarDeslocamento();
    protected:
        Tipo* tipo;
        bool ponteiro;
        int arranjo;
        AcessoLocal *acesso;
        Variavel *variavel;
        bool escapa;
        int tamBytes;
        int deslocamento;
};
class AtributoFuncao:public Atributo{
    public:
        AtributoFuncao();
        virtual ~AtributoFuncao();
        void adicionarParametro(AtributoVariavel *atributo);
        void adicionarRetorno(Tipo *atributo);
        void adicionarVariavel(AtributoVariavel *atributo);
        void atribuirParametros(TabelaSimbolos *parametros);
        void atribuirVariaveis(TabelaSimbolos *variaveis);
        void atribuirPonteiro(bool ponteiro);
        bool pegarPonteiro();
        TabelaSimbolos *pegarVariaveisLocais();
        TabelaSimbolos *pegarParametros();
        Tipo *pegarRetorno();
        Atributo *busca(char *id);
        Atributo *buscaParametro(char *id);
        Atributo *buscaVariavel(char *id);
    protected:
        TabelaSimbolos *parametros;
        TabelaSimbolos *variaveisLocais;
        bool ponteiro;
        Tipo *retorno;
};
class AtributoFuncaoClasse:public AtributoFuncao{
    public:
        AtributoFuncaoClasse();
        ~AtributoFuncaoClasse();
        void atribuiPublico(bool publico);
        bool pegaPublico();
    private:
        bool publico;
};
class AtributoVariavelClasse:public AtributoVariavel{
    public:
        AtributoVariavelClasse();
        ~AtributoVariavelClasse();
        void atribuiPublico(bool publico);
        bool pegaPublico();
    private:
        bool publico;
};
class AtributoClasse:public Atributo{
    public:
        AtributoClasse();
        ~AtributoClasse();
        void adicionarFuncao(AtributoFuncaoClasse *atributo);
        void adicionarVariavel(AtributoVariavelClasse *atributo);
        void adicionarTamanho(int tamBytes);
        int pegarTamBytes();
        Atributo *buscaFuncao(char *id);
        Atributo *buscaVariavel(char *id);
        void atribuirHeranca(Atributo *heranca);
        Atributo *pegarHeranca();
        TabelaSimbolos *pegarVariaveis();
        TabelaSimbolos *pegarFuncoes();
    private:
        TabelaSimbolos *funcoes;
        TabelaSimbolos *variaveis;
        Atributo *heranca;
        int tamBytes;
};
class AtributoTipo:public Atributo{
    public:
        AtributoTipo();
        void adicionarVariavel(AtributoVariavel *var);
        void adicionarTamanho(int tamBytes);
        int pegarTamBytes();
        Atributo *buscaVariavel(char *id);
        TabelaSimbolos *pegaVariaveis();
        ~AtributoTipo();
    private:
        TabelaSimbolos *variaveis;
        int tamBytes;
};
#endif
