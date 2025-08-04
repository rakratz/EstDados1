#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    while (true) {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Exibir nome do aluno" << endl;
        cout << "2. Somar dois n�meros" << endl;
        cout << "3. Calcular fatorial" << endl;
        cout << "4. Verificar se n�mero � par ou �mpar" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma op��o: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                cin.ignore(); // limpar buffer
                string nome;
                cout << "Digite seu nome completo: ";
                getline(cin, nome);
                cout << "Bem-vindo(a), " << nome << "!" << endl;
                break;
            }

            case 2: {
                int a, b;
                cout << "Digite dois n�meros: ";
                cin >> a >> b;
                cout << "Soma: " << a + b << endl;
                break;
            }

            case 3: {
                int n, fat = 1;
                cout << "Digite um n�mero para calcular o fatorial: ";
                cin >> n;
                for (int i = 1; i <= n; i++) {
                    fat *= i;
                }
                cout << "Fatorial de " << n << " �: " << fat << endl;
                break;
            }

            case 4: {
                int n;
                cout << "Digite um n�mero: ";
                cin >> n;
                if (n % 2 == 0)
                    cout << "O n�mero " << n << " � par." << endl;
                else
                    cout << "O n�mero " << n << " � �mpar." << endl;
                break;
            }

            case 0:
                cout << "Saindo do programa..." << endl;
                return 0;

            default:
                cout << "Op��o inv�lida!" << endl;
        }
    }

    return 0;
}
