#include <iostream>
#include <string>
using namespace std;


void limparTela() { system("clear || cls"); }
void pausar() { cout << "\nPressione ENTER..."; cin.ignore(); cin.get(); }

class Alunos {
public:

    class NoAluno {
    public:
        int matricula;
        string nome;
        NoAluno *prox;
    };

    NoAluno *inicio = NULL;
    int proxMatricula = 1;

    void inserir() {
        string nome;
        cout << "Nome do aluno: ";
        getline(cin, nome);

        NoAluno *novo = new NoAluno();
        novo->matricula = proxMatricula++;
        novo->nome = nome;
        novo->prox = NULL;

        if (inicio == NULL)
            inicio = novo;
        else {
            NoAluno *aux = inicio;
            while (aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novo;
        }

        cout << "Aluno cadastrado! Matrícula: " << novo->matricula << endl;
    }

    void exibir() {
        cout << "\n=== ALUNOS CADASTRADOS ===\n";
        NoAluno *aux = inicio;
        while (aux != NULL) {
            cout << "Matricula: " << aux->matricula 
                 << " | Nome: " << aux->nome << endl;
            aux = aux->prox;
        }
    }

    int pesquisar(string nome) {
        NoAluno *aux = inicio;
        while (aux != NULL) {
            if (aux->nome == nome)
                return aux->matricula;
            aux = aux->prox;
        }
        return -1;
    }

    bool remover(string nome, bool temNotas) {
        if (temNotas) {
            cout << "ERRO: aluno possui notas.\n";
            return false;
        }

        NoAluno *aux = inicio;
        NoAluno *ant = NULL;

        while (aux != NULL) {
            if (aux->nome == nome) {
                if (ant == NULL)
                    inicio = aux->prox;
                else
                    ant->prox = aux->prox;
                delete aux;
                cout << "Aluno removido.\n";
                return true;
            }
            ant = aux;
            aux = aux->prox;
        }

        cout << "Aluno não encontrado.\n";
        return false;
    }
};


class Notas {
public:

    class NoNota {
    public:
        int matricula;
        float valor;
        NoNota *prox;
    };

    NoNota *inicio = NULL;

    void inserir(int matricula) {
        if (matricula == -1) {
            cout << "Aluno nao encontrado.\n";
            return;
        }

        float nota;
        cout << "Digite a nota: ";
        cin >> nota;
        cin.ignore();

        NoNota *nova = new NoNota();
        nova->matricula = matricula;
        nova->valor = nota;
        nova->prox = NULL;

        if (inicio == NULL || inicio->matricula > matricula) {
            nova->prox = inicio;
            inicio = nova;
            cout << "Nota registrada!\n";
            return;
        }

        NoNota *aux = inicio;
        while (aux->prox != NULL && aux->prox->matricula < matricula)
            aux = aux->prox;

        if (aux->prox != NULL && aux->prox->matricula == matricula) {

            NoNota *pilhaTopo = aux->prox;

            nova->prox = pilhaTopo;
            aux->prox = nova;

            cout << "Nota registrada!\n";
            return;
        }

        nova->prox = aux->prox;
        aux->prox = nova;

        cout << "Nota registrada!\n";
    }

    bool temNotas(int matricula) {
        NoNota *aux = inicio;
        while (aux != NULL) {
            if (aux->matricula == matricula)
                return true;
            aux = aux->prox;
        }
        return false;
    }

    void exibir(int matricula) {
        if (matricula == -1) {
            cout << "Aluno nao encontrado.\n";
            return;
        }

        cout << "\n=== NOTAS DO ALUNO ===\n";
        NoNota *aux = inicio;
        bool achou = false;

        while (aux != NULL) {
            if (aux->matricula == matricula) {
                cout << "Nota: " << aux->valor << endl;
                achou = true;
            }
            aux = aux->prox;
        }

        if (!achou)
            cout << "Sem notas.\n";
    }

    void removerNota(int matricula) {
        NoNota *aux = inicio;
        NoNota *ant = NULL;

        while (aux != NULL) {
            if (aux->matricula == matricula) {
                if (ant == NULL)
                    inicio = aux->prox;
                else
                    ant->prox = aux->prox;

                delete aux;
                cout << "Nota mais recente removida.\n";
                return;
            }
            ant = aux;
            aux = aux->prox;
        }

        cout << "Nao ha notas.\n";
    }
};


int main() {
    Alunos alunos;
    Notas notas;

    int op;
    string nome;

    while (true) {
        cout << "=== MENU ===\n";
        cout << "1 - Inserir aluno\n";
        cout << "2 - Exibir alunos\n";
        cout << "3 - Inserir nota\n";
        cout << "4 - Exibir notas\n";
        cout << "5 - Excluir nota mais recente\n";
        cout << "6 - Remover aluno\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";
        cin >> op;
        cin.ignore();

        limparTela();

        switch (op) {
        case 1:
            alunos.inserir();
            pausar(); limparTela();
            break;

        case 2:
            alunos.exibir();
            pausar(); limparTela();
            break;

        case 3:
            cout << "Nome do aluno: ";
            getline(cin, nome);
            notas.inserir(alunos.pesquisar(nome));
            pausar(); limparTela();
            break;

        case 4:
            cout << "Nome do aluno: ";
            getline(cin, nome);
            notas.exibir(alunos.pesquisar(nome));
            pausar(); limparTela();
            break;

        case 5:
            cout << "Nome do aluno: ";
            getline(cin, nome);
            notas.removerNota(alunos.pesquisar(nome));
            pausar(); limparTela();
            break;

        case 6:
            cout << "Nome do aluno: ";
            getline(cin, nome);
            alunos.remover(nome, notas.temNotas(alunos.pesquisar(nome)));
            pausar(); limparTela();
            break;

        case 0:
            return 0;
        }
    }
}
