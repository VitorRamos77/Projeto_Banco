#include <iostream>
#include <string>
#include "Conta.cpp"

using namespace std;

int main() {
    Conta umaConta;
    Conta umaOutraConta;

    umaOutraConta.depositar(500);
    umaOutraConta.sacar(200);

    cout << "Uma conta:" << umaConta.recuperaSaldo() << endl << "Outra conta: " << umaOutraConta.recuperaSaldo() << endl;

}