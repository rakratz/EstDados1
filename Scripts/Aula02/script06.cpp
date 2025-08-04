#include <iostream>
using namespace std;

int main() {
    int capacidade = 2; // capacidade inicial do vetor
    int* valores = new int[capacidade]; // alocação dinâmica
    int quantidade = 0;
    int entrada;

    cout << "Digite valores inteiros (0 para encerrar):" << endl;

    while (true) {
        cin >> entrada;
        if (entrada == 0) break;

        // Verifica se precisamos realocar
        if (quantidade == capacidade) {
            // dobra a capacidade
            int* novoArray = new int[capacidade * 2];
            for (int i = 0; i < quantidade; i++) {
                novoArray[i] = valores[i];
            }
            delete[] valores; // libera o antigo
            valores = novoArray;
            capacidade *= 2;
        }

        valores[quantidade] = entrada;
        quantidade++;
    }

    // Calcula a média
    if (quantidade > 0) {
        int soma = 0;
        for (int i = 0; i < quantidade; i++) {
            soma += valores[i];
        }
        double media = static_cast<double>(soma) / quantidade;
        cout << "Média dos valores: " << media << endl;
    } else {
        cout << "Nenhum valor foi inserido." << endl;
    }

    delete[] valores; // libera memória
    return 0;
}
