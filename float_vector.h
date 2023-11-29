#ifndef FLOAT_VECTOR_H
#define FLOAT_VECTOR_H

typedef struct float_vector {
    int capacity;
    int size;
    float *data;
} FloatVector;

FloatVector *create(int capacity);
void destroy(FloatVector **vec_ref);
void append(FloatVector *vec, float val);
float at(const FloatVector *vec, int index);
float get(const FloatVector *vec, int index);
void set(FloatVector *vec, int index, float val);
int size(const FloatVector *vec);
void print(const FloatVector *vec);
int capacity(const FloatVector *vec);

#endif /* FLOAT_VECTOR_H */
