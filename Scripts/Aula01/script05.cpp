#include <iostream>
#include <locale>

using namespace std;

int main() {    
    setlocale(LC_ALL, "Portuguese");
    
    int a = 10, b = 3;

    cout << "Soma: " << a + b << endl;
    cout << "Subtra��o: " << a - b << endl;
    cout << "Multiplica��o: " << a * b << endl;
    cout << "Divis�o: " << a / b << endl;
    cout << "Resto: " << a % b << endl;

    return 0;
}