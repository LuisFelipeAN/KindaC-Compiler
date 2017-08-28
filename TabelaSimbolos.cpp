#include "TabelaSimbolos.h"

TabelaSimbolos::TabelaSimbolos()
{
    raiz = NULL;
    altura = -1;
}
/** \brief
 *  Fun��o para fazer a inser��o de lexemas dentro da tabela de simbolos
 * \param
 *  entrada: lexema a ser inserido na tabela
 *  atributo: atributo associado ao lexema
 * \param
 * \return
 *  vazio
 */

void TabelaSimbolos::insere(char *entrada, Atributo *atributo){

    raiz = insereRecursivo(entrada, 0, raiz, atributo);

}
/** \brief
 *  Fun��o auxiliar para o metodo de inser��o
 * \param
 *  entrada: lexema a ser inserido na tabela
 *  atributo: atributo associado ao lexema
 *  pai: n� da �rvore trie a ser analisado
 * \param
 * \return
 *  Ponteiro para o n� que foi analisado
 *  vazio
 */
NoTrie *TabelaSimbolos::insereRecursivo(char *entrada, int indice, NoTrie *pai, Atributo *atributo){

    if(pai == NULL){///Caso encontre uma n� nulo, cria um novo n� e atribui o caracter correspondente a ele

        pai = new NoTrie();
        pai->atribuirCaractere(entrada[indice]);
        if(entrada[indice+1] == '\0'){///se tiver chegado no fim da string, marca esse n� como chave e termina a recurs�o

            pai->atribuirChave(true);
            pai->atribuirAtributo(atributo);
            altura = indice + 2;

        }else{///se n�o tiver chegado no fim da string, desce um nivel na �rvore

            pai->atribuirMeio(insereRecursivo(entrada, indice + 1, NULL, atributo));

        }
    }else{

        if(entrada[indice] == pai->pegarCaractere()){///verifica se o caminho que tomou � prefixo de algum outro lexema j� inserido

            if(entrada[indice + 1] == '\0'){///se sim, e se tiver chegado no fim da string, encerra a recurs�o

                pai->atribuirChave(true);
                pai->atribuirAtributo(atributo);

            }else{

                pai->atribuirMeio(insereRecursivo(entrada, indice + 1, pai->pegarMeio(), atributo));

            }

        }else if(entrada[indice] > pai->pegarCaractere()){///caso n�o tenha encontrado o caracter ainda, e o caracter for maior do que o armazenado no pai, desce a direita

            pai->atribuirDireita(insereRecursivo(entrada, indice, pai->pegarDireita(), atributo));

        }else{ /// se n�o, desce � esquerda

            pai->atribuirEsquerda(insereRecursivo(entrada, indice, pai->pegarEsquerda(), atributo));

        }

    }
    return pai;
}

/** \brief
 *  Fun��o para imprimir todos os lexemas guardados dentro da tabela
 * \param
 * \param
 * \return
 *
 */

void TabelaSimbolos::imprime(){

    char saida[altura];
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

void TabelaSimbolos::imprimeRecursivo(char *saida, int indice, NoTrie *pai){

    if(pai != NULL){

        if(pai->pegarChave()){

            saida[indice] = pai->pegarCaractere();
            saida[indice + 1] = '\0';
            printf("[%s]", saida);

        }
        imprimeRecursivo(saida,indice, pai->pegarDireita());
        imprimeRecursivo(saida,indice, pai->pegarEsquerda());
        saida[indice] = pai->pegarCaractere();
        imprimeRecursivo(saida,indice + 1, pai->pegarMeio());

    }

}
/** \brief
 *  Fun��o que busca um lexema na trie e retorna o atributo associado a ele
 * \param
 *  entrada: lexema a ser buscado
 * \param
 * \return
 *  Atributo associado a esse lexema
 */

Atributo* TabelaSimbolos::busca(char *entrada){

    return buscaRecursivo(entrada, 0, raiz);

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

Atributo* TabelaSimbolos::buscaRecursivo(char *entrada, int indice, NoTrie *pai){

    if(pai != NULL){

        if(entrada[indice + 1] == '\0'){ /// se terminou de verificar a string

            if(pai->pegarCaractere() == entrada[indice]){ /// e o caractere do n� casa com o caractere buscado

                if(pai->pegarChave()){ /// e esse n� � uma chave, entao encontramos o lexema

                    return pai->pegarAtributo();

                }

            }

        }else{

            if(pai->pegarCaractere() == entrada[indice]){/// caso n�o estejamos no fim da string e o caractere buscado casa com o que est� armazenado no n�, desce um n�vel no meio

                return buscaRecursivo(entrada, indice + 1, pai->pegarMeio());

            }else if(entrada[indice] > pai->pegarCaractere()){ /// caso o caractere seja maior, desce � direita

                return buscaRecursivo(entrada, indice, pai->pegarDireita());

            }else{ /// se n�o, desce � esquerda

                return buscaRecursivo(entrada, indice, pai->pegarEsquerda());

            }

        }
    }
    return NULL;

}
TabelaSimbolos::~TabelaSimbolos()
{
    if(raiz != NULL){

        delete raiz;

    }
}
