

#include <iostream>

using namespace std;

int main(){

    double lado1 , lado2 , lado3;
    cout << "digite os lados dos triangulos : \n";
    cin >> lado1 >> lado2 >> lado3;


    if (lado1 !=lado2 && lado1 !=lado3){
        cout<<"Este triangulo é escaleno!";

    }else if (lado1 == lado2 && lado1<lado3){
        cout << "o triangulo é isóceles!";

    }else{
        cout <<"este triangulo é equilátero!";
    }


    return 0;
}
