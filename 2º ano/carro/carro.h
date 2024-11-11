#ifndef CARRO_H
#define CARRO_H
#include <iostream>
#include <string>
using namespace std;

class Carro {
    private:
        string marca;
        string modelo;
    public:
        Carro(string marca, string modelo);
};


#endif