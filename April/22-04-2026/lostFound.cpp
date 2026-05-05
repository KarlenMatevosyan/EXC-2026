#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> lostItems;

void addLostItem(string item, int time) {
    int i = 2;
    if (lostItems[item] != time) {
        lostItems[item] = time;
    } else {
        string temp = item + to_string(i);
        lostItems[temp] = time;
    }
}

void searchItem(string item) {
    if (lostItems.find(item) != lostItems.end()) {
        cout << "Item: " << item << ", Time Lost: " << lostItems[item] << endl;
    } else {
        cout << "Item not found." << endl;
    }

}

void queryByTime(int time) {
    for (auto item : lostItems) {
        if (item.second <= time) {
            cout << "Item: " << item.first << ", Time Lost: " << item.second << endl;
        }
    }
}

int main () {
    string command;
    cout << "Enter command (add/search/query/exit): ";
    while (cin >> command) {
        if (command == "add") {
            string addItem;
            int lostTime;
            cout << "Enter the item you want to add: ";
            cin >> addItem;
            cout << "Enter the time you lost item: ";
            cin >> lostTime;
            addLostItem(addItem, lostTime);
            cout << "Enter command (add/search/query/exit): ";
        } else if (command == "search") {
            string item;
            cout << "Enter the item you want to search: ";
            cin >> item;
            searchItem(item);
            cout << "Enter command (add/search/query/exit): ";
        } else if (command == "query") {
            int queryTime;
            cout << "Enter the time: ";
            cin >> queryTime;
            queryByTime(queryTime);
            cout << "Enter command (add/search/query/exit): ";
        } else if (command == "exit") {
            break;
        } else if (command == "sort") {
            cout << "Enter command (add/search/query/exit): ";
        }
            else {
            cout << "Invalid command, please enter valid command..." << endl;
        }
    }
    return 0;
}