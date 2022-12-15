#include <iostream>
// #include "../array1d.h"
#include <fstream>
using namespace std;

class B2 {
public:
  B2();
  void JenisBeasiswa();
  void PendaftaranBeasiswa();
  void TampilkanData();
  void HasilBeasiswa();
  void syarat();
  void FAQ();

  int pil;
};

B2::B2() {
  cout << "\n=====================================================" << endl;
  cout << "=====================================================" << endl;
  cout << "||                                                 ||" << endl;
  cout << "||                  SELAMAT DATANG                 ||" << endl;
  cout << "||                DI PORTAL BEASISWA               ||" << endl;
  cout << "||                                                 ||" << endl;
  cout << "=====================================================" << endl;
  cout << "=====================================================" << endl;
  cout << "-----------------------------------------------------\n" << endl;
  cout << "\tMenu yang disediakan \n";
  cout << "\t\t1. Lihat Jenis Beasiswa \n";
  cout << "\t\t2. Pendaftar Beasiswa \n";
  cout << "\t\t3. Tampilkan Data Yang Masuk\n";
  cout << "\t\t4. Lihat Hasil Seleksi Beasiswa \n";
  cout << "\t\t5. Lihat FAQ \n\n";
  cout << "\tMasukkan Pilihan Anda : ";
  cin >> pil;
  getchar();
  if (pil == 1) {
    JenisBeasiswa();

  } else if (pil == 2) {
    PendaftaranBeasiswa();

    do {
      cout << "Kembali (1) : ";
      cin >> pil;
      if (pil == 1) {
        B2();
      }
    } while (pil >= 2);
  } else if (pil == 3) {
    TampilkanData();

    do {
      cout << "Kembali (1) : ";
      cin >> pil;
      if (pil == 1) {
        B2();
      }
    } while (pil >= 2);
  } else if (pil == 4) {
    HasilBeasiswa();
    do {
      cout << "Kembali (1) : ";
      cin >> pil;
      if (pil == 1) {
        B2();
      }
    } while (pil >= 2);
  } else if (pil == 5) {
    FAQ();
    do {
      cout << "Kembali (1) : ";
      cin >> pil;
      if (pil == 1) {
        B2();
      }
    } while (pil >= 2);
  }
}
void B2::JenisBeasiswa() {
  int jenjang;
  char pilSyarat;
  do {
    cout << "\n=====================================================" << endl;
    cout << "=====================================================" << endl;
    cout << "||                                                 ||" << endl;
    cout << "||                JENIS BEASISWA                   ||" << endl;
    cout << "||                YANG DI TAWARKAN                 ||" << endl;
    cout << "||                                                 ||" << endl;
    cout << "=====================================================" << endl;
    cout << "=====================================================" << endl;
    cout << "-----------------------------------------------------\n" << endl;
    cout << "\tJENIS " << endl;
    cout << "\t\t 1. Beasiswa Universitas" << endl;
    cout << "\t\t 2. Beasiswa Prestasi" << endl;
    cout << "\t\t 3. Persyaratan Umum" << endl;
    cout << "\t\t 5. Kembali" << endl;
    cout << "\tPilih : ";
    cin >> jenjang;
    switch (jenjang) {
    case 1:
      cout << "\n=====================================================" << endl;
      cout << "=====================================================" << endl;
      cout << "||                                                 ||" << endl;
      cout << "||                BEASISWA UNIVERSITAS             ||" << endl;
      cout << "||                                                 ||" << endl;
      cout << "=====================================================" << endl;
      cout << "=====================================================" << endl;
      cout << "-----------------------------------------------------\n" << endl;
      cout << " => Jalur seleksi beasiswa masuk Universitas dengan\n";
      cout << "    seleksi menggunakan nilai akademik dan prestasi\n";
      cout << "    kejuaraan." << endl;
      cout << "-----------------------------------------------------" << endl;
      cout << "No     Jenis Beasiswa              Uraian      " << endl;
      cout << "-----------------------------------------------------" << endl;
      cout << "1.        BPM-KP            Ditujukan bagi pendaftar\n";
      cout << "                             keluarga persyarikatan" << endl;
      cout << "-----------------------------------------------------" << endl;
      cout << "2.      BPM-Hafidz          Ditujukan bagi pendaftar\n";
      cout << "                             penghafal Al-Qur'an" << endl;
      cout << "-----------------------------------------------------" << endl;
      cout << "=====================================================" << endl;

      break;
    case 2:
      cout << "\n=====================================================" << endl;
      cout << "=====================================================" << endl;
      cout << "||                                                 ||" << endl;
      cout << "||                  BEASISWA PRESTASI              ||" << endl;
      cout << "||                                                 ||" << endl;
      cout << "=====================================================" << endl;
      cout << "=====================================================" << endl;
      cout << "-----------------------------------------------------\n" << endl;
      cout << " => Jalur seleksi beasiswa masuk Universitas dengan\n";
      cout << "    seleksi menggunakan nilai akademik dan prestasi\n";
      cout << "    kejuaraan bidang seni, sains, dan olahraga\n, ";
      cout << "    berupa potongan biaya selama studi.\n";
      cout << "-----------------------------------------------------\n" << endl; 
      cout << "=====================================================" << endl;
    }
  } while (jenjang != 0);
}
void B2 :: syarat(){
  cout << "Syarat \n";
  cout << "  1. Siswa kelas XII yang akan lulus pada tahun\n";
  cout << "     2023 atau lulusan tahun 2021, 2022\n";
  cout << "  2. Tidak buta warna untuk program studi tertentu\n";
  cout << "  3. Pasfoto berwarna terbaru berpakaian formal\n";
  cout << "  4. Kartu Keluarga\n";
  cout << "  5. Ijazah bagi lulusan 2021 dan 2022\n";
  cout << "  6. Rapor semester 2,3,4 dengan rata rata nilai\n";
  cout << "     pengetahuan 80 untuk 3 mata pelajaran (Matematika,\n";
  cout << "     Bahasa Indonesia, Bahasa Inggris)\n";
  cout << "  7. Sertifikat prestasi minimal juara 3 tingkat SMTA se-\n";
  cout << "     Kabupaten/Kota\n";
  cout << "  8. Bersedia aktif dalam organisasi mahasiswa dan \n";
  cout << "     mengikuti kompetisi selama di UAD\n";
  cout << "  9. Bersedia tidak menikah selama kontrak beasiswa\n";
}
void B2::PendaftaranBeasiswa() {
  cout << "\n=====================================================" << endl;
  cout << "=====================================================" << endl;
  cout << "||                                                 ||" << endl;
  cout << "||                PENDAFTARAN UNIVERSITAS          ||" << endl;
  cout << "||                                                 ||" << endl;
  cout << "=====================================================" << endl;
  cout << "=====================================================" << endl;
  cout << "-----------------------------------------------------\n" << endl;
}
void B2::TampilkanData() {
  cout << "\n=====================================================" << endl;
  cout << "=====================================================" << endl;
  cout << "||                                                 ||" << endl;
  cout << "||                    DAFTAR DATA                  ||" << endl;
  cout << "||                PENDAFTARAN UNIVERSITAS          ||" << endl;
  cout << "||                                                 ||" << endl;
  cout << "=====================================================" << endl;
  cout << "=====================================================" << endl;
  cout << "-----------------------------------------------------\n" << endl;
}
void HasilBeasiswa() {
  cout << "\n=====================================================" << endl;
  cout << "=====================================================" << endl;
  cout << "||                                                 ||" << endl;
  cout << "||                         HASIL                   ||" << endl;
  cout << "||                PENDAFTARAN UNIVERSITAS          ||" << endl;
  cout << "||                                                 ||" << endl;
  cout << "=====================================================" << endl;
  cout << "=====================================================" << endl;
  cout << "-----------------------------------------------------\n" << endl;
}

void B2::FAQ() {
  cout << "\n=====================================================" << endl;
  cout << "=====================================================" << endl;
  cout << "||                                                 ||" << endl;
  cout << "||               FREQUENTLY ASKED QUESTIONS        ||" << endl;
  cout << "||               PENDAFTARAN UNIVERSITAS           ||" << endl;
  cout << "||                                                 ||" << endl;
  cout << "=====================================================" << endl;
  cout << "=====================================================" << endl;
  cout << "-----------------------------------------------------\n" << endl;
  cout << "\n\tPertanyaan : \n\n";
  cout << "Apa Itu Beasiswa Universitas B ";
  cout << "\n\tJawaban : \n \n";
  cout << "adalah seleksi penerimaan mahasiswa baru dengan seleksi menggunakan "
          "\n";
  cout << "nilai akademik dan prestasi kejuaraan atau hafalan Al Qur’an\n";
  cout << "untuk pendaftar yang dinyatakan lulus dan diterima akan mendapatkan "
          "\n";
  cout << "beasiswa berupa gratis biaya kuliah selama 8 semester.\n";

  cout << "\n\tPertanyaan : \n\n";
  cout << "Adakah batas kuota dan apakah harus dengan program studi yang "
          "ditawarkan ";
  cout << "\n\tJawaban : \n \n";
  cout << "Program studi/ jurusan dan kuota beasiswa terbatas\n";
  cout << "pendaftar hanya bisa memilih program studi/ jurusan sesuai dengan "
          "yang ditawarkan.\n";

  cout << "\n\tPertanyaan : \n\n";
  cout << "Tahap Jalur Seleksi ";
  cout << "\n\tJawaban : \n \n";
  cout << "1. Seleksi berkas pendaftaran\n";
}

//int main() { B2 x; }
