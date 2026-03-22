#include <iostream>
#include <string>
#include "Conta.hpp"
#include "Titular.hpp"
#include "Conta.cpp"
#include "Titular.cpp"
#include "Cpf.cpp"
#include "Cpf.hpp"

using namespace std;

int main() {
    Cpf cpf1("123.456.789-10");
    Titular titular1(cpf1, "Vitor");
    Conta umaConta("123456", titular1);

    umaConta.depositar(500);
    umaConta.sacar(200);

    cout << "Uma conta:" << umaConta.recuperaSaldo() << endl;

    Cpf cpf2("109.876.543-21");
    Titular titular2(cpf2, "Dias");
    Conta umaOutraConta("654321", titular2);

    umaOutraConta.depositar(400);
    umaOutraConta.sacar(100);

    cout << "Uma OutrcaConta:" << umaOutraConta.recuperaSaldo() << endl;

    cout << "Numeor de contas: " << Conta::recuperaNumeroDeContas() << endl;

}