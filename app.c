#include "float_vector.h"
#include <stdio.h>

int main() {
    // Criar um vetor com capacidade 5
    FloatVector *vec = FloatVector_create(5);

    // Adicionar elementos ao vetor
    FloatVector_append(vec, 1.0);
    FloatVector_append(vec, 2.5);
    FloatVector_append(vec, 3.7);

    // Imprimir o tamanho do vetor
    printf("Tamanho do vetor: %d\n", FloatVector_size(vec));

    // Imprimir os elementos do vetor
    FloatVector_print(vec);

    // Remover e imprimir
    FloatVector_remove(vec, 1);
    puts("**************************");
    FloatVector_print(vec);

    // Apagar e imprimir
    //FloatVector_erase(vec);
    //FloatVector_print(vec);

    // Clonar o vetor e imprimir o clone
    FloatVector *vec_clone = FloatVector_clone(vec);
    puts("**************************");
    FloatVector_print(vec_clone);

    // Imprimir o tamanho do vetor clone
    printf("Tamanho do vetor clone: %d\n", FloatVector_size(vec_clone));

    // Liberar a memória alocada pelos vetores
    FloatVector_destroy(&vec);
    FloatVector_destroy(&vec_clone);

    return 0;
}
