#include <iostream>
#include "HW03.cpp"
using namespace std;

int main()
{

cout << "Simple testcase from GitHub\n";

    Polynomial f1;
    Polynomial f2;

    // f1 = 5x^8 + 4x^3 + 2x
    f1.addTerm(5, 8);
    f1.addTerm(4, 3);
    f1.addTerm(2, 1);
    cout << "f1 = ";
    f1.printPolynomial();

    // f2 = 4x^5 + x - 5
    f2.addTerm(4, 5);
    f2.addTerm(1, 1);
    f2.addTerm(-5, 0);
    cout << "f2 = ";
    f2.printPolynomial();

    // f1 - f2 = 5x^8 - 4x^5 + 4x^3 + x - 5
    f1.minus(f2);
    cout << "f1 - f2 = ";
    f1.printPolynomial();

    Polynomial f3;
    Polynomial f4;

    cout << "\nAdding 2 polynomials where the left one has less terms than the right.\n";

    // f3 = x
    f3.addTerm(1, 1);
    cout << "f3 = ";
    f3.printPolynomial();

    // f4 = x^4 + x^3 + x^2 + 1
    f4.addTerm(1, 4);
    f4.addTerm(1, 3);
    f4.addTerm(1, 2);
    f4.addTerm(1, 0);
    cout << "f4 = ";
    f4.printPolynomial();

    // f3 + f4 = x^4 + x^3 + x^2 + x + 1
    f3.plus(f4);
    cout << "f3 + f4 = ";
    f3.printPolynomial();

    cout << "\nAdding a polynomial into the one with no terms\n";

    Polynomial f5;
    Polynomial f6;

    // f5 = 0;
    cout << "f5 = ";
    f5.printPolynomial();

    // f6 = x + x^2
    f6.addTerm(1, 1);
    f6.addTerm(1, 2);
    cout << "f6 = ";
    f6.printPolynomial();

    // f5 + f6 MUST BE x^2 + x (sorted by degrees)
    f5.plus(f6);
    cout << "f5 + f6 = ";
    f5.printPolynomial();

    cout << "\nTry adding itself\n";
    Polynomial f7;
    f7.addTerm(1, 1);
    cout << "f7 = ";
    f7.printPolynomial();

    f7.plus(f7);
    cout << "f7 + f7 = ";
    f7.printPolynomial();

    f7.minus(f7);
    cout << "f7 - f7 = ";
    f7.printPolynomial();
    return 0;
}