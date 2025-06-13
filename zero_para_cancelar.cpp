#include <iostream>
using namespace std;

class Pilha
{
private:
    string Nome, Telefone;
    Pilha *elo;

public:
    Pilha* InserirPilha(Pilha *T, std::string N, std::string Tel)
    {
        Pilha *aux = new Pilha();
        aux->Nome = N;
        aux->Telefone = Tel;
        aux->elo = T;
        T = aux;
        return T;
    }

    void PercorrerPilha(Pilha *T)
    {
        Pilha *aux = T;
        if (aux == NULL)
        {
            std::cout << "\nPilha vazia!\n";
        }
        else
        {
            std::cout << "\nRegistros Cadastrados\n";
            while (aux != NULL)
            {
                std::cout << aux->Nome << " - " << aux->Telefone << std::endl;
                aux = aux->elo;
            }
        }
    }

    Pilha* RemoverPilha(Pilha *T)
    {
        Pilha *aux = T;
        T = T->elo;
        delete(aux);
        return T;
    }

    Pilha* EsvaziarPilha(Pilha *T)
    {
        Pilha *aux = T;
        while (aux != NULL)
        {
            T = T->elo;
            delete(aux);
            aux = T;
        }
        return T;
    }
};

void Menu()
{
    system("clear");
    cout << "1 - Inserir dados\n";
    cout << "2 - Exibir dados\n";
    cout << "3 - Apagar registro\n";
    cout << "4 - Esvaziar pilha de dados\n";
    cout << "5 - Finalizar programa\n";
    cout << "Informe sua opção: ";
}

int main()
{
    Pilha P, *topo = NULL;
    int op;
    string n, t;

    do {
        Menu();
        cin >> op;
        switch (op) {
        case 1:
            cout << "\nDigite o nome: ";
            cin.ignore(); // limpa o buffer
            getline(cin, n); // armazena até digitar o enter
            cout << "\nDigite o telefone: ";
            getline(cin, t);
            topo = P.InserirPilha(topo, n, t);
            cout << "\nRegistro incluído com sucesso!!\n";
            break;
        case 2:
            P.PercorrerPilha(topo);
            break;
        case 3:
            if (topo == NULL) {
                cout << "\nSem registros para deletar!\n";
            } else {
                topo = P.RemoverPilha(topo);
                cout << "\nRegistro deletado!\n";
            }
            break;
        case 4:
            if (topo == NULL) {
                cout << "\nSem registros para deletar!\n";
            } else {
                topo = P.EsvaziarPilha(topo);
                cout << "\nPilha vazia!\n";
            }
            break;
        case 5:
            cout << "\nTchau!!\n";
            break;
        default:
            cout << "\nOpção inválida!\n";
        }
        cout << "\nPressione Enter para continuar!! ";
        cin.ignore().get();
    } while (op != 5);

    return 0;
}
