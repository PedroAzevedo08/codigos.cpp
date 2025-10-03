#include <iostream>
using namespace std;

class Listac {
public:
    struct Elo {
        int numero;
        int quantidade;
        Elo* prox;
        Elo(int n, int q) {
            numero = n;
            quantidade = q;
            prox = nullptr;
        }
    };

    Elo* inicio;

    Listac();
    void destruirLista();
    bool vemAntes(Elo* novo, Elo* atual);
    Elo* pesquisar(int num);
    void inserir(int numero, int quantidade);
    void exibir();
    void excluir(int numero);
};

Listac::Listac() {
    inicio = nullptr;
}

void Listac::destruirLista() {
    if (!inicio) return;
    Elo* p = inicio->prox;
    while (p != inicio) {
        Elo* aux = p;
        p = p->prox;
        delete aux;
    }
    delete inicio;
    inicio = nullptr;
}

bool Listac::vemAntes(Elo* novo, Elo* atual) {
    if (novo->quantidade > atual->quantidade) return true;
    if (novo->quantidade < atual->quantidade) return false;
    int resultado;
    do {
        resultado = rand() % 101;
    } while (resultado != 0);
    return true;
}

Listac::Elo* Listac::pesquisar(int num) {
    if (!inicio) return nullptr;
    Elo* p = inicio;
    do {
        if (p->numero == num) return p;
        p = p->prox;
    } while (p != inicio);
    return nullptr;
}

void Listac::inserir(int numero, int quantidade) {
    Elo* existente = pesquisar(numero);
    if (existente) {
        existente->quantidade += quantidade;

        if (inicio->prox != inicio) {
            Elo* p = inicio;
            Elo* ant = nullptr;
            do {
                if (p == existente) {
                    if (ant) ant->prox = p->prox;
                    else {
                        Elo* ult = inicio;
                        while (ult->prox != inicio) ult = ult->prox;
                        inicio = inicio->prox;
                        ult->prox = inicio;
                    }
                    break;
                }
                ant = p;
                p = p->prox;
            } while (p != inicio);

            Elo* p2 = inicio;
            Elo* ant2 = nullptr;
            do {
                if (vemAntes(existente, p2)) break;
                ant2 = p2;
                p2 = p2->prox;
            } while (p2 != inicio);

            if (!ant2) {
                Elo* ult = inicio;
                while (ult->prox != inicio) ult = ult->prox;
                existente->prox = inicio;
                ult->prox = existente;
                inicio = existente;
            } else {
                ant2->prox = existente;
                existente->prox = p2;
            }
        }

        return;
    }

    Elo* novo = new Elo(numero, quantidade);

    if (!inicio) {
        inicio = novo;
        inicio->prox = inicio;
        return;
    }

    Elo* p = inicio;
    Elo* ant = nullptr;
    do {
        if (vemAntes(novo, p)) break;
        ant = p;
        p = p->prox;
    } while (p != inicio);

    if (!ant) {
        Elo* ult = inicio;
        while (ult->prox != inicio) ult = ult->prox;
        novo->prox = inicio;
        ult->prox = novo;
        inicio = novo;
    } else {
        ant->prox = novo;
        novo->prox = p;
    }
}

void Listac::exibir() {
    if (!inicio) {
        cout << "Lista vazia!\n";
        return;
    }
    Elo* p = inicio;
    do {
        cout << "Numero: " << p->numero
             << " - repetiu: " << p->quantidade
             << (p->quantidade > 1 ? " vezes" : " vez") << endl;
        p = p->prox;
    } while (p != inicio);
}

void Listac::excluir(int numero) {
    if (!inicio) {
        cout << "Lista vazia!\n";
        return;
    }
    Elo* p = inicio;
    Elo* ant = nullptr;
    do {
        if (p->numero == numero) {
            if (p == inicio) {
                if (inicio->prox == inicio) {
                    delete inicio;
                    inicio = nullptr;
                    return;
                }
                Elo* ult = inicio;
                while (ult->prox != inicio) ult = ult->prox;
                inicio = inicio->prox;
                ult->prox = inicio;
                delete p;
            } else {
                ant->prox = p->prox;
                delete p;
            }
            cout << "Numero " << numero << " removido.\n";
            return;
        }
        ant = p;
        p = p->prox;
    } while (p != inicio);
    cout << "Numero nao encontrado.\n";
}

int main() {
    srand(time(nullptr));
    Listac lista;
    int opcao;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Inserir Numeros\n";
        cout << "2. Exibir Numeros\n";
        cout << "3. Excluir Numero\n";
        cout << "4. Finalizar\n";
        cout << "Escolha: ";
        cin >> opcao;

        if (opcao == 1) {
            int x;
            do {
                x = rand() % 101;
                if (x != 0) lista.inserir(x, 1);
            } while (x != 0);
            cout << "Numeros inseridos!\n";
        } else if (opcao == 2) {
            lista.exibir();
        } else if (opcao == 3) {
            int n;
            cout << "Informe o numero para excluir: ";
            cin >> n;
            lista.excluir(n);
        }

        cout << "\nPressione ENTER para continuar...";
        cin.ignore();
        cin.get();
        system("clear");

    } while (opcao != 4);

    lista.destruirLista();
    return 0;
}
