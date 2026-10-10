#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double matriz[3][3];
    double inversa[3][3];
    double dp = 0.0, ds = 0.0;
    double determinante;

    cout << "Digite os elementos da matriz 3x3:\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matriz[i][j];
        }
    }

    // Calcula o determinante pela Regra de Sarrus.
    for (int i = 0; i < 3; i++) {
        dp += matriz[0][i]
            * matriz[1][(i + 1) % 3]
            * matriz[2][(i + 2) % 3];

        ds += matriz[0][i]
            * matriz[1][(i + 2) % 3]
            * matriz[2][(i + 1) % 3];
    }

    determinante = dp - ds;

    cout << "\nDeterminante: " << determinante << '\n';

    // Uma matriz com determinante zero nao possui inversa.
    if (determinante == 0.0) {
        cout << "A matriz nao possui inversa.\n";
        return 0;
    }

    // Calcula a matriz inversa pela adjunta dividida pelo determinante.
    inversa[0][0] = (matriz[1][1] * matriz[2][2]
                   - matriz[1][2] * matriz[2][1]) / determinante;

    inversa[0][1] = (matriz[0][2] * matriz[2][1]
                   - matriz[0][1] * matriz[2][2]) / determinante;

    inversa[0][2] = (matriz[0][1] * matriz[1][2]
                   - matriz[0][2] * matriz[1][1]) / determinante;

    inversa[1][0] = (matriz[1][2] * matriz[2][0]
                   - matriz[1][0] * matriz[2][2]) / determinante;

    inversa[1][1] = (matriz[0][0] * matriz[2][2]
                   - matriz[0][2] * matriz[2][0]) / determinante;

    inversa[1][2] = (matriz[0][2] * matriz[1][0]
                   - matriz[0][0] * matriz[1][2]) / determinante;

    inversa[2][0] = (matriz[1][0] * matriz[2][1]
                   - matriz[1][1] * matriz[2][0]) / determinante;

    inversa[2][1] = (matriz[0][1] * matriz[2][0]
                   - matriz[0][0] * matriz[2][1]) / determinante;

    inversa[2][2] = (matriz[0][0] * matriz[1][1]
                   - matriz[0][1] * matriz[1][0]) / determinante;

    cout << "\nMatriz inversa:\n";
    cout << fixed << setprecision(3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(10) << inversa[i][j];
        }
        cout << '\n';
    }

    return 0;
}
