#include <iostream>

using namespace std;

int main() {
    int tempo, s, m, h;

    cout << "Digite um número de segundos: " << endl;
    cin >> tempo;

    if (tempo < 0 || tempo >= 86400) {
        cout << "Entrada inválida" << endl;
        return 1; // Encerra o programa se a entrada for inválida
    }

    h = tempo / 3600;
    m = (tempo % 3600) / 60; // Correção do cálculo de minutos
    s = tempo % 60;

    // Formatação de saída com '0' e separador ':'
    if (h < 10) cout << "0";
    cout << h << ":";
    
    if (m < 10) cout << "0";
    cout << m << ":";
    
    if (s < 10) cout << "0";
    cout << s << endl;

    return 0;
}
