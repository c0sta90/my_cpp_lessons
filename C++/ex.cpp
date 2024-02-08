//Crie uma função capaz de ler os dados de uma matriz quadrada de inteiros. Ao final da leitura o programa deverá imprimir o número de linha que contem o menor dentro de todos os números lidos
// #include <iostream>
// #include <climits>
// using namespace std;

// int array[3][3] = {{5,9,9},{8,9,2},{3,1,5}};
// int menor = INT_MAX;
// int linha = 0;

// void lerMatriz(int array[3][3]){
//     for(int i = 0; i < 3; i++){
//         for(int j = 0; j < 3; j++){
//             cout << array[i][j] << " ";
//             if(array[i][j] < menor){
//                 menor = array[i][j];
//                 linha = i;
//             }
//         }
//         cout << endl;
//     }
//     cout << "Menor: " << menor << endl;
//     cout << "Linha: " << linha << endl;
// }

// int main(){
//     system("clear");
//     lerMatriz(array);
//     return 0;
// }

// cria um programa capaz de multiplicar uma matriz bidimensional de inteiros por um dado número e criar uma nova matriz com o produto
#include <iostream>
#include <climits> // INT_MAX

using namespace std;

const int ROWS = 3;
const int COLS = 3;

void multiplyMatrix(int matrix[ROWS][COLS], int num, int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] > INT_MAX / num) { // Verifique se o resultado excede o valor máximo de um int
                result[i][j] = INT_MAX; // Defina o resultado para o valor máximo de um int
            } else {
                result[i][j] = matrix[i][j] * num;
            }
        }
    }
}

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    system("clear");
    int matrix[ROWS][COLS] = {{5, 9, 9}, {8, 9, 2}, {3, 1, 5}};
    int num = 2;
    int result[ROWS][COLS];

    multiplyMatrix(matrix, num, result);
    printMatrix(result);

    return 0;
}
