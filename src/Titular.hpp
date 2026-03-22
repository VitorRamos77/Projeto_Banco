#pragma once
#include <string>

using namespace std;

class Titular
{
private:
    string cpf;
    string nome;

public:
    Titular(string cpf, string nome);

private:
    void verificaTamanhoDoNome();
};