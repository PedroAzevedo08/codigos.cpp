#include <iostream>
#include <string>
using namespace std;

void limparTela() { system("clear || cls"); }
void pausar() { cout << "\nPressione ENTER..."; cin.ignore(); cin.get(); }

class Alunos {
public:
    int matriculas[100];
    string nomes[100];
    int totalAlunos = 0;
    int proximaMatricula = 1;

    void inserir() {
        string nome;
        cout << "Nome do aluno: ";
        getline(cin, nome);

        matriculas[totalAlunos] = proximaMatricula++;
        nomes[totalAlunos] = nome;
        totalAlunos++;

        cout << "Aluno cadastrado! Matrícula: "
             << matriculas[totalAlunos - 1] << endl;
    }

    void exibir() {
        cout << "\n=== ALUNOS CADASTRADOS ===\n";
        for (int i = 0; i < totalAlunos; i++) {
            cout << "Matricula: " << matriculas[i]
                 << " | Nome: " << nomes[i] << endl;
        }
    }

    int pesquisar(string nome) {
        for (int i = 0; i < totalAlunos; i++) {
            if (nomes[i] == nome)
                return matriculas[i];
        }
        return -1;
    }

    bool remover(string nome, bool temNotas) {
        if (temNotas) {
            cout << "ERRO: este aluno possui notas.\n";
            return false;
        }

        for (int i = 0; i < totalAlunos; i++) {
            if (nomes[i] == nome) {
                for (int j = i; j < totalAlunos - 1; j++) {
                    matriculas[j] = matriculas[j + 1];
                    nomes[j] = nomes[j + 1];
                }
                totalAlunos--;
                cout << "Aluno removido.\n";
                return true;
            }
        }

        cout << "Aluno nao encontrado.\n";
        return false;
    }
};

class Notas {
public:
    int matriculaNota[200];
    float valorNota[200];
    int totalNotas = 0;

    void inserir(int matricula) {
        if (matricula == -1) {
            cout << "Aluno nao encontrado.\n";
            return;
        }

        float nota;
        cout << "Digite a nota: ";
        cin >> nota;
        cin.ignore();

        int pos = 0;

        while (pos < totalNotas && matriculaNota[pos] < matricula)
            pos++;

        if (pos < totalNotas && matriculaNota[pos] == matricula) {
            int inicio = pos;
            while (pos < totalNotas && matriculaNota[pos] == matricula)
                pos++;

            for (int i = totalNotas; i > inicio; i--) {
                matriculaNota[i] = matriculaNota[i - 1];
                valorNota[i] = valorNota[i - 1];
            }

            matriculaNota[inicio] = matricula;
            valorNota[inicio] = nota;
            totalNotas++;

            cout << "Nota registrada!\n";
            return;
        }

        for (int i = totalNotas; i > pos; i--) {
            matriculaNota[i] = matriculaNota[i - 1];
            valorNota[i] = valorNota[i - 1];
        }

        matriculaNota[pos] = matricula;
        valorNota[pos] = nota;
        totalNotas++;

        cout << "Nota registrada!\n";
    }

    bool temNotas(int matricula) {
        for (int i = 0; i < totalNotas; i++)
            if (matriculaNota[i] == matricula)
                return true;
        return false;
    }

    void exibir(int matricula) {
        if (matricula == -1) {
            cout << "Aluno nao encontrado.\n";
            return;
        }

        bool encontrou = false;
        cout << "\n=== NOTAS DO ALUNO ===\n";

        for (int i = 0; i < totalNotas; i++) {
            if (matriculaNota[i] == matricula) {
                cout << "Nota: " << valorNota[i] << endl;
                encontrou = true;
            }
        }

        if (!encontrou)
            cout << "Sem notas.\n";
    }

    void removerNota(int matricula) {
        for (int i = totalNotas - 1; i >= 0; i--) {
            if (matriculaNota[i] == matricula) {
                for (int j = i; j < totalNotas - 1; j++) {
                    matriculaNota[j] = matriculaNota[j + 1];
                    valorNota[j] = valorNota[j + 1];
                }
                totalNotas--;
                cout << "Nota mais recente removida.\n";
                return;
            }
        }

        cout << "Nao ha notas para excluir.\n";
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
