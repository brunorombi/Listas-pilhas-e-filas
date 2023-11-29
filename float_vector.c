#include "float_vector.h"
#include <stdlib.h>
#include <stdio.h>

FloatVector *create(int capacity) {
    FloatVector *vec = (FloatVector *)calloc(1, sizeof(FloatVector));
    if (vec == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    vec->capacity = capacity;
    vec->size = 0;
    vec->data = (float *)calloc(capacity, sizeof(float));
    if (vec->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    return vec;
}

void destroy(FloatVector **vec_ref) {
    FloatVector *vec = *vec_ref;

    free(vec->data);
    free(vec);
    *vec_ref = NULL;
}

void append(FloatVector *vec, float val) {
    if (vec->size < vec->capacity) {
        vec->data[vec->size] = val;
        vec->size++;
    } else {
        printf("O vetor está cheio\n");
        exit(EXIT_FAILURE);
    }
}

float at(const FloatVector *vec, int index) {
    return vec->data[index];
}

float get(const FloatVector *vec, int index) {
    if (index < 0 || index >= vec->size) {
        printf("Erro: Índice fora dos limites\n");
        exit(EXIT_FAILURE);
    } else {
        return vec->data[index];
    }
}

void set(FloatVector *vec, int index, float val) {
    if (index < 0 || index >= vec->capacity) {
        printf("Erro: Índice fora dos limites\n");
        exit(EXIT_FAILURE);
    } else {
        vec->data[index] = val;
    }
}

int size(const FloatVector *vec) {
    return vec->size;
}

void print(const FloatVector *vec) {
    for (int i = 0; i < vec->size; i++) {
        printf("vetor[%d] = %f\n", i, vec->data[i]);
    }
}

int capacity(const FloatVector *vec) {
    return vec->capacity;
}