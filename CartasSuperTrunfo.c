#include <stdio.h>

int main(){

    //Informações usuário
    printf("Seja bem-vindo ao jogo Super Trunfo!\n");
    printf("Jogo em desenvolvimento!\n");
    printf("Cadastre suas carta para jogar!\n");
    printf("Versão 1.0\n");

    //Variáveis
    //Carta 1
    char cidade_1[50];
    int populacao_1, p_turistico_1;
    float area_1;
    double pib_1;

    //Carta 2
    char cidade_2[50];
    int populacao_2, p_turistico_2;
    float area_2;
    double pib_2;

    //Entrada de Dados
    //Carta 1
    printf("\nCidade: ");
    scanf("%s", cidade_1);

    printf("\nPopulação: ");
    scanf("%d", &populacao_1);

    printf("\nÁrea do município: ");
    scanf("%f", &area_1);

    printf("\nPIB do muncípio: ");
    scanf("%f", &pib_1);

    printf("\nPontos turisticos: ");
    scanf("%d", &p_turistico_1);

    //Carta 2
    printf("Cidade: ");
    scanf("%s", cidade_2);

    printf("\nPopulação: ");
    scanf("%d", &populacao_2);

    printf("\nÁrea do município: ");
    scanf("%f", &area_2);

    printf("\nPIB do muncípio: ");
    scanf("%f", &pib_2);

    printf("\nPontos turisticos: ");
    scanf("%d", &p_turistico_2);

    //Saída de dados
    //Carta 1
    printf("\nCADASTRO DE CARTAS SUPER TRUNFO");
    printf("\nCarta 1\n");
    printf("\nCidade: %s.\n", cidade_1);
    printf("\nPopulação: %d.\n", populacao_1);
    printf("\nArea do Município: %.2f.\n", area_1);
    printf("\nPIB do Município: %.2f.\n", pib_1);
    printf("\nPontos Turísticos: %d.\n", p_turistico_1);

    //Carta 2
    printf("\nCarta 2\n");
    printf("\nCidade: %s.\n", cidade_2);
    printf("\nPopulação: %d.\n", populacao_2);
    printf("\nArea do Município: %.2f.\n", area_2);
    printf("\nPIB do Município: %.2f.\n", pib_2);
    printf("\nPontos Turísticos: %d.\n", p_turistico_2);

    return 0;

}