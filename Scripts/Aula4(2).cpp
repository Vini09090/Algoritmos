#include <iostream>



using namespace std;

int main(){

    long long n, prod = 1;

    cout << "Digite um número: ";
    cin >> n;

    if(n < 0){
        cout << "Não existe fatorial de número negativo." << endl;
    }
    else{
        while(n > 1){
            prod = prod * n;
            n = n - 1;
        }

        cout << "Fatorial: " << prod << endl;
    }

    return 0;
}
