#include <iostream>
using namespace std;

int main() {
    int matriz[3][3]; // Matriz ordem 3
    int dp = 0, ds = 0;

    cout << "Digite os elementos da matriz 3x3:\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matriz[i][j];
        }
    }
    for(int i = 0 ; i<3 ; i++){
        for (int j = 0 ; j < 3 ;j++ ){
            matriz[i][j];
            
        }
        cout << endl;
    }

    for(int i = 0 ; i<3 ; i++){
        for (int j = 0 ; j < 3 ;j++ ){
            matriz[j][i];

            
        }
    }
    for(int i = 0 ; i<3 ; i++){
        for (int j = 0 ; j < 3 ;j++ ){
            cout << matriz[j][i];

        }
        cout << endl;
    }

    return 0;
}
