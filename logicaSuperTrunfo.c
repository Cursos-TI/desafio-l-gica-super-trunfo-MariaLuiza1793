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

// Função para exibir o menu com exclusão de uma opção
void exibirMenu(int excluir) {
    printf("Escolha o atributo para comparar:\n");
    if (excluir != 1) printf("1 - População\n");
    if (excluir != 2) printf("2 - Área\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Número de Pontos Turísticos\n");
    if (excluir != 5) printf("5 - Densidade Populacional\n");
    if (excluir != 6) printf("6 - PIB per Capita\n");
    printf("Digite sua escolha: ");
}

// Função para obter o valor do atributo escolhido
float obterValorAtributo(struct Cidade cidade, int atributo) {
    switch (atributo) {
        case 1: return cidade.populacao;
        case 2: return cidade.area;
        case 3: return cidade.pib;
        case 4: return cidade.pontosTuristicos;
        case 5: return cidade.densidadePopulacional;
        case 6: return cidade.pibPerCapita;
        default: return 0;
    }
}

// Função para obter o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per Capita";
        default: return "";
    }
}

int main() {
    // Cartas
    struct Cidade cidade1 = {"C01", "Rio de Janeiro", 6748000, 1182.3, 364.5, 25, 0.0, 0.0};
    struct Cidade cidade2 = {"C02", "Salvador", 2887000, 693.8, 85.2, 18, 0.0, 0.0};

    // Cálculo
    cidade1.densidadePopulacional = cidade1.populacao / cidade1.area;
    cidade2.densidadePopulacional = cidade2.populacao / cidade2.area;
    cidade1.pibPerCapita = (cidade1.pib * 1000000000) / cidade1.populacao;
    cidade2.pibPerCapita = (cidade2.pib * 1000000000) / cidade2.populacao;

    int atributo1, atributo2;

    printf("\n=== Super Trunfo de Cidades ===\n");
    
    // Escolha do primeiro atributo
    exibirMenu(0);
    scanf("%d", &atributo1);

    // Escolha do segundo atributo, sem repetir o primeiro
    do {
        printf("\nEscolha um segundo atributo (diferente do primeiro):\n");
        exibirMenu(atributo1);
        scanf("%d", &atributo2);
        if (atributo2 == atributo1) {
            printf("Atributo repetido! Escolha outro diferente.\n");
        }
    } while (atributo2 == atributo1);

    // Obtenção de valores
    float valor1_attr1 = obterValorAtributo(cidade1, atributo1);
    float valor2_attr1 = obterValorAtributo(cidade2, atributo1);
    float valor1_attr2 = obterValorAtributo(cidade1, atributo2);
    float valor2_attr2 = obterValorAtributo(cidade2, atributo2);

    // Comparações individuais (com regras específicas para densidade)
    float score1 = 0, score2 = 0;

    printf("\nComparando %s e %s\n", cidade1.nome, cidade2.nome);

    // Comparar primeiro atributo
    printf("\nAtributo 1: %s\n", nomeAtributo(atributo1));
    printf("%s: %.2f\n", cidade1.nome, valor1_attr1);
    printf("%s: %.2f\n", cidade2.nome, valor2_attr1);
    if (atributo1 == 5) { // Regra invertida para densidade
        score1 += (valor1_attr1 < valor2_attr1) ? valor1_attr1 : 0;
        score2 += (valor2_attr1 < valor1_attr1) ? valor2_attr1 : 0;
    } else {
        score1 += valor1_attr1;
        score2 += valor2_attr1;
    }

    // Comparar segundo atributo
    printf("\nAtributo 2: %s\n", nomeAtributo(atributo2));
    printf("%s: %.2f\n", cidade1.nome, valor1_attr2);
    printf("%s: %.2f\n", cidade2.nome, valor2_attr2);
    if (atributo2 == 5) {
        score1 += (valor1_attr2 < valor2_attr2) ? valor1_attr2 : 0;
        score2 += (valor2_attr2 < valor1_attr2) ? valor2_attr2 : 0;
    } else {
        score1 += valor1_attr2;
        score2 += valor2_attr2;
    }

    // Mostrar somas
    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", cidade1.nome, score1);
    printf("%s: %.2f\n", cidade2.nome, score2);

    // Resultado final
    printf("\nResultado final:\n");
    if (score1 > score2)
        printf("%s venceu!\n", cidade1.nome);
    else if (score2 > score1)
        printf("%s venceu!\n", cidade2.nome);
    else
        printf("Empate!\n");

    return 0;
}

