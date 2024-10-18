#include <iostream>

using namespace std; 

void teste(){
    cout << "Teste sem namespace" << endl;
}

namespace xpto
{
    void teste(){
        cout << "Teste com namespace" << endl;
    }
}

namespace abc
{
    void teste(){
        cout << "Teste com namespace abc" << endl;
    }
}

int main(){
    teste();
    xpto::teste();
    abc::teste();
    return 0;
}