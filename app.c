#include "float_vector.h"
#include <stdio.h>

int main() {
    // Criar um vetor com capacidade 5
    FloatVector *vec = create(5);

    // Adicionar elementos ao vetor
    append(vec, 1.0);
    append(vec, 2.5);
    append(vec, 3.7);

    // Imprimir o tamanho do vetor
    printf("Tamanho do vetor: %d\n", size(vec));

    // Imprimir a capacidade do vetor
    printf("Capacidade do vetor: %d\n", capacity(vec));

    // Imprimir os elementos do vetor
    print(vec);

    // Liberar a memória alocada pelo vetor
    destroy(&vec);

    return 0;
}
