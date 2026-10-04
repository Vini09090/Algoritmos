#include <iostream>

using namespace std;


int main(){ // 2n² + 3n /6
    int soma = 0, n;
    cout << "digite o n quadrados." << endl;

    cout << "Digite o valor de n" << endl;
    cin >> n;

    for (int i = 1; i <= n ; i++){
        soma += i*i;
    }
    cout <<"A soma de n termos quadrados : " <<  soma << endl;
    

    return 0;
}
