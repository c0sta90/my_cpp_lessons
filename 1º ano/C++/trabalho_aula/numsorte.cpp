#include <iostream>

using namespace std;

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