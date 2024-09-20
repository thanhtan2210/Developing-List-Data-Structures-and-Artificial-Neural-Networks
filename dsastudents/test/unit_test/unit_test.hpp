/*
 * Assignment 1 - Developing List Data Structures and Artificial Neural Networks
 * file : unit_test.hpp
 * Data Structures and Algorithms
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 10.9.2024
 */
#ifndef UNIT_TEST_HPP
#define UNIT_TEST_HPP

#include "../../include/list/listheader.h"
#include "../../include/util/Point.h"
#include "../main.hpp"
class UnitTest {
 public:
  UnitTest() {
    // test Array List
    UnitTest::registerTest("array01", &UnitTest::arrayList1);
    UnitTest::registerTest("array02", &UnitTest::arrayList2);
    UnitTest::registerTest("array03", &UnitTest::arrayList3);
    UnitTest::registerTest("array04", &UnitTest::arrayList4);
    UnitTest::registerTest("array05", &UnitTest::arrayList5);
    UnitTest::registerTest("array06", &UnitTest::arrayList6);
    UnitTest::registerTest("array07", &UnitTest::arrayList7);
    UnitTest::registerTest("array08", &UnitTest::arrayList8);
    UnitTest::registerTest("array09", &UnitTest::arrayList9);
    UnitTest::registerTest("array10", &UnitTest::arrayList10);
    UnitTest::registerTest("array11", &UnitTest::arrayList11);
    UnitTest::registerTest("array12", &UnitTest::arrayList12);
    UnitTest::registerTest("array13", &UnitTest::arrayList13);
    UnitTest::registerTest("array14", &UnitTest::arrayList14);
    UnitTest::registerTest("array15", &UnitTest::arrayList15);
    UnitTest::registerTest("array16", &UnitTest::arrayList16);
    UnitTest::registerTest("array17", &UnitTest::arrayList17);
    UnitTest::registerTest("array18", &UnitTest::arrayList18);
    UnitTest::registerTest("array19", &UnitTest::arrayList19);
    UnitTest::registerTest("array20", &UnitTest::arrayList20);
    UnitTest::registerTest("array21", &UnitTest::arrayList21);
    UnitTest::registerTest("array22", &UnitTest::arrayList22);
    UnitTest::registerTest("array23", &UnitTest::arrayList23);
    UnitTest::registerTest("array24", &UnitTest::arrayList24);
    UnitTest::registerTest("array25", &UnitTest::arrayList25);
    UnitTest::registerTest("array26", &UnitTest::arrayList26);
    UnitTest::registerTest("array27", &UnitTest::arrayList27);
    UnitTest::registerTest("array28", &UnitTest::arrayList28);
    UnitTest::registerTest("array29", &UnitTest::arrayList29);
    UnitTest::registerTest("array30", &UnitTest::arrayList30);
    UnitTest::registerTest("array31", &UnitTest::arrayList31);
    UnitTest::registerTest("array32", &UnitTest::arrayList32);
    // TODO unit new
  }

 private:
  bool arrayList1();
  bool arrayList2();
  bool arrayList3();
  bool arrayList4();
  bool arrayList5();
  bool arrayList6();
  bool arrayList7();
  bool arrayList8();
  bool arrayList9();
  bool arrayList10();
  bool arrayList11();
  bool arrayList12();
  bool arrayList13();
  bool arrayList14();
  bool arrayList15();
  bool arrayList16();
  bool arrayList17();
  bool arrayList18();
  bool arrayList19();
  bool arrayList20();
  bool arrayList21();
  bool arrayList22();
  bool arrayList23();
  bool arrayList24();
  bool arrayList25();
  bool arrayList26();
  bool arrayList27();
  bool arrayList28();
  bool arrayList29();
  bool arrayList30();
  bool arrayList31();
  bool arrayList32();
  // TODO unit new

 public:
  static map<string, bool (UnitTest::*)()> TESTS;
  // ANSI escape codes for colors
  const string green = "\033[32m";
  const string red = "\033[31m";
  const string cyan = "\033[36m";
  const string reset = "\033[0m";  // To reset to default color

  bool printResult(string output, string expect, string name) {
    if (expect == output) {
      cout << green << "test " + name + " --------------- PASS" << reset
           << "\n";
      return true;
    } else {
      cout << red << "test " + name + " --------------- FAIL" << reset << "\n";
      cout << "\texpect : " << expect << endl;
      cout << "\toutput : " << output << endl;
      return false;
    }
  }

  static void registerTest(string name, bool (UnitTest::*function)()) {
    if (TESTS.find(name) != TESTS.end()) {
      throw std::runtime_error("Test with name '" + name + "' already exists.");
    }
    TESTS[name] = function;
  }

  void runTest(const std::string &name) {
    auto it = TESTS.find(name);
    if (it != TESTS.end()) {
      (this->*(it->second))();  // Gọi hàm kiểm tra
    } else {
      throw std::runtime_error("Test with name '" + name + "' does not exist.");
    }
  }

  void runAllTests() {
    vector<string> fails;
    for (const auto &test : TESTS) {
      if (!(this->*(test.second))()) {
        fails.push_back(test.first);
      }
    }

    cout << cyan << "\nResult -------------------------" << reset << endl;
    // Print the results
    if (fails.empty()) {
      cout << green << "All tests passed!" << reset << endl;
    } else {
      int totalTests = TESTS.size();
      int failedTests = fails.size();
      int passedTests = totalTests - failedTests;
      double passRate =
          (totalTests > 0)
              ? (static_cast<double>(passedTests) / totalTests) * 100.0
              : 0.0;
      cout << red << "Some tests failed:";
      for (const auto &fail : fails) {
        cout << "  " << fail;
      }
      cout << cyan << "\nPass rate: " << passRate << "%" << reset << endl;
    }
  }
};

#endif  // UNIT_TEST_HPP