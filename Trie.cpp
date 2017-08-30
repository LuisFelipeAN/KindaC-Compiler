#include "Trie.h"

Trie::Trie() { raiz = new No_Trie(); altura = 0; }

/** \brief
 *  Fun��o para fazer a inser��o de lexemas dentro da tabela de simbolos
 * \param
 *  entrada: lexema a ser inserido na tabela
 *  atributo: atributo associado ao lexema
 * \param
 * \return
 *  vazio
 */
void Trie::insere(char* entrada, Atributo* atributo){
    insereRecursivo(entrada, 0, raiz, atributo);
}

/** \brief
 *  Fun��o auxiliar para o metodo de inser��o
 * \param
 *  entrada: lexema a ser inserido na tabela
 *  indice: indice da entrada a ser analisada
 *  atributo: atributo associado ao lexema
 *  pai: n� da �rvore trie a ser analisado
 * \param
 * \return
 *  Ponteiro para o n� que foi analisado
 *  vazio
 */
void Trie::insereRecursivo(char* entrada, int indice, No_Trie *pai, Atributo* atributo){
    /// se caso tenha chegado ao fim da string, termina a recurs�o e marca n� como chave
    if(entrada[indice] == '\0'){
        pai->atribuirChave(true);
        pai->atribuirAtributo(atributo);
        if(altura < indice + 1) { altura = indice + 1; }
    }
    else{
        No_Trie *filho = pai->pegarCaractere(entrada[indice]);
        if(filho == NULL){ ///Se o n� associado ao caractere da entrada nao existir, o cria
            filho = new No_Trie();
            pai->atribuirCaractere(entrada[indice], filho);
        }
        insereRecursivo(entrada, indice + 1, filho,atributo);
    }
}

/** \brief
 *  Fun��o para imprimir todos os lexemas guardados dentro da tabela
 * \param
 * \param
 * \return
 *
 */
void Trie::imprime(){
    imprimeCabecalho();
    char saida[altura + 1];
    imprimeRecursivo(saida, 0, raiz);
}

/** \brief
 *  Fun��o recursiva auxiliar para percorrer a trie
 * \param
 *  saida: string parcial que � usada na impress�o
 * \param
 * \return
 *
 */
void Trie::imprimeRecursivo(char* saida, int indice, No_Trie *n){
    if(n->EChave()){
        saida[indice] = '\0';
        imprimeLexema(saida, n->pegarAtributo());
    }
    No_Trie *filho = NULL;
    for(unsigned int caractere = 0; caractere < TAMANHO_ALFABETO; caractere++){
        filho = n->pegarCaractere(caractere);
        if(filho != NULL){
            saida[indice] = caractere;
            imprimeRecursivo(saida, indice + 1, filho);
        }
    }
}

/** \brief
 *  Fun��o recursiva auxiliar que percorre a trie
 * \param
 *  entrada: lexema a ser buscado
 *  indice: indice da string de entrada que ser� analisado
 *  pai: no da trie a ser analisado
 * \param
 * \return
 *  Atributo associado ao lexema buscado
 */
Atributo* Trie::buscaRecursivo(char *entrada, int indice, No_Trie *pai){
    if(pai != NULL){                 /// se chagar em um n� nulo o lexema n�o existe na tabela
        if(entrada[indice] == '\0'){ /// se chaegar no fim da string dentro de um n� existente
            if(pai->EChave()){       /// e esse n� for uma chave, encontrei o lexema na tabela de simbolos
                return pai->pegarAtributo();
            }
        }
        else{                        ///se n�o, desce mais um n�vel na �rvore
            return buscaRecursivo(entrada, indice + 1, pai->pegarCaractere(entrada[indice]));
        }
    }
    return NULL;
}

/** \brief
 *  Fun��o que busca um lexema na trie e retorna o atributo associado a ele
 * \param
 *  entrada: lexema a ser buscado
 * \param
 * \return
 *  Atributo associado a esse lexema
 */
Atributo* Trie::busca(char *entrada){
    return buscaRecursivo(entrada, 0, raiz);
}
int Trie::calcularTamanhoLexema(char *lexema){
    int total=0;
    while( lexema[total] != '\0')
        total++;
    return total;
}
void Trie::imprimeLexema(char* saida, Atributo * atr){
    fprintf(stdout,"[%s]\n", saida);
}
void Trie::imprimeCabecalho(){
    fprintf(stdout,"---------------------------------------\n");
    fprintf(stdout,"---------------TABELA------------------\n");
    fprintf(stdout,"---------------------------------------\n");
}
Trie::~Trie() { delete raiz; }
