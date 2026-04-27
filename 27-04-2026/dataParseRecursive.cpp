#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Person {
    string name;
    int score;
};

void parseJSON(string, vector<Person>&);
void printNames(vector<Person>&);

int main() {
    ifstream file("data.json");
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Read the entire file into a string
    stringstream ss;
    ss << file.rdbuf();
    string content = ss.str();
    file.close();

    vector<Person> people;
    
    parseJSON(content, people);

    printNames(people);
    return 0;
}

void printNames(vector<Person>& list) {
    double avg = 0;
    cout << "Names:" << endl;
    for (const auto& person : list) {
        cout << person.name << endl;
        avg += person.score;
    }
    cout << "\nAverage: " << avg / list.size() << endl;
}

void parseJSON(string data, vector<Person>& list) {
    string namekey = "\"fullName\": \"";
    int start = data.find(namekey);

    if (start == string::npos) {
        return;
    }

    // Name
    int nameStart = start + namekey.length();
    int nameEnd = data.find("\"", nameStart);
    string name = data.substr(nameStart, nameEnd - nameStart);

    // Score
    string scoreKey = "\"points\": ";
    int scoreStart = data.find(scoreKey, nameEnd) + scoreKey.length();
    // Finding the end of the score value, which can be ", space, newline, or }"
    int scoreEnd = data.find_first_of(", \n}", scoreStart);
    int score = stoi(data.substr(scoreStart, scoreEnd - scoreStart));

    string remainingData = data.substr(scoreEnd);

    list.push_back({name, score});

    parseJSON(remainingData, list);
}
