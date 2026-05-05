#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string RESET = "\033[0m";

class City {
public:
    string cityName;
    long long population;

    City() : cityName(""), population(0) {}

    void display() {
        cout << "City: " << cityName << ", Population: " << population << endl;
    }
};

int main() {
    ifstream file("worldcities.csv");
    if (!file.is_open()) {
        cout << RED << "Error: Could not open worldcities.csv" << RESET << endl;
        return 1;
    }

    string line;
    string input;
    set<string> usedCities;

    char expectedLetter = '\0';
    cout << "--- Welcome to the Cities Game! ---" << endl;

    while (true) {
        if (expectedLetter == '\0') {
            cout << GREEN << "Enter any city to start: " << RESET;
        } else {
            cout << GREEN << "Enter a city starting with '" << (char)toupper(expectedLetter) << "': " << RESET;
        }
        getline(cin, input);

        if (input == "exit") {
            break;
        }

        if (input.empty()) {
            continue;
        }

        if (input == "help") {
            if (expectedLetter == '\0') {
                cout << "Hint: Try starting with 'Tokyo'!" << endl;
            } else {
                file.clear();
                file.seekg(0);
                getline(file, line); 
                bool helpFound = false;
                while (getline(file, line)) {
                    stringstream ss(line); 
                    string field, currentCity;
                    int i = 0;
                    while (getline(ss, field, ',')) {
                        if (field.front() == '"' && field.back() == '"') {
                            field = field.substr(1, field.length() - 2);
                        }
                        if (i == 1) { 
                            currentCity = field; break;
                        }
                        i++;
                    }
                    if (!currentCity.empty() && tolower(currentCity[0]) == tolower(expectedLetter) && usedCities.find(currentCity) == usedCities.end()) {
                        cout << "Hint: How about '" << currentCity << "'?" << endl;
                        helpFound = true;
                        break;
                    }
                }
                if (!helpFound) {
                    cout << RED << "No cities found for hint!" << RESET << endl;
                }
            }
            continue;
        }

        if (usedCities.find(input) != usedCities.end()) {
            cout << RED << "That city has already been used! Try another one." << RESET << endl;
            continue;
        }

        if (expectedLetter != '\0' && tolower(input[0]) != tolower(expectedLetter)) {
            cout << RED << "Wrong letter! You must start with '" << (char)toupper(expectedLetter) << "'." << RESET << endl;
            continue;
        }

        bool inputExists = false;
        file.clear();
        file.seekg(0);
        getline(file, line); 
        while (getline(file, line)) {
            stringstream ss(line);
            string field, currentCity;
            int i = 0;
            while (getline(ss, field, ',')) {
                if (!field.empty() && field.front() == '"' && field.back() == '"') {
                    field = field.substr(1, field.length() - 2);
                }
                if (i == 1) { 
                    currentCity = field; break; 
                }
                i++;
            }
            if (currentCity == input) {
                inputExists = true;
                break;
            }
        }

        if (!inputExists) {
            cout << RED << "That city is not in our database! Try another city." << RESET << endl;
            continue;
        }

        usedCities.insert(input);

        char lastChar = tolower(input[input.length() - 1]);
        bool found = false;

        file.clear();
        file.seekg(0);
        getline(file, line); 

        while (getline(file, line)) {
            stringstream ss(line);
            string field;
            string currentCity;
            string currentPop;
            
            int i = 0;
            while (getline(ss, field, ',')) {
                if (!field.empty() && field.front() == '"' && field.back() == '"') {
                    field = field.substr(1, field.length() - 2);
                }

                if (i == 1) {
                    currentCity = field;
                }
                if (i == 7) {
                    currentPop = field;
                }
                i++;
            }

            if (!currentCity.empty() && tolower(currentCity[0]) == lastChar && usedCities.find(currentCity) == usedCities.end()) {
                cout << "PC chooses: " << currentCity << " | Population: " << currentPop << endl;
                usedCities.insert(currentCity);
                expectedLetter = tolower(currentCity[currentCity.length() - 1]);
                found = true;
                break;
            }
        }

        if (!found) {
            cout << RED << "No unused city found starting with the letter '" << lastChar << "'. You win!" << RESET << endl;
            break; 
        }
        cout << "-------------------------------" << endl;
    }

    file.close();
    cout << GREEN << "Game Over." << RESET << endl;
    return 0;
}