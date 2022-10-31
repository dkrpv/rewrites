#include <matplot/matplot.h>
#include <random>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>

// try typedef a 3d vector later

const std::vector<double> testP1 { 1, 1 };
const std::vector<double> testP2 { 9, 9 };

class Student {
  public:
    double grade1;
    double grade2;
    std::string assess;
    int id;
};

std::vector<Student> fillDataSet() {
  std::vector<Student> testList;
  for(int i = 0; i < 100; i++) {
    Student newSt;
    newSt.grade1 = (rand() % 100);
    newSt.grade1 /= 10;
    newSt.grade2 = (rand() % 100);
    newSt.grade2 /= 10;
    if (((newSt.grade1 + newSt.grade2)/2) < 5) {
      newSt.assess = "Bad Student";
    } else {
      newSt.assess = "Good Student";
    }
    newSt.id = i;
    testList.push_back(newSt);
  }
  return testList;
}

std::vector<std::vector<std::vector<double>>> result(std::vector<Student> vct) {
  std::vector<std::vector<double>> boo, haa;

  for(int i = 0; i < vct.size(); i++) {
    std::vector<double> z, v, j { vct[i].grade1, vct[i].grade2 };
    std::transform(z.begin(), z.end(), testP1.begin(), z.begin(), std::minus<double>());
    std::transform(v.begin(), v.end(), testP2.begin(), v.begin(), std::minus<double>());
    double l1 = std::sqrt((pow(z[0], 2) + pow(z[1], 2)));
    double l2 = std::sqrt((pow(v[0], 2) + pow(v[1], 2)));
    if(l1 > l2) {
      boo.push_back(j);
    } else {
      haa.push_back(j);
    }
  }
  std::vector<std::vector<std::vector<double>>> res { boo, haa };
  return(res);
}

int main() {
    using namespace matplot;
    std::vector<Student> data = fillDataSet();
    std::vector<double> x1, y1, x2, y2;
    for(int i = 0; i < data.size(); i++) {
      x1.push_back(result(data)[0][i][0]);
      y1.push_back(result(data)[0][i][1]);
      x2.push_back(result(data)[1][i][0]);
      y2.push_back(result(data)[1][i][1]);
    }
    plot(x1, y2, "-o");
    return 0;
}
