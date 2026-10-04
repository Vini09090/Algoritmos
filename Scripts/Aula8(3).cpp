#include <iostream>

using namespace std;

int main() {

    int n;
    long long fatorial = 1;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        fatorial = fatorial * i;
    }

    cout << n << "! = " << fatorial << endl;

    return 0;
}
