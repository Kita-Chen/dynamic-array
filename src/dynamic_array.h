#include <assert.h>
#include <stdlib.h>

typedef struct char_dynamic_array {
  char* arr;
  int size;
  int capacity;
} char_dynamic_array_t;

char_dynamic_array_t* create_char_dynamic_array() {
  char_dynamic_array_t* dynamic_array = malloc(sizeof(char_dynamic_array_t));
  dynamic_array->size = 0;
  dynamic_array->capacity = 3;
  dynamic_array->arr = malloc(sizeof(char) * dynamic_array->capacity);
  return dynamic_array;
}

void delete_char_dynamic_array(char_dynamic_array_t* dynamic_array) {
  free(dynamic_array->arr);
  free(dynamic_array);
}

void push_back_c(char_dynamic_array_t* self, char c) {
  assert(self->size <= self->capacity);
  if (self->size >= self->capacity) {
    self->capacity *= 2;
    self->arr = realloc(self->arr, sizeof(char) * self->capacity);
  }
  self->arr[self->size] = c;
  self->size++;
}

void push_back_s(char_dynamic_array_t* self, char* str) {
  while (*str) {
    push_back_c(self, *str);
    str++;
  }
}
