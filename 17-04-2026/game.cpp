#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

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
        cout << "Error: Could not open worldcities.csv" << endl;
        return 1;
    }

    string line;
    string input;

    char expectedLetter = '\0';
    cout << "--- Welcome to the Cities Game! ---" << endl;

    while (true) {
        if (expectedLetter == '\0') {
            cout << "Enter any city to start: ";
        } else {
            cout << "Enter a city starting with '" << (char)toupper(expectedLetter) << "': ";
        }
        getline(cin, input);

        if (input == "exit") {
            break;
        }

        if (input.empty()) continue;

        if (expectedLetter != '\0' && tolower(input[0]) != tolower(expectedLetter)) {
            cout << "Wrong letter! You must start with '" << (char)toupper(expectedLetter) << "'." << endl;
            continue;
        }

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
                if (field.front() == '"' && field.back() == '"') {
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

            if (!currentCity.empty() && tolower(currentCity[0]) == lastChar) {
                cout << "PC chooses: " << currentCity << " | Population: " << currentPop << endl;
                expectedLetter = tolower(currentCity[currentCity.length() - 1]);
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "No city found starting with the letter '" << lastChar << "'." << endl;
        }
        cout << "-------------------------------" << endl;
    }

    file.close();
    cout << "Game Over." << endl;
    return 0;
}