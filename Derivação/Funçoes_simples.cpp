#include <iostream>
#include <math.h>
using namespace std;

int f(int x);
int g(int x);


int main() {
    //Derivada da função g(x)
    for (int a = 0; a < 10; a++) {

        int b = a + 1;
        int h = b - a;

        int resultado = (g(b) - g(a)) / h;

        cout << "Intervalo: [" << a << ", " << b << "]" << endl;

        cout << "Formula: (" 
             << g(b) << " - " << g(a) 
             << ") / " << h << endl;

        cout << "Resultado: " << resultado << endl;

        cout << "----------------------" << endl;
    }

    return 0;
}

int f(int x) {
    return x * x;
}


// variação média da função g(x) = (x + 1)^3 + (x+1)^3
int g(int x){

    int y = pow((x+1), 3);
    return y + y;
}
