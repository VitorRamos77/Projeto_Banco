#include "Conta.hpp"
#include <iostream>

using namespace std;

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

void Conta::definirNomeTitular(std::string nome){
    nomeTitular = nome;
}

void Conta::definirCpfTitular(std::string cpf){
    cpfTitular = cpf;
}

void Conta::definirNumero(std::string num){
    numero = num;
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

