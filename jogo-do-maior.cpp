#include <iostream>

using namespace std;

int main()
{
int partidas, a, b, jg1 = 0, jg2 = 0;

do {
cin >> partidas;
if ( partidas > 10){
    return 0;
}
for ( int i = 0; i < partidas; i++){
cin >> a >> b;

if ( a > b){
jg1++;
}else if (a == b){

jg1 += 0;
jg2 += 0;

}else{
jg2++;
}
}
if ( partidas == 0){
    return 0;
} else {
cout << jg1 << " " << jg2 << endl;
}
jg1 = 0;
jg2 = 0;
}while ( partidas != 0);
return 0;
}

