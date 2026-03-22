#include <iostream>
#include <string>

using namespace std;

struct Conta {
    string numero;
    string cpfTitular;
    string nomeTitular;
    float saldo;
};

void sacar(Conta conta, float valorASacar){
    if(valorASacar < 0){
        cout << "Não pode sacar valor negativo" << endl;
        cout <<"Digite outro valor:";
        cin >> valorASacar;
        sacar(conta, valorASacar);
    }

    if(valorASacar >conta.saldo){
        cout << "Nao pode sacar um valor maior que o saldo." << endl;
    }

    conta.saldo -= valorASacar;
}

int main() {
    Conta umaConta;
    umaConta.numero = "12345-6";
    umaConta.cpfTitular = "12345678900";
    umaConta.nomeTitular = "João Silva";
    umaConta.saldo = 1000;

}