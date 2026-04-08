#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Animais {
public:
    string Nome;
    int Idade;
    string Raca;
    int Codigo;
    vector<string> Especie;
    Animais(string nome, int codigo, int idade, string raca, string tipo, string especie): Nome(nome), Codigo(codigo), Idade(idade), Raca(raca), Especie() {
        Especie.push_back(especie);
    }
       
    void registrar() {
        cout << "Nome: " << Nome << endl;
        cout << "Codigo: " << Codigo << endl;
        cout << "Idade: " << Idade << endl;
        cout << "Raca: " << Raca << endl;
    }
};

class pessoa {
public:
    string Nome; string telefone; string Cpf; string Endereco;

    pessoa(string nome, string cpf, string endereco) : Nome(nome), Cpf(cpf), Endereco(endereco) {}

    void registrar() {
        cout << "Nome: " << Nome << endl;
        cout << "CPF: " << Cpf << endl;
    }

    void linkarAnimal(Animais animal) { cout << "Linkando animal " << animal.Nome << " com pessoa " << Nome << endl; }
};

class funcionario : public pessoa {
public:
    string Funcao;
    vector<Animais> AnimaisDeAtendimento;
    int Codigo;

    funcionario(string nome, string cpf, string endereco, string funcao, int codigo) : pessoa(nome, cpf, endereco) {
        Funcao = funcao;
        Codigo = codigo;
    }

    void registrar() {
        pessoa::registrar();
        cout << "Funcao: " << Funcao << endl;
        cout << "Codigo: " << Codigo << endl;
    }

    void linkarAnimal(Animais animal) {
        pessoa::linkarAnimal(animal);
        AnimaisDeAtendimento.push_back(animal);
    }
};

class cliente : public pessoa {
public:
    vector<Animais> animais;

    cliente(string nome, string cpf, string endereco) : pessoa(nome, cpf, endereco) {};

    void linkarAnimal(Animais animal) {
        pessoa::linkarAnimal(animal);
        animais.push_back(animal);
    }
};

class veterinaria {
public:
    string Nome;
    vector<funcionario> funcionarios; vector<cliente> clientes; vector<Animais> animais;

    veterinaria(string nome) : Nome(nome) {}

    void registrarFuncionario(funcionario escravo) { funcionarios.push_back(escravo); }

    void registrarCliente(cliente fonteDinheiro) { clientes.push_back(fonteDinheiro); }

    void registrarAnimal(Animais animal) { animais.push_back(animal); }

    void relacoes() {
    }
};

int main() {
    int opcao, codigo, idade;
    string nome, endereco, funcao, tipo, raca, especie, cpf;
    veterinaria PS("Pet Shop");
    do {
        cout << "Menu" << endl;
        cout << "1 - colocar Funcionario" << endl;
        cout << "2 - colocar Cliente" << endl;
        cout << "3 - colocar Animal" << endl;
        cout << "4 - AnimalFuncionario" << endl;
        cout << "5 - AnimalCliente" << endl;
        cout << "6 - Relacoes" << endl;
        cout << "0 - sair" << endl;
        cout << "Escolha uma opcao: "; cin >> opcao;

        switch (opcao) {
        case 1: {
            cout << "Digite o nome do funcionario: "; cin.ignore(); getline(cin, nome);
            cout << "Digite o CPF do funcionario: "; getline(cin, cpf);
            cout << "Digite o endereco do funcionario: "; cin.ignore(); getline(cin, endereco);
            cout << "Digite a funcao do funcionario: "; getline(cin, funcao);
            cout << "Digite o codigo do funcionario: "; cin >> codigo;

            funcionario escravo(nome, cpf, endereco, funcao, codigo);
            PS.registrarFuncionario(escravo);
            escravo.registrar();
            break;
        }
        case 2: {
            cout << "Digite o nome do cliente: "; cin.ignore(); getline(cin, nome);
            cout << "Digite o CPF do cliente: "; getline(cin, cpf);
            cout << "Digite o endereco do cliente: "; cin.ignore(); getline(cin, endereco);

            cliente fonteDinheiro(nome, cpf, endereco);
            PS.registrarCliente(fonteDinheiro);
            fonteDinheiro.registrar();
            break;
        }
        case 3: {
            cout << "Digite o nome do animal: "; cin.ignore(); getline(cin, nome);
            cout << "Digite o codigo do animal: "; cin >> codigo;
            cout << "Digite a idade do animal: "; cin >> idade;
            cout << "Digite a raca do animal: "; cin.ignore(); getline(cin, raca);
            cout << "Digite o tipo do animal: "; getline(cin, tipo);
            cout << "Digite a especie do animal: "; getline(cin, especie);

            Animais animal(nome, codigo, idade, raca, tipo, especie);
            PS.registrarAnimal(animal);
            animal.registrar();
            break;
        }
        case 4: {
            cout << "Digite o codigo do funcionario: "; cin >> codigo;
            cout << "Digite o codigo do animal: "; cin >> codigo;

            for (auto& func : PS.funcionarios) {
                if (func.Codigo == codigo) {
                    for (auto& animal : PS.animais) {
                        if (animal.Codigo == codigo) {
                            func.linkarAnimal(animal);
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }
        case 5: {
            cout << "Digite o codigo do cliente: "; cin >> codigo;
            cout << "Digite o codigo do animal: "; cin >> codigo;
            
            for (auto& cliente : PS.clientes) {
                if (cliente.Cpf == to_string(codigo)) {
                    for (auto& animal : PS.animais) {
                        if (animal.Codigo == codigo) {
                            cliente.linkarAnimal(animal);
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }
        default:
            if (opcao == 0) {
                cout << "codigo saido";
                return 0;
            } else {
                cout << "Opção inválida" << endl;
            }
        }
    } while (opcao != 0);
    return 0;
}