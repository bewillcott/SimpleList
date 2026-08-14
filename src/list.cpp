#include "include/list.h"

#include <string>

/**
 * @brief Print the menu to the terminal.
 */
void List::print_menu() {
    unsigned long choice;

    cout << "\n********************\n";
    cout << " 1 - Print List.\n";
    cout << " 2 - Add to list.\n";
    cout << " 3 - Delete from list.\n";
    cout << " 4 - Save the list.\n";
    cout << " 5 - Quit.\n";
    cout << "\n Enter your choice: ";

    choice = getNum();

    if (choice == 5) {
        return;
    } else if (choice == 4) {
        save_list();
    } else if (choice == 3) {
        delete_item();
    } else if (choice == 2) {
        add_item();
    } else if (choice == 1) {
        print_list();
    } else {
        print_menu();
    }
}

/**
 * @brief Add an item to the list.
 * The user enters the text of the new item.
 */
void List::add_item() {
    cout << "\n*** Add Item ***\n";
    cout << "Type in an item and press enter: ";

    string item;
    cin >> item;

    list.push_back(item);

    cout << "\nSuccessfully added an item to the list.\n\n";
    cin.clear();

    print_menu();
}

/**
 * @brief Delete an item from the list.
 * The user enters the number of the required entry.
 */
void List::delete_item() {
    cout << "\n*** Delete Item ***\n";

    if (list.size()) {
        for (unsigned long int i = 1; i < list.size(); i++) {
            cout << i << ": " << list[i] << endl;
        }

        cout << "\nSelect an item index number to delete: ";
        unsigned long choiceNum = getNum();

        if (choiceNum > 0 && choiceNum < list.size()) {
            list.erase(list.begin() + choiceNum);
        }

    } else {
        cout << "\nNo items in the list to delete.\n\n";
    }

    print_menu();
}

/**
 * @brief Print the list to the terminal.
 */
void List::print_list() {
    cout << "\n*** Printing List ***\n";

    for (unsigned long int idx = 1; idx < list.size(); idx++) {
        cout << " " << idx << " " << list[idx] << "\n";
    }

    cout << "\nPress enter to return to the menu: ";

    char c;
    cin.get(c);  // get a single character

    print_menu();
}

/**
 * @brief Find the user in the list.
 *
 * @return true - if found.
 * @return false - if not found.
 */
bool List::find_userList() {
    bool userFound = false;

    cout << "\n*** Welcome " << name << " ***\n";

    for (unsigned int user_idx = 0; user_idx < mainList.size(); user_idx++) {
        // cout << mainList[user_idx][0] << "\n";

        if (mainList[user_idx][0] == name) {
            cout << "You are in the list.\n";
            list             = mainList[user_idx];
            currentUserIndex = user_idx;
            userFound        = true;
            break;
        }
    }

    if (!userFound) {
        cout << "You are not in the list.\nYou will be added.";
        list.push_back(name);
        mainList.push_back(list);
        currentUserIndex = mainList.size() - 1;
    }

    return userFound;
}

/**
 * @brief Save the list to persistent storage.
 */
void List::save_list() {
    cout << "Saving the list ...\n";

    mainList[currentUserIndex] = list;
    data.write(mainList);
    print_menu();
}

/**
 * @brief Get a number from the user.
 *
 * @return unsigned long - 0: if non-integer provided.
 */
unsigned long List::getNum() {
    unsigned long choice;
    string line;

    getline(cin, line);

    if (!line.empty() && line.find_first_not_of("0123456789") == string::npos) {
        choice = stoul(line);
    } else {
        choice = 0;
    }

    return choice;
}