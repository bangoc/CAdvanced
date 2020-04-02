#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jrb.h"
#include "fields.h"

int main(int argc, char* argv[])
{
  JRB b;
  JRB bn;
  IS is;

  if (argc < 2) {
    printf("Usage: ./p 'cat data.txt'\n");
    return 1;
  }

  is = pipe_inputstruct(argv[1]);
  b = make_jrb();

  while (get_line(is) >= 0) {
    (void) jrb_insert_str(b, strdup(is->text1), new_jval_v(NULL));
  }

  jrb_traverse(bn, b) {
    printf("%s", jval_s(bn->key));
  }
  exit(0);
}