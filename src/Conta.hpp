#pragma once
#include <string>

class Conta
{
private:
    std::string numero;
    std::string nomeTitular;
    std::string cpfTitular;
    float saldo;

public:
    Conta(std::string numero, std::string nomeTitular, std::string cpfTitular);
    void sacar(float valorASacar);
    void depositar(float valorADepositar);
    float recuperaSaldo() const;
    void definirNomeTitular(std::string nome);
    void definirCpfTitular(std::string cpfTitular);
    void definirNumero(std::string numero);
    std::string recuperaNumero();
    std::string recuperaCpfTitular();
    std::string recuperaNomeTitular();
};