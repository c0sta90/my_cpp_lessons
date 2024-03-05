#include <iostream> 
using namespace std;

int main(){
    int i = 10;
    float f = 3.14;
    char c = 'A';

    // Cast implicito
    float f2 = i;
    char c2 = i;
    cout << "f2 = " << f2 << endl;
    cout << "c2 = " << c2 << endl;

    // Cast explicito

    int i2 = (int)f; // f = float é como o float fosse guardado no (int)
    int i3 = (int)c; // c = char
    
    //cast de um inteiro oara um char

    char c3 = (char)i; 




}
