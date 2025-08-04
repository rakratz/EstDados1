#include <iostream>
#include <locale>

using namespace std;

int main() {    
    setlocale(LC_ALL, "Portuguese");

    int notas[5] = {7, 8, 9, 5, 6};

    for (int i = 0; i < 5; i++) {
        if (notas[i] >= 7) {
            cout << "Aluno " << i << " aprovado com nota " << notas[i] << endl;
        } else {
            cout << "Aluno " << i << " reprovado com nota " << notas[i] << endl;
        }
    }

    return 0;
}