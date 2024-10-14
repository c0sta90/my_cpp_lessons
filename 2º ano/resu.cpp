#include <iostream>

using namespace std;

struct hardware{
    string ram;
    string cpu;
    string gpu;
    string psu;
    string caixa;
    string mb;
    string hd;
    string fans;
    char perifericos[5];
};

class Computer {
    
    private:
    hardware computer;
    bool state;

        void Formatar(){
             cout << "o computador vai ser formatado" << endl;
        }

        void AbrirPasta(){
            cout << "a pasta foi aberta" << endl;
        }

        void IniciarGPU(){
            cout << "o gpu foi iniciado" << endl;
        }

        void IniciarSO(){
            cout <<"A placa gráfica está a ser iniciada!" << endl;
        }

        void RemoverFicheiro(){
            cout << "o ficheiro foi removido" << endl;
        }

        void listaHardware(){
            cout << endl;
            cout << "Lista de Hardware: " << endl;
            cout << "Ram: " << computer.ram << endl;
            cout << "CPU: " << computer.cpu << endl;
            cout << "GPU:  " << computer.gpu << endl;
            cout << "PSU: " << computer.psu << endl;
            cout << "Caixa: " << computer.caixa << endl;
            cout << "MB: " << computer.mb << endl;
            cout << "HD: " << computer.hd << endl;
            cout << "Fans: " << computer.fans << endl;
            cout << "Perifericos: " << computer.perifericos << endl;
            for(int  i = 0; i < 5; i++){
                cout << computer.perifericos[i] << " - ";
            }
            cout << endl;
        }

        public:
        Computer (hardware hardware){
            this->computer = hardware;
            this->state = false;
            cout << "O computador foi instanciado com sucesso!" << endl;
            listaHardware();
        }

        void Ligar(){
            if(state){
                cout << "O computador já está ligado!" << endl;
            }
            else{
                cout  << "O computador está a ser ligado!" << endl;
                this->state = true;
            }
        }

        void Desligar(){
            if(state){
                cout << "O computador já está desligado!" << endl;
                this->state = false;
            }
            else{
                cout << "O computador está a ser desligado!" << endl;
            }
        }
        void Reset(){
            if(state){
                cout << "O computador está a ser resetado!" << endl;
            }
            else{
                cout << "O computador já está desligado!" << endl;
            }
        }
        void Abrirtampa(){
                cout << "A tampa do computador está a ser aberta!" << endl;
        }
        void Executar (int opt){
            switch(opt){
                case 1:
                if(state){
                    Formatar();
                }else{
                    cout << "O computador está desligado!" << endl;
                }
                case 2:
                if(state){
                    AbrirPasta();
                }else{
                    cout << "O computador está desligado!" << endl;
                }
                case 3:
                if(state){
                    RemoverFicheiro();
                }else{
                    cout << "O computador está desligado!" << endl;
                }
            }
        }
        
};