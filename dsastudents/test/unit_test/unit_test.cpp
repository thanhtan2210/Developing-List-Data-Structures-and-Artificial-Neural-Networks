/*
 * Assignment 1 - Developing List Data Structures and Artificial Neural Networks
 * file : unit_test.cpp
 * Data Structures and Algorithms
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 10.9.2024
 */
#include "unit_test.hpp"
map<string, bool (UnitTest::*)()> UnitTest::TESTS;

ostream &operator<<(ostream &os, const Point &point) {
  os << "P(" << fixed << setw(6) << setprecision(2) << point.x << "," << setw(6)
     << setprecision(2) << point.y << "," << setw(6) << setprecision(2)
     << point.z << ")";
  return os;
}

bool UnitTest::arrayList1() {
  string name = "array1";
  //! data
  XArrayList<int> list;

  //! expect
  string expect = "[]\nsize=0\nempty=1";

  //! output
  string output = list.toString() + "\nsize=" + to_string(list.size()) +
                  "\nempty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList2() {
  string name = "array2";
  //! data
  XArrayList<int> list;
  list.add(0);

  //! expect
  string expect = "[0]\nsize=1\nempty=0";

  //! output
  string output = list.toString() + "\nsize=" + to_string(list.size()) +
                  "\nempty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList3() {
  string name = "array3";
  //! data
  XArrayList<int> list;
  list.add(0);
  list.add(1);
  list.add(2);
  list.add(3);
  list.add(4);
  list.add(5);
  list.add(6);
  list.add(7);
  list.add(8);
  list.add(9);
  list.add(10);

  //! expect
  string expect = "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]\nsize=11\nempty=0";

  //! output
  string output = list.toString() + "\nsize=" + to_string(list.size()) +
                  "\nempty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList4() {
  string name = "array4";
  //! data
  XArrayList<int> list;
  list.add(0, 0);
  list.add(0, 1);
  list.add(0, 2);
  list.add(2, 3);

  //! expect
  string expect = "[2, 1, 3, 0]\nsize=4";

  //! output
  string output = list.toString() + "\nsize=" + to_string(list.size());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList5() {
  string name = "array5";
  //! data
  XArrayList<int> list;
  list.add(0);
  list.add(0, 1);
  list.add(1, 2);
  list.add(3, 3);
  list.add(2, 4);
  list.add(4, 5);
  list.add(6);
  list.add(6, 7);
  list.add(0, 8);
  list.add(1, 9);
  list.add(2, 10);

  //! expect
  string expect = "[8, 9, 10, 1, 2, 4, 0, 5, 3, 7, 6]\nsize=11";

  //! output
  string output = list.toString() + "\nsize=" + to_string(list.size());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList6() {
  string name = "array6";
  //! data
  XArrayList<int> list;

  //! expect
  string expect = "Error: Out of range exception: Index is out of range!";

  //! output
  string output = "";
  try {
    list.add(1, 0);
  } catch (const std::out_of_range &e) {
    output = "Error: Out of range exception: " + string(e.what());
  }

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList7() {
  string name = "array7";
  //! data
  XArrayList<int> list;
  list.add(0, 0);
  list.add(0, 1);
  list.add(0, 2);

  //! expect
  string expect = "Error: Out of range exception: Index is out of range!";

  //! output
  string output = "";
  try {
    list.add(-1, 3);
  } catch (const std::out_of_range &e) {
    output = "Error: Out of range exception: " + string(e.what());
  }
  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList8() {
  string name = "array8";
  //! data
  XArrayList<int> list;

  //! expect
  string expect = "Error: Out of range exception: Index is out of range!";

  //! output
  string output = "";
  try {
    list.removeAt(0);
  } catch (const std::out_of_range &e) {
    output = "Error: Out of range exception: " + string(e.what());
  }

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList9() {
  string name = "array9";
  //! data
  XArrayList<int> list;
  list.add(0, 0);
  list.add(0, 1);
  list.add(0, 2);

  //! expect
  string expect = "Error: Out of range exception: Index is out of range!";

  //! output
  string output = "";
  try {
    list.removeAt(3);
  } catch (const std::out_of_range &e) {
    output = "Error: Out of range exception: " + string(e.what());
  }
  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList10() {
  string name = "array10";
  //! data
  XArrayList<int> list;
  list.add(0);
  list.removeAt(0);
  //! expect
  string expect = "[]\nsize=0\nempty=1";

  //! output
  string output = list.toString() + "\nsize=" + to_string(list.size()) +
                  "\nempty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList11() {
  string name = "array11";
  //! data
  XArrayList<int> list;
  list.add(0);
  list.add(1);
  list.add(2);
  list.removeAt(1);
  list.add(1, 1);
  list.removeAt(2);
  //! expect
  string expect = "[0, 1];size=2;empty=0";

  //! output
  string output = list.toString() + ";size=" + to_string(list.size()) +
                  ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList12() {
  string name = "array12";
  //! data
  XArrayList<int> list;
  list.add(0);

  //! expect
  string expect = "removeItem=1;[];size=0;empty=1";

  //! output
  string output = "removeItem=" + to_string(list.removeItem(0)) + ";";
  output += list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList13() {
  string name = "array13";
  //! data
  XArrayList<int> list;
  list.add(0);

  //! expect
  string expect = "removeItem=0;[0];size=1;empty=0";

  //! output
  string output = "removeItem=" + to_string(list.removeItem(1)) + ";";
  output += list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList14() {
  string name = "array14";
  //! data
  XArrayList<int> list;
  list.add(0);
  list.add(1);
  list.add(2);
  list.add(1);

  //! expect
  string expect = "removeItem=1;[0, 2, 1];size=3;empty=0";

  //! output
  string output = "removeItem=" + to_string(list.removeItem(1)) + ";";
  output += list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList15() {
  string name = "array15";
  //! data
  XArrayList<int> list;
  list.add(0);
  list.add(1);
  list.add(2);
  list.add(1);

  //! expect
  string expect = "removeItem=1;[0, 2, 1];size=3;empty=0";

  //! output
  string output = "removeItem=" + to_string(list.removeItem(1)) + ";";
  output += list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList16() {
  string name = "array16";
  //! data
  XArrayList<int> list;
  list.add(0);
  list.add(1);
  list.add(2);
  list.add(1);

  //! expect
  string expect = "removeItem=0;[0, 1, 2, 1];size=4;empty=0";

  //! output
  string output = "removeItem=" + to_string(list.removeItem(-1)) + ";";
  output += list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList17() {
  string name = "array17";
  //! data
  XArrayList<int> list;
  list.clear();
  list.add(0);
  list.add(1);
  list.add(2);
  list.add(1);
  list.clear();
  list.add(2);
  list.add(1);
  list.clear();
  //! expect
  string expect = "[];size=0;empty=1";

  //! output
  string output = list.toString() + ";size=" + to_string(list.size()) +
                  ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList18() {
  string name = "array18";
  //! data
  XArrayList<int> list;

  //! expect
  string expect = "Error: Out of range exception: Index is out of range!";

  //! output
  string output = "";
  try {
    list.get(0);
  } catch (const std::out_of_range &e) {
    output = "Error: Out of range exception: " + string(e.what());
  }
  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList19() {
  string name = "array19";
  //! data
  XArrayList<int> list;
  list.add(0);
  list.add(1);
  list.add(2);

  //! expect
  string expect = "Error: Out of range exception: Index is out of range!";

  //! output
  string output = "";
  try {
    list.get(-1);
  } catch (const std::out_of_range &e) {
    output = "Error: Out of range exception: " + string(e.what());
  }
  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList20() {
  string name = "array20";
  //! data
  XArrayList<int> list;
  list.add(0);
  list.add(10);
  list.add(2);

  //! expect
  string expect = "get=10;[0, 10, 2];size=3;empty=0";

  //! output
  string output = "get=" + to_string(list.get(1)) + ";";
  output += list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList21() {
  string name = "array21";
  //! data
  XArrayList<int> list;
  list.clear();
  list.add(0);
  list.add(1);
  list.add(2);
  list.add(1);

  //! expect
  string expect = "Index of item 1: 1";

  //! output
  int index = list.indexOf(1);
  string output = "Index of item 1: " + to_string(index);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList22() {
  string name = "array22";
  //! data
  XArrayList<int> list;
  list.clear();
  list.add(0);
  list.add(1);
  list.add(2);
  list.add(1);

  //! expect
  string expect = "Index of item 1: -1";

  //! output
  int index = list.indexOf(-1);
  string output = "Index of item 1: " + to_string(index);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList23() {
  string name = "array23";
  //! data
  XArrayList<int> list;
  list.clear();
  list.add(0);
  list.add(1);
  list.add(2);

  //! expect
  string expect = "Contains item 1: true";

  //! output
  bool contains = list.contains(1);
  string output = "Contains item 1: " + string(contains ? "true" : "false");

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList24() {
  string name = "array24";
  //! data
  XArrayList<int> list;
  list.clear();
  list.add(0);
  list.add(1);
  list.add(2);

  //! expect
  string expect = "Contains item 1: false";

  //! output
  bool contains = list.contains(3);
  string output = "Contains item 1: " + string(contains ? "true" : "false");

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList25() {
  string name = "array25";
  //! data
  XArrayList<Point> list;
  list.add(Point(23.2f, 25.4f));
  list.add(Point(24.6f, 23.1f));

  //! expect
  string expect = "[34.400581, 33.745667]";

  //! output
  string output = list.toString(&Point::point2float);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList26() {
  string name = "array26";
  //! data
  XArrayList<Point> list;
  list.add(Point(23.2f, 25.4f));
  list.add(Point(24.6f, 23.1f));

  //! expect
  string expect = "[P( 23.20, 25.40,  0.00), P( 24.60, 23.10,  0.00)]";

  //! output
  string output = list.toString(&Point::point2str);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList27() {
  string name = "array27";
  //! data
  XArrayList<Point> list(0, &Point::pointEQ);
  list.add(Point(3.f, 4.f));
  list.add(Point(4.f, 3.f));

  //! expect
  string expect = "Index of item 1: -1";

  //! output
  int index = list.indexOf(Point(3.f, 5.f));
  string output = "Index of item 1: " + to_string(index);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList28() {
  string name = "array28";
  //! data
  XArrayList<Point> list(0, &Point::pointEQ);
  list.add(Point(3.f, 4.f));
  list.add(Point(4.f, 3.f));

  //! expect
  string expect = "Index of item 1: 1";

  //! output
  int index = list.indexOf(Point(4.f, 3.f));
  string output = "Index of item 1: " + to_string(index);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList29() {
  string name = "array29";
  //! data
  XArrayList<Point> list(0, &Point::pointEQx);
  list.add(Point(3.f, 4.f));
  list.add(Point(4.f, 3.f));

  //! expect
  string expect = "Contains item 1: true";

  //! output
  bool contains = list.contains(Point(3.f, 5.f));
  string output = "Contains item 1: " + string(contains ? "true" : "false");

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList30() {
  string name = "array30";
  //! data
  XArrayList<Point *> list(&XArrayList<Point *>::free, &Point::pointEQ);
  list.add(new Point(23.2f, 25.4f));
  list.add(new Point(24.6f, 23.1f));
  list.add(new Point(12.5f, 22.3f));

  //! expect
  string expect =
      "[P( 23.20, 25.40,  0.00), P( 24.60, 23.10,  0.00), P( 12.50, 22.30,  "
      "0.00)]";

  //! output
  string output = list.toString(&Point::point2str);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList31() {
  string name = "array31";
  //! data
  XArrayList<Point *> list(&XArrayList<Point *>::free, &Point::pointEQ);
  list.add(new Point(23.2f, 25.4f));
  list.add(new Point(24.6f, 23.1f));
  list.add(new Point(12.5f, 22.3f));
  list.clear();
  //! expect
  string expect = "[]";

  //! output
  string output = list.toString(&Point::point2str);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool UnitTest::arrayList32() {
  string name = "array32";
  //! data
  XArrayList<Point *> list(&XArrayList<Point *>::free, &Point::pointEQ);
  list.add(new Point(23.2f, 25.4f));
  list.add(new Point(24.6f, 23.1f));
  list.add(new Point(12.5f, 22.3f));
  Point p = Point(23.2f, 25.4f);

  //! expect
  string expect = "removeItem=1";

  //! output

  string output =
      "removeItem=" + to_string(list.removeItem(&p, &Point::pointRemove)) + ";";

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
