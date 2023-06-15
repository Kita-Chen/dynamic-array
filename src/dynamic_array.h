#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct dynamic_array {
  void* arr;
  int size;
  int capacity;
  size_t cast_size;
} dynamic_array_t;

dynamic_array_t* create_dynamic_array(size_t cast_size) {
  dynamic_array_t* dynamic_array = malloc(sizeof(dynamic_array_t));
  dynamic_array->size = 0;
  dynamic_array->capacity = 3;
  dynamic_array->arr = malloc(sizeof(cast_size) * dynamic_array->capacity);
  dynamic_array->cast_size = cast_size;
  return dynamic_array;
}

void delete_dynamic_array(dynamic_array_t* dynamic_array) {
  free(dynamic_array->arr);
  free(dynamic_array);
}

void push(dynamic_array_t* self, void* element) {
  assert(self->size <= self->capacity);
  if (self->size >= self->capacity) {
    self->capacity *= 2;
    self->arr = realloc(self->arr, sizeof(char) * self->capacity);
  }
  memcpy((uint8_t*)self->arr + self->cast_size * self->size, element, self->cast_size);
  self->size++;
}

void extend(dynamic_array_t* self, void** elements, int num_of_elements) {
  for(int i = 0; i < num_of_elements; i++) {
    push(self, *elements);
    elements++;
  }
}
