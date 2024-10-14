#include <iostream>
#include <fstream>
using namespace std;


struct Produto {
    string nome;
    float preco;
    int quantidade;
};

void adicionarProduto(Produto produtos[], int& quantidadeAtual) {
    cout << "Escreve o nome do produto: ";
    cin >> produtos[quantidadeAtual].nome;
   
    cout << "Escreve o preço do produto: ";
    cin >> produtos[quantidadeAtual].preco;
   
    cout << "Escreve a quantidade do produto: ";
    cin >> produtos[quantidadeAtual].quantidade;

//incrementando o valor da variável
    quantidadeAtual++;
}

//função para mostrar os produtos
void exibirProdutos(const Produto produtos[], int quantidadeAtual) {
    for (int i = 0; i < quantidadeAtual; i++) {
        cout << "Nome: " << produtos[i].nome
             << ", Preço: " << produtos[i].preco
             << ", Quantidade: " << produtos[i].quantidade << endl;
    }
}

//função para calcular o total e devolver um valor
float calcularValorTotal(const Produto produtos[], int quantidadeAtual) {
    float valorTotal = 0;
    for (int i = 0; i < quantidadeAtual; i++) {
        valorTotal += produtos[i].preco * produtos[i].quantidade;
    }
    return valorTotal;
}

int main() {
    fstream MyFile("database.txt");
    Produto produtos[100];
    int quantidadeAtual = 0;
    int opcao;

    do {
        cout << "1. Adicionar Produto" << endl;
        cout << "2. Exibir Produtos" << endl;
        cout << "3. Calcular Valor Total do Stock" << endl;
        cout << "4. Sair" << endl;
        cin >> opcao;

        if (opcao == 1) {
            adicionarProduto(produtos, quantidadeAtual);
        } else if (opcao == 2) {
            exibirProdutos(produtos, quantidadeAtual);
        } else if (opcao == 3) {
            cout << "Valor total do stock: " << calcularValorTotal(produtos, quantidadeAtual) << endl;
        }

    } while (opcao != 4);

    return 0;
}
