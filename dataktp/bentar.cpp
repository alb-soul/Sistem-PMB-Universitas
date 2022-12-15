#include <iostream>
using namespace std;
string merk_shoes [3] = {"Converse, Adidas, Nike"};
void inputan()
{
cout << "Menu Sepatu : "<< endl;
for (int a =0; a < 3; a++)
{
cout << merk_shoes[a] << endl;
}
}
void pilihan()
{
int jenis;
long converse = 150000, adidas = 300000, nike = 500000;
cout << "Input Pilihan Sepatu : ";
cin >> jenis;
cout << endl;
switch (jenis)
{
case 1:
cout<<"Harga Sepatu : " << merk_shoes[0] << " = Rp " << jenis;
break;
case 2:
cout << " Harga Sepatu : " << merk_shoes [1] << " = Rp " << jenis; break;
case 3:
cout << "Harga Sepatu : "<< merk_shoes [2] << " = Rp " << jenis; break;
}
}
int main(){
inputan(); pilihan();
return 0;
}


