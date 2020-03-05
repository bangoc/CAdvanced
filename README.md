# CAdvanced
Tài nguyên học tập cho khóa CAdvanced

Nên sử dụng lệnh sau để tạo bản sao cùng với các mô-đun con:

```
git clone --recurse-submodules https://github.com/bangoc/CAdvanced.git
```

Một số lệnh thông dụng để làm việc với thẻ:
* Xem danh sách thẻ: ```git tag```
* Sử dụng phiên bản được gán thẻ (để làm bài tập): ```git checkout -b <tên thẻ>```, ví dụ ```git checkout -b lesson01.1```

Một số lệnh làm việc với nhánh:
* Xem danh sách nhánh: ```git branch```
* Chuyển đổi giữa các nhánh: ```git checkout <tên nhánh>```, ví dụ ```git checkout master```

Để thiết lập mức log bằng các mã bash có trong thư mục bin:
```
source <đường dẫn tới thư mục bin>/set-log-level-none.sh
source <đường dẫn tới thư mục bin>/set-log-level-all.sh
```
