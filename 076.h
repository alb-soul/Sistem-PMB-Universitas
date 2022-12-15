#include <cstring>
#include <fstream>
#include <sstream>
#include <string>
#include "llist.h"
#include "binary.h"

using namespace std;

struct alamatt {
  string provinsi, kab, kec, kota;
  int rt, rw;
};

struct mahasiswaa {
  string nim, nama, nisn, no_hp;
  alamatt almt;
  mahasiswaa *next;
};

struct node_hapus {
  string data;
  node_hapus *next;
};

struct priorityQueue {
  string data;
  int prioritas;
  priorityQueue *next;
  priorityQueue *prev;
};

int numAntrian;

/*void Enqueue(string x, int p) {
  if (numAntrian==0) {
    priorityQueue *baru = new priorityQueue;
    baru->data = x;
    baru->prioritas = p;
    baru->next = NULL;
    baru->prev = NULL;
    head = baru;
    ptr = baru;
    numAntrian++;
  } else {
    priorityQueue *baru = new priorityQueue;
    baru->data = x;
    baru->prioritas = p;
    baru->next = NULL;
    baru->prev = ptr;
    ptr->next = baru;
    ptr = baru;
    numAntrian++;
  }
}*/

template <class T>
class Mahasiswa {
public:
  Mahasiswa();
  bool login();
  void input_data_mhs();
  void list_data_mhs();
  void cari_data_mhs();
  void update_data_mhs();
  void hapus_data_mhs();
  void pengajuan_update();
  void cek_ajuan_update();

  void aturAntrian(); //mengatur antrian utk rekap data dari hasil seleksi beasiswa
  void Enqueue(string x, int p); //menambahkan data ke antrian
  string Dequeue(); //menghapus data dari antrian

private:
  mahasiswaa *mhs = new mahasiswaa[10];
  
  Array1D<string> stackmhsdata;
  Array1D<string> tempstackmhsdata;
  int menu, n, index;

  ofstream kefile, store_last_index;
  ifstream getfile, get_index;
  size_t nim_len = 5;
  int precision;
  string temp_str[50];

  vector<string>data;
  string key;
  string status;
  string current_credential;
  bool proses = false;

  priorityQueue *head = NULL;
  priorityQueue *ptr = NULL;
};

template <class T>
Mahasiswa<T>::Mahasiswa() {
  get_index.open("datamanagemen/banyak_index.txt");
  if (!get_index) 
  {
    get_index.close();

    store_last_index.open("datamanagemen/banyak_index.txt");
    store_last_index << 0;
    store_last_index.close();

    get_index.open("datamanagemen/banyak_index.txt");
    get_index >> index;
    get_index.close();
  } 
  else 
  {
    proses = true;
    while (!get_index.eof())
    {
      get_index >> index;
    }
    get_index.close();
  }

  // cout << index << endl;
  bool status_login = login();
  if (status_login) 
  {
    if (status == "Admin") 
    {
      do {
        cout << "\n=================================" << endl;
        cout << "=================================" << endl;
        cout << "=====    SELAMAT DATANG     =====" << endl;
        cout << "=====     DI PROGRAM        =====" << endl;
        cout << "=====        ADMIN        =====" << endl;
        cout << "=================================" << endl;
        cout << "=================================\n" << endl;
        cout << "Anda sedang login sebagai 'Admin' : " << current_credential << endl;
        cout << "Daftar Menu : \n";
        cout << "0. Keluar\n";
        cout << "1. Rekap data mahasiswa\n";
        cout << "2. List data mahasiswa\n";
        cout << "3. Update data mahasiswa\n";
        cout << "4. Hapus data mahasiswa\n";
        cout << "5. Cari data\n";
        cout << "6. Cek ajuan update mahasiswa\n";
        cout << "\nPilih menu yang tersedia: ";
        cin >> menu;
        getchar();
        switch (menu) {
        case 1:
          proses = true;
          // cout << "\nBanyak mahasiswa yang akan diinput : "; cin >> n;
          // getchar(); kefile.open("../../data/mahasiswa.txt",ios_base::app);
          input_data_mhs();
          break;
          
        case 2:
          if (proses == false)
          {
            cout << "\n\e[1;31mData masih kosong...\e[0m\n\n";
          }
          else
          {
            list_data_mhs();
            break;
          }
          
          
        case 3:
          if (proses == false)
          {
            cout << "\n\e[1;31mData masih kosong...\e[0m\n\n";
          }
          else
          {
            update_data_mhs();
            break;
          }
          
        case 4:
          if (proses == false)
          {
            cout << "\n\e[1;31mData masih kosong...\e[0m\n\n";
          }
          else
          {
            hapus_data_mhs();
            break;
          }
          
        case 5:
          if (proses == false)
          {
            cout << "\n\e[1;31mData masih kosong...\e[0m\n\n";
          }
          else
          {
            cari_data_mhs();
            break;
          }

        case 6:
          cek_ajuan_update();
          break;
          
        case 0:
          cout << "\nTerimakasih...\n";
          delete[] mhs; // delete array of struct/class (dealokasi memori)
          break;
        }
      } while (menu != 0);
    } 
    else if (status == "Tamu") 
    {
      do {
        cout << "\n=================================" << endl;
        cout << "=================================" << endl;
        cout << "=====    SELAMAT DATANG     =====" << endl;
        cout << "=====     DI PROGRAM        =====" << endl;
        cout << "=====        TAMU        =====" << endl;
        cout << "=================================" << endl;
        cout << "=================================\n" << endl;
        cout << "Anda sedang login sebagai 'Tamu' : " << current_credential << endl;
        cout << "Daftar Menu : \n";
        cout << "0. Keluar\n";
        cout << "1. List data mahasiswa\n";
        cout << "2. Cari data\n";
        cout << "3. Ajukan perubahan data mahasiswa\n";
        cout << "\nPilih menu yang tersedia : ";
        cin >> menu;
        getchar();
        switch (menu) {
        case 1:
          if (proses == 0)
          {
            cout << "\n\e[1;31mData masih kosong...\e[0m\n\n";
          }
          else 
          {
            list_data_mhs();
            break;
          }
          
        case 2:
          if (proses == 0)
          {
            cout << "\n\e[1;31mData masih kosong...\e[0m\n\n";
          }
          else
          {
            cari_data_mhs();
            break;
          };

        case 3:
          pengajuan_update();
          break;
          
        case 0:
          cout << "\nTerimakasih...\n";
          delete[] mhs; // delete array of struct/class (dealokasi memori)
          break;
        }
      } while (menu != 0);
    }

  } 
  else 
  {
    cout << "Anda gagal login. Silakan coba lagi nanti...\n";
  }
}

template <class T>
bool Mahasiswa<T>::login() {
  bool status_login;
  string temp_usr, temp_pass;
  string username, password;
  // gagal_login:
  cout << "\n=================================" << endl;
  cout << "=================================" << endl;
  cout << "=====    SELAMAT DATANG     =====" << endl;
  cout << "=====     DI PROGRAM        =====" << endl;
  cout << "=====     MANAGEMEN         =====" << endl;
  cout << "=================================" << endl;
  cout << "=================================\n" << endl;
  cout << "Daftar Menu : \n";
  cout << "1. Login sebagai Admin\n";
  cout << "2. Login sebagai Tamu\n";
  cout << "\nPilih menu yang tersedia : ";
  cin >> menu;
  getchar();

  if (menu == 1) 
  {
    cout << "\nUsername : ";
    getline(cin, username);
    cout << "Password : ";
    getline(cin, password);

    getfile.open("dataktp/data_ktp_admin.txt");
    while (!getfile.eof()) 
    {
      getline(getfile, temp_pass);
      getline(getfile, temp_usr);
      if (username == temp_usr && password == temp_pass) 
      {
        status_login = true;
        status = "Admin";
        break;
      } 
      else 
      {
        status_login = false;
      }
    }
    getfile.close();
  } 
  else if (menu == 2) 
  {
    cout << "\nNama : ";
    getline(cin, username);
    cout << "NIK : ";
    getline(cin, password);
    string temp_str;
    getfile.open("datamanagemen/mahasiswa.txt");
    while (!getfile.eof()) 
    {
      getline(getfile, temp_str);
      if (temp_str.find(username) != string::npos && temp_str.find(password)!= string::npos) 
      {
        status_login = true;
        status = "Tamu";
        current_credential = username;
        break;
      } 
      else 
      {
        status_login = false;
      }
    }
    getfile.close();
  }
  return status_login;
}

template <class T>
void Mahasiswa<T>::input_data_mhs() {

  cout << "\n=================================" << endl;
  cout << "1. Rekap dari PMB\n";
  cout << "2. Rekap dari Beasiswa\n";
  cout << "Pilih : ";
  cin >> menu;
  getchar();

  // kefile.close();
  if (menu==1) {
    index = 0;

    string temp_rekap;
    ifstream read;
    ofstream rekap;
    rekap.open("datamanagemen/maha_rekap.txt");
    read.open("datamanagemen/mahasiswa.txt");

    while (getline(read, temp_rekap)) 
    {
      mhs[index].nim = to_string(index + 1);
      precision = nim_len - min(nim_len, mhs[index].nim.size());
      mhs[index].nim.insert(0, precision, '0');

      if (temp_rekap.find(mhs[index].nim) == string::npos) 
      {
        rekap << mhs[index].nim << '\t';
      }

      rekap << temp_rekap << endl;
      index++;
    }

    read.close();
    rekap.close();

    remove("datamanagemen/mahasiswa.txt");
    rename("datamanagemen/maha_rekap.txt", "datamanagemen/mahasiswa.txt");

    store_last_index.open("datamanagemen/banyak_index.txt");
    store_last_index << index;
    store_last_index.close();
  }
  else {
    ofstream rekap_seleksi;
    //get index
    get_index.open("datamanagemen/banyak_index.txt");
    while (!get_index.eof()) 
    get_index >> index;
    get_index.close();
    cout << "Index yg terbaca : " << index << endl;

    int n_rpr;
    int index_seleksi = 0;
    string buff;
    string buff2;
    get_index.open("Beasiswa/hasilseleksi.txt");
    while (getline(get_index, buff)) {
      
      //store nilai_raport to int var
    
      //cout << "Cek nilai n_npr hasil konvert : " << n_rpr << ",";
      //get_index >> buff;
      buff2 = buff;
      buff2 = buff2.substr(0, 2);
      n_rpr = stoi(buff2);
      //n_rpr = stoi(buff.substr(0, 2));
      buff = buff.substr(3, buff.length());
      cout << "Cek buff : " << buff << endl;
      Enqueue(buff,n_rpr);
      cout << "INi errornya dimana?" << endl;
      index_seleksi++;
      //if (get_index.eof()) break;
    }
    get_index.close();

    cout << "Index utk hasil seleksi : " << index_seleksi << endl;

    string x = "";
    int i = 0;
    cout << "Apakah berhasil kebuka? (sebelum buka file)" << endl;
    rekap_seleksi.open("datamanagemen/maha_rekap.txt");

    cout << "Apakah berhasil kebuka?" << endl;
    int nim_index = index;
    for (int j = 0; j < index_seleksi; j++) {
      cout << "Emang mhs[nim...dst.] ada isinya? " << endl;
      mhs[nim_index].nim = to_string(nim_index + 1);
      cout << "Cuba kaau muncul berarti beanrhasil" << endl;
      precision = nim_len - min(nim_len, mhs[nim_index].nim.size());
      mhs[nim_index].nim.insert(0, precision, '0');
      x += mhs[nim_index].nim + '\t';
      x += Dequeue();
      rekap_seleksi << x << endl;
      //index++;
      nim_index++;
      x = "";
      index++;
    }
    rekap_seleksi.close();

    rekap_seleksi.open("datamanagemen/mahasiswa.txt", ios::app);
    ifstream read;
    read.open("datamanagemen/maha_rekap.txt");
    while (getline(read, x)) {
      rekap_seleksi << x << endl;
    }
    read.close();
    rekap_seleksi.close();
    store_last_index.open("datamanagemen/banyak_index.txt");
    store_last_index << index;
    store_last_index.close();

    //bersihkan file maha_rekap.txt
    //rekap_seleksi.open("datamanagemen/maha_rekap.txt");
    //rekap_seleksi << "";
    //rekap_seleksi.close();

    //bersihkan file hasilseleksi.txt
    rekap_seleksi.open("Beasiswa/hasilseleksi.txt");
    //rekap_seleksi << "";
    rekap_seleksi.close();

  }
}

template <class T>
void Mahasiswa<T>::list_data_mhs() {
  getfile.open("datamanagemen/mahasiswa.txt");
  get_index.open("datamanagemen/banyak_index.txt");

  while (!get_index.eof()) 
  {
    get_index >> index;
  }
  get_index.close();

  int i = 0;
  cout << "\nNIM :\tNama :\t\tNISN :\tNIK :\t\tNo.HP :\t\tNm. Ayah :\tNm. Ibu :\tAlamat "
          ":\n\n";
  while (!getfile.eof()) 
  {
    getline(getfile, temp_str[i]);
    cout << temp_str[i] << endl;
    i++;
  }
  getfile.close();
}

template <class T>
void Mahasiswa<T>::cari_data_mhs() {
  cout << "\nData yang ingin dicari (nim, nama, nik, nisn, no.hp, atau alamat) : ";
  getline(cin, key);
  int index_data_dicari[10];
  int jml_dapat = 0;
  for (int i = 0; i < index; i++) {
    if (temp_str[i].find(key) != string::npos) 
    {
      index_data_dicari[jml_dapat] = i;
      jml_dapat++;
    }
  }
  cout << "\nDitemukan :\n\n";
  for (int i = 0; i < jml_dapat; i++) 
  {
    cout << temp_str[index_data_dicari[i]] << endl;
  }
  cout << "\n";
}

template <class T>
void Mahasiswa<T>::hapus_data_mhs() {

  node_hapus *head = NULL;
  node_hapus *temp = NULL;
  getfile.open("datamanagemen/mahasiswa.txt");

  get_index.open("datamanagemen/banyak_index.txt");
  while (!get_index.eof()) 
  {
    get_index >> index;
  }
  get_index.close();

  int i = 0;
  while (!getfile.eof()) 
  {
    node_hapus *new_node = new node_hapus;
    getline(getfile, new_node->data);
    new_node->next = temp;
    temp = new_node;
    head = temp;
  }
  getfile.close();

  // reverse linked list
  node_hapus *prev = NULL;
  node_hapus *curr = head;
  node_hapus *next = NULL;
  while (curr != NULL) 
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
  temp = head;

  // cetak head
  while (head != NULL) 
  {
    cout << head->data << endl;
    head = head->next;
  }

  head = temp;

  bool found = false;
  bool data_pertama = false;
  cout << "\nData Mahasiswa yang ingin dihapus (input nim atau nama) : ";
  string key;
  getline(cin, key);
  int index_data_dicari[10];
  int jml_dapat = 0;
  for (int i = 0; i < index; i++) 
  {
    if (temp_str[i].find(key) != string::npos) 
    {
      if (i == 0) 
      {
        data_pertama = true;
      }
      index_data_dicari[jml_dapat] = i;
      jml_dapat++;
      found = true;
    }
  }

  node_hapus *hapus = NULL;
  cout << "\nDitemukan :\n\n";
  for (int i = 0; i < jml_dapat; i++) 
  {
    cout << "\e[1;31m" << temp_str[index_data_dicari[i]] << "\e[0m" << endl;
  }

  if (found == false) 
  {
    cout << "\e[1;31mTidak ada Data...\e[0m\n";
    // goto delete_end;
  }

  else 
  {
    cout << "\n";
    cout << "\nAnda yakin ingin menghapus data ini? (y/n) : ";
    char pilih;
    cin >> pilih;
    if (pilih == 'y') 
    {
      head = deleteElement(head, temp, hapus, temp_str[index_data_dicari[0]],
                           data_pertama);
      

      cout << "\n\e[1;32mData berhasil dihapus\e[0m\n";

      temp = head;
      head = temp;

      while (temp->next != NULL) 
      {
        temp = temp->next;
      }
      delete temp->next;
      temp = NULL;

      temp = head;

      cout << "\nData yang tersisa :\n";
      // cetak head
      while (head->next!= NULL) 
      {
        cout << head->data << endl;
        head = head->next;
      }
      cout << endl;
      head = temp;

      kefile.open("datamanagemen/mahasiswa.txt");
      while (head->next!= NULL) 
      {
        kefile << head->data << endl;
        head = head->next;
      }
      kefile.close();

      index--;

      store_last_index.open("datamanagemen/banyak_index.txt");
      store_last_index << index;
      store_last_index.close();
    } 
    else 
    {
      cout << "\n\e[1;31mData tidak jadi dihapus\e[0m\n\n";
    }
  }
}

template <class T>
void Mahasiswa<T>::update_data_mhs() {
  string buff;
  string kredensial_update[10];
  ifstream cekajuan;
  cekajuan.open("datamanagemen/ajuan_update.txt");
  cekajuan.close();

  
  
  string line;

  cout << "\nPilih data mahasiswa yang ingin diupdate (berdasarkan nim) : ";
  getline(cin, key);

  getfile.open("datamanagemen/mahasiswa.txt");
  get_index.open("datamanagemen/banyak_index.txt");

  while (!get_index.eof()) 
  {
    get_index >> index;
  }
  get_index.close();

  int i=0;
  while (!getfile.eof()) 
  {
    getline(getfile, temp_str[i]);
    i++;
  }
  getfile.close();

  getfile.open("datamanagemen/mahasiswa.txt");
  int indexganti = 0;
  while (!getfile.eof()) 
  {

    getline(getfile, line);
    if (line.find(key) != string::npos) 
    {
      cout << "\nData yang ditemukan :\n";
      cout << "\e[1;32m" << line << "\e[0m" << endl;
      break;
    }
    indexganti++;
  
  }

  getfile.close();

  vector<string> data;

  data = explode(line, '\t');

  int len = data.size();
  for (int i = 0; i < len; i++) 
  {
    stackmhsdata.push(data[i]);
  }

  cout << "\nData yang ingin diupdate : \n";
  cout << "1. Nama\n";
  cout << "2. NISN\n";
  cout << "3. NIK\n";
  cout << "4. No. HP\n";
  cout << "5. Nama Ayah\n";
  cout << "6. Nama Ibu\n";
  cout << "7. Alamat\n";
  cout << "Pilih : ";

  int pilih;
  cin >> pilih;
  getchar();

  for (int i=7;i>=1;i--) 
  {

    if (i == pilih) 
    {

        cout << "\nData yang akan diubah : ";
        cout << "\e[1;32m" << stackmhsdata.Top() << "\e[0m" << endl;
        
        if (i!=7) {
          cout << "Data baru : ";
          getline (cin,line);
          stackmhsdata.pop(stackmhsdata.Top());
          data[i] = line;
          stackmhsdata.push(data[i]);

          for (int j=i+1;j<8;j++) 
          {
            stackmhsdata.push(data[j]);
          }
          break;
        }

        else 
        {          
          stackmhsdata.pop(stackmhsdata.Top());
          
          cout << "Data baru :\n";
          cout << "\tProvinsi : ";
          getline (cin,line);
          data[i] = line;
          cout << "\tKabupaten : ";
          getline (cin,line);
          data[i] = data[i] + ", " + line;
          cout << "\tKecamatan : ";
          getline (cin,line);
          data[i] = data[i] + ", " + line;
          cout << "\tKelurahan : ";
          getline (cin,line);
          data[i] = data[i] + ", " + line;
          cout << "\tRT : ";
          getline (cin,line);
          data[i] = data[i] + ", " + line;
          cout << "\tRW : ";
          getline (cin,line);
          data[i] = data[i] + ", " + line;

          stackmhsdata.push(data[i]);

          for (int j=i+1;j<8;j++) 
          {
            stackmhsdata.push(data[j]);
          }
          break;

        }
    }

    stackmhsdata.pop(stackmhsdata.Top());

  }

  //reverse stackmhsdata
  while (!stackmhsdata.IsEmpty()) 
  {
    tempstackmhsdata.push(stackmhsdata.Top());
    stackmhsdata.pop(stackmhsdata.Top());
  }

  line = "";
  while (!tempstackmhsdata.IsEmpty()) 
  {
    line += tempstackmhsdata.Top();
    tempstackmhsdata.pop(tempstackmhsdata.Top());
    if (!tempstackmhsdata.IsEmpty()) 
    {
      line += "\t";
    }
  }

  temp_str[indexganti] = line;

  kefile.open("datamanagemen/mahasiswa.txt");
  for (int i=0;i<index;i++) 
  {
    kefile << temp_str[i] << endl;
  }

  kefile.close();

}

template <class T>
void Mahasiswa<T>::pengajuan_update()
{
  string databaru;
  string line;
  char opsi;
  getfile.open("datamanagemen/mahasiswa.txt");

  while (!getfile.eof()) {
    getline(getfile,line);
    if (line.find(current_credential) != string::npos) {
      break;
    }
  }
  getfile.close();

  vector<string> data;
  data = explode(line, '\t');
  
  kefile.open("datamanagemen/ajuan_update.txt");

  kefile << "---------------------------------------" << endl;
  kefile << "Pengaju : " << data[1] << endl;
  kefile << "NIM : " << data[0] << endl;
  kefile << "---------------------------------------" << endl;

  while (true) {
    cout << "\nData Anda :\n";
    cout << "\e[1;32m" << line << "\e[0m" << endl << endl;
    cout << "Pilih data yang ingin diajukan update :\n";
    cout << "1. Nama\n";
    cout << "2. NISN\n";
    cout << "3. NIK\n";
    cout << "4. No. HP\n";
    cout << "5. Nama Ayah\n";
    cout << "6. Nama Ibu\n";
    cout << "7. Alamat\n";
    cout << "Pilih : ";
  
    int ch;
    cin >> ch;
    getchar();
    
    if (ch==1) {
      cout << "*** Ajuan Update Nama ***\n";
      cout << "\nData nama sekarang : " << data[1] << endl;
      cout << "\nData nama baru : ";
      getline(cin,databaru);
  
      kefile << "Data Nama baru --> " << databaru << endl;
    }
    else if (ch==2) {
      cout << "*** Ajuan Update NISN ***\n";
      cout << "\nData NISN sekarang : " << data[2] << endl;
      cout << "\nData NISN baru : ";
      getline(cin,databaru);
  
      kefile << "Data NISN baru --> " << databaru << endl;
    }
    else if (ch==3) {
      cout << "*** Ajuan Update NIK ***\n";
      cout << "\nData NIK sekarang : " << data[3] << endl;
      cout << "\nData NIK baru : ";
      getline(cin,databaru);
  
      kefile << "Data NIK baru --> " << databaru << endl;
    }
    else if (ch==4) {
      cout << "*** Ajuan Update No. HP ***\n";
      cout << "\nData No. HP sekarang : " << data[4] << endl;
      cout << "\nData No. HP baru : ";
      getline(cin,databaru);
  
      kefile << "Data No. HP baru --> " << databaru << endl;
    }
    else if (ch==5) {
      cout << "*** Ajuan Update Nama Ayah ***\n";
      cout << "\nData Nama Ayah sekarang : " << data[5] << endl;
      cout << "\nData Nama Ayah baru : ";
      getline(cin,databaru);
  
      kefile << "Data Nama Ayah baru --> " << databaru << endl;
    }
    else if (ch==6) {
      cout << "*** Ajuan Update Nama Ibu ***\n";
      cout << "\nData Nama Ibu sekarang : " << data[6] << endl;
      cout << "\nData Nama Ibu baru : ";
      getline(cin,databaru);
  
      kefile << "Data Nama Ibu baru --> " << databaru << endl;
    }
    else if (ch==7) {
      string tempdatabaru;
      cout << "*** Ajuan Update Alamat ***\n";
      cout << "\nData Alamat sekarang : " << data[7] << endl;
      cout << "\nData Alamat baru : \n";
            cout << "\tProvinsi : ";
            getline (cin,databaru);
            tempdatabaru = databaru;
            cout << "\tKabupaten : ";
            getline (cin,databaru);
            tempdatabaru = tempdatabaru + ", " + databaru;
            cout << "\tKecamatan : ";
            getline (cin,databaru);
            tempdatabaru = tempdatabaru + ", " + databaru;
            cout << "\tKelurahan : ";
            getline (cin,databaru);
            tempdatabaru = tempdatabaru + ", " + databaru;
            cout << "\tRT : ";
            getline (cin,databaru);
            tempdatabaru = tempdatabaru + ", RT." + databaru;
            cout << "\tRW : ";
            getline (cin,databaru);
            tempdatabaru = tempdatabaru + ", RW." + databaru;
  
      databaru = tempdatabaru;
      
      kefile << "Data Alamat baru --> " << databaru << endl;
  
    }
    cout << "\nAda lagi? (y/n) : ";
    cin >> opsi;
    getchar();

    if (opsi=='n') break;
  }

  cout << "\n\e[1;32mTerimakasih... Ajuan Anda telah dikirim.\e[0m\n";
  cout << "Admin akan mengubah data Anda segera.\n";
  cout << "\n...Terimakasih...";
  kefile.close();
  
}

template <class T>
void Mahasiswa<T>::cek_ajuan_update() {

  getfile.open("datamanagemen/ajuan_update.txt");
  
  string line;
  int bykajuan = 0;
  int range[10];
  string nama[10];
  
  for (int i=0;i<10;i++) {
    range[i] = 0;
  }
  
  cout << "\n*** List Pengajuan Update Data Mahasiswa ***\n\n";

  bool begin_count = false;
  
  while (!getfile.eof()) {
    getline(getfile,line);
    cout << line << endl;
    
      if (line.find("---------------------------------------") != string::npos) {
        bykajuan++;
        getline(getfile,line);
        cout << line << endl;
        nama[bykajuan-1] = line;
        getline(getfile,line);
        cout << line << endl;
        getline(getfile,line);
        cout << line << endl;
        begin_count = true;
        getline(getfile,line);
        cout << line << endl;
      }
      if (begin_count == true) {
        if (!getfile.eof()) {
          range[bykajuan-1]++;
        }
      }
    
  }

  getfile.close();

  kefile.open("datamanagemen/cek_byk_ajuan.txt");

  kefile << "Jumlah ajuan : " << bykajuan << endl;
  for (int i=0;i<bykajuan;i++) {
    kefile << "\tAjuan ke-" << i+1 << ", " << nama[i] << ", " << range[i] << " data yang diubah" << endl;
  }
  kefile.close();
}

template <class T>
void Mahasiswa<T>::Enqueue(string x, int p) {
  if (numAntrian==0) {
    priorityQueue* baru = new priorityQueue;
    baru->data = x;
    baru->prioritas = p;
    baru->next = NULL;
    baru->prev = NULL;
    head = baru;
    ptr = baru;
    numAntrian++;
    cout << "\n\e[1;32mData berhasil dimasukkan ke antrian. dan numAntrian = " << numAntrian << " \e[0m\n";
  }
  else {
    if (p > head->prioritas) {
      priorityQueue* baru = new priorityQueue;
      baru->data = x;
      baru->prioritas = p;
      baru->next = head;
      baru->prev = NULL;
      head->prev = baru;
      head = baru;
      numAntrian++;
    }
    else if (p < ptr->prioritas) {
      priorityQueue* baru = new priorityQueue;
      baru->data = x;
      baru->prioritas = p;
      baru->next = NULL;
      baru->prev = ptr;
      ptr->next = baru;
      ptr = baru;
      numAntrian++;
    }
    else if (p == head->prioritas) {
      priorityQueue* baru = new priorityQueue;
      baru->data = x;
      baru->prioritas = p;
      baru->next = head;
      baru->prev = NULL;
      head->prev = baru;
      head = baru;
      numAntrian++;
    }
    else if (p == ptr->prioritas) {
      priorityQueue* baru = new priorityQueue;
      baru->data = x;
      baru->prioritas = p;
      baru->next = NULL;
      baru->prev = ptr;
      ptr->next = baru;
      ptr = baru;
      numAntrian++;
    }
    else {
      priorityQueue* temp = head;
      while (temp->prioritas > p) {
        temp = temp->next;
      }
      priorityQueue* baru = new priorityQueue;
      baru->data = x;
      baru->prioritas = p;
      baru->next = temp;
      baru->prev = temp->prev;
      temp->prev->next = baru;
      temp->prev = baru;
      numAntrian++;
    }
  }
}

template <class T>
string Mahasiswa<T>::Dequeue() {
  priorityQueue* temp = NULL;
  string data;

  cout << "Cek dequeue : numAntrian = " << numAntrian << "\n";
  if (numAntrian==0) {
    return "Antrian Beasiswa kosong";
  }
  else if (numAntrian==1) {
    temp = head;
    head = NULL;
    ptr = NULL;
    numAntrian--;
    data = temp->data;
    delete temp;
    
    return data;
  }
  else {
    temp = head;
    head = head->next;
    head->prev = NULL;
    numAntrian--;
    data = temp->data;
    delete temp;
    
    return data;
  }
}

/*template <class T>
void Mahasiswa<T>::aturAntrian() {
        priorityQueue current = new priorityQueue();
        ifstream readhasil;
        readhasil.open("Beasiswa/hasilseleksi.txt");

        ofstream temp;
        temp.open("Beasiswa/tempseleksi.txt");

        vector<string> data[8];
        string line;

        int i = 0;
        while(!readhasil.eof()) {
                getline(readhasil, line);
                data[i] = explode(line, '\t');
                line = line.substr(3, line.length());
                Enqueue(line, stoi(data[i][2]));
                i++;
                if (readhasil.eof()) {
                        break;
                }
        }
        readhasil.close();
        temp.close();
}*/