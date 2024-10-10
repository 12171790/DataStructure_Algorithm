#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, int> fruits;
    fruits.insert({"banana", 1500}); // pair 형태로 삽입됨
    fruits.insert({"apple", 1000}); 
    fruits["orange"] = 3000;
    fruits["grape"] = 5000;
    fruits["lemon"] = 4000;

    fruits.erase("grape");

    for (const auto& p : fruits) {
        cout << p.first << " is " << p.second << " won." << endl;
    }
}