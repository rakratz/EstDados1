#include <iostream>
#include <locale>  // necessário para setlocale
#include <string>  // necessário para usar std::string e getline

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    string nomeCompleto;

    cout << "Digite seu nome completo: ";
    getline(cin, nomeCompleto);  // Lê a linha inteira (com espaços)

    cout << "Olá, " << nomeCompleto << "! Seja bem-vindo à disciplina de Estrutura de Dados." << endl;

    return 0;
}
