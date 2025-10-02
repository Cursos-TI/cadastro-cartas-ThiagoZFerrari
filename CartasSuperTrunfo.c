#include <stdio.h>

//==================================================================================
// DEFINIÇÃO DAS ESTRUTURAS DE DADOS
//==================================================================================

// Estrutura para armazenar todos os atributos de uma carta do jogo.
typedef struct {
    char cidade[30];
    int populacao;
    int p_turistico;
    float area;
    float pib;
} Carta;

// Estrutura para armazenar os resultados dos cálculos derivados de uma carta.
typedef struct {
    double densidade;
    double per_capita;
} ResultadoCalculado;


//==================================================================================
// FUNÇÕES DO PROGRAMA
//==================================================================================

// Apresenta a tela de boas-vindas do programa.
void interface(){
    printf("Seja bem-vindo ao jogo Super Trunfo!\n");
    printf("Jogo em desenvolvimento!\n");
    printf("Cadastre suas carta para jogar!\n");
    printf("Versão 1.1.1\n\n");
}

// Função auxiliar para consumir caracteres restantes no buffer de entrada (stdin),
// evitando o bug do "Enter fantasma" entre leituras de scanf e fgets.
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Coleta os dados do usuário para preencher as informações de UMA carta.
void preenche_uma_carta(Carta *carta){
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
    
    // Limpa o buffer de entrada para a próxima leitura de string.
    limpar_buffer();
}

// Realiza os cálculos de densidade e PIB per capita para uma única carta.
// Retorna uma struct 'ResultadoCalculado' com os valores.
ResultadoCalculado operacao_dados(Carta carta){
    ResultadoCalculado resultado;

    // Tratamento para evitar divisão por zero.
    if (carta.area > 0) {
        resultado.densidade = (double)carta.populacao / carta.area; 
    } else {
        resultado.densidade = 0;
    }

    if (carta.populacao > 0) {
        resultado.per_capita = (double)carta.pib / carta.populacao;
    } else {
        resultado.per_capita = 0;
    }
    
    return resultado;
}

// Exibe na tela os dados formatados de uma carta e seus resultados.
void saida_dados(Carta carta, ResultadoCalculado resultado){
    printf("\n----------------------------------\n");
    printf("CADASTRO DA CARTA SUPER TRUNFO\n");
    printf("Cidade: %s", carta.cidade);
    printf("População: %d\n", carta.populacao);
    printf("Area do Município: %.2f m²\n", carta.area);
    printf("PIB do Município: R$ %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.p_turistico);
    printf(">> Densidade Populacional: %.2f hab/m²\n", resultado.densidade);
    printf(">> PIB Per Capita: R$ %.2f\n", resultado.per_capita);
    printf("----------------------------------\n");
}

//==================================================================================
// FUNÇÃO PRINCIPAL
//==================================================================================

int main(){
    // Declaração das variáveis para as duas cartas e seus respectivos resultados.
    Carta carta1, carta2;
    ResultadoCalculado resultado1, resultado2;

    // Etapa 1: Apresentação da interface.
    interface();

    // Etapa 2: Leitura dos dados de entrada do usuário para cada carta.
    printf("--- Cadastro da Carta 1 ---\n");
    preenche_uma_carta(&carta1);
    
    printf("\n--- Cadastro da Carta 2 ---\n");
    preenche_uma_carta(&carta2);
    
    // Etapa 3: Processamento dos dados para cada carta.
    resultado1 = operacao_dados(carta1);
    resultado2 = operacao_dados(carta2);

    // Etapa 4: Exibição dos dados finais formatados.
    saida_dados(carta1, resultado1);
    saida_dados(carta2, resultado2);
    
    return 0;
}