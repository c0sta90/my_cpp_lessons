// tratamento de erros

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    try {
        ifstream file("file.txt");
        if (!file.is_open()) {
            throw "Erro ao abrir o arquivo";
        }
    } catch (const char* e) {
        cout << "Erro: " << e << endl;
    }
    return 0;
}