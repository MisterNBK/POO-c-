#include <iostream>
#include <vector>
#include <string>

using namespace std;

class produto;

class estoque{
    public:
    string Nome;
    int Quantidade; int Codigo;
    double Preco;
    

    estoque(string nome, int quantidade, double preco, int codigo) : Nome(nome), Quantidade(quantidade), Preco(preco), Codigo(codigo) {}

    void registrar() {
        cout << "Nome: " << Nome << endl;
        cout << "Quantidade: " << Quantidade << endl;
        cout << "Preco: " << Preco << endl;
        cout << "Codigo: " << Codigo << endl;
    }

};

class produto : public estoque {
    public:
    string Categoria;

    produto(string nome, int quantidade, double preco, int codigo, string categoria) : estoque(nome, quantidade, preco, codigo), Categoria(categoria) {}

    void registrar() {
        estoque::registrar();
        cout << "Categoria: " << Categoria << endl;
    }
};

class funcionario {
    public:
    string Nome; string Funcao;
    int Codigo;

    funcionario(string nome, string funcao, int codigo) : Nome(nome), Funcao(funcao), Codigo(codigo) {}

    void registrar() {
        cout << "Nome: " << Nome << endl;
        cout << "Funcao: " << Funcao << endl;
        cout << "Codigo: " << Codigo << endl;
    }
};

class sistema {
    public:
    vector<estoque> Estoques; vector<produto> Produtos; vector<funcionario> Funcionarios;

    void registrarProduto(produto item) { Produtos.push_back(item); }
    void registrarFuncionario(funcionario escravo) { Funcionarios.push_back(escravo); }
    void registrarEstoque(estoque estoque) { Estoques.push_back(estoque); }

    void listarProdutos() {
        cout << "Produtos registrados:" << endl;
        for (auto& p : Produtos) {
            cout << "- " << p.Nome << " (Categoria: " << p.Categoria << ", Codigo: " << p.Codigo << ", quantidade: " << p.Quantidade << ")" << endl;
        }
    }

    void listarFuncionarios() {
        cout << "Funcionarios registrados:" << endl;
        for (auto& f : Funcionarios) {
            cout << "- " << f.Nome << "(funcao: " << f.Funcao << ")" << endl;
        }
    }


};

int main() {
    sistema loja;
    string nome, funcao, categoria; int quantidade, codigo; double preco;
    int opcao;
    do{
    cout << "1 - Registrar Funcionario\n2 - Registrar Produto\n3 - Listar Produtos\n4 - Listar Funcionarios\n0 - sair" << endl;
    cout << "Digite a opcao: "; cin >> opcao; cin.ignore();
switch (opcao) {
        case 1: {
    cout << "Digite o nome do funcionario: "; getline(cin, nome);
    cout << "Digite a funcao do funcionario: "; getline(cin, funcao);
    cout << "Digite o codigo do funcionario: "; cin >> codigo;
    funcionario escravo(nome, funcao, codigo);
    loja.registrarFuncionario(escravo);
    escravo.registrar();
            break;
        }
        case 2: {
    cout << "Digite o nome do produto: "; getline(cin, nome);
    cout << "Digite a categoria do produto"; getline(cin, categoria);
    cout << "Digite a quantidade do produto: "; cin >> quantidade;
    cout << "Digite o preco do produto: "; cin >> preco;
    cout << "Digite o codigo do produto: "; cin >> codigo;
    produto prod(nome, quantidade, preco, codigo, categoria);
    loja.registrarProduto(prod);
    prod.registrar();
            break;
        }
        case 3: {
    loja.listarProdutos();
            break;
        }
        case 4:{
    loja.listarFuncionarios();
            break;
        }
        case 0:{
            break;
        }
        default:
            cout << "Opcao invalida!" << endl;
}
    }while(opcao != 0);
     
    
     return 0;
}