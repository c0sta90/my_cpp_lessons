#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <limits>

using namespace std;

int dimensao;

void equacaoA(){

    float x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;

    cout << "Para a equação (x1+x2)/2 o  resultado é: " << (x1 + x2)/2 << endl;
    cout << "Para a equação (y1+y2)/2 o  resultado é: " << (y1 + y2)/2 << endl;

    cout << "O vector de saída é: " << "(" << (x1 + x2)/2 << "," 
                                    << (y1 + y2)/2 << ")" << endl;

}

void nestedCondition(){

    char response;
    cout << "has Power? ";
    cin >> response;

    if(response == 'y'){
        cout << "has power" << endl;
        cout << "Seek other Help, I don't know what to do" << endl;
        exit(0);
    }else{
        cout << "Is pluged in? ";
        cin >> response;
        if(response == 'y'){
            cout << "Is the switch on?" << endl;
            cin >> response;
            if(response == 'y'){
                cout << "Is the fuse ok?" << endl;
                cin >> response;
                if(response == 'y'){
                    cout << "Seek other Help, I don't know what to do" << endl;
                    exit(0);
                }else{
                    cout << "Replace the fuse" << endl;
                    exit(0);
                }
            }else{
                cout << "Turn on the switch" << endl;
                exit(0);
            }
        }else{
            cout << "plug in" << endl;  
            exit(0);        
        }
    }
}

void matriz(int dim){

      // system("clear");
    // cout << "Digite a dimensão da matriz: ";
    // cin >> dimensao;
    // if(cin.fail()){
    //     cin.clear();
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //     cout << "ERRO Valor inválido" << endl;
    //     return 1;
    // }else{
    //     matriz(dimensao);
    // }
    
    int count = 0;
    system("clear");

    for (int i=0; i<= dim; i++){
        for (int j=0; j<= dim; j++) cout << setw(4) << ++count;
        cout << endl;
    }
    cout << endl;
}

void divisao(float x, float y){

    if(y == 0){
        cout << "Não é possível dividir por zero" << endl;
        return;
    }
    cout << "O resultado da divisão é: " << x/y << endl;
}

void graficoHorizontal(int x, int y, int z){

    //encontra o maior valor entre x,y e z
    int maior = x;
    if(y > maior) maior = y;
    if(z > maior) maior = z;

    //valores reais
    int a,b,c;
    a = x;
    b = y;
    c = z;

    //normaliza os valores
    x = x * 50 / maior;
    y = y * 50 / maior;
    z = z * 50 / maior;

    //imprime o gráfico horizontal 

    cout << "x: " << setw(2) << x << " ";
    for(int i=0; i<x; i++) cout << "*";
    cout << endl;

    cout << "y: " << setw(2) << y << " ";
    for(int i=0; i<y; i++) cout << "*";
    cout << endl;

    cout << "z: " << setw(2) << z << " ";
    for(int i=0; i<z; i++) cout << "*";
    cout << endl;
    

    cout << endl;
}


int main(){
graficoHorizontal(510,100,500) ;
  return 0;
}  