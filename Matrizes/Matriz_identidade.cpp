#include <iostream>


// Matriz identidade tem determinante igual a 1

using namespace std;

int main() {
    int n;

    cout << "Digite a ordem da matriz: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j) {
                cout << "1 ";
            }
            else {
                cout << "0 ";
            }
        }

        cout << endl;
    }

    return 0;
}
