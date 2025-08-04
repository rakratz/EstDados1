#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int* ptr_a = (int*) malloc(sizeof(int));

    if (ptr_a == nullptr) {
        cout << "Memória insuficiente!" << endl;
        return 1;
    }

    *ptr_a = 90;
    cout << "Conteúdo: " << *ptr_a << endl;
    free(ptr_a);

    return 0;
}
