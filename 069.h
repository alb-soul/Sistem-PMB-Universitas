#include <fstream>
#include <string>
using namespace std;

struct tanggal{
    int day, month, year;
};

struct anggota{
    int pk;
    string nik, nama_lengkap, tmp_lahir, pekerjaan, ibu, ayah;
    int gol_darah,agama,warga, pendidikan, hubungan;
    bool gender,kawin,status;
    tanggal lahir;
};

struct dataKartu {
    string no_kk, kepala_keluarga, alamat, desa, kecamatan, kabupaten, provinsi;
    int rt, rw, kode_pos;
};

class KartuKeluarga{
    friend ostream& operator << (ostream&, KartuKeluarga&);

    public:
        KartuKeluarga();
        int menu();
        void option();
        void cekData();
        void buatData();
        int bacaData();
        int buatKTP();
        void writeDataKartu();
        void writeDataAnggota();
        int readDataKartu();
        int readDataAnggota();
        int tambahData();
        void convert(int&);
        int menuPilihanSatu();
        void writeDataArray();
        void writeDataAnggotaArray(anggota&);
        void printKTP(int&);

    private:
        fstream dataBase, dataOut; 
        int pilih, jumlah, menuSatu, hasil;
        char permission;
        string gender, agama, pendidikan, status, hubungan, warga, goldar;
        dataKartu kartu;
        Array1D<anggota> cekin;
        anggota *orang, keluarga; 
};

KartuKeluarga :: KartuKeluarga()
{
    option();
}

int KartuKeluarga :: menu() 
{
    cout << "=================================================" << endl;
    cout << "|\t\t\tDATA KARTU KELUARGA\t\t\t|" << endl;
    cout << "=================================================" << endl;
    cout << "1. Buat Data" << endl;
    cout << "2. Baca Data" << endl;
    cout << "3. Buat KTP" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih : "; cin >> pilih;
    return pilih;
}
int KartuKeluarga :: menuPilihanSatu()
{
    cout << " 1. Buat data kartu keluarga" << endl;
    cout << " 2. Tambah data anggota" << endl;
    cout << " Pilih : "; cin >> menuSatu;
    return menuSatu;
}
void KartuKeluarga :: option () 
{
    int ms;
    int pilihanMenu = menu();
    while(pilihanMenu != 5)
    {
        switch(pilihanMenu)
        {
            case 1:
                ms = menuPilihanSatu();
                while(ms != 1 && ms!=2){
                    ms = menuPilihanSatu();
                }
                if(ms == 1){
                    cekData();
                }else{
                    tambahData();
                }                
                break;
          
            case 2:
                bacaData();
                break;
          
            case 3:
                buatKTP();
                break;
          
            default:
                cout << " Tidak ada di menu" << endl;
                break;
        }
        pilihanMenu = menu();
    }
}
void KartuKeluarga :: cekData()
{
    dataBase.open("dataktp/data.txt", ios::out | ios::in);
    if(dataBase.is_open())
    {
        cout << "DATA TERSEDIA" << endl;
        cout << " Apakah anda ingin memasukkan data baru?";
        cin >> permission;
        if(permission == 'y')
        {
            cout << "DIBUAT DATABASE BARU" << endl;
            dataBase.close();
            dataBase.open("dataktp/dataAnggota.txt", ios::trunc | ios::out | ios::in);
            dataBase.close();
            dataBase.open("dataktp/data.txt", ios::trunc | ios::out | ios::in);
            buatData();
            dataBase.close();
        }
        else
        {
            cout << " Data Akan tetap sama" << endl;
        }
    } 
    else 
    {
        cout << "DIBUAT DATABASE BARU" << endl;
        dataBase.close();
        dataBase.open("dataktp/data.txt", ios::trunc | ios::out | ios::in);
        buatData();
        dataBase.close();
        dataBase.open("dataktp/dataAnggota.txt", ios::trunc | ios::out | ios::in);
        dataBase.close();
    }
}

void KartuKeluarga :: buatData() 
{
    cout << "============================================" << endl;
    cout << "|\t\tMASUKKAN DATA\t\t|" << endl;
    cout << "============================================" << endl;
    while(true)
    {
        cout << "   No. KK   : "; cin >> kartu.no_kk; 
        cin.ignore();
        switch(kartu.no_kk.length())
        {
            case 0 ... 15:
                cout << " No KK kurang dari 16 digit" << endl;
                continue;
          
            case 17 ... 100:
                cout << " No KK lebih dari 16 digit" << endl;
                continue;
          
            default:
                break;
        }
        break;
    }
    
    cout << "   Nama Kepala Keluarga    : "; getline(cin, kartu.kepala_keluarga);
    cout << "   Alamat                  : "; getline(cin, kartu.alamat);
    cout << "   RT                      : "; cin >> kartu.rt;
    cout << "   RW                      : "; cin >> kartu.rw;
    cout << "   Kode Pos                : "; cin >> kartu.kode_pos; cin.ignore();
    cout << "   Desa/Keluarahan         : "; getline(cin, kartu.desa);
    cout << "   Kecamatan               : "; getline(cin, kartu.kecamatan);
    cout << "   Kabupaten/Kota          : "; getline(cin, kartu.kabupaten);
    cout << "   Provinsi                : "; getline(cin, kartu.provinsi);
    writeDataKartu();
}
int KartuKeluarga :: tambahData()
{
    int hitung = 1;
    dataBase.open("dataktp/dataAnggota.txt", ios::in|ios::out);
    if(!dataBase.is_open())
    {
        dataBase.close();
        return 0;
    } 
    dataBase.close();
    cout << "=======================================" << endl;

    cout << "\tDATA ANGGOTA KELUARGA" << endl;
    cout << " Tambah banyak data anggota  : "; cin >> jumlah; cin.ignore();
    int i = 0;
    cekin.ReSize(jumlah);
    dataBase.open("dataktp/dataAnggota.txt", ios::in | ios::out | ios::app);
    while(i < jumlah)
    {
        cout << "================================" << endl;
        cout << "|         DATA ANGGOTA " << hitung << "       |" << endl;
        cout << "================================" << endl;
        cout << "  Nama Lengkap  : "; getline(cin, keluarga.nama_lengkap);
        while(true)
        {
            cout << "  NIK           : "; cin >> keluarga.nik; 
            cin.ignore();
            switch(keluarga.nik.length())
            {
                case 0 ... 15:
                    cout << " NIK kurang dari 16 digit" << endl;
                    continue;
              
                case 17 ... 100:
                    cout << " NIK lebih dari 16 digit" << endl;
                    continue;
              
                default:
                    break;
            }
            break;
        }
        cout << "================================" << endl;
        cout << "  Jenis Kelamin " << endl;
        cout << "     1 = Laki - Laki"<< endl;
        cout << "     0 = Perempuan" << endl;
        cout << "   Pilih : "; cin >> keluarga.gender; cin.ignore();
        cout << "================================" << endl;
        cout << "  Tempat Lahir  : "; getline(cin, keluarga.tmp_lahir);
        cout << "  Tanggal Lahir  " << endl;
        cout << "     Tanggal   : "; cin >> keluarga.lahir.day;
        cout << "     Bulan     : "; cin >> keluarga.lahir.month;
        cout << "     Tahun     : "; cin >> keluarga.lahir.year;
        cout << "================================" << endl;
        cout << "  Agama         " << endl;
        cout << "     1. Islam " << endl;
        cout << "     2. Katolik" << endl;
        cout << "     3. Protestan "<< endl;
        cout << "     4. Buddha" << endl;
        cout << "     5. Hindu" << endl;
        cout << "     6. Konghucu" << endl;
        cout << "   Pilih : "; cin >> keluarga.agama;
        cout << "================================" << endl;
        cout << "  Pendidikan    : " << endl;
        cout << "     1. SD/Sederajat" << endl;
        cout << "     2. SLTP/Sederajat" << endl;
        cout << "     3. SLTA/Sederajat" << endl;
        cout << "     4. S1" << endl;
        cout << "     5. S2" << endl;
        cout << "     6. S3" << endl;
        cout << "   Pilih : "; cin >> keluarga.pendidikan;
        cout << "================================" << endl;
        cout << "  Jenis Pekerjaan : "; cin >> keluarga.pekerjaan;
        cout << "================================" << endl;
        cout << "  Golongan Darah  " << endl; 
        cout << "     1. A" << endl;
        cout << "     2. B" << endl;
        cout << "     3. AB" << endl;
        cout << "     4. O" << endl;
        cout << "   Pilih : "; cin >> keluarga.gol_darah;
        cout << "================================" << endl;
        cout << "  Status Perkawinan " << endl;
        cout << "     1 = Kawin "<< endl;
        cout << "     0 = Belum Kawin " << endl;
        cout << "   Pilih : "; cin >> keluarga.status;

        cout << "================================" << endl;
        cout << "  Status Hubungan Dalam Keluarga " << endl;
        cout << "     1 = Kepala Keluarga" << endl;
        cout << "     2 = Istri" << endl;
        cout << "     3 = Anak" << endl;
        cout << "   Pilih : "; cin >> keluarga.hubungan;
        cout << "================================" << endl;
        cout << "  Kewarganegaraan " << endl;
        cout << "     1 = WNI" << endl;
        cout << "     0 = WNA" << endl;
        cout << "   Pilih : "; cin >> keluarga.warga; cin.ignore();
        cout << "================================" << endl;
        cout << "  Nama Orang Tua" << endl;
        cout << "     1. Ayah   : "; getline(cin, keluarga.ayah);
        cout << "     2. Ibu    : "; getline(cin, keluarga.ibu);
        cekin[i] = keluarga;
        i++;
    }
    cout << "================================" << endl;
    writeDataArray();
    dataBase.close();
    return 1;
}

void KartuKeluarga :: writeDataArray()
{
    anggota temp;
    for(int i = 0; i<cekin.Size(); i++)
    {
        temp = cekin[i];
        writeDataAnggotaArray(temp);
    }
}

void KartuKeluarga :: writeDataAnggotaArray(anggota& temp) 
{
    fstream dataAdmin;
    string buff;
    int index = 0;
    dataAdmin.open("data_ktp_admin.txt", ios::in | ios::out | ios::app);
    if(!dataAdmin.is_open())
    {
        dataAdmin.close();
        dataAdmin.open("data_ktp_admin.txt", ios::in | ios::out | ios::trunc);
        dataAdmin.close();
    }
    else
    {
        while(!dataAdmin.eof())
        {
            getline(dataAdmin, buff);
            index++;
        }
        dataAdmin.close();
    }
    
    index/=2;
    if(index > 4)
    {
        dataAdmin.open("dataktp/data_ktp_tamu.txt", ios::in|ios::out|ios::app);
        if(!dataAdmin.is_open())
        {
            dataAdmin.close();
            dataAdmin.open("dataktp/data_ktp_tamu.txt", ios::in|ios::out|ios::trunc);
        }
        dataAdmin << temp.nik << endl;
        dataAdmin << temp.nama_lengkap << endl;
        dataAdmin.close();
    }
    else
    {
        dataAdmin.open("data_ktp_admin.txt", ios::in | ios::out | ios::app);
        dataAdmin << temp.nik << endl;
        dataAdmin << temp.nama_lengkap << endl;
        dataAdmin.close();
    }
    //dataAdmin.close();
    dataBase << temp.nama_lengkap << endl;
    dataBase << temp.nik << endl;
    dataBase << temp.gender << endl;
    dataBase << temp.tmp_lahir << endl;
    dataBase << temp.lahir.day << endl;
    dataBase << temp.lahir.month << endl;
    dataBase << temp.lahir.year << endl;
    dataBase << temp.agama << endl;
    dataBase << temp.pendidikan << endl;
    dataBase << temp.pekerjaan << endl;
    dataBase << temp.gol_darah << endl;
    dataBase << temp.status << endl;
    dataBase << temp.hubungan << endl;
    dataBase << temp.warga << endl;
    dataBase << temp.ayah << endl;
    dataBase << temp.ibu << endl;
}

int KartuKeluarga :: bacaData() 
{
    int info = readDataKartu();
    int info2 = readDataAnggota();

    if(info == 0 || info2 == 0) return 0;
    int banyak = 1;
    cout << "=============================================================================================" << endl;
    cout << "|                                     KARTU KELUARGA                                        |" << endl;
    cout << "=============================================================================================" << endl;
    cout << "                                No. " << kartu.no_kk << endl;
    cout << " Nama Kepala Keluarga : " << kartu.kepala_keluarga       << "\t\t\t\tKecamatan      : " << kartu.kecamatan << endl;
    cout << " Alamat               : " << kartu.alamat                << "\t\t\t\tKabupaten/Kota : " << kartu.kabupaten << endl;
    cout << " RT/RW                : " << kartu.rt << "/" << kartu.rw << "\t\t\t\tKode Pos       : " << kartu.kode_pos << endl;
    cout << " Desa/Kelurahan       : " << kartu.desa                  << "\t\t\t\tProvinsi       : " << kartu.provinsi << endl;
    cout << "=============================================================================================" << endl;
    cout << " No.\tNama Lengkap\tNIK\tJenis Kelamin\tTempat Lahir\tTanggal Lahir\tAgama   " << endl;
    cout << "=============================================================================================" << endl;
    for(int i=0; i<hasil; i++)
    {
        convert(i);
        cout << banyak << "\t" << orang[i].nama_lengkap << "\t" << orang[i].nik << "\t" << gender << "\t" << orang[i].tmp_lahir <<"\t\t"<< orang[i].lahir.day <<"/"<< orang[i].lahir.month <<"/"<< orang[i].lahir.year << "\t"<< agama << endl;
        banyak++;
    }
    banyak = 1;
    cout << "=============================================================================================" << endl;
    cout << " No.\tPendidikan\tJenis Pekerjaan\t\tStatus\t\tHubungan keluarga\tKewarganegaraan  " << endl;
    cout << "=============================================================================================" << endl;
    for(int i=0; i<hasil; i++)
    {
        convert(i);
        cout << banyak << "\t" << pendidikan << "\t" << orang[i].pekerjaan << "\t\t" << status << "\t" << hubungan << "\t\t" << warga << endl;
        banyak++;
    }
    cout << "=============================================================================================" << endl;
    return 1;
}

void KartuKeluarga :: convert(int& g)
{
    //convert gender
    orang[g].gender == 1 ? gender = "Laki - laki" : gender = "Perempuan";

    //convert agama
    switch(orang[g].agama)
    {
        case 1:
            agama = "Islam";
            break;
      
        case 2:
            agama = "Katolik";
            break;
      
        case 3:
            agama = "Protestan";
            break;
      
        case 4:
            agama = "Buddha";
            break;
      
        case 5:
            agama = "Hindu";
            break;
      
        case 6:
            agama = "Konghucu";
            break;
    }

    //convert golongan darah
    switch(orang[g].gol_darah)
    {
        case 1:
            goldar = "A";
            break;
      
        case 2:
            goldar = "B";
            break;
      
        case 3:
            goldar = "AB";
            break;
      
        case 4:
            goldar = "O";
            break;
    }
    //convertpendidikan
    switch(orang[g].pendidikan)
    {
        case 1:
            pendidikan = "SD/Sederajat";
            break;
      
        case 2:
            pendidikan = "SMP/Sederajat";
            break;
      
        case 3:
            pendidikan = "SMA/Sederajat";
            break;
      
        case 4:
            pendidikan = "S1";
            break;
      
        case 5:
            pendidikan = "S2";
            break;
      
        case 6:
            pendidikan = "S3";
            break;
    }

    //convert status
    orang[g].status == 1 ? status = "Kawin" : status = "Belum kawin";
    //convert hubungan
    switch(orang[g].hubungan)
    {
        case 1:
            hubungan = "Kepala Keluarga";
            break;
      
        case 2:
            hubungan = "Istri";
            break;
      
        case 3:
            hubungan = "Anak";
            break;
    }

    //convert warga
    orang[g].warga == 1 ? warga = "WNI" : warga = "WNA";
}

int KartuKeluarga :: readDataKartu() 
{
    dataBase.open("dataktp/data.txt", ios::out | ios::in);
    if(!dataBase.is_open())
    {
        dataBase.close();
        return 0;
    }
    dataBase >> kartu.no_kk;dataBase.ignore();
    getline(dataBase, kartu.kepala_keluarga);
    getline(dataBase, kartu.alamat);
    dataBase >> kartu.rt;
    dataBase >> kartu.rw;
    dataBase >> kartu.kode_pos;dataBase.ignore();
    getline(dataBase, kartu.desa);
    getline(dataBase, kartu.kecamatan);
    getline(dataBase, kartu.kabupaten);
    getline(dataBase, kartu.provinsi);
  
    dataBase.close(); 
    return 1;
}

int KartuKeluarga :: readDataAnggota() 
{
    int index = 0;
    string teks;
    orang = new anggota[2];
    dataOut.open("dataktp/dataAnggota.txt", ios::in |ios::out );
    if(!dataOut.is_open())
    {
        dataOut.close();
        return 0;
    } 
    
    while(!dataOut.eof())
    {
        getline(dataOut, teks);
        index++;
    }
    dataOut.close();

    //banyak data
    hasil = index/16;

    if(hasil>2)
    {
        delete[] orang;
        orang = new anggota[hasil];
    }
    dataOut.open("dataktp/dataAnggota.txt", ios::in |ios::out );
    for(int i=0; i<hasil; i++)
    {
        getline(dataOut, orang[i].nama_lengkap);
        dataOut >> orang[i].nik;
        dataOut >> orang[i].gender;dataOut.ignore();
        getline(dataOut, orang[i].tmp_lahir);
        dataOut >> orang[i].lahir.day;
        dataOut >> orang[i].lahir.month;
        dataOut >> orang[i].lahir.year;
        dataOut >> orang[i].agama;
        dataOut >> orang[i].pendidikan;dataOut.ignore();
        getline(dataOut, orang[i].pekerjaan);
        dataOut >> orang[i].gol_darah;
        dataOut >> orang[i].status;
        dataOut >> orang[i].hubungan;
        dataOut >> orang[i].warga;dataOut.ignore();
        getline(dataOut, orang[i].ayah);
        getline(dataOut, orang[i].ibu);
    }
    dataOut.close();
    return 1;
}

int KartuKeluarga :: buatKTP()
{
    int i;
    if(bacaData()==0) return 0;
    cout << " Cetak Anggota Berapa = ";
    cin >> i;
    i-=1;
    convert(i);
    cout << "=====================================================" << endl;
    cout << "                    " << kartu.provinsi << endl;
    cout << "                " << kartu.kabupaten << endl;
    cout << "=====================================================" << endl;
    cout << "\nNIK          : " << orang[i].nik << endl;
    cout << "\nNama            : " << orang[i].nama_lengkap << endl;
    cout << "Tempat/Tgl Lahir: " << orang[i].tmp_lahir << ", " << orang[i].lahir.day << "-" << orang[i].lahir.month << "-" << orang[i].lahir.year << endl;
    cout << "Jenis Kelamin   : " << gender << "\t\tGol. Darah : " << goldar << endl;
    cout << "Alamat          : " << kartu.alamat << endl;
    cout << "   RT/RW        : " << kartu.rt << "/" << kartu.rw << endl;
    cout << "   Kel/Desa     : " << kartu.desa << endl;
    cout << "   Kecamatan    : " << kartu.kecamatan << endl;
    cout << "Agama           : " << agama << endl;
    cout << "Status Perkawinan : " << status << endl;
    cout << "Pekerjaan       : " << orang[i].pekerjaan << endl;
    cout << "Kewarganegaraan : " << warga << endl;
    cout << "Berlaku Hingga  : SEUMUR HIDUP" << endl; 
    cout << "====================================================" << endl;
    printKTP(i);
    return 1;
}
void KartuKeluarga :: printKTP(int& i)
{
    dataOut.open("dataktp/ktp.txt", ios::trunc|ios::in|ios::out);
    convert(i);
    dataOut << "=====================================================" << endl;
    dataOut << "                    " << kartu.provinsi << endl;
    dataOut << "                " << kartu.kabupaten << endl;
    dataOut << "=====================================================" << endl;
    dataOut << "\nNIK          : " << orang[i].nik << endl;
    dataOut << "\nNama            : " << orang[i].nama_lengkap << endl;
    dataOut << "Tempat/Tgl Lahir: " << orang[i].tmp_lahir << ", " << orang[i].lahir.day << "-" << orang[i].lahir.month << "-" << orang[i].lahir.year << endl;
    dataOut << "Jenis Kelamin   : " << gender << "\t\tGol. Darah : " << goldar << endl;
    dataOut << "Alamat          : " << kartu.alamat << endl;
    dataOut << "   RT/RW        : " << kartu.rt << "/" << kartu.rw << endl;
    dataOut << "   Kel/Desa     : " << kartu.desa << endl;
    dataOut << "   Kecamatan    : " << kartu.kecamatan << endl;
    dataOut << "Agama           : " << agama << endl;
    dataOut << "Status Perkawinan : " << status << endl;
    dataOut << "Pekerjaan       : " << orang[i].pekerjaan << endl;
    dataOut << "Kewarganegaraan : " << warga << endl;
    dataOut << "Berlaku Hingga  : SEUMUR HIDUP" << endl; 
    dataOut << "====================================================" << endl;
    dataOut.close();
}

void KartuKeluarga :: writeDataKartu() 
{
    dataBase << kartu.no_kk << endl;
    dataBase << kartu.kepala_keluarga << endl;
    dataBase << kartu.alamat << endl;
    dataBase << kartu.rt << endl;
    dataBase << kartu.rw << endl;
    dataBase << kartu.kode_pos << endl;
    dataBase << kartu.desa << endl;
    dataBase << kartu.kecamatan << endl;
    dataBase << kartu.kabupaten << endl;
    dataBase << kartu.provinsi << endl;
}

void KartuKeluarga :: writeDataAnggota() 
{
    dataBase << keluarga.nama_lengkap << endl;
    dataBase << keluarga.nik << endl;
    dataBase << keluarga.gender << endl;
    dataBase << keluarga.tmp_lahir << endl;
    dataBase << keluarga.lahir.day << endl;
    dataBase << keluarga.lahir.month << endl;
    dataBase << keluarga.lahir.year << endl;
    dataBase << keluarga.agama << endl;
    dataBase << keluarga.pendidikan << endl;
    dataBase << keluarga.pekerjaan << endl;
    dataBase << keluarga.gol_darah << endl;
    dataBase << keluarga.status << endl;
    dataBase << keluarga.hubungan << endl;
    dataBase << keluarga.warga << endl;
    dataBase << keluarga.ayah << endl;
    dataBase << keluarga.ibu << endl;
}

// int main() {
//     KartuKeluarga X;
// }

// #include <iostream>
// #include <fstream>
// #include "array1d.h"

// int n;

// struct alamat {
//     string tmp_lhr;
//     string almt, desa, kec;
//     int rt, rw;
// };

// struct tanggal {
//     int tgl, bln, thn;
// };

// struct Person {
//       string nik, nama , pekerjaan;
//       tanggal tgl_lhr;
//       alamat almt;
//       bool jns_kl,warga,status;
//       int agama,gol_drh;
// };

// class KTP {
//     friend istream &operator>>(istream &, KTP &);
//     friend ostream &operator<<(ostream &, KTP &);
//     public:
//       void store(KTP ktp);
//     private:
//       Person person;
// };

// istream &operator>>(istream &in, KTP &data) {
//     cout << "Banyak data KTP : ";
//     cin >> n;
//     getchar();

//     Array1D <KTP> dataKTP(n);

//     for (int i = 0; i < n; i++) {
//         while (true) { // Input dalam perulangan untuk validasi jumlah digit NIK
//             cout << "\nNIK\t: ";
//             getline(in, data.person.nik);
//             if (data.person.nik.length() == 16)
//                 break;
//             else
//                 cout << "\n\e[1;31mNIK harus berjumlah 16 digit!\e[0m\n";
//         }
//         cout << "Nama\t: ";
//         getline(in, data.person.nama);
//         cout << "Tmp.lhr\t: ";
//         getline(in, data.person.almt.tmp_lhr);
//         cout << "Tanggal\t: ";
//         in >> data.person.tgl_lhr.tgl;
//         cout << "Bulan\t: ";
//         in >> data.person.tgl_lhr.bln;
//         cout << "Tahun\t: ";
//         in >> data.person.tgl_lhr.thn;
//         cout << "Jenis kelamin :\n";
//         cout << "\t0. Laki-laki\n\t1. Perempuan\n";
//         cout << "Pilih\t: ";
//         in >> data.person.jns_kl;
//         cout << "Golongan darah :\n";
//         cout << "\t1. A\n\t2. B\n\t3. AB\n\t4. O\n";
//         cout << "Pilih\t: ";
//         in >> data.person.gol_drh;
//         getchar();
//         cout << "Alamat\t: ";
//         getline(in, data.person.almt.almt);
//         cout << "RT\t: ";
//         in >> data.person.almt.rt;
//         cout << "RW\t: ";
//         in >> data.person.almt.rw;
//         getchar();
//         cout << "Kel/Desa\t: ";
//         getline(in, data.person.almt.desa);
//         cout << "Kecamatan\t: ";
//         getline(in, data.person.almt.kec);
//         cout << "Agama :\n";
//         cout << "\t1. Islam\n\t2. Katolik\n\t3. Protestan\n\t4. Hindu\n\t5. "
//                 "Budha\n\t6. Konghucu\n";
//         cout << "Pilih\t: ";
//         in >> data.person.agama;
//         cout << "Status :\n";
//         cout << "\t0. Belum Menikah\n\t1. Sudah Menikah\n";
//         cout << "Pilih\t: ";
//         in >> data.person.status;
//         getchar();
//         cout << "Pekerjaan\t: ";
//         getline(in, data.person.pekerjaan);
//         cout << "Kewarganegaraan :\n";
//         cout << "\t0. WNI\n\t1. WNA\n";
//         cout << "Pilih\t: ";
//         in >> data.person.warga;
//         getchar();

//         dataKTP[i] = data;

//         data.store(dataKTP[i]);

//     }
//     return in;
// }

// void KTP::store(KTP ktp) {
//     ofstream file;
//     file.open("ktp.txt", ios::app);

//     file << ktp.person.nik << endl;
//     file << ktp.person.nama << endl;
//     if (ktp.person.jns_kl == 0) {
//         file << "Laki-laki" << endl;
//     } else {
//         file << "Perempuan" << endl;
//     }
//     file << ktp.person.almt.tmp_lhr << ", " << ktp.person.tgl_lhr.tgl << "-" << ktp.person.tgl_lhr.bln << "-" << ktp.person.tgl_lhr.thn << endl;

//     if (ktp.person.agama == 1) {
//         file << "Islam" << endl;
//     } else if (ktp.person.agama == 2) {
//         file << "Kristen" << endl;
//     } else if (ktp.person.agama == 3) {
//         file << "Katolik" << endl;
//     } else if (ktp.person.agama == 4) {
//         file << "Hindu" << endl;
//     } else if (ktp.person.agama == 5) {
//         file << "Budha" << endl;
//     } else {
//         file << "Konghucu" << endl;
//     }
    
//     if (ktp.person.gol_drh == 1) {
//         file << "A" << endl;
//     } else if (ktp.person.gol_drh == 2) {
//         file << "B" << endl;
//     } else if (ktp.person.gol_drh == 3) {
//         file << "AB" << endl;
//     } else {
//         file << "O" << endl;
//     }

//     if (ktp.person.status == true) {
//         file << "Kawin" << endl;
//     } else if (ktp.person.status == false) {
//         file << "Belum Kawin" << endl;
//     } else {
//         file << "Cerai" << endl;
//     }
    
//     file << ktp.person.pekerjaan << endl;

//     if (ktp.person.warga == 0) {
//         file << "WNI" << endl;
//     } else {
//         file << "WNA" << endl;
//     }
  
//     file << ktp.person.almt.almt << ", " << ktp.person.almt.desa << ", " << ktp.person.almt.kec << ", RT." << ktp.person.almt.rt << "/RW." << ktp.person.almt.rw << endl;

//     file.close();

//     file.open("data_ktp_admin.txt", ios::app);
//     file << ktp.person.nik << endl;
//     file << ktp.person.nama << endl;

//     file.close();
// }


// ostream &operator<<(ostream &out, KTP &data) {
//     string nik,nama,jk,ttl,agama,goldrh,status,pekerjaan,warga,alamat;
//     ifstream file;
//     file.open("ktp.txt");
    
//     out << "\nNIK :\t\t\t Nama :\t\t\t Jns. Kelamin :\t TTL :\t\t\t Agama :\t Gol.Darah :\t Status :\t Pekerjaan :\t Warga :\t Alamat :\n\n";

//     while (!file.eof()) {
//         getline(file, nik);
//         getline(file, nama);
//         getline(file, jk);
//         getline(file, ttl);
//         getline(file, agama);
//         getline(file, goldrh);
//         getline(file, status);
//         getline(file, pekerjaan);
//         getline(file, warga);
//         getline(file, alamat);
        
//         if (file.eof()) break;
//         out << nik << "\t " << nama << "\t " << jk << "\t " << ttl << "\t " << agama << "\t\t " << goldrh << "\t\t " << status << "\t " << pekerjaan << "\t " << warga << "\t\t " << alamat << endl;
//     }
//   return out;
// }

// int main() {



//   return 0;
// }