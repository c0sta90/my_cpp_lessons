#include <iostream>
using namespace std;

int somaNumero(int x, int y ){
    return x+y;

}

double somaNumero(double x, double y ){
        return x+y;
}
int main(){

    cout << somaNumero(2.2,6.4) << "\n";
    return 0;

}