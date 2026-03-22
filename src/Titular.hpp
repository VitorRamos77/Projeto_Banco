#pragma once
#include <string>
#include "Cpf.hpp"

using namespace std;

class Titular
{
private:
    Cpf cpf;
    string nome;

public:
    Titular(Cpf cpf, string nome);

private:
    void verificaTamanhoDoNome();
};