#include <assert.h>
#include <stdio.h>

#include "../src/dynamic_array.h"

void test_push_back_c() {
  char_dynamic_array_t* dynamic_array = create_char_dynamic_array();

  push_back_c(dynamic_array, 'a');
  push_back_c(dynamic_array, 'b');
  push_back_c(dynamic_array, 'c');

  assert(dynamic_array->size == 3);
  assert(dynamic_array->arr[0] == 'a');
  assert(dynamic_array->arr[1] == 'b');
  assert(dynamic_array->arr[2] == 'c');

  delete_char_dynamic_array(dynamic_array);
}

void test_push_back_c_more_than_capacity() {
  char_dynamic_array_t* dynamic_array = create_char_dynamic_array();

  push_back_c(dynamic_array, 'a');
  push_back_c(dynamic_array, 'b');
  push_back_c(dynamic_array, 'c');
  push_back_c(dynamic_array, 'd');

  assert(dynamic_array->size == 4);
  assert(dynamic_array->arr[0] == 'a');
  assert(dynamic_array->arr[1] == 'b');
  assert(dynamic_array->arr[2] == 'c');
  assert(dynamic_array->arr[3] == 'd');

  delete_char_dynamic_array(dynamic_array);
}

void test_push_back_s() {
  char_dynamic_array_t* dynamic_array = create_char_dynamic_array();

  push_back_s(dynamic_array, "abcd");

  assert(dynamic_array->size == 4);
  assert(dynamic_array->arr[0] == 'a');
  assert(dynamic_array->arr[1] == 'b');
  assert(dynamic_array->arr[2] == 'c');
  assert(dynamic_array->arr[3] == 'd');

  delete_char_dynamic_array(dynamic_array);
}

int main() {
  test_push_back_c();
  test_push_back_c_more_than_capacity();
  test_push_back_s();
  printf("All passed!\n");
  return 0;
}
