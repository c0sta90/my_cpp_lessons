#include <iostream>

using namespace std;

class Refrigerante {
private:
string nome;
int quantidade;
int data;
float preco;
bool state;
string validade;
string codeBarras;


// ------------------------------------------------------------------------ //
    void abrirRefri(){
        if(state){
            cout << "Estás a abrir a Fanta" << endl;
        }
        else{
            cout << "A Fanta já estava aberta tolo" << endl;
            this->state = true;
        }
    }

    void beber(){
    if(state){
        cout << "A beber a fanta ..." << endl;
    }
    else{
        cout << "A Fanta já está vazia!" << endl;
        this->state = true;
    }
    };

    void lixo(){
        if (state)
        cout << "Queres mesmo colocar a Fata cheia no lixo?" << endl;
    }

// ------------------------------------------------------------------------ //

public:


void Executar (int opt){
            switch(opt){
                case 1:
                if(state){
                    abrirRefri();
                }else{
                    cout << " " << endl;
                }
                case 2:
                if(state){
                    beber();
                }else{
                    cout << " " << endl;
                }
                case 3:
                if(state){
                    lixo();
                }else{
                    cout << " " << endl;
                }
            }
        }
};