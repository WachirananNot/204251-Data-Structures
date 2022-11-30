#include<iostream>
#include "HW08.cpp"
using namespace std;

int main() {
    BST tree;
    tree.insert(8);
    tree.insert(5);
    tree.insert(17);
    tree.insert(13);
    tree.insert(12);
    tree.insert(14);
    tree.insert(32);
    tree.insert(25);
    tree.insert(40);
    tree.remove(17);
    cout << tree.get_depth(13) << endl;
    tree.remove(25);
    tree.remove(25);
    cout << tree.get_depth(8) << endl;
    cout << tree.get_depth(5) << endl;
    cout << tree.get_depth(17) << endl;
    
    cout << tree.get_depth(12) << endl;
    cout << tree.get_depth(14) << endl;
    cout << tree.get_depth(32) << endl;
    cout << tree.get_depth(25) << endl;
    cout << tree.get_depth(40) << endl;

    return 0;
}