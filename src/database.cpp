#include "include/database.h"
#include <vector>

vector<vector<string> > Database::read() {
	string line;
	ifstream db;

	db.open("db/lists.sl");
	vector<string> userList;

	if (db.is_open()) {
		while (getline(db, line, '\n')) {
			if (line.front() == '#') {
				cout << "Found a hashtag: " << line << "\n";
				line.erase(line.begin());
				userList.push_back(line);
			} else if (line.front() == '%') {
				cout << "Found a percentage: " << line << "\n";
				mainList.push_back(userList);
				userList.clear();
			} else {
				cout << "Found an item: " << line << "\n";
				userList.push_back(line);
			}
		}
	} else {
		cout << "Cannot open file for reading.\n";
	}

	db.close();
	return mainList;
}

void Database::write(vector<vector<string> > mainList) {
	ofstream db;
	db.open("db/lists.sl");

	if (db.is_open()) {
		for (unsigned int user_idx = 0; user_idx < mainList.size(); user_idx++) {
			for (unsigned int list_idx; list_idx < mainList[user_idx].size();      list_idx++) {






				if (list_idx == 0) {
					db << mainList[user_idx][list_idx] << "\n";
				}
				db << mainList[user_idx][list_idx] << "\n";
			}
		}

	} else {
		cout << "Cannot open file for writing.\n";
	}

	db.close();
}
