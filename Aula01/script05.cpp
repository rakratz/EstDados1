#include <iostream>
#include <locale>

using namespace std;

int main() {    
    setlocale(LC_ALL, "Portuguese");
    
    int a = 10, b = 3;

    cout << "Soma: " << a + b << endl;
    cout << "Subtração: " << a - b << endl;
    cout << "Multiplicação: " << a * b << endl;
    cout << "Divisão: " << a / b << endl;
    cout << "Resto: " << a % b << endl;

    return 0;
}