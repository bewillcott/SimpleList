#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Database {
private:
protected:
public:
  Database() {}
  ~Database() {}

  vector<vector<string>> mainList;
  string name;

  vector<vector<string>> read();
  void write(vector<vector<string>> mainList);
};

#endif