#ifndef LIST_H
#define LIST_H

#include "database.h"

/**
 * @brief The List class stores the active user list,
 * and provides functions to process that list.
 */
class List {
  private:
    unsigned long getNum();

  protected:
  public:
    List() {}
    ~List() {}

    Database data;
    vector<vector<string>> mainList;
    vector<string> list;
    string name;
    unsigned int currentUserIndex;

    void print_menu();
    void print_list();
    void add_item();
    void delete_item();
    bool find_userList();
    void save_list();
};

#endif