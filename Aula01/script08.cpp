#include <iostream>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    float nota;

    cout << "Digite a nota final do aluno (0 a 10): ";
    cin >> nota;

    if (nota < 0 || nota > 10) {
        cout << "Erro: nota inv�lida. Digite um valor entre 0 e 10." << endl;
    } else {
        char conceito;

        if (nota >= 9.0) {
            conceito = 'A';
        } else if (nota >= 7.0) {
            conceito = 'B';
        } else if (nota >= 5.0) {
            conceito = 'C';
        } else if (nota >= 3.0) {
            conceito = 'D';
        } else {
            conceito = 'F';
        }

        cout << "Nota: " << nota << " | Conceito: " << conceito << endl;

        if (conceito == 'A' || conceito == 'B') {
            cout << "Situa��o: Aprovado" << endl;
        } else if (conceito == 'C') {
            cout << "Situa��o: Em recupera��o" << endl;
        } else {
            cout << "Situa��o: Reprovado" << endl;
        }
    }

    return 0;
}
