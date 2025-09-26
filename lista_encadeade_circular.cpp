#include <iostream>
#include <string>
#include <unistd.h>
#include <limits>
using namespace std;

class Processo {
public:
    string nome;
    int tempo;
    Processo* prox;
    Processo(string n, int t) {
        nome = n;
        tempo = t;
        prox = nullptr;
    }
};

class ListaCircular {
private:
    Processo* inicio;
public:
    ListaCircular() {
        inicio = nullptr;
    }

    void inserir(string nome, int tempo) {
        Processo* novo = new Processo(nome, tempo);
        if (!inicio) {
            inicio = novo;
            novo->prox = novo;
            return;
        }
        if (nome < inicio->nome) {
            Processo* ultimo = inicio;
            while (ultimo->prox != inicio) ultimo = ultimo->prox;
            ultimo->prox = novo;
            novo->prox = inicio;
            inicio = novo;
            return;
        }
        Processo* prev = inicio;
        Processo* curr = inicio->prox;
        while (curr != inicio && curr->nome < nome) {
            prev = curr;
            curr = curr->prox;
        }
        prev->prox = novo;
        novo->prox = curr;
    }

    void exibir() {
        if (!inicio) {
            cout << "Nenhum processo cadastrado.\n";
            return;
        }
        Processo* curr = inicio;
        do {
            cout << "Processo: " << curr->nome << " | Tempo: " << curr->tempo << "s\n";
            curr = curr->prox;
        } while (curr != inicio);
    }

    void executar() {
        if (!inicio) {
            cout << "Nenhum processo para executar.\n";
            return;
        }
        unsigned int microsecond = 1000000;
        Processo* curr = inicio;
        Processo* prev = nullptr;
        while (inicio) {
            cout << "Executando: " << curr->nome << " (Restante: " << curr->tempo << "s)\n";
            usleep(1 * microsecond);
            curr->tempo--;
            if (curr->tempo <= 0) {
                cout << "Processo " << curr->nome << " finalizado!\n";
                if (curr->prox == curr) {
                    delete curr;
                    inicio = nullptr;
                    break;
                }
                if (prev == nullptr) {
                    prev = inicio;
                    while (prev->prox != curr) prev = prev->prox;
                }
                prev->prox = curr->prox;
                if (curr == inicio) inicio = curr->prox;
                Processo* toDelete = curr;
                curr = curr->prox;
                delete toDelete;
            } else {
                prev = curr;
                curr = curr->prox;
            }
        }
        cout << "Todos os processos foram finalizados!\n";
    }

    void excluir(const string& nome) {
        if (!inicio) {
            cout << "Lista vazia.\n";
            return;
        }
        Processo* atual = inicio;
        Processo* anterior = nullptr;
        do {
            if (atual->nome == nome) {
                if (atual == inicio) {
                    if (inicio->prox == inicio) {
                        delete inicio;
                        inicio = nullptr;
                        cout << "Processo removido.\n";
                        return;
                    }
                    Processo* ultimo = inicio;
                    while (ultimo->prox != inicio) ultimo = ultimo->prox;
                    ultimo->prox = inicio->prox;
                    inicio = inicio->prox;
                    delete atual;
                    cout << "Processo removido.\n";
                    return;
                } else {
                    anterior->prox = atual->prox;
                    delete atual;
                    cout << "Processo removido.\n";
                    return;
                }
            }
            anterior = atual;
            atual = atual->prox;
        } while (atual != inicio);
        cout << "Processo nao encontrado.\n";
    }
};

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    ListaCircular lista;
    int opcao = 0;
    string nome;
    int tempo;
    string aux;
    do {
        limparTela();
        cout << "\n=== Menu ===\n";
        cout << "1. Inserir processo\n";
        cout << "2. Exibir processos\n";
        cout << "3. Executar processos\n";
        cout << "4. Excluir processo\n";
        cout << "5. Finalizar\n";
        cout << "Opcao: ";
        if (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcao = 0;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (opcao) {
        case 1:
            cout << "Nome do processo: ";
            getline(cin, nome);
            cout << "Tempo de execucao (s): ";
            if (!(cin >> tempo)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                tempo = 0;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            lista.inserir(nome, tempo);
            break;
        case 2:
            lista.exibir();
            cout << "\nPressione ENTER para voltar ao menu...";
            getline(cin, aux);
            break;
        case 3:
            lista.executar();
            cout << "\nPressione ENTER para voltar ao menu...";
            getline(cin, aux);
            break;
        case 4:
            cout << "Nome do processo a excluir: ";
            getline(cin, nome);
            lista.excluir(nome);
            cout << "\nPressione ENTER para voltar ao menu...";
            getline(cin, aux);
            break;
        case 5:
            cout << "Encerrando programa...\n";
            break;
        default:
            if (opcao != 0) {
                cout << "Opcao invalida!\n";
                cout << "\nPressione ENTER para voltar ao menu...";
                getline(cin, aux);
            }
        }
    } while (opcao != 5);
    return 0;
}
