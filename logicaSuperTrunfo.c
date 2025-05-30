#include <stdio.h>

// Definição da struct Cidade
struct Cidade {
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos; 
    float densidadePopulacional;
    float pibPerCapita;
};

int main() {
    // Carta 1 - Rio de Janeiro
    struct Cidade cidade1 = {
        "C01",
        "Rio de Janeiro",
        6748000,
        1182.3,
        364.5,
        25,
        0.0,
        0.0
    };

    // Carta 2 - Salvador
    struct Cidade cidade2 = {
        "C02",
        "Salvador",
        2887000,
        693.8,
        85.2,
        18,
        0.0,
        0.0
    };

    // Calculando densidade populacional e PIB per capita para cidade1
    cidade1.densidadePopulacional = cidade1.populacao / cidade1.area;
    cidade1.pibPerCapita = (cidade1.pib * 1000000000) / cidade1.populacao;

    // Calculando densidade populacional e PIB per capita para cidade2
    cidade2.densidadePopulacional = cidade2.populacao / cidade2.area;
    cidade2.pibPerCapita = (cidade2.pib * 1000000000) / cidade2.populacao;

    // Exibindo carta 1
    printf("\n--- Carta 1 ---\n");
    printf("Código: %s\n", cidade1.codigo);
    printf("Nome da Cidade: %s\n", cidade1.nome);
    printf("População: %d\n", cidade1.populacao);
    printf("Área: %.2f km²\n", cidade1.area);
    printf("PIB: %.2f bilhões de reais\n", cidade1.pib);
    printf("Número de Pontos Turísticos: %d\n", cidade1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", cidade1.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", cidade1.pibPerCapita);

    // Exibindo carta 2
    printf("\n--- Carta 2 ---\n");
    printf("Código: %s\n", cidade2.codigo);
    printf("Nome da Cidade: %s\n", cidade2.nome);
    printf("População: %d\n", cidade2.populacao);
    printf("Área: %.2f km²\n", cidade2.area);
    printf("PIB: %.2f bilhões de reais\n", cidade2.pib);
    printf("Número de Pontos Turísticos: %d\n", cidade2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", cidade2.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", cidade2.pibPerCapita);

    // Comparação usando PIB per capita
    printf("\nComparação de cartas (Atributo: PIB per Capita):\n");
    printf("Carta 1 - %s: %.2f reais\n", cidade1.nome, cidade1.pibPerCapita);
    printf("Carta 2 - %s: %.2f reais\n", cidade2.nome, cidade2.pibPerCapita);

    if (cidade1.pibPerCapita > cidade2.pibPerCapita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1.nome);
    } else if (cidade2.pibPerCapita > cidade1.pibPerCapita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
