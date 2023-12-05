#include "float_vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/********************************* INTERFACE PRIVADA ***************************/
typedef struct float_vector {
    int capacity;
    int size;
    float *data;
};

//função "privada" ==> não esta disponivel para os usuarios/programas
//ou outros arquivos que usam o float_vector.h
bool _FloatVector_isFull(const FloatVector *vec){
    return vec->size == vec->capacity;
}


/********************************* INTERFACE PUBLICA ***************************/



FloatVector *FloatVector_create(int capacity) {
    FloatVector *vec = (FloatVector *)calloc(1, sizeof(FloatVector));  
    vec->capacity = capacity;
    vec->size = 0;
    vec->data = (float *)calloc(capacity, sizeof(float));
   
    return vec;
}

void FloatVector_destroy(FloatVector **vec_ref) {
    FloatVector *vec = *vec_ref;

    free(vec->data);
    free(vec);
    *vec_ref = NULL;
}

void FloatVector_append(FloatVector *vec, float val) {
    if (_FloatVector_isFull(vec)) {
        printf("O vetor está cheio\n");
        exit(EXIT_FAILURE);
    } else {
        vec->data[vec->size] = val;
        vec->size++;
    }
}

float FloatVector_at(const FloatVector *vec, int index) {
    return vec->data[index];
}

float FloatVector_get(const FloatVector *vec, int index) {
    if (index < 0 || index >= vec->size) {
        printf("Erro: Índice fora dos limites\n");
        exit(EXIT_FAILURE);
    } else {
        return vec->data[index];
    }
}

void FloatVector_set(FloatVector *vec, int index, float val) {
    if (index < 0 || index >= vec->capacity) {
        printf("Erro: Índice fora dos limites\n");
        exit(EXIT_FAILURE);
    } else {
        vec->data[index] = val;
    }
}

int FloatVector_size(const FloatVector *vec) {
    return vec->size;
}

void FloatVector_print(const FloatVector *vec) {
    for (int i = 0; i < vec->size; i++) {
        printf("vetor[%d] = %f\n", i, vec->data[i]);
    }
}

int FloatVector_capacity(const FloatVector *vec) {
    return vec->capacity;
}

void FloatVector_remove(FloatVector *vec, int index) {
    if(index < vec->size && index > -1){
        for(index; index < vec->size - 1; index++) {
            vec->data[index] = vec->data[index + 1];
        }
        vec->size--;
    } else {
        printf("Erro, índice fora dos parametros");
        exit(EXIT_FAILURE);
    }
} 

void FloatVector_erase(FloatVector *vec) {
    for (int i = 0; i <= vec->size; i++) {
        FloatVector_remove(vec, i);
    }
}

FloatVector *FloatVector_clone(FloatVector *vec) {
    FloatVector *vec_clone = FloatVector_create(vec->capacity);
    vec_clone->size = vec->size;

    for(int i = 0; i < vec->size; i++) {
        vec_clone->data[i] = vec->data[i]; 
    }
    return vec_clone;
}


void FloatVector_remove (FloatVector *vec) {
    if (vec->size > 0) {
        free(vec->data[vec->size-1]);
        vec->size--;
    }
    else {
        printf("vetor esta cheio");
        return -1;
    } 
}