#include <iostream>
#include <string>
#include "Conta.cpp"

using namespace std;

int main() {
    Conta umaConta("123456", "Vitor", "123.456.789-10");

    umaConta.depositar(500);
    umaConta.sacar(200);

    cout << "Uma conta:" << umaConta.recuperaSaldo() << endl;

}