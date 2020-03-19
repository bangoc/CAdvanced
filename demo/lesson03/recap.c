// Hiển thị bất kỳ kiểu dữ liệu nào

typedef enum {
  int_tag,
  double_tag,
  string_tag
} Tags;

struct {
  Tags tag;
  void (*handler)(void*);
} displays[] = {{int_tag, display_i},
                {double_tag, display_d},
                {string_tag, display_s}};

void display(void *data, Tags tag) {
  int n = sizeof(displays)/sizeof(displays[0]);
  for (int i = 0; i < n; ++i) {
    if (tag == displays[i].tag) {
      displays[i].handler(data);
      break;
    }
  }
}

// Có thể tiếp tục phát triển đếm bất kỳ mảng nào?
typedef int (*predicate_t)(int);

int count_if(int n, int a[], predicate_t p) {
  int cc = 0;
  for (int i = 0; i < n; ++i) {
    if (p(a[i])) {  // Đếm vậy đúng hay sai
      ++cc;
    }
  }
  return cc;
}


// Chi tiết -> Khái quát