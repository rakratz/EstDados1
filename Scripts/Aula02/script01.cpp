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
        cout << "2. Somar dois números" << endl;
        cout << "3. Calcular fatorial" << endl;
        cout << "4. Verificar se número é par ou ímpar" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
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
                cout << "Digite dois números: ";
                cin >> a >> b;
                cout << "Soma: " << a + b << endl;
                break;
            }

            case 3: {
                int n, fat = 1;
                cout << "Digite um número para calcular o fatorial: ";
                cin >> n;
                for (int i = 1; i <= n; i++) {
                    fat *= i;
                }
                cout << "Fatorial de " << n << " é: " << fat << endl;
                break;
            }

            case 4: {
                int n;
                cout << "Digite um número: ";
                cin >> n;
                if (n % 2 == 0)
                    cout << "O número " << n << " é par." << endl;
                else
                    cout << "O número " << n << " é ímpar." << endl;
                break;
            }

            case 0:
                cout << "Saindo do programa..." << endl;
                return 0;

            default:
                cout << "Opção inválida!" << endl;
        }
    }

    return 0;
}
