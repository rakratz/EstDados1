/* 
// ======== Operadores Aritméticos ========
+     // Adição
-     // Subtração
*     // Multiplicação
/     // Divisão
%     // Resto

// ======== Operadores Relacionais ========
<     // Menor que
<=    // Menor ou igual que
>     // Maior que
>=    // Maior ou igual que
==    // Igual a
!=    // Diferente de

// ======== Operadores de Incremento e Decremento ========
++    // Incremento (pós-fixado ou pré-fixado)
--    // Decremento (pós-fixado ou pré-fixado)

// ======== Operadores Lógicos ========
!     // Não lógico (negação)
&&    // E lógico (and)
||    // Ou lógico (or)
*/
#include <iostream>
#include <locale>

using namespace std;

int main() {    
    setlocale(LC_ALL, "Portuguese");

    int a = 10, b = 5;

    // Aritméticos
    cout << "Aritméticos:" << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;

    // Relacionais
    cout << "\nRelacionais:" << endl;
    cout << "a == b? " << (a == b) << endl;
    cout << "a != b? " << (a != b) << endl;
    cout << "a > b? " << (a > b) << endl;
    cout << "a >= b? " << (a >= b) << endl;
    cout << "a < b? " << (a < b) << endl;
    cout << "a <= b? " << (a <= b) << endl;

    // Incremento e Decremento
    cout << "\nIncremento e Decremento:" << endl;
    cout << "Pré-incremento (++a): " << ++a << endl;
    cout << "Pós-incremento (a++): " << a++ << endl;
    cout << "Valor de a agora: " << a << endl;
    cout << "Pré-decremento (--b): " << --b << endl;
    cout << "Pós-decremento (b--): " << b-- << endl;
    cout << "Valor de b agora: " << b << endl;

    // Lógicos
    cout << "\nLógicos:" << endl;
    cout << "(a > 5 && b > 2)? " << ((a > 5 && b > 2) ? "true" : "false") << endl;
    cout << "(a > 5 || b > 10)? " << ((a > 5 || b > 10) ? "true" : "false") << endl;
    cout << "!(a == b)? " << (!(a == b) ? "true" : "false") << endl;
    return 0;
}