#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
    int forca;
    int inteligencia;
    int velocidade;
    int resistencia;
} Carta;


void mostrarCarta(Carta c) {
    printf("\n=== Carta: %s ===\n", c.nome);
    printf("Força: %d\n", c.forca);
    printf("Inteligência: %d\n", c.inteligencia);
    printf("Velocidade: %d\n", c.velocidade);
    printf("Resistência: %d\n", c.resistencia);
}


void compararSimples(Carta c1, Carta c2) {
    printf("\n[ MÓDULO 1 - Comparação Simples (força) ]\n");
    if (c1.forca > c2.forca)
        printf("%s venceu! (%d > %d)\n", c1.nome, c1.forca, c2.forca);
    else if (c2.forca > c1.forca)
        printf("%s venceu! (%d > %d)\n", c2.nome, c2.forca, c1.forca);
    else
        printf("Empate! (%d = %d)\n", c1.forca, c2.forca);
}

void compararAvancado(Carta c1, Carta c2) {
    int opcao;
    printf("\n[ MÓDULO 2 - Comparação Avançada ]\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1. Força\n");
    printf("2. Inteligência\n");
    printf("3. Velocidade\n");
    printf("4. Resistência\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            if (c1.forca > c2.forca)
                printf("%s venceu na força!\n", c1.nome);
            else if (c2.forca > c1.forca)
                printf("%s venceu na força!\n", c2.nome);
            else
                printf("Empate na força!\n");
            break;

        case 2:
            if (c1.inteligencia > c2.inteligencia)
                printf("%s venceu na inteligência!\n", c1.nome);
            else if (c2.inteligencia > c1.inteligencia)
                printf("%s venceu na inteligência!\n", c2.nome);
            else
                printf("Empate na inteligência!\n");
            break;

        case 3:
            if (c1.velocidade > c2.velocidade)
                printf("%s venceu na velocidade!\n", c1.nome);
            else if (c2.velocidade > c1.velocidade)
                printf("%s venceu na velocidade!\n", c2.nome);
            else
                printf("Empate na velocidade!\n");
            break;

        case 4:
            if (c1.resistencia > c2.resistencia)
                printf("%s venceu na resistência!\n", c1.nome);
            else if (c2.resistencia > c1.resistencia)
                printf("%s venceu na resistência!\n", c2.nome);
            else
                printf("Empate na resistência!\n");
            break;

        default:
            printf("Opção inválida!\n");
    }
}

void compararTernario(Carta c1, Carta c2) {
    printf("\n[ MÓDULO 3 - Comparação com Operador Ternário ]\n");

    int soma1 = c1.forca + c1.velocidade;
    int soma2 = c2.forca + c2.velocidade;

    printf("%s (Força + Velocidade): %d\n", c1.nome, soma1);
    printf("%s (Força + Velocidade): %d\n", c2.nome, soma2);

    (soma1 > soma2) ? 
        printf("%s venceu com melhor combinação de atributos!\n", c1.nome) :
        (soma2 > soma1) ?
            printf("%s venceu com melhor combinação de atributos!\n", c2.nome) :
            printf("Empate técnico!\n");
}

int main() {
    Carta carta1 = {"Dragão Vermelho", 90, 70, 60, 80};
    Carta carta2 = {"Fênix Dourada", 85, 90, 75, 70};

    int opcao;
    do {
        printf("\n=== SUPER TRUNFO - TECHNOVA ===\n");
        printf("1. Mostrar cartas\n");
        printf("2. Comparar atributo simples (if / if-else)\n");
        printf("3. Comparar com menu (switch + if encadeado)\n");
        printf("4. Comparar dois atributos (ternário)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                mostrarCarta(carta1);
                mostrarCarta(carta2);
                break;
            case 2:
                compararSimples(carta1, carta2);
                break;
            case 3:
                compararAvancado(carta1, carta2);
                break;
            case 4:
                compararTernario(carta1, carta2);
                break;
            case 0:
                printf("Encerrando o jogo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
