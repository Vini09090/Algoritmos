#include <iostream>
using namespace std;

// Devolve a soma dos dígitos de n (n >= 0).
// Exemplo: 1234 -> 1 + 2 + 3 + 4 = 10
int somaDigitos(int n) {
    int soma = 0;
    while (n > 0) {
        soma += n % 10;  // pega o último dígito
        n /= 10;         // remove o último dígito
    }
    return soma;
}

// Devolve true se n é primo e false caso contrário.
// Números menores que 2 não são primos.
bool ehPrimo(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Digite um numero: ";
    cin >> n;

    if (ehPrimo(n)) {
        cout << n << " e primo" << endl;
        cout << "Soma dos digitos: " << somaDigitos(n) << endl;
    } else {
        cout << n << " nao e primo" << endl;
    }

    return 0;
}
