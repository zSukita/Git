#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constantes de conversao
#define W_TO_KW 0.001
#define W_TO_CV 0.00136
#define W_TO_HP 0.00134102
#define KW_TO_W 1000.0
#define CV_TO_W 735.499
#define HP_TO_W 745.7

// Enumeracao para unidades de potencia
typedef enum {
    WATTS = 1,
    KILOWATTS,
    CV,
    HP,
    SAIR = 0
} UnidadePotencia;

// Estrutura para armazenar os fatores de conversao
typedef struct {
    double fator;
    const char* unidade;
} FatorConversao;

// Funcao para limpar o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Funcao para exibir o menu
void exibirMenu(const char* titulo) {
    printf("\n=== %s ===\n", titulo);
    printf("1 - Watts (W)\n");
    printf("2 - Quilowatts (kW)\n");
    printf("3 - Cavalos-vapor (CV)\n");
    printf("4 - Horse Power (HP)\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

// Funcao para validar entrada
bool entradaValida(int opcao) {
    return (opcao >= 0 && opcao <= 4);
}

// Funcao para obter input do usuario com validacao
int obterOpcao(const char* titulo) {
    int opcao;
    do {
        exibirMenu(titulo);
        if (scanf("%d", &opcao) != 1) {
            limparBuffer();
            printf("Entrada invalida! Digite um numero.\n");
            continue;
        }
        limparBuffer();
        
        if (!entradaValida(opcao)) {
            printf("Opcao invalida! Escolha entre 0 e 4.\n");
        }
    } while (!entradaValida(opcao));
    
    return opcao;
}

// Funcao para obter valor com validacao
double obterValor() {
    double valor;
    bool entradaValida = false;
    
    do {
        printf("Digite o valor a ser convertido: ");
        if (scanf("%lf", &valor) != 1) {
            limparBuffer();
            printf("Entrada invalida! Digite um numero.\n");
            continue;
        }
        limparBuffer();
        
        if (valor < 0) {
            printf("Por favor, digite um valor positivo.\n");
            continue;
        }
        entradaValida = true;
    } while (!entradaValida);
    
    return valor;
}

// Funcao para converter potencia
void converterPotencia(double valor, UnidadePotencia entrada, UnidadePotencia saida) {
    if (entrada == saida) {
        printf("Resultado: %.4f (mesma unidade)\n", valor);
        return;
    }

    // Tabela de conversao para Watts
    const FatorConversao paraWatts[] = {
        {1.0, "W"},           // WATTS
        {KW_TO_W, "W"},       // KILOWATTS
        {CV_TO_W, "W"},       // CV
        {HP_TO_W, "W"}        // HP
    };

    // Tabela de conversao de Watts
    const FatorConversao deWatts[] = {
        {1.0, "W"},                    // WATTS
        {W_TO_KW, "kW"},              // KILOWATTS
        {W_TO_CV, "CV"},              // CV
        {W_TO_HP, "HP"}               // HP
    };

    // Primeiro converte para Watts, depois para a unidade desejada
    double valorEmWatts = valor * paraWatts[entrada - 1].fator;
    double resultado = valorEmWatts * deWatts[saida - 1].fator;

    printf("%.4f %s = %.4f %s\n", 
           valor, deWatts[entrada - 1].unidade,
           resultado, deWatts[saida - 1].unidade);
}

int main() {
    printf("### Conversor de Potencia ###\n");
    
    while (true) {
        UnidadePotencia unidadeEntrada = obterOpcao("Unidade de Entrada");
        if (unidadeEntrada == SAIR) break;

        double valor = obterValor();

        UnidadePotencia unidadeSaida = obterOpcao("Unidade de Saida");
        if (unidadeSaida == SAIR) break;

        converterPotencia(valor, unidadeEntrada, unidadeSaida);
        
        printf("\nPressione Enter para continuar...");
        getchar();
    }

    printf("\nPrograma encerrado. Obrigado!\n");
    return 0;
}
