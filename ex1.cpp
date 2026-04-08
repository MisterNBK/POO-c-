#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Pessoa {
public:
    int Id, Titulo;
    string Nome;
    Pessoa(int id, int titulo, string nome) : Id(id), Titulo(titulo), Nome(nome) {}
};

class Eleitor : public Pessoa {
public:
    bool Votou;
    Eleitor(int id, int titulo, string nome) : Pessoa(id, titulo, nome), Votou(false) {}
    void exibir() { 
        cout << "ID: " << Id << " Nome: " << Nome << " Titulo: " << Titulo << " Votou: " << (Votou ? "Sim" : "Nao") << endl; 
    }
};

class Candidato : public Pessoa {
public:
    int Numero;
    string Partido;
    Candidato(int id, int numero, int titulo, string nome, string partido) : Pessoa(id, titulo, nome), Numero(numero), Partido(partido) {}
    void exibir() { 
        cout << "Candidato " << Nome << " (" << Partido << ") - N° " << Numero << endl; 
    }
};

struct Voto {
    Candidato* candidato;
    Eleitor* eleitor;
    Voto(Candidato* c, Eleitor* e) : candidato(c), eleitor(e) {}
};

class Sistema {
public:
    int Id;
    string Data, Descricao;
    bool Ativa;
    vector<Candidato*> Candidatos;
    vector<Eleitor*> Eleitores;
    vector<Voto> Votos;
    map<int, Eleitor*> DicEleitores;
    map<int, Candidato*> DicCandidatos;

    Sistema(int id, string data, string descricao) : Id(id), Data(data), Descricao(descricao), Ativa(true) {}

    void criarCandidato(Candidato* c) {
        Candidatos.push_back(c);
        DicCandidatos[c->Numero] = c;
        cout << "Candidato adicionado: " << c->Nome << endl;
    }

    void criarEleitor(Eleitor* e) {
        Eleitores.push_back(e);
        DicEleitores[e->Id] = e;
        cout << "Eleitor adicionado: " << e->Nome << endl;
    }

    bool votou(int idEleitor, int numCandidato) {
        if (!Ativa) {
            cout << "Votacao encerrada" << endl;
            return false;
        }

        auto itEleitor = DicEleitores.find(idEleitor);
        if (itEleitor == DicEleitores.end()) {
            cout << "Eleitor nao encontrado" << endl;
            return false;
        }

        Eleitor* e = itEleitor->second;
        if (e->Votou) {
            cout << "Eleitor ja votou" << endl;
            return false;
        }

        auto itCandidato = DicCandidatos.find(numCandidato);
        if (itCandidato == DicCandidatos.end()) {
            cout << "Candidato nao encontrado" << endl;
            return false;
        }

        e->Votou = true;
        Votos.emplace_back(itCandidato->second, e);
        cout << "Voto registrado para " << itCandidato->second->Nome << endl;
        return true;
    }

    void apurarVotacao() {
        cout << "\nRESULTADO DA ELEICAO" << endl;
        cout << "Descricao: " << Descricao << endl;
        cout << "Total de votos: " << Votos.size() << "\n" << endl;

        map<Candidato*, int> contagem;
        for (auto& v : Votos) contagem[v.candidato]++;

        vector<pair<Candidato*, int>> ordenado(contagem.begin(), contagem.end());
        sort(ordenado.begin(), ordenado.end(), 
             [](auto& a, auto& b) { return a.second > b.second; });

        for (auto& [c, votos] : ordenado) {
            cout << c->Nome << " (" << c->Partido << "): " << votos << " votos" << endl;
        }
    }
};

int main() {
    Sistema sistema(1, "2026-10-01", "Eleicao Municipal");
    int id, titulo, numero;
    string nome, partido;

    cout << "CANDIDATOS" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\nCandidato " << i+1 << ":\nID: "; cin >> id;
        cout << "Numero: "; cin >> numero; 
        cout << "Titulo: "; cin >> titulo; 
        cout << "Nome: "; cin.ignore(); getline(cin, nome);
        cout << "Partido: ";  getline(cin, partido);
        sistema.criarCandidato(new Candidato(id, numero, titulo, nome, partido));
    }

    cout << "\nELEITORES " << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\nEleitor " << i+1 << ":\nID: "; cin >> id;
        cout << "Titulo: "; cin >> titulo;  
        cout << "Nome: ";cin.ignore(); getline(cin, nome);
        sistema.criarEleitor(new Eleitor(id, titulo, nome));
    }

    cout << "\nVOTACAO " << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\nID do Eleitor: "; cin >> id;
        cout << "Numero do Candidato: "; cin >> numero;
        sistema.votou(id, numero);
    }

    sistema.apurarVotacao();

    return 0;
}