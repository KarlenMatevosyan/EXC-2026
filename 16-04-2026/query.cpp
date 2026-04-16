#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

string clean(string s) {
    string res = "";
    for (char ch : s) {
        if (ch != '\"' && ch != '\r' && ch != '\n') res += ch;
    }
    return res;
}

class City {
    public:
    string city, country;
    int population, id;
    double lat, lng;

    City() {}

    void display() {
        cout << "ID: " << id << endl;
        cout << "City: " << city << endl;
        cout << "LAT: " << lat << endl;
        cout << "LNG: " << lng << endl;
        cout << "Country: " << country << endl;
        cout << "Population: " << population << endl;
    }

};

City parseCSVLine(string line) {
    City c;
    stringstream ss(line);
    string temp;
    string cols[8]; // id, city, lat, lng, country, iso2, iso3, population

    int i = 0;
    while (getline(ss, temp, ',') && i < 8) {
        cols[i] = clean(temp);
        i++;
    }

    try {
        c.id = stoi(cols[0]);
        c.city = cols[1];
        c.lat = stod(cols[2]);
        c.lng = stod(cols[3]);
        c.country = cols[4];
        c.population = stoll(cols[7]);
    } catch (...) {
        c.id = -1;
    }
    return c;
}

int main () {
    string query;
    cout << "Enter your query: ";
    getline(cin, query);

    string field = "", op = "", value = "";
    for (int i = 0; i < query.length(); i++) {
        if (query[i] == ' ') {
            continue;
        } 
        else if (query[i] == '=' || query[i] == '>' || query[i] == '<') {
            op += query[i];
        } 
        else if (op.empty()) {
            field += query[i];
        } 
        else {
            value += query[i];
        }
    }
    cout << "Field: " << field << endl; 
    cout << "Operator: " << op << endl;
    cout << "Value: " << value << endl;
    
    int targetValue = 0;
    ifstream file("worldcities.csv");
    string line;
    getline(file, line); 

while (getline(file, line)) {
    City c = parseCSVLine(line);
    bool isMatch = false;

    if (field == "city" || field == "population") {
        if (op == "<") isMatch = (c.population < targetValue);
        else if (op == ">") isMatch = (c.population > targetValue);
        else if (op == "==") isMatch = (c.population == targetValue);
        else if (op == "<=") isMatch = (c.population <= targetValue);
        else if (op == ">=") isMatch = (c.population >= targetValue);
    }
    else if (field == "lat" || field == "lng") {
        double currentCoord = (field == "lat") ? c.lat : c.lng;
        double target = stod(value);
        if (op == "<") isMatch = (currentCoord < target);
        else if (op == ">") isMatch = (currentCoord > target);
        else if (op == "==") isMatch = (currentCoord == target);
        else if (op == "<=") isMatch = (currentCoord <= target);
        else if (op == ">=") isMatch = (currentCoord >= target);
    }

    if (isMatch) {
        c.display();
        cout << "-----------------------" << endl;
    }
}
file.close();
   
return 0;
}