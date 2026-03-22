#pragma once
#include <string>

using namespace std;

class Cpf{
    string numero;
public:
    Cpf(string numero);
    string recuperaNumero();
};