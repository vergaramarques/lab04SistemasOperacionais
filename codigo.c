#include <stdio.h>
#include <stdlib.h>

struct reg {
    int conteudo;
    struct reg *prox;
};

typedef struct reg celula;

// Função para imprimir os valores da lista
void imprimirLista(celula *cabeca) {
    celula *atual = cabeca;
    while (atual != NULL) {
        printf("%d ", atual->conteudo);
        atual = atual->prox;
    }
    printf("\n");
}

// Função para calcular a quantidade de memória gasta por uma instância de célula
size_t calcularMemoriaGasta() {
    return sizeof(celula);
}

// Função para remover os elementos da lista e liberar a memória
void removerElementos(celula *cabeca) {
    celula *atual = cabeca;
    while (atual != NULL) {
        celula *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

int main() {
    celula *cabeca = NULL;
    celula *atual = NULL;
    int i;

    // Criar três instâncias do objeto célula (três valores na lista)
    for (i = 1; i <= 3; i++) {
        celula *nova_celula = (celula *)malloc(sizeof(celula));
        nova_celula->conteudo = i;
        nova_celula->prox = NULL;
        if (cabeca == NULL) {
            cabeca = nova_celula;
            atual = nova_celula;
        } else {
            atual->prox = nova_celula;
            atual = nova_celula;
        }
    }

    // Imprimir os valores da lista
    imprimirLista(cabeca);

    // Calcular a quantidade de memória gasta por uma instância de célula
    size_t memoria_gasta = calcularMemoriaGasta();
    printf("Memória gasta por uma instância de célula: %lu bytes\n", memoria_gasta);

    // Remover os elementos da lista e liberar a memória
    removerElementos(cabeca);

    // Calcular o máximo de elementos possíveis na lista considerando a memória disponível
    size_t memoria_disponivel = 1024 * 1024; // Suponha 1 MB de memória disponível
    int max_elementos = memoria_disponivel / memoria_gasta;
    printf("Máximo de elementos possíveis na lista: %d\n", max_elementos);

    return 0;
}
