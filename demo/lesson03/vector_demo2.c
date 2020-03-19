#include "c-vector/cvector.h"
#include "DebugPrintf/debug_printf.h"

typedef struct {
  char name[100];
  char phone[20];
} NamePhone;

typedef struct {
  char *name;
  char *phone;
} NamePhone2;

int main() {
  cvector_vector_type(int) v_i = NULL;
  cvector_push_back(v_i, 5);

  cvector_vector_type(float) v_f = NULL;
  cvector_push_back(v_f, 0.999f);

  cvector_vector_type(NamePhone) v_s = NULL;
  NamePhone nva = {.name = "Nguyen Van A", .phone = "(+84) 977799999"};
  cvector_push_back(v_s, nva);

  cvector_vector_type(NamePhone2) v_s2 = NULL;
  NamePhone2 nva2 = {.name = "Nguyen Van A", .phone = "(+84) 977799999"};
  cvector_push_back(v_s2, nva2);  // ?
  printfDebug("name: %s", v_s2[0].name);
  printfDebug("phone: %s", v_s2[0].phone);

  cvector_free(v_i);
  cvector_free(v_f);
  cvector_free(v_s);
  cvector_free(v_s2);  // ??
  return 0;
}