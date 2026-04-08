#include <iostream>
#include <vector>
#include <string>

using namespace std;

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
    void linkarProduto(produto item) { cout << "Linkando produto " << item.Nome << " com estoque " << Nome << endl; }

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

    void linkarProdutoEstoque(produto item, estoque estoque) {
        cout << "Linkando produto " << item.Nome << " com estoque " << estoque.Nome << endl;
        estoque.linkarProduto(item);
    }
    
    void linkarFuncionarioProduto(funcionario escravo, produto item) {
        cout << "Linkando funcionario " << escravo.Nome << " com produto " << item.Nome << endl;
        escravo.registrar();
        item.registrar();
    }
    
    void linkarFuncionarioEstoque(funcionario escravo, estoque estoque) {
        cout << "Linkando funcionario " << escravo.Nome << " com estoque " << estoque.Nome << endl;
        escravo.registrar();
        estoque.registrar();
    }

    void listarProdutos() {
        cout << "Produtos registrados:" << endl;
        for (auto& p : Produtos) {
            cout << "- " << p.Nome << " (Categoria: " << p.Categoria << ", Codigo: " << p.Codigo << ")" << endl;
        }
    }

};

int main() {
    sistema loja;
    string nome, funcao, categoria; int quantidade, codigo; double preco;
    int opcao;
    cout << "Digite a opcao: "; cin >> opcao; cin.ignore();
    cout << "1 - Registrar Funcionario\n2 - Registrar Produto\n3 - Listar Produtos" << endl;
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
     return 0;
}