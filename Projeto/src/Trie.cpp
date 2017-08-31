#include "Trie.h"

Trie::Trie() { raiz = new No_Trie(); altura = 0; }

/** \brief insere
 *  Fun��o para fazer a inser��o de lexemas dentro da tabela de simbolos
 * \param
 *  entrada: lexema a ser inserido na tabela
 *  atributo: atributo associado ao lexema
 * \param
 */
void Trie::insere(char* entrada, Atributo* atributo){
    int indice = 0;
    No_Trie *no = raiz;
    No_Trie *auxiliar = NULL;
    char caractere;

    while(entrada[indice] != '\0'){ ///Percorre todo os caracteres da entrada
        caractere = entrada[indice];
        auxiliar = no->pegarCaractere(caractere);   ///para cada caractere busca o filho correspondente do n� atual
        if(auxiliar == NULL){   ///se esse filho nao existir, o cria e associa o n� atual a ele
            auxiliar = new No_Trie();
            no->atribuirCaractere(caractere, auxiliar);
            no = auxiliar;
        } else{ ///se o filho existir, apenas desce um n�vel da �rvore
            no = no->pegarCaractere(caractere);
        }
        indice++;
    }
    if(altura < indice + 1) { altura = indice + 1; }
    ///ao chegar no final da string, coloca o n� atual como chave e associa o atributo � ele
    no->atribuirChave(true);
    no->atribuirAtributo(atributo);
}

/** \brief imprime
 *  Fun��o para imprimir todos os lexemas guardados dentro da tabela
 */
void Trie::imprime(){
    imprimeCabecalho();
    char saida[altura + 1];
    imprimeRecursivo(saida, 0, raiz);
}

/** \brief imprimeRecursivo
 *  Fun��o recursiva auxiliar para percorrer a trie
 * \param
 *  saida: string parcial que � usada na impress�o
 * \param
 */
void Trie::imprimeRecursivo(char* saida, int indice, No_Trie *n){
    if(n->EChave()){///Para cada n� que for chave, imprime o caminho que foi percorrido pela recurs�o
        saida[indice] = '\0';
        imprimeLexema(saida, n->pegarAtributo());
    }
    No_Trie *filho = NULL;
    ///Para cada filho n�o nulo do n� atual,
    for(unsigned int caractere = 0; caractere < TAMANHO_ALFABETO; caractere++){
        ///coloca o caractere correspondente na saida e desce um n�vel
        filho = n->pegarCaractere(caractere);
        if(filho != NULL){
            saida[indice] = caractere;
            imprimeRecursivo(saida, indice + 1, filho);
        }
    }
}

/** \brief busca
 *  Fun��o que busca um lexema na trie e retorna o atributo associado a ele
 * \param
 *  entrada: lexema a ser buscado
 * \param
 * \return
 *  Atributo associado a esse lexema
 */
Atributo* Trie::busca(char *entrada){
    int indice = 0;
    No_Trie *no = raiz;
    while(entrada[indice] != '\0'){///enquanto percorre toda a entrada buscada
        no = no->pegarCaractere(entrada[indice]);
        if(no == NULL){///se encontrar um n� nulo pelo caminho, a entrada n�o existe
            return NULL;
        }
        indice++;
    }
    if(no->EChave()){///se n�o encontrou nenhum n� nulo pelo caminho e o n� que parou � uma chave, ent�o encontrou a entrada
        return no->pegarAtributo();
    }
    return NULL;
}

/** \brief calcularTamanhoLexema
 *  FUn��o para calcular o tamanho de lexemas
 * \param
 * lexema: lexema para ser calculado o seu tamanho
 * \return
 *  Tamanho do lexema
 */
int Trie::calcularTamanhoLexema(char *lexema){
    int total = 0;
    while( lexema[total] != '\0') { total++; }
    return total;
}

/** \brief imprimeLexema
 *  Fun��o para colocar a string associada a um lexema no stdout
 * \param
 *  saida: lexema a ser impresso
 *  atr: atributo do lexema que ser� impresso juntamente com ele
 */
void Trie::imprimeLexema(char* saida, Atributo * atr){
    fprintf(stdout,"[%s]\n", saida);
}

/** \brief imprimeCabecalho
 *  Fun��o para colocar no stdout a descri��o da tabela antes de imprimi-la
 */
void Trie::imprimeCabecalho(){
    fprintf(stdout,"---------------------------------------\n");
    fprintf(stdout,"---------------TABELA------------------\n");
    fprintf(stdout,"---------------------------------------\n");
}
Trie::~Trie() { delete raiz; }
