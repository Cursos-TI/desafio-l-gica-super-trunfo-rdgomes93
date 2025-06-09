#include <stdio.h>
#include <string.h>  

int main(){
    
    char estado1;
    char codigoCarta1[5];
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    printf("--- Cadastro da Carta 1 ---\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", codigoCarta1);
    
    printf("Nome da Cidade: ");
    int c; 
    while ((c = getchar()) != '\n' && c != EOF); 
    fgets(nomeCidade1, sizeof(nomeCidade1), stdin);
    nomeCidade1[strcspn(nomeCidade1, "\n")] = 0;

    printf("Populacao: ");
    scanf("%d", &populacao1);

    printf("Area (em km^2): ");
    scanf("%f", &area1);

    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);
    
    printf("\n"); 

    char estado2;
    char codigoCarta2[5];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    float pontosTuristicos2;

    printf("--- Cadastro da Carta 2 ---\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2); 
    
    printf("Codigo da Carta (ex: A01): ");
    scanf("%s", codigoCarta2);
    
    printf("Nome da Cidade: ");
    while ((c = getchar()) != '\n' && c != EOF);
    fgets(nomeCidade2, sizeof(nomeCidade2), stdin);
    nomeCidade2[strcspn(nomeCidade2, "\n")] = 0;

    printf("Populacao: ");
    scanf("%d", &populacao2);

    printf("Area (em km^2): ");
    scanf("%f", &area2);

    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Numero de Pontos Turisticos: ");
    scanf("%f", &pontosTuristicos2);
    
    printf("\n"); 

    printf("--- Carta 1 Cadastrada ---\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigoCarta1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km^2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("\n");

    printf("--- Carta 2 Cadastrada ---\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigoCarta2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km^2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %f\n", pontosTuristicos2);
    printf("\n");

    float densidadePopulacional1 = 0.0;
    float pibPerCapita1 = 0.0;
    if (area1 > 0) { // Evita divisão por zero
        densidadePopulacional1 = (float)populacao1 / area1;
    }
    if (populacao1 > 0) { // Evita divisão por zero
        pibPerCapita1 = pib1 / (float)populacao1; // Converte para float para garantir divisão float
    }

    float densidadePopulacional2 = 0.0;
    float pibPerCapita2 = 0.0;
    if (area2 > 0) { // Evita divisão por zero
        densidadePopulacional2 = (float)populacao2 / area2;
    }
    if (populacao2 > 0) { // Evita divisão por zero
        pibPerCapita2 = pib2 / (float)populacao2;
    }

    printf("--- Estatisticas Calculadas ---\n");
    printf("Carta 1 - %s:\n", nomeCidade1);
    printf("  Densidade Populacional: %.2f hab/km^2\n", densidadePopulacional1);
    printf("  PIB per Capita: %.2f bilhoes/hab\n", pibPerCapita1);
    printf("Carta 2 - %s:\n", nomeCidade2);
    printf("  Densidade Populacional: %.2f hab/km^2\n", densidadePopulacional2);
    printf("  PIB per Capita: %.2f bilhoes/hab\n", pibPerCapita2);
    printf("\n");

   
    const char* atributoComparacao = "População"; // Exemplo: Comparar por População

    printf("--- Comparacao de Cartas (Atributo: %s) ---\n", atributoComparacao);


    float valorCarta1 = 0.0;
    float valorCarta2 = 0.0;
    
    
    int assumeMAIOR = 1;

    if (strcmp(atributoComparacao, "População") == 0) {
        valorCarta1 = (float)populacao1;
        valorCarta2 = (float)populacao2;
        assumeMAIOR = 1; 
    } else if (strcmp(atributoComparacao, "Area") == 0) {
        valorCarta1 = area1;
        valorCarta2 = area2;
        assumeMAIOR = 1;
    } else if (strcmp(atributoComparacao, "PIB") == 0) {
        valorCarta1 = pib1;
        valorCarta2 = pib2;
        assumeMAIOR = 1;
    } else if (strcmp(atributoComparacao, "Numero de Pontos Turisticos") == 0) {
        valorCarta1 = (float)pontosTuristicos1;
        valorCarta2 = (float)pontosTuristicos2;
        assumeMAIOR = 1; 
    } else if (strcmp(atributoComparacao, "Densidade Populacional") == 0) {
        valorCarta1 = densidadePopulacional1;
        valorCarta2 = densidadePopulacional2;
        assumeMAIOR = 0;
    } else if (strcmp(atributoComparacao, "PIB per Capita") == 0) {
        valorCarta1 = pibPerCapita1;
        valorCarta2 = pibPerCapita2;
        assumeMAIOR = 1; 
    } else {
        printf("Atributo de comparacao invalido. Nao foi possivel determinar o vencedor.\n");
        return 1; 
    }

    printf("Carta 1 - %s (%s): %.2f\n", nomeCidade1, codigoCarta1, valorCarta1);
    printf("Carta 2 - %s (%s): %.2f\n", nomeCidade2, codigoCarta2, valorCarta2);

    if (valorCarta1 == valorCarta2) {
        printf("Resultado: Empate!\n");
    } else if ((assumeMAIOR && valorCarta1 > valorCarta2) || (!assumeMAIOR && valorCarta1 < valorCarta2)) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    }

    return 0;
}