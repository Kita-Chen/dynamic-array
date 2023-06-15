#include <stdio.h>
#include <string.h>

#include "src/dynamic_array.h"

int main() {
  FILE* file = fopen("file.txt", "r");
  if (!file) {
    return 1;
  }
  

  dynamic_array_t* buf = create_dynamic_array(sizeof(char));
  char small_buf;
  while ((small_buf = fgetc(file)) && !feof(file)) {
    push(buf, &small_buf);
  }
  char c = '\0';
  push(buf, &c);
  printf("%s", (char*)buf->arr);

  delete_dynamic_array(buf);
  fclose(file);
  return 0;
}
