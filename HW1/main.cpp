#include "HW01.cpp"
#include <iostream>
using namespace std;

int main() {
    CardList L{};

    L.pop_back();
    L.pop_back();
    L.pop_back();
    L.pop_back();
    L.pop_back();
    L.pop_back();
    L.insert_back("A");
    L.printCardList();
    L.shuffle(-1);
    L.shuffle(0);
    L.shuffle(1);
    L.shuffle(2);
    cout << "DONE\n";
    return 0;
}
