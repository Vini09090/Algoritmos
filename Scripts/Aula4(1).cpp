#include <iostream>

using namespace std;

int main(){
    int soma = 0, n, i = 0;
    cout << "Digite um número : " << endl;
    cin >> n;
    while(soma < n){
        i = i + 1;
        soma += i;   // agora acumula de verdade
    }
    if (soma == n){
        cout << "Número triangular: \n" << soma << "\n";
    } else {
        cout << "Número não triangular." << endl;
    }
    return 0;
}
