#include <iostream>
#include <locale>  // necessário para setlocale

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    cout << "Ol�, mundo!" << endl;
    cout << "Resultado da soma: " << 2 + 3 << endl;

    return 0;
}
