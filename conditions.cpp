#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
/**
int a = 10;
int b = 12;
int c = 9;
int main(){
    if (a > b || b < c){
        cont <<"é verdade" <<endl;
    }else{
        cont << "é mentira" << endl;
    
    }
    return 0;
}
*/

// int main (){

//     int num;

//     cont <<"Diga um numero: ";
//     cin >> num;

//     if(num >=0){
//     cont << "O numero é possitivo" << endl;
//     }else{
//     cont << "O numero é negativo" << endl;
//     }

//     return 0;
// }

// int main (){

//     int num;

//     cout <<"Diga um numero: ";
//     cin >> num;

//     switch (num)
//     {
//     case 1:
//         cout << "O numero é 1" << endl; 
//         break;
//             case 2:
//         cout << "O numero é 2" << endl; 
//         break;
    
//     default:
//     cout << "O numero não é 1 nem 2" << endl;
//         break;
//     }
// }
// parametros de obrigadorio
int main(){
int numSorte = 1+(rand()%100);
srand((unsigned) time(0));
    int num = 0;
    while(numSorte != num){
        cout <<"Qual o numero da sorte? ";
        cin >> num;
        if (numSorte > num){
            cout << "O número da sorte é maior " << num << endl;
            }else if (numSorte < num){
                cout << "O num é menor do que: " << num << endl;
            }else{
                cout << "Parabens acertaste" << endl;
            }
        }
        cout << "Acabou o jogo!" << endl;
        return 0;
    }