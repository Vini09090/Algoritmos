#include <iostream>


using namespace std;

int main(){
    
    int x, parada = -1;
    while(parada == -1){
            cin >> x;
    if (x % 2 == 0) {
        if (x > 10) {
           cout << "P";
        } else {
           cout << "Q";
    }
    } else if (x % 3 == 0) {
         cout << "R";
    } else {
         cout << "S";
    }
    if (x > 0) {
         cout << "+" << "\n";
    } else {
        cout << "-" << "\n";


    return 0;
}
    cout << "Deseja continuar? -1/N" << endl;
    cin >> parada;
    
    }

    return 0;
}
