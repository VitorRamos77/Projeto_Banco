# Sistema Bancário - Programação Orientada a Objetos em C++

Repositório de estudo de **POO (Programação Orientada a Objetos)** do curso da Alura.

## 📋 Descrição do Projeto

Este projeto implementa um **sistema bancário simplificado** utilizando os princípios de **Programação Orientada a Objetos (POO)** em C++. O sistema permite criar contas bancárias, gerenciar titulares, realizar operações de depósito e saque, e manter um controle do número de contas ativas.

### Funcionalidades Principais

- ✅ **Gestão de Contas**: Criar e gerenciar contas bancárias
- ✅ **Operações Bancárias**: Depositar e sacar valores com validação
- ✅ **Titulares**: Associar um titular (com CPF) a cada conta
- ✅ **Contador de Contas**: Rastrear automaticamente o número total de contas ativas
- ✅ **Validações**: Prevenir operações inválidas (valores negativos, saldo insuficiente, etc.)

---

## 🏗️ Estrutura do Projeto

### Classes Principais

#### **1. Cpf**
Representa um número de CPF do titular.

```cpp
class Cpf {
private:
    string numero;
public:
    Cpf(string numero);
    string recuperaNumero();
};
```

- **Atributos**: `numero` (string com o CPF)
- **Métodos**: Construtor e getter para recuperar o número do CPF
- **Arquivo**: `Cpf.hpp` e `Cpf.cpp`

#### **2. Titular**
Representa o titular de uma conta com validação de dados.

```cpp
class Titular {
private:
    Cpf cpf;
    string nome;
public:
    Titular(Cpf cpf, string nome);
private:
    void verificaTamanhoDoNome();
};
```

- **Atributos**: 
  - `cpf` (objeto Cpf)
  - `nome` (string)
- **Métodos**: 
  - Construtor que valida o nome (mínimo 5 caracteres)
  - `verificaTamanhoDoNome()` (validação privada)
- **Arquivo**: `Titular.hpp` e `Titular.cpp`

#### **3. Conta**
Gerencia informações da conta bancária com operações financeiras.

```cpp
class Conta {
private:
    static int numeroDeContas;
    string numero;
    Titular titular;
    float saldo;
public:
    Conta(string numero, Titular titular);
    ~Conta();
    void sacar(float valorASacar);
    void depositar(float valorADepositar);
    float recuperaSaldo() const;
    static int recuperaNumeroDeContas();
};
```

- **Atributos Privados**:
  - `numero` (identificador da conta)
  - `titular` (objeto Titular)
  - `saldo` (saldo atual, iniciado com 0)
  - `numeroDeContas` **(estático)** - conta total de contas ativas
  
- **Métodos Públicos**:
  - `sacar(float)` - Remove valor com validações
  - `depositar(float)` - Adiciona valor com validações
  - `recuperaSaldo()` - Retorna saldo (método const)
  - `recuperaNumeroDeContas()` - Retorna total de contas (método estático)
  - Construtor: inicializa saldo e incrementa contador
  - Destrutor: decrementa contador
- **Arquivo**: `Conta.hpp` e `Conta.cpp`

---

## 🔑 Conceitos de POO Utilizados

| Conceito | Implementação |
|----------|--------------|
| **Encapsulamento** | Atributos privados, métodos públicos controlam acesso |
| **Composição** | `Conta` contém `Titular`, que contém `Cpf` (relacionamento "tem-um") |
| **Atributos Estáticos** | `numeroDeContas` compartilhado entre todas as instâncias |
| **Construtores/Destrutores** | Inicialização automática e limpeza de recursos |
| **Métodos Const** | `recuperaSaldo()` não modifica o estado do objeto |
| **Validação de Dados** | Verificações em operações bancárias e criação de titulares |
| **Classes Auxiliares** | Separação de responsabilidades (Cpf, Titular, Conta) |

---

## 🛠️ Ferramentas Utilizadas

### Linguagem e Compilador
- **C++** (C++11 ou superior)
- **g++** - Compilador GNU C++ para Windows (MinGW)
  - Flags de compilação utilizadas:
    - `-Wall` - Mostra todos os avisos do compilador
    - `-Wextra` - Avisos adicionais e extra
    - `-g3` - Informações de debug completas para depuração

### Bibliotecas Padrão C++
- `<iostream>` - Entrada/saída de dados (cout, cin)
- `<string>` - Manipulação de strings

### Estrutura de Arquivos

```
pooAlura/
├── src/
│   ├── Cpf.hpp              # Interface da classe Cpf
│   ├── Cpf.cpp              # Implementação de Cpf
│   ├── Titular.hpp          # Interface da classe Titular
│   ├── Titular.cpp          # Implementação de Titular
│   ├── Conta.hpp            # Interface da classe Conta
│   ├── Conta.cpp            # Implementação de Conta
│   ├── main.cpp             # Programa principal (exemplo de uso)
│   └── output/              # Diretório de saída dos executáveis
├── README.md                # Este arquivo
└── LICENSE
```

---

## 📦 Como Compilar e Executar

### Pré-requisitos
- **g++** instalado (MinGW no Windows ou GCC no Linux/Mac)
- Terminal ou Prompt de Comando

### Passos

1. **Navegue até a pasta `src`**:
   ```bash
   cd src
   ```

2. **Compile todos os arquivos-fonte**:
   ```bash
   g++ -Wall -Wextra -g3 Conta.cpp Titular.cpp Cpf.cpp main.cpp -o output/programa
   ```
   
   Explicação do comando:
   - `Conta.cpp Titular.cpp Cpf.cpp main.cpp` - Arquivos-fonte a compilar
   - `-o output/programa` - Especifica o nome e local do executável
   - Flags `-Wall -Wextra -g3` - Ativa avisos e debug

3. **Execute o programa**:
   ```bash
   output/programa
   ```
   ou (no Windows):
   ```bash
   output\programa.exe
   ```

### Saída Esperada
```
Uma conta:300
Uma OutrcaConta:300
Numeor de contas: 2
```

---

## 💡 Exemplo de Uso Prático

```cpp
#include <iostream>
#include "Conta.hpp"
#include "Titular.hpp"
#include "Cpf.hpp"

using namespace std;

int main() {
    // Criar um CPF
    Cpf cpf1("123.456.789-10");

    // Criar um Titular com o CPF
    Titular titular1(cpf1, "Vitor");

    // Criar uma Conta bancária
    Conta umaConta("123456", titular1);

    // Realizar operações financeiras
    umaConta.depositar(500);    // Adiciona R$ 500.00
    umaConta.sacar(200);        // Remove R$ 200.00
    
    // Exibir saldo atual
    cout << "Saldo: " << umaConta.recuperaSaldo() << endl;  // Saída: 300

    // Criar outra conta
    Cpf cpf2("109.876.543-21");
    Titular titular2(cpf2, "Dias");
    Conta outraConta("654321", titular2);

    // Consultar número total de contas ativas
    cout << "Contas ativas: " << Conta::recuperaNumeroDeContas() << endl;  // 2
    
    return 0;
}
```

---

## ⚠️ Validações Implementadas

- **Depósito**: Rejeita valores negativos com mensagem de erro
- **Saque**: 
  - Rejeita valores negativos
  - Rejeita saques sem saldo suficiente
- **Titular**: Nome deve ter no mínimo 5 caracteres (encerra com exit(1) se inválido)
- **Saldo Inicial**: Toda conta começa com saldo R$ 0.00

### Exemplos de Validação

```cpp
// Tentativa de depositar valor negativo
conta.depositar(-50);  // Saída: "Não pode depositar valor negativo."

// Tentativa de sacar mais que o saldo
conta.sacar(1000);  // Saída: "Saldo insuficiente"

// Titular com nome curto
Titular titular("123.456.789-10", "Ana");  // Saída: "Nome muito curto!" + exit(1)
```

---

## 📝 Notas Técnicas Importantes

### 1. Atributo Estático `numeroDeContas`
- Compartilhado por **todas as instâncias** da classe `Conta`
- Incrementado no construtor (`numberOfContas++`)
- Decrementado no destrutor (`numberOfContas--`)
- Acessado via `Conta::recuperaNumeroDeContas()`

### 2. Composição de Objetos
A arquitetura segue o padrão de composição:
```
Conta "tem-um" Titular
            |
Titular "tem-um" Cpf
```

### 3. Encapsulamento
- Atributos são **privados** para proteger integridade dos dados
- Acesso controlado via métodos **públicos**
- Validações ocorrem nos setters (depositar, sacar)

### 4. Métodos Const
- `recuperaSaldo() const` garante que não modifica o objeto
- Permite chamar em objetos `const` e referências `const`

### 5. Destrutor
O destrutor `~Conta()` é crucial para:
- Manter o contador correto quando objetos são destruídos
- Simular "encerramento" da conta

---

## 🎓 Objetivo Educacional

Este projeto é um exercício prático para ensinar:
- ✅ Modelagem de classes em C++
- ✅ Separação entre interface (.hpp) e implementação (.cpp)
- ✅ Uso de construtores e destrutores
- ✅ Implementação de validações e tratamento de erros
- ✅ Composição de objetos (relacionamento "tem-um")
- ✅ Atributos e métodos estáticos
- ✅ Métodos const
- ✅ Princípios SOLID (Single Responsibility Principle)
- ✅ Encapsulamento e abstração

---

## 🔍 Conceitos Avançados

### Padrão de Implementação em C++
Este projeto segue o padrão tradicional de C++ com header guards:
- `#pragma once` previne inclusões múltiplas
- Separação clara entre interface e implementação
- Uma classe por par de arquivos (.hpp/.cpp)

### Gerenciamento de Memória
- Uso de objetos na **stack** (sem alocação dinâmica com `new`/`delete`)
- Destrutores garantem limpeza automática

---

## 📄 Referências

- [C++ Standard Library Reference](https://cplusplus.com/)
- [Curso Alura - POO em C++](https://www.alura.com.br/)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

---

## 📄 Licença

Este projeto é fornecido como material educacional para fins de aprendizado.
