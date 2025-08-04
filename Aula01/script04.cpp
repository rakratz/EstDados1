#include <iostream>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    string nome;
    int idade;

    cout << "Digite seu nome: ";
    cin >> nome;

    cout << "Digite sua idade: ";
    cin >> idade;

    cout << endl;
    cout << "Olá, " << nome << "! Você tem " << idade << " anos." << endl;

    return 0;
}