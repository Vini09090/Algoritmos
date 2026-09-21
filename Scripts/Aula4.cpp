#include <iostream>

using namespace std;

int main(){
    int numero , contador = 0; // numero é o que foi digitado pelo usuário e contador é a quantia de digitos do numero 

    cout << "Digite um numero :" << endl; 
    cin >> numero;
    while(numero > 0){
        numero = numero/10;
        contador = contador + 1;
    }
    cout << contador <<endl;
    return 0;
}
