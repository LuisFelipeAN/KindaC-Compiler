#include "No_Trie.h"

No_Trie::No_Trie(){
    for(int i = 0; i < TAMANHO_ALFABETO; i++) { caracteres[i] = NULL; }
    atributos = NULL;
    chave = false;
}
/** \brief pegarCaractere
 *  Fun��o para retornar o filho correspondente � um caractere informado
 * \param
 * c: caractere a ser buscado no vetor de caracteres
 * \return
 *  O filho buscado a partir do caractere informado
 */
No_Trie* No_Trie::pegarCaractere(char c) { return caracteres[(int)c]; }
/** \brief atribuirCaractere
 *  Fun��o para atribuir � posi��o do vetor de caractere um n� informadado
 * \param
 * c: caractere correspondente a posi��o do vetor de caracteres
 * n: n� a ser atribuido nessa posi��o
 * \param
 */
void No_Trie::atribuirCaractere(char c, No_Trie* n) { caracteres[(int)c] = n; }
/** \brief pegarAtributo
 *  Retornar o atributo armazenado neste n�
 */
Atributo* No_Trie::pegarAtributo() { return atributos; }
/** \brief atribuirAtributo
 *  Fun��o para atribuir um atributo passado como par�metro a este n�
 * \param
 * p: atributo a ser armazenado
 * \param
 */
void No_Trie::atribuirAtributo(Atributo *p) { atributos = p; }
/** \brief atribuirChave
 *  Fun��o para definir se o npo eh chave ou n�o
 * \param
 * c: booleano para ser atribuido a variavel da classe 'chave'
 * \param
 */

void No_Trie::atribuirChave(bool c) { chave = c; }
/** \brief EChave
 * Fun��o que retorna se o n� eh um n� chave ou n�o
 * \param
 * \param
 * \return
 *  Retorna a variavel chave
 *
 */
bool No_Trie::EChave() { return chave; }

No_Trie::~No_Trie(){
    for(int i = 0; i < TAMANHO_ALFABETO; i++){
        if(caracteres[i] != NULL){ delete caracteres[i]; }
    }
    if(atributos != NULL){ delete atributos; }
}
