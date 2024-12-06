#include <iostream>

using namespace std;

int main(){

    char a;
    cout << "digite uma letra minuscula: ";
    cin >> a;

    cout << "Letra " << a << " Em maiscula é " << (char)(a - 32) << endl;
}