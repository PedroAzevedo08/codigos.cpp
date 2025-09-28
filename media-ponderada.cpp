#include <iostream>
using namespace std;

int main()
{
    float media, n1, n2, n3, n4, exame;
    cout << "Digite as quatro notas do aluno: ";
    cin >> n1 >> n2 >> n3 >> n4;

    media = ((2 * n1) + (3 * n2) + (4 * n3) + n4) / 10;

    if (media >= 7.0) {
        printf("Media: %.1f\n", media);
        cout << "Aluno aprovado." << endl;
    } else if (media < 5.0) {
        printf("Media: %.1f\n", media);
        cout << "Aluno reprovado." << endl;
    } else if (media >= 5.0 && media <= 6.9) {
        printf("Media: %.1f\n", media);
        cout << "Aluno em exame." << endl;
        cout << "Digite a nota do exame: ";
        cin >> exame;
        printf("Nota do exame: %.1f\n", exame);
        media = (media + exame) / 2;
        if (media >= 5.0) {
            cout << "Aluno aprovado." << endl;
        } else {
            cout << "Aluno reprovado." << endl;
        }
        printf("Media final: %.1f\n", media);
    }

    return 0;
}
