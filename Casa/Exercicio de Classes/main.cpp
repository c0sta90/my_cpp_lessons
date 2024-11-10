#include <iostream>
#include <string>

using namespace std;

class Veiculo {
protected:
    string nome;
public:
    Veiculo(const string& nome) : nome(nome) {}
    virtual void mostrarDetalhes() const {
        cout << "Veículo: " << nome << endl;
    }
    virtual ~Veiculo() = default;
};

class Carro : public Veiculo {
private:
    int numeroDePortas;
public:
    Carro(const string& nome, int numeroDePortas) : Veiculo(nome), numeroDePortas(numeroDePortas) {}
    void mostrarDetalhes() const override {
        cout << "Carro: " << nome << ", Número de portas: " << numeroDePortas << endl;
    }
};

class Moto : public Veiculo {
private:
    string tipoDeGuidao;
public:
    Moto(const string& nome, const string& tipoDeGuidao) : Veiculo(nome), tipoDeGuidao(tipoDeGuidao) {}
    void mostrarDetalhes() const override {
        cout << "Moto: " << nome << ", Tipo de guidão: " << tipoDeGuidao << endl;
    }
};

int main() {
    Carro carro("Fusca", 2);
    Moto moto("Harley", "Ape Hanger");

    carro.mostrarDetalhes();
    moto.mostrarDetalhes();

    return 0;
}