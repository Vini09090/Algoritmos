#include <iostream>
using namespace std;

int main() {
    int matriz[3][3];
    int dp = 0, ds = 0;

    cout << "Digite os elementos da matriz 3x3:\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        dp += matriz[0][i]
            * matriz[1][(i + 1) % 3]
            * matriz[2][(i + 2) % 3];

        ds += matriz[0][i]
            * matriz[1][(i + 2) % 3]
            * matriz[2][(i + 1) % 3];
    }

    cout << "Determinante: " << dp - ds << endl;

    return 0;
}
