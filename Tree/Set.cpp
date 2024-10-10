#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    set<int> odds {1, 7, 5, 3, 9};
    set<int, greater<>> evens {2, 4, 6, 8};

    evens.insert(10);
    evens.insert(2);

    /*
    odds.insert(9);
    odds.insert(7);
    odds.insert(1);
    odds.insert(5);
    odds.insert(3);
    */

   if (evens.find(4) != evens.end()) {
        cout << "find 4!!" << endl;
   }

   if (evens.find(3) == evens.end()) {
        cout << "Can't find 3!!" << endl;
   }

    for (auto n : odds) {
        cout << n << " ";
    }
    cout << endl;


    for (auto n : evens) {
        cout << n << " ";
    }
    cout << endl;

    using psi = pair<string, int>; // string을 기준으로 정렬. string이 동일하면 int로 정렬 (오름차순)
    set</*pair<string, int>*/psi> managers {{"Amelia", 29}, {"Noah", 25}, {"Olivia", 31}};
    managers.insert({"George", 35});

    psi person1 = {"Noah", 25};

    if (managers.find(person1) != managers.end()) {
        cout << person1.first << " is a manager" << endl;
    }

    managers.erase({"Olivia", 31});
    managers.erase({"Noah", 30});

    for (const auto& p : managers) {
        cout << p.first << "is a manager. Age : " << p.second << endl;
    }
}