#ifndef CJSET_H_
#define CJSET_H_

#include "libfdr/jrb.h"

// tìm nút theo key, nếu đã có thì trả về 0,
//    nếu ngược lại thì thêm vào và trả về 1
//
// trong trường hợp thêm vào thì jset tự tạo bản sao của key
extern int jset_insert_str(JRB tree, char *key, Jval val);

// tìm nút theo key, nếu tìm thấy thì cập nhật giá trị mới và trả về 1,
//      nếu ngược lại thì trả về 0
extern int jset_update_str(JRB tree, char *key, Jval val);

// trả về kích thước tập hợp
extern int jset_size(JRB tree);

#endif  // CJSET_H_