#include <iostream>

using namespace std;

void menu(){
    cout << "1 - Calculo" << endl;
    cout << "2 - Notas" << endl;
    cout << "3 - Tabuada" << endl;
}

void menucal(){
    cout << "====================" << endl;
    cout << "1 - Soma" << endl;
    cout << "2 - Subtracao" << endl;
    cout << "3 - Multiplicacao" << endl;
    cout << "4 - Divisao" << endl;
    cout << "====================" << endl;
}

void calculo(){
    int a, b;
    cout << "Digite o primeiro numero: ";
    cin >> a;
    cout << "Digite o segundo numero: ";
    cin >> b;
    cout << "Soma: " << a + b << endl;
    cout << "Subtracao: " << a - b << endl;
    cout << "Multiplicacao: " << a * b << endl;
    cout << "Divisao: " << a / b << endl;
}

void notas(){
    float n1, n2, n3, media;
    cout << "Escreva a primeira nota: ";
    cin >> n1;
    cout << "Escreva a segunda nota: ";
    cin >> n2;
    cout << "Escreva a terceira nota: ";
    cin >> n3;
    media = (n1 + n2 + n3) / 3;
    cout << "Media: " << media << endl;
    if(media >= 7){
        cout << "Aprovado" << endl;
    }else{
        cout << "Reprovado" << endl;
    }
}

void tabuada(){
    int n;
    cout << "Escolhe um numero: ";
    cin >> n;

    for(int x = 1; x <= 10; x++){
        cout << x << " * " << n << " = " << x * n << endl;
    }
}


int main(){

    return 0;
}