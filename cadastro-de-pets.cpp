#include <iostream>
#include <string>
using namespace std;

class Pet {
public:
    string nome;
    int tipo;
    int idade;
    string raca;
    Pet* anterior;
    Pet* proximo;

    Pet() {
        anterior = nullptr;
        proximo = nullptr;
    }
};

class ListaPets {
private:
    Pet* inicio;

public:
    ListaPets() {
        inicio = nullptr;
    }


    bool comparar(Pet* a, Pet* b) {
        if (a->tipo != b->tipo)
            return a->tipo < b->tipo;
        return a->nome < b->nome;
    }

    void cadastrarPet(string nome, int tipo, int idade, string raca) {
        Pet* novo = new Pet();
        novo->nome = nome;
        novo->tipo = tipo;
        novo->idade = idade;
        novo->raca = raca;


        if (inicio == nullptr) {
            inicio = novo;
            return;
        }


        Pet* atual = inicio;
        Pet* anterior = nullptr;

        while (atual != nullptr && comparar(atual, novo)) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (anterior == nullptr) {

            novo->proximo = inicio;
            inicio->anterior = novo;
            inicio = novo;
        } else {

            novo->proximo = atual;
            novo->anterior = anterior;
            anterior->proximo = novo;
            if (atual != nullptr) {
                atual->anterior = novo;
            }
        }
    }

    void excluirPet(string nome, int tipo) {
        Pet* atual = inicio;

        while (atual != nullptr) {
            if (atual->nome == nome && atual->tipo == tipo) {
                if (atual->anterior != nullptr) {
                    atual->anterior->proximo = atual->proximo;
                } else {
                    inicio = atual->proximo;
                }
                if (atual->proximo != nullptr) {
                    atual->proximo->anterior = atual->anterior;
                }
                delete atual;
                cout << "Pet removido com sucesso!\n";
                return;
            }
            atual = atual->proximo;
        }
        cout << "Pet não encontrado.\n";
    }

    void listarGeral() {
        if (inicio == nullptr) {
            cout << "Lista vazia.\n";
            return;
        }

        Pet* aux = inicio;
        cout << "\nLISTAGEM GERAL:\n";
        while (aux != nullptr) {
            mostrarPet(aux);
            aux = aux->proximo;
        }
    }

    void listarCaes() {
        Pet* aux = inicio;
        cout << "\nLISTAGEM DE CÃES:\n";
        bool achou = false;
        while (aux != nullptr) {
            if (aux->tipo == 1) {
                mostrarPet(aux);
                achou = true;
            }
            aux = aux->proximo;
        }
        if (!achou) cout << "Nenhum cão cadastrado.\n";
    }

    void listarGatos() {
        Pet* aux = inicio;
        if (aux == nullptr) {
            cout << "Lista vazia.\n";
            return;
        }


        while (aux->proximo != nullptr) {
            aux = aux->proximo;
        }

        cout << "\nLISTAGEM DE GATOS (ordem decrescente):\n";
        bool achou = false;
        while (aux != nullptr) {
            if (aux->tipo == 2) {
                mostrarPet(aux);
                achou = true;
            }
            aux = aux->anterior;
        }
        if (!achou) cout << "Nenhum gato cadastrado.\n";
    }

    void pesquisarPet(string nome, int tipo) {
        Pet* aux = inicio;

        while (aux != nullptr) {
            if (aux->nome == nome && aux->tipo == tipo) {
                cout << "\nPET ENCONTRADO:\n";
                mostrarPet(aux);
                return;
            }
            aux = aux->proximo;
        }

        cout << "Não cadastrado.\n";
    }

    void mostrarPet(Pet* p) {
        cout << "Nome: " << p->nome << "\n";
        cout << "Tipo: " << (p->tipo == 1 ? "Cão" : "Gato") << "\n";
        cout << "Idade: " << p->idade << "\n";
        cout << "Raça: " << p->raca << "\n";
        cout << "-----------------------------\n";
    }
};

int main() {
    ListaPets lista;
    int opcao;

    do {
        system("clear");
        cout << "\nMENU\n";
        cout << "1. Cadastrar Pet\n";
        cout << "2. Excluir Pet\n";
        cout << "3. Listagem Geral\n";
        cout << "4. Listagem de cães\n";
        cout << "5. Listagem de gatos\n";
        cout << "6. Pesquisar\n";
        cout << "7. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        string nome, raca;
        int tipo, idade;

        switch (opcao) {
            case 1:
                cout << "Nome do pet: ";
                getline(cin, nome);
                cout << "Tipo (1 - Cão | 2 - Gato): ";
                cin >> tipo;
                cout << "Idade: ";
                cin >> idade;
                cin.ignore();
                cout << "Raça: ";
                getline(cin, raca);
                lista.cadastrarPet(nome, tipo, idade, raca);
                break;


            case 2:
                cout << "Nome do pet para exclusão: ";
                getline(cin, nome);
                cout << "Tipo (1 - Cão | 2 - Gato):";
                cin >> tipo;
                cin.ignore();
                lista.excluirPet(nome, tipo);
                break;

            case 3:
                lista.listarGeral();
                break;

            case 4:
                lista.listarCaes();
                break;

            case 5:
                lista.listarGatos();
                break;

            case 6:
                cout << "Nome do pet para pesquisar: ";
                getline(cin, nome);
                cout << "Tipo (1 - Cão | 2 - Gato): ";
                cin >> tipo;
                cin.ignore();
                lista.pesquisarPet(nome, tipo);
                break;
system("clear");
            case 7:
                cout << "Saindo do programa...\n";
                break;
system("clear");
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
        cin.ignore().get();
} while (opcao != 7);

    return 0;
}
