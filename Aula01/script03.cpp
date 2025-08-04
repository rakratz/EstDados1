#include <iostream>
#include <locale>  // necess√°rio para setlocale

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    cout << "CMP2106 - Estrutura de Dados I" << endl;
    cout << "Bem-vindo(a) ‡ primeira aula pr·tica da disciplina!" << endl;
    cout << "LaboratÛrio: 02 C 101 | Professor: Ricardo Kratz" << endl;
    cout << "Data: 06/08/2025";

    return 0;
}
