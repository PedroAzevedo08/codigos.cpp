#include <iostream>

using namespace std;

int main()
{
int n, aux = 1;
cout << "Digite o numero de casos: ";
cin >> n;
for ( int i = 0; i < n; i++){
 for ( int j = 0; j < 3; j++){
  cout << aux << " ";
  aux ++;
  }
cout << "PUM" << endl;
aux++;
}
 return 0;
}
