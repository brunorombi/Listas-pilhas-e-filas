#ifndef FLOAT_VECTOR_H
#define FLOAT_VECTOR_H

/******************* INTERFACE PUBLICA **********************/
typedef struct float_vector FloatVector;

FloatVector *FloatVector_create(int capacity);
void FloatVector_destroy(FloatVector **vec_ref);
void FloatVector_append(FloatVector *vec, float val);
float FloatVector_at(const FloatVector *vec, int index);
float FloatVector_get(const FloatVector *vec, int index);
void FloatVector_set(FloatVector *vec, int index, float val);
int FloatVector_size(const FloatVector *vec);
void FloatVector_print(const FloatVector *vec);
int FloatVector_capacity(const FloatVector *vec);
void FloatVector_remove(FloatVector *vec, int index);
void FloatVector_erase(FloatVector *vec);
FloatVector *FloatVector_clone(FloatVector *vec);
/***********************************************************/


#endif 