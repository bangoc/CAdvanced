# CAdvanced
Tài nguyên học tập cho khóa CAdvanced

Nên sử dụng lệnh sau để tạo bản sao cùng với các mô-đun con:
```
git clone --recurse-submodules https://github.com/bangoc/CAdvanced.git
```

Để cập nhật mã nguồn trong thư mục CAdvanced cùng với tất cả các mô-đun con, bạn có thể sử dụng lệnh sau
```
git pull --recurse-submodules
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

Một số cách xem các thay đổi đã được thực hiện trong 1 commit:
1. Sử dụng giao diện đồ họa tiêu chuẩn git-gui: ```sudo apt-get install git-gui``` sau đó chạy lệnh ```git gui``` hoặc ```gitk``` trong thư mục gốc của mã nguồn.
2. Sử dụng meld ```git difftool -t meld --dir-diff <commit A> <commit B>```

## Bài tập
Các bài tập đi kèm được lưu riêng trong nhánh ```baitap``` (xem thư mục ```assignments```)
