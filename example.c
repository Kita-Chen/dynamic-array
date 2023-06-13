#include <stdio.h>
#include <string.h>

#include "dynamic_array/src/dynamic_array.h"

int main() {
  FILE* file = fopen("file.txt", "r");
  if (!file) {
    return 1;
  }

  char_dynamic_array_t* buf = create_char_dynamic_array();
  char small_buf[5];
  while (fgets(small_buf, sizeof(small_buf), file) && !feof(file)) {
    push_back_s(buf, small_buf);
  }
  push_back_c(buf, '\0');
  printf("%s", buf->arr);

  delete_char_dynamic_array(buf);
  fclose(file);
  return 0;
}
