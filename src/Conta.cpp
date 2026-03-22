#include "Conta.hpp"
#include <iostream>
#include "Titular.hpp"

using namespace std;

int Conta::numeroDeContas = 0;

int Conta::recuperaNumeroDeContas(){
    return numeroDeContas;
}

Conta::Conta(std::string numero, Titular titular):
numero(numero),
titular(titular),
saldo(0)
{
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

