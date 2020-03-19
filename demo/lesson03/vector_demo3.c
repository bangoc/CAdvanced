#include <string.h>

#include "c-vector/cvector.h"
#include "DebugPrintf/debug_printf.h"

typedef struct {
  char *name;
  char *phone;
} NamePhone2;

int main(int argc, char* argv[]) {
  cvector_vector_type(NamePhone2) v_s2 = NULL;

  NamePhone2 tmp = {.name = "Nguyen Van A", .phone = "(+84) 977799999"};
  cvector_push_back(v_s2, tmp);  // ?
  tmp = (NamePhone2){.name = "Nguyen Thi B", .phone = "(+84) 987799999"};
  cvector_push_back(v_s2, tmp);
  for (int i = 0; i < cvector_size(v_s2); ++i) {
    printfDebug("name: %s", v_s2[i].name);
    printfDebug("phone: %s", v_s2[i].phone);
  }

  char* danger = "Very dangerous";
  tmp = (NamePhone2){.name = (char*)malloc(strlen(danger) + 1), .phone = "Don't know"};
  strcpy(tmp.name, danger);
  cvector_push_back(v_s2, tmp);
  for (int i = 0; i < cvector_size(v_s2); ++i) {
    printfDebug("name: %s", v_s2[i].name);
    printfDebug("phone: %s", v_s2[i].phone);
  }

  // free(tmp.name);

  // for (int i = 0; i < cvector_size(v_s2); ++i) {
  //   printfDebug("name: %s", v_s2[i].name);
  //   printfDebug("phone: %s", v_s2[i].phone);
  // }

  // giải phóng bộ nhớ
  // for (int i = 0; i < cvector_size(v_s2); ++i) {
  //   free(v_s2[i].name);
  //   free(v_s2[i].phone);
  // }
  // cvector_free(v_s2);

  return 0;
}