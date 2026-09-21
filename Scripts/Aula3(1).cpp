#include <iostream>

using namespace std;


int main() {
    int valor;

    cout << "Digite o valor em centavos: ";
    cin >> valor;

    int moedas100 = valor / 100;
    valor = valor % 100;

    int moedas50 = valor / 50;
    valor = valor % 50;

    int moedas25 = valor / 25;
    valor = valor % 25;

    int moedas10 = valor / 10;
    valor = valor % 10;

    int moedas5 = valor / 5;
    valor = valor % 5;

    int moedas1 = valor / 1;
    valor = valor % 1;

    cout << "Moedas de 1 real: " << moedas100 << endl;
    cout << "Moedas de 50 centavos: " << moedas50 << endl;
    cout << "Moedas de 25 centavos: " << moedas25 << endl;
    cout << "Moedas de 10 centavos: " << moedas10 << endl;
    cout << "Moedas de 5 centavos: " << moedas5 << endl;
    cout << "Moedas de 1 centavo: " << moedas1 << endl;

    return 0;
}
