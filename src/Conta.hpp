#pragma once
#include <string>

struct Conta
{
private:
    std::string numero;
    std::string cpfTitular;
    std::string nomeTitular;
    float saldo = 0;

public:
    void sacar(float valorASacar);
    void depositar(float valorADepositar);
    float recuperaSaldo();
    void definirNomeTitular(std::string nome);
    void definirCpfTitular(std::string cpfTitular);
    void definirNumero(std::string numero);
    string recuperaNumero();
    string recuperaCpfTitular();
    string recuperaNomeTitular();
};