// /*
//  * Assignment 1 - Developing List Data Structures and Artificial Neural Networks
//  * file : main.cpp
//  * Data Structures and Algorithms
//  * Author: Võ Tiến
//  * Link FB : https://www.facebook.com/Shiba.Vo.Tien
//  * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
//  * Date: 18.9.2024

//  ! build code : g++ -o main -Iinclude -Isrc -std=c++17 main.cpp test/unit_test/arrayList/unit_test.cpp test/unit_test/linkedList/unit_test.cpp test/random_test/random_test.cpp src/ann/xtensor_lib.cpp src/util/Point.cpp
// g++ -o main -Iinclude -Isrc -std=c++17 main.cpp test/unit_test/arrayList/unit_test.cpp test/unit_test/linkedList/unit_test.cpp test/unit_test/data/unit_test.cpp test/random_test/random_test.cpp src/ann/xtensor_lib.cpp src/util/Point.cpp


// g++ -fsanitize=address  -o main -Iinclude -Isrc -std=c++17 main.cpp test/unit_test/arrayList/unit_test.cpp test/unit_test/linkedList/unit_test.cpp test/unit_test/data/unit_test.cpp test/random_test/random_test.cpp src/ann/xtensor_lib.cpp src/util/Point.cpp

//  * run code
//     * terminal unit test array list
//     !./main test_unit_array
//     !./main test_unit_array nameFunctionUnitTest

//     * terminal unit test linked list
//     ! ./main test_unit_linkedList
//     ! ./main test_unit_linkedList nameFunctionUnitTest

//     * terminal unit test dataset
//     ! ./main test_unit_data
//     ! ./main test_unit_data nameFunctionUnitTest

//     * terminal auto test
//     ! ./main test_random number_1 number_2
//     ! ./main test_random number
// */

// #include "test/random_test/random_test.hpp"
// #include "test/unit_test/arrayList/unit_test.hpp"
// #include "test/unit_test/data/unit_test.hpp"
// #include "test/unit_test/linkedList/unit_test.hpp"
// void printTestCase();
// void handleTestUnitArray(int argc, char *argv[]);
// void handleTestUnitLinkedList(int argc, char *argv[]);
// void handleTestRandom(int argc, char *argv[]);
// void handleTestUnitData(int argc, char *argv[]);

// int main(int argc, char *argv[]) {
//   if (argc <= 1) {
//     printTestCase();
//     return 1;
//   }

//   std::string arg1 = argv[1];
//   if (arg1 == "test_unit_array") {
//     handleTestUnitArray(argc, argv);
//   } else if (arg1 == "test_unit_linkedList") {
//     handleTestUnitLinkedList(argc, argv);
//   } else if (arg1 == "test_unit_data") {
//     handleTestUnitData(argc, argv);
//   } else if (arg1 == "test_random") {
//     handleTestRandom(argc, argv);
//   } else {
//     printTestCase();
//   }
// }

// void handleTestUnitArray(int argc, char *argv[]) {
//   T_ArrayList unitTest;

//   if (argc == 2 || (argc == 3 && std::string(argv[2]) == "all")) {
//     std::cout << "Running all unit tests array: ----------\n";
//     unitTest.runAllTests();
//   } else if (argc == 3) {
//     std::cout << "Running unit test array: " << argv[2] << " ----------\n";
//     unitTest.runTest(argv[2]);
//   } else {
//     printTestCase();
//   }
// }

// void handleTestUnitLinkedList(int argc, char *argv[]) {
//   T_LinkedList unitTest;

//   if (argc == 2 || (argc == 3 && std::string(argv[2]) == "all")) {
//     std::cout << "Running all unit tests data: ----------\n";
//     unitTest.runAllTests();
//   } else if (argc == 3) {
//     std::cout << "Running unit test data: " << argv[2] << " ----------\n";
//     unitTest.runTest(argv[2]);
//   } else {
//     printTestCase();
//   }
// }

// void handleTestUnitData(int argc, char *argv[]) {
//   T_Data unitTest;

//   if (argc == 2 || (argc == 3 && std::string(argv[2]) == "all")) {
//     std::cout << "Running all unit tests linked list: ----------\n";
//     unitTest.runAllTests();
//   } else if (argc == 3) {
//     std::cout << "Running unit test linked list: " << argv[2]
//               << " ----------\n";
//     unitTest.runTest(argv[2]);
//   } else {
//     printTestCase();
//   }
// }

// void handleTestRandom(int argc, char *argv[]) {
//   if (argc == 3) {
//     try {
//       int number = std::stoi(argv[2]);
//       std::cout << "Running RandomTest with single number: " << number
//                 << " ----------\n";
//       RandomTest random(number, number);
//       random.runTest();
//     } catch (const std::invalid_argument &e) {
//       std::cerr << "Invalid number argument: " << e.what() << std::endl;
//     }
//   } else if (argc == 4) {
//     try {
//       int number1 = std::stoi(argv[2]);
//       int number2 = std::stoi(argv[3]);
//       std::cout << "Running RandomTest with numbers: " << number1 << " to "
//                 << number2 << " ----------\n";
//       RandomTest random(number1, number2);
//       random.runTest();
//     } catch (const std::invalid_argument &e) {
//       std::cerr << "Invalid number argument: " << e.what() << std::endl;
//     }
//   } else {
//     printTestCase();
//   }
// }

// void printTestCase() {
//   const std::string RESET = "\033[0m";
//   const std::string BOLD = "\033[1m";
//   const std::string RED = "\033[31m";
//   const std::string GREEN = "\033[32m";
//   const std::string CYAN = "\033[36m";

//   std::cout << GREEN << BOLD << "terminal unit test array list" << RESET
//             << std::endl;
//   std::cout << RED << "./main test_unit_array" << RESET << std::endl;
//   std::cout << RED << "./main test_unit_array nameFunctionUnitTest" << RESET
//             << std::endl
//             << std::endl;

//   std::cout << GREEN << BOLD << "terminal unit test linked list" << RESET
//             << std::endl;
//   std::cout << RED << "./main test_unit_linkedList" << RESET << std::endl;
//   std::cout << RED << "./main test_unit_linkedList nameFunctionUnitTest"
//             << RESET << std::endl
//             << std::endl;
//   std::cout << GREEN << BOLD << "terminal unit test data" << RESET << std::endl;
//   std::cout << RED << "./main test_unit_data" << RESET << std::endl;
//   std::cout << RED << "./main test_unit_data nameFunctionUnitTest" << RESET
//             << std::endl
//             << std::endl;

//   std::cout << GREEN << BOLD << "terminal auto test" << RESET << std::endl;
//   std::cout << RED << "./main test_random number_1 number_2" << RESET
//             << std::endl;
//   std::cout << RED << "./main test_random number" << RESET << std::endl;
// }

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "include/list/listheader.h"
#include "include/list/DLinkedList.h"
#include "include/list/XArrayList.h"
#include "include/util/Point.h"
#include "include/ann/dataloader.h"
#include "include/ann/dataset.h"

using namespace std;

//g++ -Iinclude -Isrc -std=c++17 main.cpp


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
// run test case // nho phai xoa
void dlistDemo1(){
    List<int> dlist;
    for(int i = 0; i< 20 ; i++)
        dlist.add(i, i*i);
    dlist.println();

    for(List<int>::BWDIterator it=dlist.bbegin(); it != dlist.bend(); it++ )
        cout << *it << " ";
    cout << endl;
}

void dlistDemo2(){
    DLinkedList<Point*> list1(&DLinkedList<Point*>::free, &Point::pointEQ);
    list1.add(new Point(23.2f, 25.4f));
    list1.add(new Point(24.6f, 23.1f));
    list1.add(new Point(12.5f, 22.3f));

    for(DLinkedList<Point*>::Iterator it = list1.begin(); it != list1.end(); it++)
        cout << **it << endl;

    Point* p1 = new Point(24.6f, 23.1f); //found in list
    Point* p2 = new Point(124.6f, 23.1f); //not found
    cout << *p1 << "=> " << (list1.contains(p1)? "found; " : "not found; ")
                << " indexOf returns: " << list1.indexOf(p1) << endl;
    cout << *p2 << "=> " << (list1.contains(p2)? "found; " : "not found; ")
                << " indexOf returns: " << list1.indexOf(p2) << endl;

    ///Different results if not pass &Point::equals
    cout << endl << endl;
    DLinkedList<Point*> list2(&DLinkedList<Point*>::free);
    list2.add(new Point(23.2f, 25.4f));
    list2.add(new Point(24.6f, 23.1f));
    list2.add(new Point(12.5f, 22.3f));

    for(DLinkedList<Point*>::Iterator it = list2.begin(); it != list2.end(); it++)
        cout << **it << endl;

    cout << *p1 << "=> " << (list2.contains(p1)? "found; " : "not found; ")
                << " indexOf returns: " << list2.indexOf(p1) << endl;
    cout << *p2 << "=> " << (list2.contains(p2)? "found; " : "not found; ")
                << " indexOf returns: " << list2.indexOf(p2) << endl;

    delete p1; delete p2;
}


	
bool pointComparator(Point*& p1, Point*& p2){
    return (p1->getX() == p2->getX()) && (p1->getY() == p2->getY());
}
string LpointPtr2Str(Point*& ptr){
    stringstream os;
    os << "("   << ptr->getX() << ", "
                << ptr->getY()
       << ")";
    return os.str();
}
void dlistDemo4(){
    DLinkedList<Point*> dList(&DLinkedList<Point*>::free, &pointComparator);
    dList.add(new Point(1.5, 3.5));
    dList.add(new Point(2.5, 4.5));
    dList.add(new Point(1.6, 3.1));
    dList.println(&LpointPtr2Str);

    cout << "test for indexOf: " << endl;
    Point* p = new Point(1.6, 3.1);
    cout << *p << " at: " << dList.indexOf(p) << endl;
    delete p;
}



void xlistDemo4(){
    XArrayList<Point*> list1(&XArrayList<Point*>::free, &Point::pointEQ);
    list1.add(new Point(23.2f, 25.4f));
    list1.add(new Point(24.6f, 23.1f));
    list1.add(new Point(12.5f, 22.3f));

    for(XArrayList<Point*>::Iterator it = list1.begin(); it != list1.end(); it++)
        cout << **it << endl;

    Point* p1 = new Point(24.6f, 23.1f); //found in list
    Point* p2 = new Point(124.6f, 23.1f); //not found
    cout << *p1 << "=> " << (list1.contains(p1)? "found; " : "not found; ")
                << " indexOf returns: " << list1.indexOf(p1) << endl;
    cout << *p2 << "=> " << (list1.contains(p2)? "found; " : "not found; ")
                << " indexOf returns: " << list1.indexOf(p2) << endl;

    ///Different results if not pass &Point::equals
    cout << endl << endl;
    XArrayList<Point*> list2(&XArrayList<Point*>::free);
    list2.add(new Point(23.2f, 25.4f));
    list2.add(new Point(24.6f, 23.1f));
    list2.add(new Point(12.5f, 22.3f));

    for(XArrayList<Point*>::Iterator it = list2.begin(); it != list2.end(); it++)
        cout << **it << endl;

    cout << *p1 << "=> " << (list2.contains(p1)? "found; " : "not found; ")
                << " indexOf returns: " << list2.indexOf(p1) << endl;
    cout << *p2 << "=> " << (list2.contains(p2)? "found; " : "not found; ")
                << " indexOf returns: " << list2.indexOf(p2) << endl;

    delete p1; delete p2;
}
	
void dataloadertc1(){
    xt::random::seed(10);
    xt::xarray<double> X = xt::random::randn<double>({105, 10, 10});
    xt::xarray<int> t = xt::ones<int>({105});
    TensorDataset<double, int> ds(X, t);
    cout << ds.len() << endl;
    DataLabel<double, int> item = ds.getitem(0);
    cout << item.getData() << endl;
    cout << item.getLabel() << endl;
}

void case_data_wi_label_1(){
    xt::xarray<int> X = xt::arange<int>(10*4).reshape({10, 4});
    xt::xarray<int> t = xt::arange<int>(10);
    //Show X and t
    cout << "############################################" << endl;
    cout << "#CASE: data WITH label" << endl;
    cout << "WHEN label is available: " << endl;
    cout << "\tAssignment-1: ASSUME that dimension-0 on data = dimension-0 on label" << endl;
    cout << "############################################" << endl;
    cout << "ORIGINAL data and label:" << endl;
    cout << "X.shape: " << shape2str(X.shape()) << endl;
    cout << "X: " << endl << X << endl;
    cout << "t.shape: " << shape2str(t.shape()) << endl;
    cout << "t: " << endl << t << endl;
    cout << "=================================" << endl;

    //Create TensorDataset and DataLoader
    TensorDataset<int, int> ds(X, t);
    int batch_size = 3;
    bool shuffle = false, drop_last = false;
    int seed;
    DataLoader<int, int> *pLoader;

    cout << "Loading (1): with shuffle=false:" << endl;
    cout << "################################" << endl;
    shuffle = false;
    pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
    int batch_idx = 1;
    for(auto batch: *pLoader){
        cout << "batch_idx:" << batch_idx++ << endl;
        string dshape = shape2str(batch.getData().shape());
        string lshape = shape2str(batch.getLabel().shape());
        cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
        cout << "data:"  << endl << batch.getData() << endl;
        cout << "label:" << endl << batch.getLabel() << endl;
    }
    cout << endl << endl;
    delete pLoader;

    // cout << "Loading (2): with shuffle=true + no seed (seed < 0):" << endl;
    // cout << "when seed < 0: DO NOT call xt::random:seed" << endl;
    // cout << "################################" << endl;
    // shuffle = true;
    // seed = -1;
    // pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
    // batch_idx = 1;
    // for(auto batch: *pLoader){
    //     cout << "batch_idx:" << batch_idx++ << endl;
    //     string dshape = shape2str(batch.getData().shape());
    //     string lshape = shape2str(batch.getLabel().shape());
    //     cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
    //     cout << "data:"  << endl << batch.getData() << endl;
    //     cout << "label:" << endl << batch.getLabel() << endl;
    // }
    // cout << endl << endl;
    // delete pLoader;

    // cout << "Loading (3): with shuffle=true + no seed (seed < 0):" << endl;
    // cout << "when seed < 0: DO NOT call xt::random:seed" << endl;
    // cout << "################################" << endl;
    // shuffle = true;
    // seed = -1;
    // pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
    // batch_idx = 1;
    // for(auto batch: *pLoader){
    //     cout << "batch_idx:" << batch_idx++ << endl;
    //     string dshape = shape2str(batch.getData().shape());
    //     string lshape = shape2str(batch.getLabel().shape());
    //     cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
    //     cout << "data:"  << endl << batch.getData() << endl;
    //     cout << "label:" << endl << batch.getLabel() << endl;
    // }
    // cout << endl << endl;
    // delete pLoader;
    cout << "NOTE: Loading (2) and (3): DO NOT CALL seed; so results are different." << endl;
    cout << endl << endl;

    cout << "Loading (4): with shuffle=true + with seed (seed >= 0):" << endl;
    cout << "when seed >= 0: CALL xt::random:seed" << endl;
    cout << "################################" << endl;
    shuffle = true;
    seed = 100;
    pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
    batch_idx = 1;
    for(auto batch: *pLoader){
        cout << "batch_idx:" << batch_idx++ << endl;
        string dshape = shape2str(batch.getData().shape());
        string lshape = shape2str(batch.getLabel().shape());
        cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
        cout << "data:"  << endl << batch.getData() << endl;
        cout << "label:" << endl << batch.getLabel() << endl;
    }
    delete pLoader;
    cout << endl << endl;

    cout << "Loading (5): with shuffle=true + with seed (seed >= 0):" << endl;
    cout << "when seed >= 0: CALL xt::random:seed" << endl;
    cout << "################################" << endl;
    shuffle = true;
    seed = 100;
    pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
    batch_idx = 1;
    for(auto batch: *pLoader){
        cout << "batch_idx:" << batch_idx++ << endl;
        string dshape = shape2str(batch.getData().shape());
        string lshape = shape2str(batch.getLabel().shape());
        cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
        cout << "data:"  << endl << batch.getData() << endl;
        cout << "label:" << endl << batch.getLabel() << endl;
    }
    delete pLoader;
    cout << "NOTE: Loading (4) and (5): CALL xt::random::seed and use SAME seed => same results." << endl;
    cout << endl << endl;
}

// ############################################
// #CASE: data WITH label
// WHEN label is available:
// \tAssignment-1: ASSUME that dimension-0 on data = dimension-0 on label
// ############################################
// ORIGINAL data and label:
// X.shape: (10, 4)
// X:
// {{ 0,  1,  2,  3},
//  { 4,  5,  6,  7},
//  { 8,  9, 10, 11},
//  {12, 13, 14, 15},
//  {16, 17, 18, 19},
//  {20, 21, 22, 23},
//  {24, 25, 26, 27},
//  {28, 29, 30, 31},
//  {32, 33, 34, 35},
//  {36, 37, 38, 39}}
// t.shape: (10,)
// t:
// {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
// =================================
// Loading (1): with shuffle=false:
// ################################
// batch_idx:1
// (data.shape, label.shape): (3, 4), (3,)
// data:
// {{ 0,  1,  2,  3},
//  { 4,  5,  6,  7},
//  { 8,  9, 10, 11}}
// label:
// {0, 1, 2}
// batch_idx:2
// (data.shape, label.shape): (3, 4), (3,)
// data:
// {{12, 13, 14, 15},
//  {16, 17, 18, 19},
//  {20, 21, 22, 23}}
// label:
// {3, 4, 5}
// batch_idx:3
// (data.shape, label.shape): (4, 4), (4,)
// data:
// {{24, 25, 26, 27},
//  {28, 29, 30, 31},
//  {32, 33, 34, 35},
//  {36, 37, 38, 39}}
// label:
// {6, 7, 8, 9}


// NOTE: Loading (2) and (3): DO NOT CALL seed; so results are different.


// Loading (4): with shuffle=true + with seed (seed >= 0):
// when seed >= 0: CALL xt::random:seed
// ################################
// batch_idx:1
// (data.shape, label.shape): (3, 4), (3,)
// data:
// {{ 4,  5,  6,  7},
//  {16, 17, 18, 19},
//  { 0,  1,  2,  3}}
// label:
// {1, 4, 0}
// batch_idx:2
// (data.shape, label.shape): (3, 4), (3,)
// data:
// {{12, 13, 14, 15},
//  {36, 37, 38, 39},
//  {32, 33, 34, 35}}
// label:
// {3, 9, 8}
// batch_idx:3
// (data.shape, label.shape): (4, 4), (4,)
// data:
// {{28, 29, 30, 31},
//  { 8,  9, 10, 11},
//  {24, 25, 26, 27},
//  {20, 21, 22, 23}}
// label:
// {7, 2, 6, 5}


// Loading (5): with shuffle=true + with seed (seed >= 0):
// when seed >= 0: CALL xt::random:seed
// ################################
// batch_idx:1
// (data.shape, label.shape): (3, 4), (3,)
// data:
// {{ 4,  5,  6,  7},
//  {16, 17, 18, 19},
//  { 0,  1,  2,  3}}
// label:
// {1, 4, 0}
// batch_idx:2
// (data.shape, label.shape): (3, 4), (3,)
// data:
// {{12, 13, 14, 15},
//  {36, 37, 38, 39},
//  {32, 33, 34, 35}}
// label:
// {3, 9, 8}
// batch_idx:3
// (data.shape, label.shape): (4, 4), (4,)
// data:
// {{28, 29, 30, 31},
//  { 8,  9, 10, 11},
//  {24, 25, 26, 27},
//  {20, 21, 22, 23}}
// label:
// {7, 2, 6, 5}
// NOTE: Loading (4) and (5): CALL xt::random::seed and use SAME seed => same results.
// ############################################
// #CASE: data WITH label
// WHEN label is available:
// \tAssignment-1: ASSUME that dimension-0 on data = dimension-0 on label
// ############################################
// ORIGINAL data and label:
// X.shape: (10, 4)
// X:
// {{ 0,  1,  2,  3},
//  { 4,  5,  6,  7},
//  { 8,  9, 10, 11},
//  {12, 13, 14, 15},
//  {16, 17, 18, 19},
//  {20, 21, 22, 23},
//  {24, 25, 26, 27},
//  {28, 29, 30, 31},
//  {32, 33, 34, 35},
//  {36, 37, 38, 39}}
// t.shape: (10,)
// t:
// {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
// =================================
// Loading (1): with shuffle=false:
// ################################


// NOTE: Loading (2) and (3): DO NOT CALL seed; so results are different.


// Loading (4): with shuffle=true + with seed (seed >= 0):
// when seed >= 0: CALL xt::random:seed
// ################################


// Loading (5): with shuffle=true + with seed (seed >= 0):
// when seed >= 0: CALL xt::random:seed
// ################################

	
void case_batch_larger_nsamples(){
    int nsamples = 10;
    xt::xarray<int> X = xt::arange<int>(nsamples*4).reshape({nsamples, 4});
    xt::xarray<int> t;
    //Show X and t
    cout << "############################################" << endl;
    cout << "#CASE: data WITHOUT label" << endl;
    cout << "############################################" << endl;
    cout << "ORIGINAL data and label:" << endl;
    cout << "X.shape: " << shape2str(X.shape()) << endl;
    cout << "X: " << endl << X << endl;
    cout << "t.shape: " << shape2str(t.shape()) << endl;
    cout << "t: " << endl << t << endl;
    cout << "=================================" << endl;

    //Create TensorDataset and DataLoader
    TensorDataset<int, int> ds(X, t);
    int batch_size = 15; //15 > 10 => 10/15 = 0
    bool shuffle = false, drop_last = false;
    int seed;
    DataLoader<int, int> *pLoader;

    cout << "Loading (1): with shuffle=false:" << endl;
    cout << "Number of samples: " << nsamples << endl;
    cout << "batch-size: " << batch_size << endl;
    cout << "=> number of batches to be processed: " << int(nsamples/batch_size) << endl;
    cout << "################################" << endl;
    shuffle = false;
    pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
    int batch_idx = 0;
    for(auto batch: *pLoader){
        cout << "batch_idx:" << batch_idx++ << endl;
        string dshape = shape2str(batch.getData().shape());
        string lshape = shape2str(batch.getLabel().shape());
        cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
        cout << "data:"  << endl << batch.getData() << endl;
        cout << "label:" << endl << batch.getLabel() << endl;
    }
    cout << "NUMBER OF BATCHES PROCESSED: " << batch_idx << endl;
    delete pLoader;
}
// ############################################
// #CASE: data WITHOUT label
// ############################################
// ORIGINAL data and label:
// X.shape: (10, 4)
// X:
// {{ 0,  1,  2,  3},
//  { 4,  5,  6,  7},
//  { 8,  9, 10, 11},
//  {12, 13, 14, 15},
//  {16, 17, 18, 19},
//  {20, 21, 22, 23},
//  {24, 25, 26, 27},
//  {28, 29, 30, 31},
//  {32, 33, 34, 35},
//  {36, 37, 38, 39}}
// t.shape: ()
// t:
// 0
// =================================
// Loading (1): with shuffle=false:
// Number of samples: 10
// batch-size: 15
// => number of batches to be processed: 0
// ################################
// NUMBER OF BATCHES PROCESSED: 0



	
void dataloadertc3(){
    xt::random::seed(10);
    xt::xarray<double> X = xt::random::randn<double>({105, 10, 10});
    xt::xarray<int> t = xt::ones<int>({105});
    TensorDataset<double, int> ds(X, t);
    cout << X << endl;
    cout << t << endl;
    DataLoader<double, int> loader(&ds, 10, false);
    auto it = loader.begin();
    it++;
    cout << xt::adapt((*it).getData().shape()) << endl;
    cout << xt::adapt((*it).getLabel().shape()) << endl;
    cout << xt::adapt((*(++it)).getData().shape()) << endl;
    cout << xt::adapt((*(++it)).getLabel().shape()) << endl;
}

// {10, 10, 10}
// {10}
// {10, 10, 10}
// {10}

void dataloadertc4(){
    xt::random::seed(10);
    xt::xarray<double> X = xt::random::randn<double>({105, 10, 10});
    xt::xarray<int> t = xt::ones<int>({105});
    TensorDataset<double, int> ds(X, t);
    DataLoader<double, int> loader(&ds, 10, false);
    for(auto it = loader.begin(); it != loader.end(); it++){
        cout << ((*it).getData().shape()[0]) << endl;
        cout << ((*it).getLabel().shape()[0]) << endl;
    }
}

// 10
// 10
// 10
// 10
// 10
// 10
// 10
// 10
// 10
// 10
// 10
// 10
// 10
// 10
// 10
// 10
// 10
// 10
// 15
// 15

	
void dataloadertc5(){
    xt::random::seed(10);
    xt::xarray<double> X = xt::random::randn<double>({105, 10, 10});
    xt::xarray<int> t = xt::ones<int>({105});
    TensorDataset<double, int> ds(X, t);
    DataLoader<double, int> loader(&ds, 10, false);
    for(auto batch: loader){
        cout << (xt::adapt(batch.getData().shape())) << endl;
        cout << (xt::adapt(batch.getLabel().shape())) << endl;
    }
}
// {10, 10, 10}
// {10}
// {10, 10, 10}
// {10}
// {10, 10, 10}
// {10}
// {10, 10, 10}
// {10}
// {10, 10, 10}
// {10}
// {10, 10, 10}
// {10}
// {10, 10, 10}
// {10}
// {10, 10, 10}
// {10}
// {10, 10, 10}
// {10}
// {15, 10, 10}
// {15}

	
void dataloadertc6(){
    xt::random::seed(10);
    xt::xarray<double> X = xt::random::randn<double>({100, 3, 3});
    xt::xarray<int> t = xt::ones<int>({100});
    TensorDataset<double, int> ds(X, t);
    DataLoader<double, int> loader(&ds, 10, false, true);
    for(auto batch: loader){
        cout << batch.getData() << endl;
        cout << batch.getLabel() << endl;
    }
}

// {{{ 1.805733, -1.416171,  0.744431},
//   {-0.272804,  1.515411, -1.10811 },
//   {-1.31327 , -0.506362,  0.826458}},
//  {{-1.61196 , -0.134643, -0.086606},
//   {-0.108172,  0.718353, -1.016792},
//   {-0.965204, -0.266265, -0.724121}},
//  {{ 0.451145,  1.410254, -1.37865 },
//   {-0.131912, -0.736679,  0.42126 },
//   {-0.160231,  0.844769,  1.662264}},
//  {{-1.32694 , -0.837512, -0.132641},
//   {-0.65521 ,  0.424079, -0.56224 },
//   { 0.163328, -0.090509,  0.303382}},
//  {{ 0.67595 , -0.167288, -1.223254},
//   {-0.499257, -1.414429, -0.114504},
//   { 1.792705, -0.182385,  0.09276 }},
//  {{ 0.202835,  0.903428,  1.094595},
//   {-1.655614,  0.169925,  1.04018 },
//   {-0.550667,  0.576693, -0.050266}},
//  {{-1.112708,  1.943595, -2.066254},
//   { 0.376038, -0.219185,  0.549599},
//   {-0.885237,  0.32259 , -0.449772}},
//  {{ 0.790567,  1.690074,  0.218961},
//   {-1.751077, -0.139271,  1.144889},
//   { 0.653499,  0.69348 , -0.566989}},
//  {{ 2.967625,  0.516867, -0.75115 },
//   {-0.448441, -0.240197,  1.216097},
//   {-0.639031,  0.653242,  2.154483}},
//  {{ 1.311621,  0.343337, -0.1684  },
//   {-1.506686, -1.289872,  0.623594},
//   {-1.488837, -0.708837,  1.514485}}}
// {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}


	
void dataloadertc7(){
    xt::random::seed(10);
    xt::xarray<double> X = xt::random::randn<double>({105, 10, 10});
    xt::xarray<int> t = xt::ones<int>({105});
    TensorDataset<double, int> ds(X, t);
    DataLoader<double, int> loader(&ds, 10, false, true);
    for(auto batch: loader){
        cout << (xt::adapt(batch.getData().shape())) << endl;
        cout << (xt::adapt(batch.getLabel().shape())) << endl;
    }
}

// {10, 10, 10}
// {10}
// {10, 10, 10}
// {10}
// {10, 10, 10}
// {10}
// {10, 10, 10}
// {10}
// {10, 10, 10}
// {10}
// {10, 10, 10}
// {10}
// {10, 10, 10}
// {10}
// {10, 10, 10}
// {10}
// {10, 10, 10}
// {10}
// {10, 10, 10}
// {10}

void case_data_wo_label_1(){
    xt::xarray<int> X = xt::arange<int>(10*4).reshape({10, 4});
    xt::xarray<int> t;
    //Show X and t
    cout << "############################################" << endl;
    cout << "#CASE: data WITHOUT label" << endl;
    cout << "############################################" << endl;
    cout << "ORIGINAL data and label:" << endl;
    cout << "X.shape: " << shape2str(X.shape()) << endl;
    cout << "X: " << endl << X << endl;
    cout << "t.shape: " << shape2str(t.shape()) << endl;
    cout << "t: " << endl << t << endl;
    cout << "=================================" << endl;

    //Create TensorDataset and DataLoader
    TensorDataset<int, int> ds(X, t);
    int batch_size = 3;
    bool shuffle = false, drop_last = false;
    int seed;
    DataLoader<int, int> *pLoader;

    cout << "Loading (1): with shuffle=false:" << endl;
    cout << "################################" << endl;
    shuffle = false;
    pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
    int batch_idx = 1;
    for(auto batch: *pLoader){
        cout << "batch_idx:" << batch_idx++ << endl;
        string dshape = shape2str(batch.getData().shape());
        string lshape = shape2str(batch.getLabel().shape());
        cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
        cout << "data:"  << endl << batch.getData() << endl;
        cout << "label:" << endl << batch.getLabel() << endl;
    }
    cout << endl << endl;
    delete pLoader;

    // cout << "Loading (2): with shuffle=true + no seed (seed < 0):" << endl;
    // cout << "when seed < 0: DO NOT call xt::random:seed" << endl;
    // cout << "################################" << endl;
    // shuffle = true;
    // seed = -1;
    // pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
    // batch_idx = 1;
    // for(auto batch: *pLoader){
    //     cout << "batch_idx:" << batch_idx++ << endl;
    //     string dshape = shape2str(batch.getData().shape());
    //     string lshape = shape2str(batch.getLabel().shape());
    //     cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
    //     cout << "data:"  << endl << batch.getData() << endl;
    //     cout << "label:" << endl << batch.getLabel() << endl;
    // }
    // cout << endl << endl;
    // delete pLoader;

    // cout << "Loading (3): with shuffle=true + no seed (seed < 0):" << endl;
    // cout << "when seed < 0: DO NOT call xt::random:seed" << endl;
    // cout << "################################" << endl;
    // shuffle = true;
    // seed = -1;
    // pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
    // batch_idx = 1;
    // for(auto batch: *pLoader){
    //     cout << "batch_idx:" << batch_idx++ << endl;
    //     string dshape = shape2str(batch.getData().shape());
    //     string lshape = shape2str(batch.getLabel().shape());
    //     cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
    //     cout << "data:"  << endl << batch.getData() << endl;
    //     cout << "label:" << endl << batch.getLabel() << endl;
    // }
    // cout << endl << endl;
    // delete pLoader;
    cout << "NOTE: Loading (2) and (3): DO NOT CALL seed; so results are different." << endl;
    cout << endl << endl;

    cout << "Loading (4): with shuffle=true + with seed (seed >= 0):" << endl;
    cout << "when seed >= 0: CALL xt::random:seed" << endl;
    cout << "################################" << endl;
    shuffle = true;
    seed = 100;
    pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
    batch_idx = 1;
    for(auto batch: *pLoader){
        cout << "batch_idx:" << batch_idx++ << endl;
        string dshape = shape2str(batch.getData().shape());
        string lshape = shape2str(batch.getLabel().shape());
        cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
        cout << "data:"  << endl << batch.getData() << endl;
        cout << "label:" << endl << batch.getLabel() << endl;
    }
    delete pLoader;

    cout << "Loading (5): with shuffle=true + with seed (seed >= 0):" << endl;
    cout << "when seed >= 0: CALL xt::random:seed" << endl;
    cout << "################################" << endl;
    shuffle = true;
    seed = 100;
    pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
    batch_idx = 1;
    for(auto batch: *pLoader){
        cout << "batch_idx:" << batch_idx++ << endl;
        string dshape = shape2str(batch.getData().shape());
        string lshape = shape2str(batch.getLabel().shape());
        cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
        cout << "data:"  << endl << batch.getData() << endl;
        cout << "label:" << endl << batch.getLabel() << endl;
    }
    delete pLoader;
    cout << "NOTE: Loading (4) and (5): CALL xt::random::seed and use SAME seed => same results." << endl;
    cout << endl << endl;
}

// ############################################
// #CASE: data WITHOUT label
// ############################################
// ORIGINAL data and label:
// X.shape: (10, 4)
// X:
// {{ 0,  1,  2,  3},
//  { 4,  5,  6,  7},
//  { 8,  9, 10, 11},
//  {12, 13, 14, 15},
//  {16, 17, 18, 19},
//  {20, 21, 22, 23},
//  {24, 25, 26, 27},
//  {28, 29, 30, 31},
//  {32, 33, 34, 35},
//  {36, 37, 38, 39}}
// t.shape: ()
// t:
// 0
// =================================
// Loading (1): with shuffle=false:
// ################################
// batch_idx:1
// (data.shape, label.shape): (3, 4), ()
// data:
// {{ 0,  1,  2,  3},
//  { 4,  5,  6,  7},
//  { 8,  9, 10, 11}}
// label:
// 0
// batch_idx:2
// (data.shape, label.shape): (3, 4), ()
// data:
// {{12, 13, 14, 15},
//  {16, 17, 18, 19},
//  {20, 21, 22, 23}}
// label:
// 0
// batch_idx:3
// (data.shape, label.shape): (4, 4), ()
// data:
// {{24, 25, 26, 27},
//  {28, 29, 30, 31},
//  {32, 33, 34, 35},
//  {36, 37, 38, 39}}
// label:
// 0


// NOTE: Loading (2) and (3): DO NOT CALL seed; so results are different.


// Loading (4): with shuffle=true + with seed (seed >= 0):
// when seed >= 0: CALL xt::random:seed
// ################################
// batch_idx:1
// (data.shape, label.shape): (3, 4), ()
// data:
// {{ 4,  5,  6,  7},
//  {16, 17, 18, 19},
//  { 0,  1,  2,  3}}
// label:
// 0
// batch_idx:2
// (data.shape, label.shape): (3, 4), ()
// data:
// {{12, 13, 14, 15},
//  {36, 37, 38, 39},
//  {32, 33, 34, 35}}
// label:
// 0
// batch_idx:3
// (data.shape, label.shape): (4, 4), ()
// data:
// {{28, 29, 30, 31},
//  { 8,  9, 10, 11},
//  {24, 25, 26, 27},
//  {20, 21, 22, 23}}
// label:
// 0
// Loading (5): with shuffle=true + with seed (seed >= 0):
// when seed >= 0: CALL xt::random:seed
// ################################
// batch_idx:1
// (data.shape, label.shape): (3, 4), ()
// data:
// {{ 4,  5,  6,  7},
//  {16, 17, 18, 19},
//  { 0,  1,  2,  3}}
// label:
// 0
// batch_idx:2
// (data.shape, label.shape): (3, 4), ()
// data:
// {{12, 13, 14, 15},
//  {36, 37, 38, 39},
//  {32, 33, 34, 35}}
// label:
// 0
// batch_idx:3
// (data.shape, label.shape): (4, 4), ()
// data:
// {{28, 29, 30, 31},
//  { 8,  9, 10, 11},
//  {24, 25, 26, 27},
//  {20, 21, 22, 23}}
// label:
// 0
// NOTE: Loading (4) and (5): CALL xt::random::seed and use SAME seed => same results.

int main(int argc, char** argv) {
    dataloadertc5();
    cout << "Assignment-1" << endl;
    return 0;
}