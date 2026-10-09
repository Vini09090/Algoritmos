
#include <iostream>

using namespace std;
// Nome : Vinicius Sousa Palmeira
// matricula 202511627
// Laboratorio 07 - Exercicio 3
// Data: 09/10/2026

int main() {
    int n;

    do {
        cout << "Digite um numero impar maior ou igual a 1: ";
        cin >> n;

        if (n < 1 || n % 2 == 0) {
            cout << "Valor invalido! Tente novamente." << endl;
        }

    } while (n < 1 || n % 2 == 0);

    for (int i = 1; i <= n; i += 2) {
        for (int j = 0; j < (n - i) / 2; j++) {
            cout << " ";
        }

        for (int j = 0; j < i; j++) {
            cout << "*";
        }

        cout << endl;
    }

    for (int i = n - 2; i >= 1; i -= 2) {
        for (int j = 0; j < (n - i) / 2; j++) {
            cout << " ";
        }

        for (int j = 0; j < i; j++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
