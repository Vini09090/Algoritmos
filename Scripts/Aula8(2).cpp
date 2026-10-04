#include <iostream>


using namespace std;


int main(){

    int n, k;

    cout << "Digite dois valores: " << endl;
    cin >> k >> n;

    for(int i = 1; i * k <= n; i++){
        int resultado = k * i;
        cout << resultado << " ";
    }

    return 0;
}
