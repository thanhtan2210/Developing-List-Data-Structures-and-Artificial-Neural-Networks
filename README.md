* Note
//
Xarraylist
Dlinkedlist hiện thực cả hai trong include/list
thư viện xtensor
tìm hiểu mmlp
hiện thực các lớp trong include/ann


g++ -Iinclude -Isrc -std=c++17 main.cpp





tạo tập dữ liệu và chia tách dữ liệu để sẵn sàng cho việc xử lý bởi MLP.
tạo các lớp và phương thức để hỗ trợ việc suy diễn (inference) bởi mạng MLP.


khi hiện thực các APIs cần phải kiểm tra kích thước mảng đang
có để đảm bảo đủ không gian lưu trữ các phần tử.

 1. Với mỗi cấu trúc dữ liệu sẽ có một hoặc vài lớp trừu tượng định nghĩa về các tác vụ sẽ được hỗ trợ bởi cấu trúc dữ liệu. Trong trường hợp danh sách, đó là lớp IList trong thư mục /include/list
 2. Trong thực tế, các cấu trúc dữ liệu sẽ chứa được các phần tử có kiểu bất kỳ, ví dụ như đối tượng sinh viên, con trỏ đến đối tượng sinh viên, hay chỉ là một con số kiểu int. Do đó, tất cả các cấu trúc dữ liệu trong môn học điều đã sử dụng template (trong C++) để tham số hoá kiểu phần tử.
 3. Tất cả các cấu trúc dữ liệu điều được thiết kế để che dấu dữ liệu và các chi tiết ở mức cao; cũng như tách bạch hai vai trò, đó là, người phát triển thư viện và người sử dụng thư viện. Cũng chính vì vậy, tất cả các cấu trúc dữ liệu, kể cả danh sách, đã được bổ sung tính năng duyệt qua các phần tử (tính năng iterator) để thuận tiện cho việc duyệt qua phần tử từ phía người dùng

