#include "include/list.h"

void List::print_menu() {
  int choice;

  cout << "\n********************\n";
  cout << " 1 - Print List.\n";
  cout << " 2 - Add to list.\n";
  cout << " 3 - Delete from list.\n";
  cout << " 4 - Quit.\n";
  cout << " Enter your choice and press return/enter.\n";

  cin >> choice;

  if (choice == 4) {
    return;
  } else if (choice == 3) {
    delete_item();
  } else if (choice == 2) {
    add_item();
  } else if (choice == 1) {
    print_list();
  } else {
    cout << "Sorry choice hasn't been implemented\n";
  }
}

void List::add_item() {
  cout << "\n*** Add Item ***\n";
  cout << "Type in an item and press enter: ";

  string item;
  cin >> item;

  list.push_back(item);

  cout << "Successfully added an item to the list.\n\n\n\n";
  cin.clear();

  print_menu();
}

void List::delete_item() {
  cout << "\n*** Delete Item ***\n";
  cout << "Select an item index number to delete.\n";

  if (list.size()) {
    for (unsigned long int i = 0; i < list.size(); i++) {
      cout << i << ": " << list[i] << endl;
    }

    int choiceNum;
    cin >> choiceNum;

    list.erase(list.begin() + choiceNum);

  } else {
    cout << "No items in the list to delete.\n";
  }

  print_menu();
}

void List::print_list() {
  cout << "\n*** Printing List ***\n";

  for (unsigned long int idx = 1; idx < list.size(); idx++) {
    cout << " " << idx << " " << list[idx] << "\n";
  }

  cout << "M - Menu\n";
  char choice;
  cin >> choice;

  if (choice == 'M' || choice == 'm') {
    print_menu();
  } else {
    cout << "Invalid Choice. Quitting.\n";
  }
}

void List::find_userList() {
  bool userFound = false;

  cout << "\n*** Welcome " << name << " ***\n";

  for (unsigned int user_idx = 0; user_idx < mainList.size(); user_idx++) {
    cout << mainList[user_idx][0] << "\n";

    if(mainList[user_idx][0] == name){
      cout << "User has been found: " << mainList[user_idx][0] << "\n";
      list = mainList[user_idx];
      userFound = true;
      break;
    }
  }
}