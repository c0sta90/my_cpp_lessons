// Costa e Marim

#include <iostream>

using namespace std;

string frase;
char letra;

int main() {
    cout << "Bem-vindo ao jogo da forca sem forca!" << endl;
    cout << "Digite uma frase para o próximo jogador adivinhar: ";
    getline(cin, frase);

    
    system("clear");

    // Criando a versão oculta da frase
    string frase_mostrada = frase;
    for (char &l : frase_mostrada) { 
        if (l != ' ') {
            l = '_';
        }
    }

    // Exibe a frase oculta com espaços entre os caracteres
    for (char c : frase_mostrada) {
        cout << c << " ";
    }
    cout << "\n\n";

    while (true) {
        cout << "Tente adivinhar a frase!" << endl;
        cout << "Digite uma letra: ";
        cin >> letra;

        bool acertou = false;

        for (size_t i = 0; i < frase.size(); i++) {
            if (frase[i] == letra) {
                frase_mostrada[i] = letra;
                acertou = true;
            }
        }

        if (!acertou) {
            cout << "A letra '" << letra << "' não está na frase. Tente novamente!\n";
        }

        // Exibe o progresso da frase
        for (char c : frase_mostrada) {
            cout << c << " ";
        }
        cout << "\n\n";

        // Verifica se a frase foi completamente adivinhada
        if (frase_mostrada == frase) {
            cout << "\nParabéns! Você adivinhou a frase: " << frase << endl;
            break;
        }
    }

    return 0;
}
