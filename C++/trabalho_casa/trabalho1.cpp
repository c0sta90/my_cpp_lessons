#include <iostream>

using namespace std;

void menu(){
    system("clear"); // Limpa o terminal
    cout << "1 - Calculo" << endl;
    cout << "2 - Notas" << endl;
    cout << "3 - Tabuada" << endl;
    cout << "4 - Raio do circulo" << endl;
    cout << "5 - Sair" << endl;
}

int getopcao(){ // Função para pegar a opção do utilizador
    int opcao;
    cout << "Digite a opção: ";
    cin >> opcao; 
    return opcao;
}

void raiocirculo(){ // Função para calcular a área do circulo
    system("clear");
    int PI = 3.14;
    float raio, area;
    cout << "Digite o raio do circulo: ";
    cin >> raio;
    area = PI * raio * raio;
    cout << "Area: " << area << endl;
}

void calculo(){ // Função para calcular a soma, subtração, multiplicação e divisão
    system("clear");
    int a, b;
    cout << "Digite o primeiro numero: ";
    cin >> a;
    cout << "Digite o segundo numero: ";
    cin >> b;
    cout << "Soma: " << a + b << endl;
    cout << "Subtração: " << a - b << endl;
    cout << "Multiplicação: " << a * b << endl;
    if (b != 0) { // Verifica se o segundo número é diferente de zero
        cout << "Divisão: " << a / b << endl;
    } else { 
        cout << "Erro: Divisão por zero" << endl;
    }
}

void notas(){ // Função para calcular a média das notas
    system("clear");
    float n1, n2, n3, media;
    cout << "Digite a primeira nota: ";
    cin >> n1;
    cout << "Digite a segunda nota: ";
    cin >> n2;
    cout << "Digite a terceira nota: ";
    cin >> n3;
    media = (n1 + n2 + n3) / 3;
    cout << "Media: " << media << endl;
    if(media >= 10){
        cout << "Aprovado" << endl;
    }else{
        cout << "Reprovado" << endl;
    }
}

void tabuada(){ // Função para calcular a tabuada
    system("clear");
    int n;
    cout << "Digite um numero: ";
    cin >> n;

    for(int x = 1; x <= 10; x++){
        cout << x << " * " << n << " = " << x * n << endl; 
    }
}


int main(){
    int opcao;
        menu();
        opcao = getopcao();
        switch(opcao){
            case 1:
                calculo();
                break;
            case 2:
                notas();
                break;
            case 3:
                tabuada();
                break;
            case 4:
                raiocirculo();
            case 5:
                return 0;
                break;
            default:
                cout << "Opção inválida escolha de 1 a 5" << endl;
        }
    return 0;
}