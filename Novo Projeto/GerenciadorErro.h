/** \brief Enumera��o dos tipos de erros
 */
typedef enum {
    ErroCaractereInvalido   = 0,
    ErroCaractereVazio,
    ErroFaltaAspaSimples,
    ErroFaltaAspasDupla,
    ErroFimDeArquivoInesperado,
    ErroComentarioNaoTerminado,
    ErroCaractereMalFormado,
    ErroNumeroMalFormado,
    ErroArquivoInvalido,
    ErroSintatico,
    ErroSIntaticoDepois,
    ErroTamanhoEnumerador
} Erros;

/** \brief Inicializa o gerenciador de erro
 *  Qualquer erro existente ser� removido
 */
void inicializaGerenciadorErro();

/** \brief Destr�i o gerenciador de erro
 */
void destruirGerenciadorErro();

/** \brief Salva o erro na lista
 *
 * \param codigo int C�digo do erro a ser impresso
 * \param linha int Linha onde o erro ocorreu
 * \param coluna int Coluna onde o erro ocorreu
 *
 */
void saidaErro(int codigo, int linha, int coluna, char* tokenEncontrado = 0, char* tokenEsperado = 0);

/** \brief Imprime o pr�ximo erro da lista no stderr
 */
void proximoErro();

/** \brief Imprime a lista de erros
 */
void imprimeListaErros();
