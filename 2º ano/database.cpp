#include <iostream>
#include <fstream>
using namespace std;

struct Produto {
    int ID;
    string nome;
    char status; // D = delete, A = ativo
    float preco;
    int quantidade;
};

void addprodutosdb(Produto produtos[], int quantidadeAtual){
    ofstream database("database.txt", ios::app); // Guardar dados na database e o 'app' é para adicionar sempre uma linha abaixo

    if(database.is_open()){
        database << produtos[quantidadeAtual - 1].ID << "," 
                  << produtos[quantidadeAtual - 1].nome << ","
                  << produtos[quantidadeAtual - 1].preco << ","
                  << produtos[quantidadeAtual - 1].quantidade << ","
                  << produtos[quantidadeAtual - 1].status << endl;

        database.close(); // Fechar database
    } else {
        cout << "Erro ao abrir a database!" << endl;
    }
}

// Função para adicionar produtos
void adicionarProduto(Produto produtos[], int& quantidadeAtual) {
    produtos[quantidadeAtual].ID = quantidadeAtual + 1; // mete sempre +1 id 
    
    cout << "Escreve o nome do produto: ";
    cin >> produtos[quantidadeAtual].nome;
   
    cout << "Escreve o preço do produto: ";
    cin >> produtos[quantidadeAtual].preco;
   
    cout << "Escreve a quantidade do produto: ";
    cin >> produtos[quantidadeAtual].quantidade;
    
    produtos[quantidadeAtual].status = 'A'; // por default fica sempre A

    // Incrementa o valor da quantidadeAtual
    quantidadeAtual++;
    
    // Chama a função para guardar na database
    addprodutosdb(produtos, quantidadeAtual);
     
    cout << "Produto adicionado com sucesso!" << endl;
}

// Função para mostrar os produtos
void exibirProdutos(const Produto produtos[], int quantidadeAtual) {
    for (int i = 0; i < quantidadeAtual; i++) {
        cout << "ID: " << produtos[i].ID 
             << ", Nome: " << produtos[i].nome
             << ", Preço: " << produtos[i].preco
             << ", Quantidade: " << produtos[i].quantidade << endl;
    }
}
//função para dar delete ao produto
void deleteproduto(Produto produtos[], int& quantidadeAtual) {
    int deleteID;
    cout << "ID do produto que queres eliminar: ";
    cin >> deleteID;

    for (int i = 0; i < quantidadeAtual; i++) {
        if (produtos[i].ID == deleteID) {
            // isto tá a alterar o status do produto para D
            produtos[i].status = 'D';
            cout << "Produto definido como eliminado!" << endl;
            return; 
        }
    }
    
    cout << "Produto não encontrado!" << endl;
}

// Função para iniciar a base de dados
void startbasedados(){
    ifstream database("database.txt", ios::app);
    if(!database){
        char opcao;
        
        cout << "Database não encontrada" << endl;
        
        cout << "Gostaria de criar uma database? (y/n): ";
        cin >> opcao;

        if(opcao == 'y'){
            // Cria uma nova base de dados
            ofstream database("database.txt");
            database.close();
            system("clear");
            cout << "Criado com sucesso" << endl;
            
        } else {
            system("clear");
            cout << "A fechar o programa" << endl;
        }
    }
}

// Função para calcular o total e devolver um valor
float calcularValorTotal(const Produto produtos[], int quantidadeAtual) {
    float valorTotal = 0;
    for (int i = 0; i < quantidadeAtual; i++) {
        valorTotal += produtos[i].quantidade;
    }
    return valorTotal;
}

int main() {
   system("clear");
    startbasedados(); // Verifica se a base de dados já existe
    Produto maxProdutos[100]; // max de produtos 
    int quantidadeAtual = 0;  // Guarda a quantidade de produtos no stock
    int opcao;
    
    

    do {    // Corre sempre o código até 0 (sair)
        cout << "1. Adicionar Produto" << endl;
        cout << "2. Exibir Produtos" << endl;
        cout << "3. Calcular Valor Total do stock da loja" << endl;
        cout << "4. Eliminar produto" << endl;
        cout << "0. Sair e salvar" << endl;
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarProduto(maxProdutos, quantidadeAtual);
                break;
            case 2:
                exibirProdutos(maxProdutos, quantidadeAtual);
                break;
            case 3:
                cout << "Valor total do stock: " << calcularValorTotal(maxProdutos, quantidadeAtual) << endl;
                break;
            case 4 :
                deleteproduto(maxProdutos, quantidadeAtual);
                break;
            case 0:
                cout << "A sair..." << endl;
                break;
            default:
                cout << "Escolha outra opção." << endl; 
        }
    } while (opcao != 0);

    return 0;
}