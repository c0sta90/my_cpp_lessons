#include <iostream> // biblioteca padrão de entrada e saída

using namespace std; // para não precisar escrever std::cout e std::cin toda vez que for usar essas funções

long a,b; // declaração de variáveis

int array[5]; // declaração de um array de 5 posições

const double PI = 3.14159; // declaração de constante

// soma, subtração, multiplicação, divisão e resto da divisão

// int main(){ 
//     cout << "Digite um número: "; 
//     cin >> a; // lê um número do teclado e armazena na variável a
//     cout << "Digite outro número: "; 
//     cin >> b; // lê um número do teclado e armazena na variável b
//     cout << "A soma dos números é: " << a+b << endl; 
//     cout << "A subtração dos números é: " << a-b << endl; 
//     cout << "A multiplicação dos números é: " << a*b << endl; 
//         if (b == 0){ // se b for igual a zero
//             cout << "Não é possível dividir por zero" << endl; 
//         }else // senão
//         double c = a/(double)b; // c recebe a divisão de a por b
//             cout << "A divisão dos números é: " << a/b << endl; 
//             cout << "O resto da divisão dos números é: " << a%b << endl;
// }


// raio do círculo


// int main(){

//     int raio;
//     cout << "Digite o raio do círculo: ";
//     cin >> raio;
//     cout << "A área do círculo é: " << PI*raio*raio << endl;
//     cout << "O perímetro do círculo é: " << 2*PI*raio << endl;
// }



// array

int main() {
    for (int i = 0; i < 5; i++){
        cout << "Digite um número: ";
        cin >> array[i];
    }
}