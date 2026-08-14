#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief The Database class provides functions to access
 * data stored in an external data file.
 */
class Database {
  private:
  protected:
  public:
    Database() {}
    ~Database() {}

    string name;

    vector<vector<string>> read();
    void write(vector<vector<string>> mainList);
};

#endif