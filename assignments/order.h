#ifndef ORDER_H_
#define ORDER_H_

typedef struct {
  char *dat;
  unsigned int len;
} Bytes;

typedef struct {
    char *name;  // giả sử độ dài của name không vượt quá 255
    int total;
} Order;

/*
  chuyển đổi một bản ghi Order thành một dãy bytes có đánh dấu độ dài
    + không lưu ký tự kết thúc chuỗi (ký tự \0) của name
    + lưu total dưới dạng chuỗi, ví dụ: 123 thì lưu như
      chuỗi dài 3 ký tự.
*/
Bytes *serialize(Order *o);

/*
  tạo một bản ghi Order từ một dãy bytes
*/
Order *deserialize(Bytes *buff);


#endif  // ORDER_H_