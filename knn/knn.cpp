#include <matplot/matplot.h>
#include <random>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>
#include <limits>

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

std::string result(std::vector<Student> vct, std::vector<double> usr) {
  std::string res;
  double max = std::numeric_limits<double>::infinity();
  for(int i = 0; i < vct.size(); i++) {
    std::vector<double> z;
    z.push_back(vct[i].grade1);
    z.push_back(vct[i].grade2);
    std::string tmp = vct[i].assess;
    std::transform(z.begin(), z.end(), usr.begin(), z.begin(), std::minus<double>());
    double l = std::sqrt((pow(z[0], 2) + pow(z[1], 2)));
    if(l < max){
      max = l;
      res = tmp;
    }
  }
  return(res);
}

void plotMe(std::vector<Student> vct) {
  using namespace matplot;
  std::vector<double> x;
  std::vector<double> y;
  for(int i = 0; i < vct.size(); i++) {
    x.push_back(vct[i].grade1);
    y.push_back(vct[i].grade2);
  }
  scatter(x,y);
  show();
}

int main() {
    double x, y;
    std::vector<Student> data = fillDataSet();
    plotMe(data);
    std::vector<double> usr;
    std::cout << "Enter grades: " << std::endl;
    std::cin >> x >> y;
    usr.push_back(x);
    usr.push_back(y);
    std::cout << result(data, usr) << std::endl;
    return 0;
}
