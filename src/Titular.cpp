#include "Titular.hpp"
#include <string>
#include <iostream>
using namespace std;

Titular::Titular(string cpf, string nome):
cpf(cpf),
nome(nome)
{
    verificaTamanhoDoNome();
}

void Titular::verificaTamanhoDoNome(){
    if(nome.size() < 5){
        cout << "Nome muito curto!" << endl;
        exit(1);
    }
}