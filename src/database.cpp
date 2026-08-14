#include "include/database.h"

#include <vector>

/**
 * @brief Read-in the contents of the data file.
 *
 * @return vector<vector<string>> - a list containing the data.
 */
vector<vector<string>> Database::read() {
    string line;
    ifstream db;
    vector<vector<string>> mainList;

    db.open("db/lists.sl");
    vector<string> userList;

    if (db.is_open()) {
        cout << "Users in the list:\n";

        while (getline(db, line, '\n')) {
            if (line.front() == '#') {
                // cout << "Found a hashtag: " << line << "\n";
                line.erase(line.begin());
                cout << " * " << line << "\n";
                userList.push_back(line);
            } else if (line.front() == '%') {
                // cout << "Found a percentage: " << line << "\n";
                mainList.push_back(userList);
                userList.clear();
            } else {
                // cout << "Found an item: " << line << "\n";
                userList.push_back(line);
            }
        }

    } else {
        cout << "Cannot open file for reading.\n";
    }

    db.close();
    return mainList;
}

/**
 * @brief Write the data in the list to an external data file.
 *
 * @param mainList - contains the data to write out.
 */
void Database::write(vector<vector<string>> mainList) {
    ofstream db;
    db.open("db/lists.sl");

    if (db.is_open()) {
        for (unsigned int user_idx = 0; user_idx < mainList.size(); user_idx++) {
            for (unsigned int list_idx = 0; list_idx < mainList[user_idx].size(); list_idx++) {
                if (list_idx == 0) {
                    db << "#" << mainList[user_idx][list_idx] << "\n";
                } else {
                    db << mainList[user_idx][list_idx] << "\n";
                }
            }

            db << "%\n";
        }

    } else {
        cout << "Cannot open file for writing.\n";
    }

    db.close();
}
