# Note
## Xarraylist
## Dlinkedlist hiện thực cả hai trong include/list
## thư viện xtensor
https://xtensor.readthedocs.io/en/latest/getting_started.html. Một số ví dụ cơ bản: 
1. Khai báo mảng 1 chiều và 2 chiều
    xtensor cung cấp nhiều kiểu dữ liệu mảng (arrays), bao gồm xt::xarray (mảng động), xt::xtensor (mảng tĩnh với kích thước cố định).
2.  Phép toán số học trên mảng
    Giống như NumPy, xtensor hỗ trợ các phép toán như cộng, trừ, nhân, chia giữa các mảng, hoặc giữa mảng và một hằng số.
    ```c++
    #include <xtensor/xarray.hpp>
    #include <xtensor/xio.hpp>
    #include <iostream>

    int main() {
        xt::xarray<int> arr1 = {{1, 2, 3}, {4, 5, 6}};
        xt::xarray<int> arr2 = {{7, 8, 9}, {10, 11, 12}};

        // Cộng hai mảng
        auto sum = arr1 + arr2;

        // Nhân một mảng với hằng số
        auto product = arr1 * 2;

        std::cout << "Sum:\n" << sum << "\n";
        std::cout << "Product:\n" << product << "\n";

        return 0;
    }

    ```

3. Thao tác với mảng con (slicing)
    Bạn có thể trích xuất mảng con bằng cách sử dụng xt::view.
    ```c++
        #include <xtensor/xarray.hpp>
        #include <xtensor/xview.hpp>  // để sử dụng xt::view
        #include <iostream>     

        int main() {
            xt::xarray<int> arr = {{1, 2, 3},
                                   {4, 5, 6},
                                   {7, 8, 9}};      

            // Trích xuất hàng thứ 2
            auto row = xt::view(arr, 1, xt::all());     

            // Trích xuất cột thứ 1
            auto col = xt::view(arr, xt::all(), 0);     

            std::cout << "Row 1: " << row << "\n";
            std::cout << "Column 0: " << col << "\n";       

            return 0;
        }       

    ```
4. Áp dụng hàm lên mảng
    xtensor cung cấp các hàm toán học như xt::sin, xt::cos, xt::exp, xt::sqrt để áp dụng trên toàn bộ các phần tử trong mảng.
5. Phép biến đổi và giảm chiều (reduction)
    xtensor cũng hỗ trợ các phép biến đổi như tổng (xt::sum), trung bình (xt::mean), hay tích phân (xt::prod).
    ```c++
    #include <xtensor/xarray.hpp>
    #include <xtensor/xio.hpp>
    #include <xtensor/xmath.hpp>
    #include <iostream> 

    int main() {
        xt::xarray<int> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};    

        // Tổng tất cả phần tử trong mảng
        auto total_sum = xt::sum(arr);  

        // Tính tổng theo hàng
        auto row_sum = xt::sum(arr, {1});   

        std::cout << "Total sum: " << total_sum << "\n";
        std::cout << "Row-wise sum: " << row_sum << "\n";   

        return 0;
    }   

    ```
## tìm hiểu mmlp
Khi phát triển một mạng nơron truyền thẳng nhiều lớp (Multilayer Perceptron, MLP), việc lựa chọn và sử dụng danh sách trong quá trình xây dựng mạng là một phần quan trọng để cấu trúc và tổ chức mô hình. Dưới đây là các bước cơ bản và cách áp dụng danh sách khi phát triển MLP:
1. Danh sách để cấu trúc các lớp của MLP
 - có thể sử dụng danh sách để lưu trữ thông tin về số lượng lớp và số nơron trong mỗi lớp.
 - Mỗi phần tử của danh sách sẽ đại diện cho số nơron trong một lớp cụ thể, bắt đầu từ lớp đầu vào và kết thúc với lớp đầu ra.
2. Tạo các lớp dựa trên danh sách
 - Khi bạn đã có danh sách các lớp, bạn có thể tạo ra các lớp trong MLP theo cách tuần tự bằng cách duyệt qua danh sách.
 - Trong thư viện như PyTorch hoặc TensorFlow, bạn có thể khởi tạo các lớp Dense (Fully Connected) theo danh sách.
3. Tối ưu hóa việc lựa chọn số lớp và số nơron trong các lớp
 - Việc lựa chọn số lớp ẩn và số nơron trong mỗi lớp phụ thuộc vào bài toán cụ thể.
 - Bạn có thể sử dụng danh sách để lưu các tập hợp kiến trúc mạng khác nhau và thử nghiệm để tìm cấu trúc tối ưu (hyperparameter tuning).
4. Danh sách để lưu trữ trọng số và hệ số bias (nếu xây dựng mạng từ đầu)
 - Nếu bạn muốn tự xây dựng MLP mà không dùng các framework như PyTorch hoặc TensorFlow, bạn có thể dùng danh sách để lưu trữ trọng số (weights) và bias cho từng lớp.
5. Danh sách để lưu các giá trị kích hoạt (activations) trong quá trình truyền thẳng
 - Khi truyền dữ liệu qua mạng, bạn cần lưu các giá trị kích hoạt (activation values) của từng lớp để sử dụng trong quá trình tính gradient (truyền ngược, backpropagation).

## hiện thực các lớp trong include/ann

## chạy trong compiler
g++ -Iinclude -Isrc -std=c++17 main.cpp

## mục đích
- tạo tập dữ liệu và chia tách dữ liệu để sẵn sàng cho việc xử lý bởi MLP.
- tạo các lớp và phương thức để hỗ trợ việc suy diễn (inference) bởi mạng MLP.
- khi hiện thực các APIs cần phải kiểm tra kích thước mảng đang có để đảm bảo đủ không gian lưu trữ các phần tử.

## data design
 1. Với mỗi cấu trúc dữ liệu sẽ có một hoặc vài lớp trừu tượng định nghĩa về các tác vụ sẽ được hỗ trợ bởi cấu trúc dữ liệu. Trong trường hợp danh sách, đó là lớp IList trong thư mục /include/list
 2. Trong thực tế, các cấu trúc dữ liệu sẽ chứa được các phần tử có kiểu bất kỳ, ví dụ như đối tượng sinh viên, con trỏ đến đối tượng sinh viên, hay chỉ là một con số kiểu int. Do đó, tất cả các cấu trúc dữ liệu trong môn học điều đã sử dụng template (trong C++) để tham số hoá kiểu phần tử.
 3. Tất cả các cấu trúc dữ liệu điều được thiết kế để che dấu dữ liệu và các chi tiết ở mức cao; cũng như tách bạch hai vai trò, đó là, người phát triển thư viện và người sử dụng thư viện. Cũng chính vì vậy, tất cả các cấu trúc dữ liệu, kể cả danh sách, đã được bổ sung tính năng duyệt qua các phần tử (tính năng iterator) để thuận tiện cho việc duyệt qua phần tử từ phía người dùng.


## use C/ C++ language advance
Để sử dụng thành thạo ngôn ngữ lập trình C/C++ ở mức cao, bạn cần kết hợp việc nắm vững lý thuyết và áp dụng chúng vào thực tế. Dưới đây là các bước và gợi ý chi tiết giúp bạn phát triển kỹ năng trong C/C++ ở mức chuyên nghiệp.

### 1. **Nắm vững các kiến thức cơ bản**

Trước khi tiến xa hơn, cần đảm bảo bạn đã hiểu rõ các kiến thức cơ bản về C/C++:

- **Cấu trúc chương trình**: Nắm vững cú pháp, các kiểu dữ liệu cơ bản (int, float, char, double), điều kiện (if, else), vòng lặp (for, while), hàm (functions), v.v.
- **Quản lý bộ nhớ**: Hiểu về con trỏ (pointers), tham chiếu (references), cấp phát bộ nhớ động (dynamic memory allocation) với `malloc`, `free` trong C và `new`, `delete` trong C++.
- **Struct và Union**: Hiểu rõ về cách tổ chức và sử dụng các cấu trúc dữ liệu.
- **OOP (Object-Oriented Programming)**: Hiểu rõ về các khái niệm lập trình hướng đối tượng (OOP) trong C++ như lớp (class), kế thừa (inheritance), đa hình (polymorphism), nạp chồng toán tử (operator overloading).

### 2. **Luyện tập với các bài toán lập trình**

Làm việc với nhiều bài toán lập trình sẽ giúp bạn rèn luyện tư duy logic và nắm chắc các khái niệm cơ bản:

- **Luyện tập giải thuật**: Thực hành các thuật toán và cấu trúc dữ liệu như sắp xếp (sorting), tìm kiếm (searching), đệ quy (recursion), stack, queue, linked list, cây (tree), đồ thị (graph), v.v.
- **Giải bài tập trên các trang học thuật**: Các trang như [LeetCode](https://leetcode.com/), [Codeforces](https://codeforces.com/), và [HackerRank](https://www.hackerrank.com/domains/tutorials/10-days-of-c) cung cấp nhiều bài toán để rèn luyện.

### 3. **Hiểu sâu về quản lý bộ nhớ**

Trong C/C++, việc quản lý bộ nhớ rất quan trọng:

- **Con trỏ (Pointers)**: Hiểu rõ về các con trỏ, thao tác với chúng, con trỏ hàm, con trỏ hàm thành viên trong C++.
- **Cấp phát bộ nhớ động**: Thành thạo việc cấp phát bộ nhớ bằng tay với `malloc`/`free` và `new`/`delete`, tránh các lỗi liên quan đến rò rỉ bộ nhớ (memory leak) và sử dụng đúng cách các công cụ phát hiện lỗi (như `valgrind`).
- **Con trỏ thông minh (Smart Pointers)** trong C++: Hiểu và sử dụng `std::shared_ptr`, `std::unique_ptr`, và `std::weak_ptr` để quản lý bộ nhớ tự động.

### 4. **Nâng cao kỹ năng với các thư viện tiêu chuẩn và C++ hiện đại**

C++ hiện đại có nhiều tính năng mạnh mẽ, giúp lập trình viên dễ dàng hơn trong việc viết mã hiệu quả và an toàn:

- **C++11/14/17/20**: Hiểu các tính năng mới của các phiên bản hiện đại như `auto`, `lambda`, `smart pointers`, `range-based for loop`, `constexpr`, `move semantics`, và `std::thread` cho lập trình đa luồng.
- **Thư viện STL (Standard Template Library)**: Hiểu rõ và sử dụng thành thạo các cấu trúc dữ liệu và thuật toán có sẵn trong STL như `std::vector`, `std::map`, `std::set`, `std::unordered_map`, `std::sort`, `std::transform`, v.v.
- **Templates và Generic Programming**: Sử dụng và viết các template để tạo các hàm và lớp tổng quát, áp dụng các khái niệm lập trình metaprogramming.

### 5. **Thực hành phát triển các dự án thực tế**

Việc tham gia phát triển dự án thực tế sẽ giúp bạn hiểu rõ hơn về cách tổ chức, quản lý mã nguồn và giải quyết các vấn đề thực tế:

- **Dự án mã nguồn mở**: Tham gia vào các dự án mã nguồn mở trên GitHub, ví dụ như thư viện Boost, OpenCV, TensorFlow, hoặc các công cụ phần mềm khác.
- **Viết các dự án nhỏ**: Bắt đầu với các dự án nhỏ như quản lý bộ nhớ, hệ thống quản lý file, hay thậm chí là một game nhỏ như "Snake" hoặc "Tic-Tac-Toe".
- **Phát triển phần mềm hệ thống**: Làm việc với hệ điều hành, trình điều khiển (driver), lập trình hệ thống cấp thấp (low-level programming), hoặc phát triển các ứng dụng nhúng.

### 6. **Học và sử dụng các công cụ lập trình**

Công cụ lập trình là một phần quan trọng giúp nâng cao hiệu quả và chất lượng mã nguồn:

- **IDE và biên dịch**: Sử dụng các IDE phổ biến như Visual Studio, CLion, hoặc GCC và g++.
- **Công cụ gỡ lỗi (debugging)**: Sử dụng các công cụ như GDB (GNU Debugger) để gỡ lỗi chương trình.
- **CMake**: Thành thạo sử dụng CMake để quản lý và biên dịch dự án đa nền tảng.
- **Công cụ kiểm tra bộ nhớ**: Dùng `valgrind` để kiểm tra rò rỉ bộ nhớ, hoặc `AddressSanitizer` để phát hiện các lỗi liên quan đến bộ nhớ.

### 7. **Nâng cao về lập trình hiệu suất và tối ưu hóa**

Hiểu rõ cách tối ưu mã nguồn, quản lý tài nguyên và tăng hiệu suất chương trình:

- **Tối ưu hóa bộ nhớ và CPU**: Sử dụng các công cụ như `gprof` để phân tích hiệu suất.
- **Quản lý tài nguyên hiệu quả**: Hiểu và áp dụng các kỹ thuật tối ưu hóa cấp phát bộ nhớ, tránh thừa tài nguyên và sử dụng hợp lý các cấu trúc dữ liệu.
- **Lập trình đa luồng**: Thành thạo các kỹ thuật lập trình đa luồng và đồng bộ hóa như mutex, semaphore, atomic operations trong C++.

### 8. **Học các kỹ thuật lập trình nâng cao**

Các kỹ thuật nâng cao sẽ giúp bạn nắm vững các khái niệm sâu về C++ và có khả năng giải quyết các bài toán phức tạp:

- **Lập trình đa luồng (multithreading)**: Sử dụng thư viện C++ `std::thread`, quản lý đồng bộ hóa với mutex, condition variable, và áp dụng mô hình lập trình song song (parallel programming).
- **Lập trình mạng (network programming)**: Sử dụng các API như Berkeley Sockets, Boost.Asio để xây dựng các ứng dụng mạng.
- **Thiết kế hệ thống**: Học cách thiết kế hệ thống lớn với các mô hình phần mềm chuẩn như MVC (Model-View-Controller), Singleton, Factory, Observer.

### 9. **Đọc và học hỏi từ mã nguồn thực tế**

- **Đọc mã nguồn của người khác**: Đọc các dự án mã nguồn mở lớn, như các dự án trên GitHub hoặc các thư viện như `Boost`, `Qt`, `OpenCV` để học cách tổ chức và tối ưu mã nguồn.
- **Tham gia vào cộng đồng lập trình**: Tham gia vào các diễn đàn, blog, và các nhóm thảo luận về C/C++, nơi bạn có thể học hỏi từ các lập trình viên khác.

### 10. **Luôn cập nhật kiến thức**

Công nghệ và các tiêu chuẩn lập trình luôn thay đổi. Hãy theo dõi các cập nhật mới nhất về ngôn ngữ và các thư viện phổ biến:

- **Đọc tài liệu và sách chuyên sâu**: Có nhiều sách chuyên sâu về C/C++, như "Effective C++" của Scott Meyers, "The C++ Programming Language" của Bjarne Stroustrup, "C++ Concurrency in Action" của Anthony Williams.
- **Theo dõi blog và video**: Các blog và video hướng dẫn từ các chuyên gia lập trình C/C++ sẽ cung cấp cho bạn cái nhìn sâu sắc hơn về các xu hướng và thực hành tốt nhất.

### Kết luận

Để sử dụng thành thạo ngôn ngữ C/C++ ở mức cao, bạn cần kiên trì học tập, rèn luyện từ những khái niệm cơ bản cho đến các kỹ thuật lập trình nâng cao. Sự kết hợp giữa việc học lý thuyết và thực hành với các dự án thực tế sẽ giúp bạn trở thành một lập trình viên C/C++ chuyên nghiệp.

