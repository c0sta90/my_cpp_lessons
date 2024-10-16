#include <iostream>
#include <fstream>
using namespace std;

class Fatura {
    public:
        int num;
        int Ano;
        float valor;
        float contribuinte;
};

void ficheiro( Fatura fatura1[], int& quantidadeAtual){
    
    string ops;
    cout << "Queres criar um ficheiro com todas as faturas registadas?" << endl;
    cout << " " << endl;
    cout << "Pressione 'Enter' para continuar ➤" << endl;
    cin.ignore();
    getline(cin, ops);
    ofstream ficheiro("Faturas.csv");
    if (ficheiro.is_open()) {
        ficheiro << "Número ┇ Ano ┇ Valor ┇ Contribuinte" << endl;
        for (int x = 0; x < quantidadeAtual; x++) {
            ficheiro << fatura1[x].num << ",";  
            ficheiro << fatura1[x].Ano << ",";
            ficheiro << fatura1[x].valor << ",";
            ficheiro << fatura1[x].contribuinte;
            ficheiro << endl; 
        }
        ficheiro.close();
        system("clear");
        cout << "O ficheiro foi criado com sucesso! ✔" << endl;
    }

} 

void criafatura(Fatura& fatura) {
    system("clear");
    cout << "A criar fatura..." << endl;
    
    cout << "Insira o Valor da fatura: ";
    cin >> fatura.valor;

    cout << "Insira o num da fatura: ";
    cin >> fatura.num;

    cout << "Insira o Ano da fatura: ";
    cin >> fatura.Ano;

    cout << "Insira o contribuinte: ";
    cin >> fatura.contribuinte;

    system("clear");
}

void mostrafatura(const Fatura& fatura) {
    system("clear");
    cout << "A(s) fatura(s) criada(s) é(são) as seguinte(s):" << endl;
    cout << "Valor:" << fatura.valor << endl;
    cout << "Número:" << fatura.num << endl;
    cout << "Ano:" << fatura.Ano << endl;
    cout << "Contribuinte:" << fatura.contribuinte << endl;
}

int main() {
    system("clear");
    Fatura fatura1;
    int quantidadeAtual = 0;
    Fatura max_Ficheiros[100];
    int ops;

    

    do {
        cout << "1.  Criar fatura" << endl;
        cout << "2.  Exibir faturas" << endl;
        cout << "3.  Criar ficheiro com todas as faturas" << endl;
        cout << "4.  Sair" << endl;
        
        cin >> ops;
        
        switch (ops) {
            case 1:
                system("clear");
                criafatura(fatura1);
                cout << "A fatura foi adicionada com sucesso!" << endl;
                break;
            case 2:
                system("clear");
                mostrafatura(fatura1);
                break;
            case 3:
                system("clear");
                ficheiro(max_Ficheiros, quantidadeAtual);
                break;
            case 4:
                cout << "A sair..." << endl;
                break;
            default:
                cout << "Opção invalida" << endl;
                break;
        }
    } while (ops != 4);

    return 0;
}