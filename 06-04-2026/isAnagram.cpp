#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram (string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }
    
    unordered_map<char, int> res;
    
    for (char c : s) {
        res[c]++;
    }
    
    for (char c : t) {
        if (res.find(c) == res.end() || res[c] == 0) {
            return false;
        }
        res[c]--;
    }
    return true;
}

int main() {
    string s1, s2;
    
    cout << "Enter first string: ";
    getline(cin, s1);
    
    cout << "Enter second string: ";
    getline(cin, s2);
    
    if (isAnagram(s1, s2)) {
        cout << s1 << " and " << s2 << " are anagrams. " << endl;
    } else {
        cout << s1 << " and " << s2 << " are not anagrams... " << endl;
    }
    
    return 0;
}
