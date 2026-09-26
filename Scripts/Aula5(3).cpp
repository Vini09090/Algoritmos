#include <iostream>

using namespace std;

int main() {
    int n, soma = 0, d = 1;

    cout << "Digite um numero: ";
    cin >> n;

    if (n <= 0) {
        cout << n << " e deficiente" << endl;
        return 0;
    }

    // Testa todos os divisores proprios (de 1 ate n - 1)
    while (d < n) {
        if (n % d == 0) {
            soma += d;
        }
        ++d;
    }

    if (soma == n) {
        cout << "Numero perfeito" << endl;
    } else if (soma > n) {
        cout << "e abundante!" << endl;
    } else {
        cout << n << " e deficiente" << endl;
    }

    return 0;
}
