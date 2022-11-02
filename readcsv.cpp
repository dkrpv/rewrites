#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>

std::vector<std::vector<std::string>> getData(std::string file){
  std::fstream f;
  std::vector<std::vector<std::string>> res;
  std::string delimeter = ",";

  f.open(file, std::ios::in);
  std::string line = "";
  getline(f, line);
  int n = std::count(line.begin(), line.end(), ',');
  n = n+1;

  std::fstream fl;
  fl.open(file, std::ios::in);
  while(getline(fl, line)){
    std::vector<std::string> row;
    for(int i = 0; i < line.size(); i++){
      if(line[i] == ','){
        line[i] = ' ';
      } else {
        continue;
      }
    }
    row.push_back(line);
    res.push_back(row);
  }

  return res;
}

int main() {
  std::string fileName = "example.csv";
  std::vector<std::vector<std::string>> data = getData(fileName);

  for(int i = 0; i < data.size(); i++){
    for(int j = 0; j < data[i].size(); j++){
      std::cout << data[i][j] << std::endl;
    }
  }
  return 0;
}
