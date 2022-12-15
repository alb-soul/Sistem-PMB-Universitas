#include <iostream>
#include "065.h"
#include "069.h"
#include "076.h"

using namespace std;

#define red "\e[1;31m"
#define green "\e[1;32m"
#define endcolor "\e[0m"

int main()
{
    system("clear");
  int pil;
  char ulang;
   do
    {
        cout << "\n===================================" << endl;
        cout << "====================================" << endl;
        cout << "=====    SELAMAT DATANG        =====" << endl;
        cout << "=====    DI PORTAL UTAMA       =====" << endl;
        cout << "=====    UNIVERSITAS B         =====" << endl;
        cout << "====================================" << endl;
        cout << "====================================\n" << endl;
        cout << "\tMenu yang disediakan \n";
        cout << "\t-----------------------------------"<<endl;
        cout << "\t|==== 1. Program PMB    =====|" << endl;
        cout << "\t|==== 2. Program Managemen =====|" << endl;
        cout << "\t|==== 3. Program KTP      =====|"<< endl;
        cout << "\t|==== 4. Keluar Program      =====|"<< endl;
        cout << "\t-----------------------------------"<<endl;
        cout << "\t|==== 11. About Us      =====|\n"<< endl;
        cout << "\t Masukkan Pilihan Anda : ";
        cin >> pil;
        if (pil == 1)
        {
            PMB pmb_mhs;
        }
        else if (pil == 2)
        {
           Mahasiswa<string> mhs;
        }
        else if (pil == 3)
        {
            KartuKeluarga x;
            // KTP x;
            // cin >> x;
            // cout << x;
        }
        else if (pil==11) {
            string str[10],buff;
            BinaryTree<string> leaf,ketua,anggota1,anggota2;
            ifstream bacaadmin;
            bacaadmin.open("dataktp/data_ktp_admin.txt");
            
            int i=0;
            while (!bacaadmin.eof()) {
                buff = "(";
                getline(bacaadmin,str[i]);
                buff += str[i] + ") ";
                str[i] = buff;
                getline(bacaadmin,buff);
                str[i] += buff;
                i++;
            }
            bacaadmin.close();
            //ketua.MakeTree(red+str[0]+endcolor,anggota1,anggota2);
            anggota1.MakeTree(str[1],leaf,leaf);
            anggota2.MakeTree(str[2],leaf,leaf);
            ketua.MakeTree(red+str[0]+endcolor,anggota1,anggota2);

            while (true) {
                cout << "\n *** Tentang Kami ***\n";
                cout << "\nTampilkan Hierarki Pengembang secara : \n";
                cout << "1. PreOrder\t(\e[1;31mKetua\e[0m - Anggota 1 - Anggota 2)\n";
                cout << "2. PostOrder\t(Anggota 1 - Anggota 2 - \e[1;31mKetua\e[0m)\n";
                cout << "3. InOrder\t(Anggota 1 - \e[1;31mKetua\e[0m - Anggota 2)\n";
                cout << "0. Kembali ke Menu Utama\n";
                cout << "\nMasukkan Pilihan Anda : ";
                cin >> pil;

                if (pil==1) {
                    cout << "\nHierarki Pengembang : \n\n";
                    ketua.PreOutput();
                } else if (pil==2) {
                    cout << "\nHierarki Pengembang : \n\n";
                    ketua.PostOutput();
                } else if (pil==3) {
                    cout << "\nHierarki Pengembang : \n\n";
                    ketua.InOutput();
                } else if (pil==0) {
                    system("clear");
                    break;
                } else {
                    cout << "\nInputan Salah\n";
                }

            }
            
        }
        else 
        {
            break;
        }
        cout << endl << "\t Kembali ke Menu ?(y/n) : ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');

    cout << "\nTerimakasih...\n";
    return 0;
}