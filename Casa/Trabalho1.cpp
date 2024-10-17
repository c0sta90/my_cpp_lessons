#include <iostream>
#include <fstream>
#include <set> // Para usar o set de IDs únicos 
#include <sstream> // Para usar o istringstream para ler os IDs do arquivo
#include <limits> // Para usar numeric_limits para limpar o buffer de entrada do cin

using namespace std;

struct carro{
    string marca;
    string modelo;
    int ano;
    string cor;
    float preco;
    string matricula;
};

void printCarro(carro c){
    cout << "Marca: " << c.marca << endl;
    cout << "Modelo: " << c.modelo << endl;
    cout << "Ano: " << c.ano << endl;
    cout << "Cor: " << c.cor << endl;
    cout << "Matricula: " << c.matricula << endl;
    cout << "Preço: " << c.preco << "€" << endl;
}

int generateUniqueId(set<int>& ids) {
    int id = 1;
    while(ids.find(id) != ids.end()) {
        id++;
    }
    ids.insert(id);
    return id;
}

void lerIdsExistentes(ifstream& arquivoLeitura, set<int>& ids) {
    string linha;
    while (getline(arquivoLeitura, linha)) {
        istringstream iss(linha);
        int id;
        iss >> id;
        ids.insert(id);
    }
}

void lerDadosCarro(carro& c, int i) {
    cout << "Digite a marca do carro " << i+1 << ": ";
    cin >> c.marca;
    cout << "Digite o modelo do carro " << i+1 << ": ";
    cin >> c.modelo;

    while (true) {
        cout << "Digite o ano do carro " << i+1 << ": ";
        cin >> c.ano;
        if(cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Entrada inválida. Por favor, insira um número inteiro para o ano." << endl;
        } else {
            break;
        }
    }

    cout << "Digite a cor do carro" << i+1 << ": ";
    cin >> c.cor;
    cout << "Digite a matrícula do carro " << i+1 << ": ";
    cin >> c.matricula;

    while (true) {
        cout << "Digite o preço do carro " << i+1 << ": ";
        cin >> c.preco;
        if(cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Entrada inválida. Por favor, insira um número válido para o preço." << endl;
        } else {
            break;
        }
    }
}

void salvarCarro(ofstream& arquivo, int id, carro& c) {
    arquivo << id << " " << c.marca << " " << c.modelo << " " << c.ano << " " << c.cor << " " << c.preco << "€ " << c.matricula << endl;
}

int main(){
    system("clear");
    carro carros[100];
    ofstream arquivo; 
    arquivo.open("carros.csv", ios::app); //append mode
    ifstream arquivoLeitura("carros.csv");
    set<int> ids;

    // Ler IDs existentes no arquivo
    lerIdsExistentes(arquivoLeitura, ids);
    arquivoLeitura.close();

    int n;
    cout << "Quantos carros deseja inserir (até 100)? ";
    cin >> n;
    if(n > 100) {
        return main();
        cout << "Número máximo de carros é 100." << endl;
    }

    for(int i = 0; i < n; i++){
        int id = generateUniqueId(ids);
        lerDadosCarro(carros[i], i);
        salvarCarro(arquivo, id, carros[i]);
    }
    arquivo.close();

    for(int i = 0; i < n; i++) {
        printCarro(carros[i]);
    }
    return 0;
}