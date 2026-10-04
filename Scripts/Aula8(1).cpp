#include <iostream>

using namespace std;


int main() {
    // Soma de n números impares 
    int n;
    int soma = 0;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        soma = soma + (2 * i - 1);
    }

    cout << soma << endl;

    return 0;
}
