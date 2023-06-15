#include <assert.h>
#include <stdio.h>

#include "../src/dynamic_array.h"

void test_push() {
  dynamic_array_t *dynamic_array = create_dynamic_array(sizeof(char));
  char a = 'a';
  char b = 'b';
  char c = 'c';
  push(dynamic_array, &a);
  push(dynamic_array, &b);
  push(dynamic_array, &c);

  assert(dynamic_array->size == 3);
  assert(((char *)dynamic_array->arr)[0] == 'a');
  assert(((char *)dynamic_array->arr)[1] == 'b');
  assert(((char *)dynamic_array->arr)[2] == 'c');

  delete_dynamic_array(dynamic_array);
}

void test_extend() {
  dynamic_array_t *dynamic_array = create_dynamic_array(sizeof(char));
  char *str = "abcd";
  void *str2[4] = {&str[0], &str[1], &str[2], &str[3]};
  extend(dynamic_array, str2, sizeof(str2) / sizeof(void *));

  assert(dynamic_array->size == 4);
  assert(((char *)dynamic_array->arr)[0] == 'a');
  assert(((char *)dynamic_array->arr)[1] == 'b');
  assert(((char *)dynamic_array->arr)[2] == 'c');
  assert(((char *)dynamic_array->arr)[3] == 'd');

  delete_dynamic_array(dynamic_array);
}

typedef struct point {
  int x;
  int y;
} point_t;

void test_push_point() {
  dynamic_array_t *dynamic_array = create_dynamic_array(sizeof(point_t));
  point_t point1 = {.x = 1, .y = 2};
  point_t point2 = {.x = 3, .y = 4};
  push(dynamic_array, &point1);
  push(dynamic_array, &point2);

  assert(dynamic_array->size == 2);
  assert(((point_t *)dynamic_array->arr)[0].x == 1);
  assert(((point_t *)dynamic_array->arr)[0].y == 2);
  assert(((point_t *)dynamic_array->arr)[1].x == 3);
  assert(((point_t *)dynamic_array->arr)[1].y == 4);

  delete_dynamic_array(dynamic_array);
}

void test_extend_point() {
  dynamic_array_t *dynamic_array = create_dynamic_array(sizeof(point_t));
  point_t point1 = {.x = 1, .y = 2};
  point_t point2 = {.x = 3, .y = 4};
  int num_of_point = 2;
  void* point[] = {&point1, &point2};
  extend(dynamic_array, point, num_of_point);

  assert(dynamic_array->size == 2);
  assert(((point_t *)dynamic_array->arr)[0].x == 1);
  assert(((point_t *)dynamic_array->arr)[0].y == 2);
  assert(((point_t *)dynamic_array->arr)[1].x == 3);
  assert(((point_t *)dynamic_array->arr)[1].y == 4);

  delete_dynamic_array(dynamic_array);
}

int main() {
  test_push();
  test_extend();
  test_push_point();
  test_extend_point();
  printf("All passed!\n");
  return 0;
}
