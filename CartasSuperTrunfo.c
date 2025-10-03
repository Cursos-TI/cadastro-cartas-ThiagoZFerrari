#include <stdio.h>

/**
 * Jogo Super Trunfo - Países (Nível Mestre)
 *
 * Este programa permite o cadastro de duas cartas de cidades, com seus respectivos
 * atributos (população, área, pib, etc.). Após o cadastro, o sistema calcula
 * propriedades derivadas (densidade, pib per capita, super poder) e, por fim,
 * compara as duas cartas, exibindo qual delas vence em cada um dos atributos,
 * seguindo as regras do jogo.
 *
 * A comparação é feita utilizando operadores relacionais que retornam 1 para
 * verdadeiro e 0 para falso, sem o uso de estruturas de decisão como if/else.
 */

//==================================================================================
// DEFINIÇÃO DAS ESTRUTURAS DE DADOS
//==================================================================================

// A struct 'Carta' armazena os dados brutos de uma cidade, inseridos pelo usuário.
typedef struct {
    char cidade[30];
    int populacao;
    int p_turistico;
    float area;
    float pib;
} Carta;

// A struct 'ResultadoCalculado' armazena os dados que são calculados a partir
// de uma carta, como a densidade populacional, pib per capita e o super poder.
typedef struct {
    double densidade;
    double per_capita;
    long int soma_carta; // Super Poder
} ResultadoCalculado;

// A struct 'ComparacaoCarta' armazena o resultado (0 ou 1) da comparação
// entre as duas cartas para cada um dos atributos.
typedef struct {
    int c_populacao;
    int c_area, c_pib;
    int c_turistico;
    int c_densidade;
    int c_percapita;
    int c_poder;
} ComparacaoCarta;

//==================================================================================
// FUNÇÕES DO PROGRAMA
//==================================================================================

/**
 * @brief Apresenta a tela de boas-vindas do programa.
 */
void interface() {
    printf("Seja bem-vindo ao jogo Super Trunfo!\n");
    printf("Jogo em desenvolvimento!\n");
    printf("Cadastre suas carta para jogar!\n");
    printf("Versão 1.1.1\n\n");
}

/**
 * @brief Limpa o buffer de entrada (stdin).
 *
 * Esta função é essencial para evitar bugs de leitura ao misturar
 * scanf() com fgets(), consumindo o caractere '\n' que sobra no buffer.
 */
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * @brief Coleta os dados do usuário para preencher uma única carta.
 * @param carta Ponteiro para a struct 'Carta' que será preenchida. O uso
 * de ponteiro permite que a função modifique a variável original da 'main'.
 */
void preenche_uma_carta(Carta *carta) {
    printf("Cidade: ");
    fgets(carta->cidade, 30, stdin);

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área M²: ");
    scanf("%f", &carta->area);

    printf("PIB: ");
    scanf("%f", &carta->pib);

    printf("Pontos Turísticos: ");
    scanf("%d", &carta->p_turistico);

    // Limpa o buffer para a próxima leitura de string na próxima chamada da função.
    limpar_buffer();
}

/**
 * @brief Realiza os cálculos derivados dos dados de uma carta.
 * @param carta A struct com os dados de entrada da cidade.
 * @return Uma struct 'ResultadoCalculado' contendo os valores processados.
 */
ResultadoCalculado operacao_dados(Carta carta) {
    ResultadoCalculado resultado;

    // Calcula a densidade, com tratamento para evitar divisão por zero.
    if (carta.area > 0) {
        resultado.densidade = (double)carta.populacao / carta.area;
    } else {
        resultado.densidade = 0;
    }

    // Calcula o PIB per capita, com tratamento para evitar divisão por zero.
    if (carta.populacao > 0) {
        resultado.per_capita = (double)carta.pib / carta.populacao;
    } else {
        resultado.per_capita = 0;
    }

    // Calcula o "Super Poder" somando os atributos numéricos.
    // O resultado é armazenado em um 'long int', descartando as casas decimais.
    resultado.soma_carta = carta.area + carta.p_turistico + carta.pib + carta.populacao;

    return resultado;
}

/**
 * @brief Compara todos os atributos de duas cartas.
 * @param carta1 Dados de entrada da primeira carta.
 * @param carta2 Dados de entrada da segunda carta.
 * @param resultado1 Dados calculados da primeira carta.
 * @param resultado2 Dados calculados da segunda carta.
 * @return Uma struct 'ComparacaoCarta' preenchida com 1 (se a carta 1 vence)
 * ou 0 (se a carta 2 vence ou empata).
 */
ComparacaoCarta comparacao_carta(Carta carta1, Carta carta2, ResultadoCalculado resultado1, ResultadoCalculado resultado2) {
    ComparacaoCarta comparacao;

    // Para a maioria dos atributos, o maior valor vence.
    comparacao.c_populacao = carta1.populacao > carta2.populacao;
    comparacao.c_area = carta1.area > carta2.area;
    comparacao.c_pib = carta1.pib > carta2.pib;
    comparacao.c_turistico = carta1.p_turistico > carta2.p_turistico;
    comparacao.c_percapita = resultado1.per_capita > resultado2.per_capita;
    comparacao.c_poder = resultado1.soma_carta > resultado2.soma_carta;

    // Regra especial para a Densidade: o menor valor vence.
    comparacao.c_densidade = resultado1.densidade < resultado2.densidade;

    return comparacao;
}

/**
 * @brief Exibe na tela os dados formatados de uma carta e seus resultados.
 * @param carta A struct com os dados de entrada.
 * @param resultado A struct com os dados calculados.
 */
void saida_carta(Carta carta, ResultadoCalculado resultado) {
    printf("\n----------------------------------\n");
    printf("CADASTRO DA CARTA SUPER TRUNFO\n");
    printf("Cidade: %s", carta.cidade);
    printf("População: %d\n", carta.populacao);
    printf("Area do Município: %.2f m²\n", carta.area);
    printf("PIB do Município: R$ %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.p_turistico);
    printf(">> Densidade Populacional: %.2f hab/m²\n", resultado.densidade);
    printf(">> PIB Per Capita: R$ %.2f\n", resultado.per_capita);
    printf("SUPER PODER: %ld\n", resultado.soma_carta);
    printf("----------------------------------\n");
}

/**
 * @brief Exibe o resultado final da comparação entre as duas cartas.
 * @param comparacao A struct contendo os resultados (0 ou 1) de cada atributo.
 */
void saida_comparacao(ComparacaoCarta comparacao) {
    printf("\n----------------------------------\n");
    printf("     RESULTADO DA COMPARAÇÃO\n");
    printf("(1 = CARTA 1 VENCE, 0 = CARTA 2 VENCE/EMPATE)\n");
    printf("----------------------------------\n");
    printf("População: %d\n", comparacao.c_populacao);
    printf("Area do Município: %d\n", comparacao.c_area);
    printf("PIB do Município: %d\n", comparacao.c_pib);
    printf("Pontos Turísticos: %d\n", comparacao.c_turistico);
    printf(">> Densidade Populacional: %d\n", comparacao.c_densidade);
    printf(">> PIB Per Capita: %d\n", comparacao.c_percapita);
    printf("SUPER PODER: %d\n", comparacao.c_poder);
    printf("----------------------------------\n");
}

//==================================================================================
// FUNÇÃO PRINCIPAL (main)
//==================================================================================

int main() {
    // Etapa 0: Declaração das variáveis principais que serão usadas no programa.
    Carta carta1, carta2;
    ResultadoCalculado resultado1, resultado2;
    ComparacaoCarta comparacao1;

    // Etapa 1: Apresentação da interface inicial do programa.
    interface();

    // Etapa 2: Leitura dos dados de entrada do usuário para cada uma das cartas.
    printf("--- Cadastro da Carta 1 ---\n");
    preenche_uma_carta(&carta1);

    printf("\n--- Cadastro da Carta 2 ---\n");
    preenche_uma_carta(&carta2);

    // Etapa 3: Processamento dos dados de cada carta para calcular seus atributos.
    resultado1 = operacao_dados(carta1);
    resultado2 = operacao_dados(carta2);

    // Etapa 4: Exibição dos dados cadastrados e calculados de cada carta.
    saida_carta(carta1, resultado1);
    saida_carta(carta2, resultado2);

    // Etapa 5: Processamento da comparação, chamando a função especialista.
    comparacao1 = comparacao_carta(carta1, carta2, resultado1, resultado2);

    // Etapa 6: Exibição do resultado final da comparação.
    saida_comparacao(comparacao1);

    // Retorna 0 para indicar que o programa foi executado com sucesso.
    return 0;
}