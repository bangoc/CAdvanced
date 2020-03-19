#include <string.h>

#include "c-vector/cvector.h"
#include "DebugPrintf/debug_printf.h"

typedef struct {
  char *name;
  char *phone;
} Contact;

Contact createContact(const char* name, const char* phone) {
  Contact c;
  c.name = (char*)malloc(strlen(name) + 1);
  strcpy(c.name, name);
  c.phone = (char*)malloc(strlen(phone) + 1);
  strcpy(c.phone, phone);
  return c;
}

Contact* searchContact(const char* name, Contact *v) {
  for (int i = 0; i < cvector_size(v); ++i) {
    if (strcmp(name, v[i].name) == 0) {
      return v + i;
    }
  }
  return NULL;
}

int main(int argc, char* argv[]) {
  cvector_vector_type(Contact) cv = NULL;
  cvector_push_back(cv, createContact("Nguyen Van A", "(+84) 977799999"));
  cvector_push_back(cv, createContact("Nguyen Thi B", "(+84) 987799999"));
  for (int i = 0; i < cvector_size(cv); ++i) {
    printfDebug("name: %s", cv[i].name);
    printfDebug("phone: %s", cv[i].phone);
  }
  char *tests[] = {"Nguyen Van A", "Nguyen Van B"};
  for (int i = 0; i < 2; ++i) {
    Contact *c = NULL;
    if ((c = searchContact(tests[i], cv))) {
      printfInfo("Found %s:%s", c->name, c->phone);
    } else {
      printfError("Not found %s", tests[i]);
    }
  }

  // giải phóng bộ nhớ
  for (int i = 0; i < cvector_size(cv); ++i) {
    free(cv[i].name);
    free(cv[i].phone);
  }
  cvector_free(cv);
  return 0;
}