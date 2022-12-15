#include <chrono>
#include <fstream>
#include <string>
#include <iomanip>
#include "explode.h"
#include "array1d.h"
#include "Beasiswa/beasiswa.h"

struct alamattt {
  string provinsi, kab, kec, kota;
  int rt, rw;
};

struct nilaii {
  float mtk, bindo, bing, fisika, kimia, bio, sosio, geo, eko;
};

struct mahasiswa {
  string nim, nama, no_hp, nisn, nik, nayah, nibu, nama_jurusan;
  int gelombang, harga;
  alamattt almt;
  nilaii nilai;
  double pass_grade_ipa = 76;
  double pass_grade_ips = 75;
  string status;
};

class PMB {
public:
  PMB();
  void input_data_mhs(int n);
  void pilih_jurusan();
  void nilai_ipa();
  void nilai_ips();
  void list_data_mhs();
  void cari_data_mhs();
  void pembayaran();
  void beasiswa();

private:
  mahasiswa *mhs = new mahasiswa[50];
  int menu, n, index;
  ofstream kefile, store_last_index;
  ifstream getfile, get_index;
  string temp_str[50];
  //string temp_str2[50][];
  int harga;
  int gelombang;
  double rata2 = 0;
  string key;
  string status;
  vector<string> data;
  bool proses = false;
};

PMB::PMB() 
{
  get_index.open("datapmb/banyak_index_seleksi.txt");
  if (!get_index) 
  {
    get_index.close();

    store_last_index.open("datapmb/banyak_index_seleksi.txt");
    store_last_index << 0;
    store_last_index.close();

    get_index.open("datapmb/banyak_index_seleksi.txt");
    get_index >> index;
    get_index.close();
  } 
  else 
  {
    while (!get_index.eof()) 
    {
      get_index >> index;
    }
    get_index.close();
    if (index==0) proses = false;
    else proses = true;
  }
  
  int lama;
  auto start = chrono::steady_clock::now();

  do {
  cout << "\n===================================" << endl;
  cout << "====================================" << endl;
  cout << "=====    SELAMAT DATANG        =====" << endl;
  cout << "=====    DI PORTAL PEMDAFTARAN =====" << endl;
  cout << "=====    MAHASISWA BARU        =====" << endl;
  cout << "=====    UNIVERSITAS B         =====" << endl;
  cout << "====================================" << endl;
  cout << "====================================\n" << endl;
  cout << "\tMenu yang disediakan \n";
    cout << "\t\t0. Keluar\n";
    cout << "\t\t1. Input data mahasiswa (baru)\n";
    cout << "\t\t2. Lihat Hasil Seleksi\n";
    cout << "\t\t3. Daftar dengan beasiswa\n";
    cout << "Pilih : ";
    cin >> menu;
    getchar();
    if (menu == 1) 
    {
      auto end = chrono::steady_clock::now();
      auto diff = end - start;
      lama = (int)chrono::duration<double>(diff).count();
      if (lama <= 10) 
      {
        gelombang = 1;
        harga = 1000000;
      } 
      else if (lama > 10 && lama <= 20) 
      {
        gelombang = 2;
        harga = 2000000;
      } 
      else if (lama > 20 && lama <= 30) 
      {
        gelombang = 3;
        harga = 3000000;
      }
      cout << "\nAnda mendaftar pada gelombang ke-" << gelombang << endl;
      cout << "Harga daftarnya : " << harga << endl;
    }

    switch (menu) 
    {
    case 1:
      proses = true;
      cout << "\nBanyak mahasiswa yang akan diinput : ";
      cin >> n;
      kefile.open("datapmb/seleksi_mahasiswa.txt");
      mhs[index].gelombang = gelombang;
      kefile << mhs[index].gelombang << ",";
      mhs[index].harga = harga;
      kefile << mhs[index].harga << endl;
      input_data_mhs(n);
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
      break;

    case 3:
        beasiswa();
        break;
      
    case 0:
      cout << "\nTerimakasih...\n";
      delete[] mhs; // delete array of struct/class (dealokasi memori)
      break;
    }
  } while (menu != 0);
}

void PMB::beasiswa() {
  Beasiswa Bsw;
}

void PMB::pilih_jurusan() 
{

  cout << "\n===================================" << endl;
  cout << "====================================" << endl;
  cout << "=====    DAFTAR RANAH JURUSAN  =====" << endl;
  cout << "=====    YANG DITAWARKAN       =====" << endl;
  cout << "=====    UNIVERSITAS B         =====" << endl;
  cout << "====================================" << endl;
  cout << "====================================\n" << endl;
  cout << "\tMenu yang disediakan \n";
  cout << "\t\t1. Ranah IPA\n";
  cout << "\n\tNilai yang dibutuhkan untuk masuk ranah IPA : \n";
  cout << "Matematika \n";
  cout << "Bahasa Indonesia\n";
  cout << "Bahasa Inggris\n";
  cout << "Biologi \n";
  cout << "Kimia \n";
  cout << "Fisika \n";
    
  cout << "\t\t2. Ranah IPS\n";
  cout << "\n\tNilai yang dibutuhkan untuk masuk ranah IPS : \n";
  cout << "Matematika\n";
  cout << "Bahasa Indonesia\n";
  cout << "Bahasa Inggris\n";
  cout << "Sosiologi \n";
  cout << "Geografi \n";
  cout << "Ekonomi \n";
  
  cout << "Pilih : ";
  cin >> menu;
  getchar();
  cout << "\n===================================" << endl;
  cout << "====================================" << endl;
  cout << "=====    DAFTAR JURUSAN        =====" << endl;
  cout << "=====    YANG DITAWARKAN       =====" << endl;
  cout << "=====    UNIVERSITAS B         =====" << endl;
  cout << "====================================" << endl;
  cout << "====================================\n" << endl;
  cout << "\tMenu yang disediakan \n";
  if (menu == 1) 
  {
    cout << "1. Informatika\n";
    cout << "2. Kedokteran\n";
    cout << "3. Farmasi\n";
    cout << "4. Kedokteran Gigi \n";
    cout << "5. Kedokteran Hewan \n";
    cout << "6. Kesehatan Masyarakat \n";
    cout << "7. Kebidanan \n";
    cout << "8. Keperawatan \n";
    cout << "9. Ilmu gizi \n";
    cout << "10. Kesehatan dan Keselamatan Kerja \n";
    cout << "11. Teknik Kimia \n";
    cout << "12. Teknik Industri \n";
    cout << "13. Teknik Komputer \n";
    cout << "14. Teknik Telekomunikasi \n";
    cout << "15. Teknik Elektro \n";
    cout << "16. Perencanaan Wilayah dan Kota \n";
    cout << "17. Teknik Biomedis \n";
    cout << "18. Teknik Sipil \n";
    cout << "19. Teknik Logistik \n";
    cout << "20. Sistem Informasi \n";
    cout << "21. Statistika \n";
    cout << "22. Matematika \n";
    cout << "23. Aktuaria \n";
    cout << "24. Biologi \n";
    cout << "25. Bioteknologi \n";
    cout << "26. Agribisnis \n";
    cout << "27. Peternakan \n";
    cout << "28. Teknologi Pangan \n";
    cout << "29. Nuklir \n";
    cout << "30. Manajemen Perairan \n";
    
    cout << "Pilih : ";
    cin >> menu;
    getchar();
    cout << "\nMasukkan Nilai : \n";
    if (menu == 1) 
    {
      mhs[index].nama_jurusan = "Informatika";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 2) 
    {
      mhs[index].nama_jurusan = "Kedokteran";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 3) 
    {
      mhs[index].nama_jurusan = "Farmasi";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 4) 
    {
      mhs[index].nama_jurusan = "Kedokteran Gigi ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 5) 
    {
      mhs[index].nama_jurusan = "Kedokteran Hewan ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 6) 
    {
      mhs[index].nama_jurusan = "Kesehatan Masyarakat ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 7) 
    {
      mhs[index].nama_jurusan = "Kebidanan ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 8) 
    {
      mhs[index].nama_jurusan = "Keperawatan ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 9) 
    {
      mhs[index].nama_jurusan = "Ilmu Gizi ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 10) 
    {
      mhs[index].nama_jurusan = "Kesehatan dan Keselamatan Kerja ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 11) 
    {
      mhs[index].nama_jurusan = "Teknik Kimia ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 12) 
    {
      mhs[index].nama_jurusan = "Teknik Industri ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 13) 
    {
      mhs[index].nama_jurusan = "Teknik Komputer";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 14) 
    {
      mhs[index].nama_jurusan = "Teknik Telekomunikasi ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 15) 
    {
      mhs[index].nama_jurusan = "Teknik Elektro ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 16) 
    {
      mhs[index].nama_jurusan = "Perencanaan Wilayah dan Kota ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 17) 
    {
      mhs[index].nama_jurusan = "Teknik Biomedis ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 18) 
    {
      mhs[index].nama_jurusan = "Teknik Sipil ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 19) 
    {
      mhs[index].nama_jurusan = "Teknik Logistik ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 20) 
    {
      mhs[index].nama_jurusan = "Sistem Informasi ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 21) 
    {
      mhs[index].nama_jurusan = "Statistika ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 22) 
    {
      mhs[index].nama_jurusan = "Matematika ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 23) 
    {
      mhs[index].nama_jurusan = "Aktuaria ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 24) 
    {
      mhs[index].nama_jurusan = "Biologi ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 25) 
    {
      mhs[index].nama_jurusan = "Bioteknologi ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 26) 
    {
      mhs[index].nama_jurusan = "Agribisnis ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 27) 
    {
      mhs[index].nama_jurusan = "Peternakan ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 28) 
    {
      mhs[index].nama_jurusan = "Teknologi Pangan ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 29) 
    {
      mhs[index].nama_jurusan = "Nuklir ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    else if (menu == 30) 
    {
      mhs[index].nama_jurusan = "Manajemen Perairan ";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ipa();
    } 
    
  } 
  else 
  {
    cout << "1. Manajemen\n";
    cout << "2. Akuntansi\n";
    cout << "3. Hukum\n";
    cout << "4. Ilmu Komunikasi\n";
    cout << "5. Hubungan Internasional \n";
    cout << "6. Psikologi \n";
    cout << "7. Kriminologi \n";
    cout << "8. Sosiologi \n";
    cout << "9. Ilmu Politik \n";
    cout << "10. Ilmu Administarsi \n";
    cout << "11. Ilmu Sejarah \n";
    cout << "12. Arkeologi \n";
    cout << "13. Filsafat \n";
    cout << "14. Sastra Indonesia \n";
    cout << "15. Sastra Inggris \n";
    cout << "16. Sastra Korea \n";
    cout << "17. Sastra Prancis \n";
    cout << "18. Sastra Belanda \n";
    cout << "19. Sastra Jerman \n";
    cout << "20. Antropologi \n";
    cout << "21. Ilmu Ekonomi \n";
    cout << "22. Ekonomi Syariah\n";
    cout << "23. Ilmu Aktuaria \n";
    cout << "24. Ilmu Perpustakaan \n";
    cout << "25. Jurnalistik \n";
    cout << "26. Ilmu Pemerintahan \n";
    cout << "27. Ilmu Pariwisata \n";
    cout << "28. PGSD \n";
    cout << "29. Bisnis Digital \n";
    cout << "30. Ilmu Kesejahteraan Sosial \n";
    cout << "Pilih : ";
    cin >> menu;
    getchar();
    cout << "\nMasukkan Nilai : \n";
    if (menu == 1) 
    {
      mhs[index].nama_jurusan = "Manajemen";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 2) 
    {
      mhs[index].nama_jurusan = "Akuntansi";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 3) 
    {
      mhs[index].nama_jurusan = "Hukum";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 4) 
    {
      mhs[index].nama_jurusan = "Ilmu Komunikasi";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 5) 
    {
      mhs[index].nama_jurusan = "Hubungan Internasional";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 6) 
    {
      mhs[index].nama_jurusan = "Psikologi";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 7) 
    {
      mhs[index].nama_jurusan = "Kriminologi";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 8) 
    {
      mhs[index].nama_jurusan = "Sosiologi";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 9) 
    {
      mhs[index].nama_jurusan = "Ilmu Politik";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 10) 
    {
      mhs[index].nama_jurusan = "Ilmu Administrasi";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 11) 
    {
      mhs[index].nama_jurusan = "Ilmu Sejarah";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 12) 
    {
      mhs[index].nama_jurusan = "Arkeologi";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 13) 
    {
      mhs[index].nama_jurusan = "Filsafat";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 14) 
    {
      mhs[index].nama_jurusan = "Sastra Indonesia";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 15) 
    {
      mhs[index].nama_jurusan = "Sastra Inggris";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 16) 
    {
      mhs[index].nama_jurusan = "Sastra Korea";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 17)
    {
      mhs[index].nama_jurusan = "Sastra Prancis";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 18) 
    {
      mhs[index].nama_jurusan = "Sastra Belanda";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 19) 
    {
      mhs[index].nama_jurusan = "Sastra Jerman";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 20) 
    {
      mhs[index].nama_jurusan = "Antropologi";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 21) 
    {
      mhs[index].nama_jurusan = "Ilmu Ekonomi";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 22) 
    {
      mhs[index].nama_jurusan = "Ekonomi Syariah";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 23)
    {
      mhs[index].nama_jurusan = "Ilmu Aktuaria";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 24) 
    {
      mhs[index].nama_jurusan = "Ilmu Perpustakaan";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 25)
    {
      mhs[index].nama_jurusan = "Jurnalisti";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    }
    else if (menu == 26) 
    {
      mhs[index].nama_jurusan = "Ilmu Pemerintahan";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 27) 
    {
      mhs[index].nama_jurusan = "Ilmu Pariwisata";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 28) 
    {
      mhs[index].nama_jurusan = "PGSD";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 29) 
    {
      mhs[index].nama_jurusan = "Bisnis Digital";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
    else if (menu == 30) 
    {
      mhs[index].nama_jurusan = "Ilmu Kesehatan Sosial";
      kefile << mhs[index].nama_jurusan << "\t";
      nilai_ips();
    } 
  }
}

void PMB::nilai_ipa() 
{
  rata2 = 0;
  cout << "Matematika : ";
  cin >> mhs[index].nilai.mtk;
  rata2 += mhs[index].nilai.mtk;
  //kefile << mhs[index].nilai.mtk << ", ";
  cout << "Bahasa Indonesia : ";
  cin >> mhs[index].nilai.bindo;
  rata2 += mhs[index].nilai.bindo;
  //kefile << mhs[index].nilai.bindo << ", ";
  cout << "Bahasa Inggris : ";
  cin >> mhs[index].nilai.bing;
  rata2 += mhs[index].nilai.bing;
  //kefile << mhs[index].nilai.bing << ", ";
  cout << "Biologi : ";
  cin >> mhs[index].nilai.bio;
  rata2 += mhs[index].nilai.bio;
  //kefile << mhs[index].nilai.bio << ", ";
  cout << "Fisika : ";
  cin >> mhs[index].nilai.fisika;
  rata2 += mhs[index].nilai.fisika;
  //kefile << mhs[index].nilai.fisika << ", ";
  cout << "Kimia : ";
  cin >> mhs[index].nilai.kimia;
  rata2 += mhs[index].nilai.kimia;
  //kefile << mhs[index].nilai.kimia << "\t";
  kefile << setprecision(2) << fixed << rata2/6.0 << "\t";
  if (rata2 / 6 >= 80) 
  {
    mhs[index].status = "LULUS";
    kefile << mhs[index].status << endl;
  } 
  else 
  {
    mhs[index].status = "TIDAK LULUS";
    kefile << mhs[index].status << endl;
  }
}

void PMB::nilai_ips()
{
  rata2 = 0;

  cout << "Matematika : ";
  cin >> mhs[index].nilai.mtk;
  rata2 += mhs[index].nilai.mtk;
  //kefile << mhs[index].nilai.mtk << ", ";
  cout << "Bahasa Indonesia : ";
  cin >> mhs[index].nilai.bindo;
  rata2 += mhs[index].nilai.bindo;
  //kefile << mhs[index].nilai.bindo << ", ";
  cout << "Bahasa Inggris : ";
  cin >> mhs[index].nilai.bing;
  rata2 += mhs[index].nilai.bing;
  //kefile << mhs[index].nilai.bing << ", ";
  cout << "Sosiologi : ";
  cin >> mhs[index].nilai.sosio;
  rata2 += mhs[index].nilai.sosio;
  //kefile << mhs[index].nilai.sosio << ", ";
  cout << "Geografi : ";
  cin >> mhs[index].nilai.geo;
  rata2 += mhs[index].nilai.geo;
  //kefile << mhs[index].nilai.geo << ", ";
  cout << "Ekonomi : ";
  cin >> mhs[index].nilai.eko;
  rata2 += mhs[index].nilai.eko;
  //kefile << mhs[index].nilai.eko << "\t";
  kefile << setprecision(2) << fixed << rata2/6.0 << "\t";
  if (rata2 / 6 >= 80) 
  {
    mhs[index].status = "LULUS";
    kefile << mhs[index].status << endl;
  } 
  else 
  {
    mhs[index].status = "TIDAK LULUS";
    kefile << mhs[index].status << endl;
  }
}

void PMB::input_data_mhs(int n) 
{
  
  if (n - 1 < 0) 
  {
    kefile.close();
    store_last_index.open("datapmb/banyak_index_seleksi.txt");
    store_last_index << index;
    store_last_index.close();
  } 
  else 
  {
    /*mhs[index].nim = to_string(index + 1);
    precision = nim_len - min(nim_len, mhs[index].nim.size());
    mhs[index].nim.insert(0, precision, '0');
    kefile << mhs[index].nim << "\t";*/
    getchar();
    cout << "\nNama : ";
    getline(cin, mhs[index].nama);
    kefile << mhs[index].nama << "\t";
    cout << "NISN : ";
    getline(cin, mhs[index].nisn);
    kefile << mhs[index].nisn << "\t";

    while (true) 
    { // Input dalam perulangan untuk validasi jumlah digit NIK
        cout << "NIK  : ";
        getline(cin, mhs[index].nik);
        if (mhs[index].nik.length() == 16) 
        {
          break;
        }
        else 
        {
          cout << "\n\e[1;31mNIK harus berjumlah 16 digit!\e[0m\n";
        }
    }
    

    kefile << mhs[index].nik << "\t";
    cout << "No.HP : ";
    getline(cin, mhs[index].no_hp);
    kefile << mhs[index].no_hp << "\t";
    cout << "Nama Ayah : ";
    getline(cin, mhs[index].nayah);
    kefile << mhs[index].nayah << "\t";
    cout << "Nama Ibu : ";
    getline(cin, mhs[index].nibu);
    kefile << mhs[index].nibu << "\t";
    cout << "Alamat :\n";
    cout << "\tProvinsi : ";
    getline(cin, mhs[index].almt.provinsi);
    kefile << mhs[index].almt.provinsi << ", ";
    cout << "\tKabupaten : ";
    getline(cin, mhs[index].almt.kab);
    kefile << mhs[index].almt.kab << ", ";
    cout << "\tKecamatan : ";
    getline(cin, mhs[index].almt.kec);
    kefile << mhs[index].almt.kec << ", ";
    cout << "\tKota : ";
    getline(cin, mhs[index].almt.kota);
    kefile << mhs[index].almt.kota << ", ";
    cout << "\tRT : ";
    cin >> mhs[index].almt.rt;
    kefile << "RT." << mhs[index].almt.rt << ",";
    cout << "\tRW : ";
    cin >> mhs[index].almt.rw;
    kefile << "RW." << mhs[index].almt.rw << "\t";

    pilih_jurusan();

    index++;
    input_data_mhs(n - 1);
  }
}

void PMB::list_data_mhs() 
{
  getfile.open("datapmb/seleksi_mahasiswa.txt");
  get_index.open("datapmb/banyak_index_seleksi.txt");

  while (!get_index.eof()) 
  {
    get_index >> index;
  }
  get_index.close();

  int i = 0;
  cout << "\n===================================" << endl;
  cout << "====================================" << endl;
  cout << "=====    DAFTAR LIST HASIL     =====" << endl;
  cout << "=====    MAHASISWA             =====" << endl;
  cout << "=====    UNIVERSITAS B         =====" << endl;
  cout << "====================================" << endl;
  cout << "====================================\n" << endl;
  
  cout << "\nNama :\t\tNISN :\t\tNIK :\t\tNo.HP :\t\tNama Ayah :\tNama Ibu :\tAlamat :\t\t\tJurusan :\tRata2 Nilai\tStatus\n\n";
  while (!getfile.eof()) 
  {
    getline(getfile, temp_str[i]);
    cout << temp_str[i] << endl;
    i++;
  }
  getfile.close();
  cout << "Lakukan Pembayaran ? (y/n) : ";
  char pilih;
  cin >> pilih; getchar();
  if (pilih == 'y') 
  {
    pembayaran();
  } 
  else 
  {
    cout << "\nTerima Kasih\n";
  }
}

//dibantu 069
void PMB::pembayaran() 
{
  ofstream update_seleksi;

  getfile.open("datapmb/seleksi_mahasiswa.txt");
  string check_gelombang;
  string yang_sdh_bayar;
  string line;

  getline(getfile,check_gelombang);
  if (check_gelombang=="1,1000000") 
  {
    gelombang = 1;
    harga = 1000000;
  }
  else if (check_gelombang=="2,2000000") 
  {
    gelombang = 2;
    harga = 2000000;
  }
  else if (check_gelombang=="3,3000000") 
  {
    gelombang = 3;
    harga = 3000000;
  }

  bool temp_bayar = false;
  

  masuk_kredensial:

  cout << "\nMasukkan Kredensial : " << endl;
  cout << "Nama : ";
  string temp_nama;
  getline(cin, temp_nama);
  cout << "NISN : ";
  string temp_nisn;
  getline(cin, temp_nisn);


  while (!getfile.eof()) 
  {

    getline(getfile, temp_str[0]);

    data = explode(temp_str[0], '\t'); //explode (pisahkan) string berdasarkan karakter tertentu

    if (data[0] == temp_nama && data[1] == temp_nisn && data[9] == "LULUS") 
    {
      if (temp_bayar == true) 
      {
        cout << "\nAnda telah melakukan pembayaran...\n";
        break;
      }
      cout << "\n\e[1;32mSelamat! " << temp_nama << ", Anda LULUS seleksi Universitas B di gelombang ke-" << gelombang << "\e[0m" << endl;
      cout << "Silahkan melakukan pembayaran sebesar Rp" << harga << endl;
      int bayar;
      while (true) 
      {
        cout << "\nMasukkan nominal pembayaran (Rp" << harga << ") : ";
        cin >> bayar;
        if (bayar == harga) 
        {
          cout << "\n\e[1;32mPembayaran Berhasil!\e[0m" << endl;
          cout << "Data Anda sudah direkap dan kini Anda telah menjadi mahasiswa Universitas B..." << endl << endl;
          yang_sdh_bayar = data[0];
          temp_bayar = true;
          break;
        } 
        else 
        {
          cout << "\n\e[1;31mPembayaran tertolak!\e[0m" << endl;
          cout << "Nominal pembayaran melebihi atau kurang dari harga" << endl;
          cout << "Silahkan ulangi..." << endl;
        }
      }
    }
    else if (data[0] == temp_nama && data[1] == temp_nisn && data[9] == "TIDAK LULUS") 
    {
      cout << "\n\e[1;31mMaaf Anda TIDAK LULUS seleksi Universitas B gelombang ke-" << gelombang << "\e[0m" << endl;
      break;
    }

    if (temp_bayar == true) 
    {
      getfile.close();

      update_seleksi.open("datapmb/update_seleksi_mahasiswa.txt");
      getfile.open("datapmb/seleksi_mahasiswa.txt");

      while (getline(getfile, line)) 
      {
        if (line.find(yang_sdh_bayar) == string::npos) 
        {
          update_seleksi << line << endl;
        }
      }

      getfile.close();
      update_seleksi.close();
      
      remove("datapmb/seleksi_mahasiswa.txt");
      rename("datapmb/update_seleksi_mahasiswa.txt", "datapmb/seleksi_mahasiswa.txt");

      index--;

      store_last_index.open("datapmb/banyak_index_seleksi.txt");
      store_last_index << index;
      store_last_index.close();


      kefile.open("datamanagemen/mahasiswa.txt", ios::app);

      string data_mhs = "";
      for (int i=0;i<7;i++)
        {
        data_mhs += data[i];
        if (i<6) 
        {
          data_mhs += "\t";
        }
      }

      kefile << data_mhs << endl;

      kefile.close();

      break;
    }

    if (getfile.eof()) 
    {
      cout << "\n\e[1;31mMaaf, Kredensial Anda salah...\e[0m\n";
      cout << "Silakan coba lagi...\n";
      getfile.close();

      goto masuk_kredensial;
    }

  }
  getfile.close();
}

void PMB::cari_data_mhs() 
{
  cout << "\nData yang ingin dicari (nim, nama, no.hp, atau alamat) : ";
  getline(cin, key);
  int index_data_dicari[30];
  int jml_dapat = 0;

  for (int i = 0; i < index; i++)
  {
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