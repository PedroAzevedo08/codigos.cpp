#include <iostream>

using namespace std;

void BolhaMelhorado( int vet[], int TAM, int &trocasb, int &compb)
{
int i = 1, j, aux;
trocasb = 0;
compb = 0;
bool troca = true ;
while (( i <= TAM) && ( troca ))

    {
         troca = false ;
         for(j = 0; j < TAM -1; j ++)
        {
        compb++;
             if ( vet [j ] > vet [j +1])
            {
                 troca = true ;
                 trocasb++;
                 aux = vet [j ];
                 vet[ j] = vet [j +1];
                 vet[ j +1] = aux ;
            }
        }
    i ++;
  }
}

void Insertion( int vet[], int TAM, int &trocasi, int &compi) {
trocasi = 0;
compi = 0;
 int i , j , eleito ;
 for( i = 1; i < TAM; i ++) {
 eleito = vet [i ];
 j = i - 1;
 while (( j >= 0) && ( vet [j] > eleito )) {

 compi++;
 vet [j + 1] = vet [j];
 j--;
 }
 vet [j + 1] = eleito;
 trocasi++;
  }
}

void Selecao( int vet[], int TAM, int &trocass, int &comps) {
 int i , j , eleito , menor , pos ;
 for( i = 0; i < TAM -1; i ++) {
 eleito = vet [i ];
 menor = vet[ i + 1];
 pos = i + 1;
 for(j = i +2; j < TAM ; j ++)
  { comps++;
 if ( vet [j ] < menor ) {
 menor = vet [j ];
 pos = j ;
 }
 }
 if( menor < eleito ){
 trocass++;
 vet [i ] = vet [ pos ];
 vet [ pos] = eleito ;
 }
 }
 }; 

void saidaBolhaMelhorado(int vet[],int TAM, int trocasb, int compb)
{
BolhaMelhorado(vet, TAM, trocasb, compb);
 cout << "Vetor ordenado:";
for ( int i = 0; i < TAM; i++)
 cout << vet[i] << "  ";
 cout << endl;
 cout << "N de trocas:" << trocasb << endl;
 cout << "N de comparacoes:" << compb << endl;}


 void saidaInsercao (int vet[], int TAM, int trocasi, int compi)
 {
 Insertion(vet, TAM, trocasi, compi);
 cout << "Vetor ordenado:";
 for (int i = 0; i < TAM; i++)
 cout << vet [i] << "  ";
 cout << endl;
 cout << "N de trocas:" << trocasi << endl;
 cout << "N de comparacoes:" << compi <<  endl;
 }

 void saidaSelecao( int vet[], int TAM, int &trocass, int &comps)
 {
 Selecao( vet, TAM, trocass,  comps);
  cout << "Vetor ordenado:";
 for (int i = 0; i < TAM; i++)
 cout << vet [i] << "  ";
 cout << endl;
 cout << "N de trocas:" << trocass << endl;
 cout << "N de comparacoes:" << comps <<  endl;
 }
int main(){

srand(time(NULL));
    int *vet = NULL, *vetcopia = NULL, TAM, inic, fim, trocasb, compb, trocasi, compi, trocass, comps;
    char resp;
    int respo;
    /*
cout << "1) Gerar Vetor" << endl;
cout << "2) Metodos" << endl;
cout << "3) Finalizar programa" << endl;
*/

//opcao1
    cout << "informe o tamanho:  ";
    cin >> TAM;
    cout << "intervalo:  ";
    cin >> inic >> fim;
    cout << "Vetor gerado: ";
    vet = new int [TAM];
    vetcopia = new int [TAM];
    for ( int i = 0; i < TAM ; i++)
    {
        vet[i] = rand() % (fim - inic + 1) + inic;
        cout << vet[i] << "  ";
    }
    cout << endl;
    cout << "-----------------------------------" << endl;
//opcao2

    if ( vet != NULL)trocasb = 0, compb = 0;
    {
        cout << "a) Apenas Bolha Melhorado" << endl;
        cout << "b) Apenas Inserção" << endl;
        cout << "c) Apenas Seleção" << endl;
        cout << "d) Bolha Melhorado e Inserção" << endl;
        cout << "e)Bolha Melhorado e Seleção" << endl;
        cout << "f) Inserção e Seleção" << endl;
        cout << "g) Todos os métodos" << endl;
    cout << "------------------------------------" << endl;
        cout << "Resposta: ";
        cin >> resp;
    cout << "------------------------------------" << endl;

if (resp == 'a'){
 saidaBolhaMelhorado(vet, TAM, trocasb, compb);
 } else
if (resp == 'b'){
saidaInsercao( vet,  TAM,  trocasi, compi);
} else
if (resp == 'c'){
saidaSelecao(vet, TAM, trocass, comps);
} else
if (resp == 'd'){
saidaBolhaMelhorado(vet, TAM, trocasb, compb);
cout << endl;
saidaInsercao( vet,  TAM,  trocasi, compi);
}

//opcao3
    /*delete(vet);
    delete(vetcopia);8*/
    return 0;
}}