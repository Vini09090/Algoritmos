#include <iostream>

int main() {
    double a, b, c;

    std::cout << "--- Derivada de uma Funcao Quadratica f(x) = ax^2 + bx + c ---\n\n";

    // Entrada dos coeficientes
    std::cout << "Digite o coeficiente a: ";
    std::cin >> a;

    std::cout << "Digite o coeficiente b: ";
    std::cin >> b;

    std::cout << "Digite o coeficiente c: ";
    std::cin >> c;

    // Calculo dos coeficientes da derivada: f'(x) = 2ax + b
    double da = 2 * a;
    double db = b;

    // Exibicao do resultado de forma formatada
    std::cout << "\nFuncao original: f(x) = " << a << "x^2 + " << b << "x + " << c << std::endl;
    std::cout << "Derivada:        f'(x) = ";

    if (da != 0) {
        std::cout << da << "x";
        if (db > 0) {
            std::cout << " + " << db;
        } else if (db < 0) {
            std::cout << " - " << -db;
        }
    } else {
        // Caso 'a' seja 0, a derivada e apenas a constante 'b'
        std::cout << db;
    }

    std::cout << std::endl;

    return 0;
}
