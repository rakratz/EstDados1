#include <iostream>
#include <locale>  // necess�rio para setlocale
#include <string>  // necess�rio para usar std::string e getline

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    string nomeCompleto;

    cout << "Digite seu nome completo: ";
    getline(cin, nomeCompleto);  // L� a linha inteira (com espa�os)

    cout << "Ol�, " << nomeCompleto << "! Seja bem-vindo � disciplina de Estrutura de Dados." << endl;

    return 0;
}
