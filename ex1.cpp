#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;
using std::map;

class Eleitor{
public:
    int Id, Titulo;
    string Nome;
    bool Votou;

    Eleitor(int id, int titulo, string nome){
        Id = id;
        Titulo = titulo;
        Nome = nome;
        Votou = false;
    }

    void exibir(){
        cout << "ID: " << Id << " Nome: " << Nome << " com o titulo: " << Titulo << "votou: " << (Votou ? "Sim" : "nao") << endl;
    }
};

class Candidato{

public:
    int Id, Numero, VotosRecebidos, Titulo;
    string Nome, Partido;
    bool Votou;

    Candidato(int id, int numero, int titulo, string nome, string partido, bool votou){
        Id = id;
        Titulo = titulo;
        Nome = nome;
        Votou = false;
        Partido = partido;
        VotosRecebidos = 0;
    }
    void exibir(){
        cout << "o candidato " << Nome << " do partido " << Partido << "do numero " << "recebeu " << VotosRecebidos << " votou: " << (Votou ? "Sim" : "Nao") << endl;
    }
};

class Sistema{
    int Id;
    string Data, Descricao;
    bool Ativa;
    list<Candidato> Candidatos;
    list<Eleitor> Eleitores;
    map<int, int> Votos;

    Sistema(int id, string data, string descricao){
        Id = id;
        Data = data;
        Descricao = descricao;
        Ativa = true;
    }

    void criarCandidato(Candidato candidato){
        cout << "Candidato adicionado: " << candidato.Nome << endl;
        Candidatos.push_back(candidato);
    }

    void criarEleitor(Eleitor eleitor){
        cout << "Eleitor adicionado: " << eleitor.Nome << endl;
    }

    bool votou(int idEleitor, int numeroCandidato){
        if (!Ativa){
            cout << "acabou a votacao" << endl;
            return false;
        }
        else{
            cout << "votacao ativa, pode votar" << endl;

            for (Eleitor &eleitor : Eleitores){
                if (eleitor.Id == idEleitor){
                    if (eleitor.Votou){
                        cout << "eleitor ja votou" << endl;
                        return false;
                    }
                    else{
                        eleitor.Votou = true;
                        for (Candidato &candidato : Candidatos){
                            if (candidato.Numero == numeroCandidato){
                                candidato.VotosRecebidos++;
                                Votos[idEleitor] = numeroCandidato;
                                cout << "voto registrado para o candidato " << candidato.Nome << endl;
                                return true;
                            }
                        }
                        cout << "candidato nao encontrado" << endl;
                        return false;
                    }
                }
            }
        }
    }
};
