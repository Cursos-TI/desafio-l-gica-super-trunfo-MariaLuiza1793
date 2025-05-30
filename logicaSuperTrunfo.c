#include <stdio.h>
#include <string.h>

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

    int escolha;
    printf("\n=== Super Trunfo de Cidades ===\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Número de Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    printf("\nComparando %s e %s\n", cidade1.nome, cidade2.nome);

    switch (escolha) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %d\n", cidade1.nome, cidade1.populacao);
            printf("%s: %d\n", cidade2.nome, cidade2.populacao);
            if (cidade1.populacao > cidade2.populacao)
                printf("Resultado: %s venceu!\n", cidade1.nome);
            else if (cidade2.populacao > cidade1.populacao)
                printf("Resultado: %s venceu!\n", cidade2.nome);
            else
                printf("Resultado: Empate!\n");
            break;

        case 2:
            printf("Atributo: Área (km²)\n");
            printf("%s: %.2f\n", cidade1.nome, cidade1.area);
            printf("%s: %.2f\n", cidade2.nome, cidade2.area);
            if (cidade1.area > cidade2.area)
                printf("Resultado: %s venceu!\n", cidade1.nome);
            else if (cidade2.area > cidade1.area)
                printf("Resultado: %s venceu!\n", cidade2.nome);
            else
                printf("Resultado: Empate!\n");
            break;

        case 3:
            printf("Atributo: PIB (em bilhões)\n");
            printf("%s: %.2f\n", cidade1.nome, cidade1.pib);
            printf("%s: %.2f\n", cidade2.nome, cidade2.pib);
            if (cidade1.pib > cidade2.pib)
                printf("Resultado: %s venceu!\n", cidade1.nome);
            else if (cidade2.pib > cidade1.pib)
                printf("Resultado: %s venceu!\n", cidade2.nome);
            else
                printf("Resultado: Empate!\n");
            break;

        case 4:
            printf("Atributo: Número de Pontos Turísticos\n");
            printf("%s: %d\n", cidade1.nome, cidade1.pontosTuristicos);
            printf("%s: %d\n", cidade2.nome, cidade2.pontosTuristicos);
            if (cidade1.pontosTuristicos > cidade2.pontosTuristicos)
                printf("Resultado: %s venceu!\n", cidade1.nome);
            else if (cidade2.pontosTuristicos > cidade1.pontosTuristicos)
                printf("Resultado: %s venceu!\n", cidade2.nome);
            else
                printf("Resultado: Empate!\n");
            break;

        case 5:
            printf("Atributo: Densidade Populacional (hab/km²)\n");
            printf("%s: %.2f\n", cidade1.nome, cidade1.densidadePopulacional);
            printf("%s: %.2f\n", cidade2.nome, cidade2.densidadePopulacional);
            if (cidade1.densidadePopulacional < cidade2.densidadePopulacional)
                printf("Resultado: %s venceu! (menor densidade)\n", cidade1.nome);
            else if (cidade2.densidadePopulacional < cidade1.densidadePopulacional)
                printf("Resultado: %s venceu! (menor densidade)\n", cidade2.nome);
            else
                printf("Resultado: Empate!\n");
            break;

        case 6:
            printf("Atributo: PIB per Capita (reais)\n");
            printf("%s: %.2f\n", cidade1.nome, cidade1.pibPerCapita);
            printf("%s: %.2f\n", cidade2.nome, cidade2.pibPerCapita);
            if (cidade1.pibPerCapita > cidade2.pibPerCapita)
                printf("Resultado: %s venceu!\n", cidade1.nome);
            else if (cidade2.pibPerCapita > cidade1.pibPerCapita)
                printf("Resultado: %s venceu!\n", cidade2.nome);
            else
                printf("Resultado: Empate!\n");
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
    }

    return 0;
}
