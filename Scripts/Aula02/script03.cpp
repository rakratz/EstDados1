#include <iostream>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int a = 42;
    int* p = &a;

    cout << "Valor de a: " << a << endl;
    cout << "Endere�o de a (&a): " << &a << endl;
    cout << "Valor do ponteiro p: " << p << endl;
    cout << "Valor apontado por p (*p): " << *p << endl;
    cout << "Endere�o de p (&p): " << &p << endl;

    return 0;
}
