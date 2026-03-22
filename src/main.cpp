#include <iostream>
#include <string>
#include "Conta.cpp"

using namespace std;

int main() {
    Conta umaConta("123456", "Vitor", "123.456.789-10");

    umaConta.depositar(500);
    umaConta.sacar(200);

    cout << "Uma conta:" << umaConta.recuperaSaldo() << endl;

    Conta umaOutraConta("654321", "Dias", "109.876.543-21");

    umaOutraConta.depositar(400);
    umaOutraConta.sacar(100);

    cout << "Uma OutrcaConta:" << umaOutraConta.recuperaSaldo() << endl;

    cout << "Numeor de contas: " << Conta::recuperaNumeroDeContas() << endl;

}