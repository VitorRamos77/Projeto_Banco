#include "Conta.hpp"
#include <iostream>

using namespace std;

int Conta::numeroDeContas = 0;

int Conta::recuperaNumeroDeContas(){
    return numeroDeContas;
}

Conta::Conta(std::string numero, std::string nomeTitular, std::string cpfTitular):
numero(numero),
nomeTitular(nomeTitular),
cpfTitular(cpfTitular),
saldo(0)
{
    verificaTamanhoDoNome(nomeTitular);
    numeroDeContas++;
}

Conta::~Conta(){
    numeroDeContas--;
}

void ExibeSaldo(const Conta& conta){
    cout << "O saldo da conta eh: " << conta.recuperaSaldo() << endl;
}

void Conta::sacar(float valorASacar){
    if(valorASacar < 0){
        cout << "Não pode sacar valor negativo." << endl;
        return;
    }

    if(valorASacar > saldo){
        cout << "Saldo insuficiente" << endl;
        return;
    }

    saldo -= valorASacar;
}

void Conta::depositar(float valorADepositar){
    if(valorADepositar < 0){
        cout << "Não pode depositar valor negativo." << endl;
        return;
    }

    saldo += valorADepositar;
}

float Conta::recuperaSaldo() const{
    return saldo;
}

string Conta::recuperaNumero(){
    return numero;
}

string Conta::recuperaCpfTitular(){
    return cpfTitular;
}

string Conta::recuperaNomeTitular(){
    return nomeTitular;
}

void Conta::verificaTamanhoDoNome(string nomeTitular){
    if(nomeTitular.size() < 5){
        cout << "Nome muito curto!" << endl;
        exit(1);
    }
}