#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

int dlinklist_counter = 0;

struct data_beasiswa {
  int n;
  int tanggal, bulan, tahun;
  string kel, kec;
  int rt, rw;
  string NIK, nama, tempat, agama, alamatt, pekerjaan, goldar,
      berlaku = "Seumur Hidup", jenis, sta, kew;
  bool jenis_kelamin, status, kewarganegaraan;
  string jenis_beasiswa;
  
};

int nilai_raport;

struct node {
  data_beasiswa data;
  node *next;
  node *prev;
};
node *head;
node *tail;
node *first, *current, *previos, *tamp;
void inisialisasi() {
  head = NULL;
  tail = NULL;
}

class Beasiswa {
public:
  Beasiswa();
  void JenisBeasiswa();
  void PendaftaranBeasiswa();
  void HasilSeleksi();
  void FAQ();
  void persyaratan();
  void persyaratanKhususS1(char &);
  void persyaratanKhususS2(char &);
  void persyaratanKhususS3(char &);
  void prosesSeleksi();
        void prosesSeleksiS1D4();
        void prosesSeleksiS2();
        void prosesSeleksiS3();
  bool wawancara();
  void simpanHasilSeleksi();

  data_beasiswa dp;
  void dlinklist_enqueu();
  void tampilkan();
  void dlinklist_insert(data_beasiswa data_masuk);
  void dlinklist_dequeu();
  void aturAntrian();

  Array1D<string>* queuektp_arr = new Array1D<string>(20);
private:
  int pil;
};

Beasiswa::Beasiswa() {
  cout << "\n=================================" << endl;
  cout << "=================================" << endl;
  cout << "=====    SELAMAT DATANG     =====" << endl;
  cout << "=====      DI PORTAL        =====" << endl;
  cout << "=====      BEASISWA         =====" << endl;
  cout << "=================================" << endl;
  cout << "=================================\n" << endl;
  cout << "\tMenu yang disediakan \n";
  cout << "\t\t1. Lihat Jenis Beasiswa \n";
  cout << "\t\t2. Pendaftaran Beasiswa \n";
  cout << "\t\t3. Tampilkan Data Yang Masuk\n";
  cout << "\t\t4. Lihat Hasil Seleksi Beasiswa \n";
  cout << "\t\t5. Lihat FAQ \n\n";
  cout << "\t\t0. Keluar \n";
  cout << "\tMasukkan Pilihan Anda : ";
  cin >> pil;
  getchar();

  if (pil == 1) {
    JenisBeasiswa();
  } else if (pil == 2) {
    PendaftaranBeasiswa();
    cout << "Kembali (1) : "; 
    cin >> pil;
    if(pil == 1){
      Beasiswa();
    }
  } else if (pil == 3) {
    tampilkan();
    cout << "Kembali (1) : "; 
    cin >> pil;
    if(pil == 1){
      Beasiswa();
    }
  } else if (pil == 4) {
    HasilSeleksi();
    cout << "Kembali (1) : "; 
    cin >> pil;
    if(pil == 1){
      Beasiswa();
    }
  } else if (pil == 5) {
    FAQ();
    cout << "Kembali (1) : "; 
    cin >> pil;
    if(pil == 1){
      Beasiswa();
    }
        } else if (pil == 0) {
        cout << "Terima Kasih Telah Menggunakan Aplikasi Kami \n";
        

  } else {
    cout << "Pilihan Anda Salah, Silahkan Ulangi Lagi \n";
  }
}

void Beasiswa::JenisBeasiswa() {
  int jenjang;
  char pilSyarat;
  do {
    cout << "\n=================================" << endl;
    cout << "=================================" << endl;
    cout << "=====    JENIS BEASISWA     =====" << endl;
    cout << "=====    YANG DI TAWARKAN   =====" << endl;
    cout << "=================================" << endl;
    cout << "=================================\n" << endl;
    cout << "\tJENJANG " << endl;
    cout << "\t\t 1. S1/D4" << endl;
    cout << "\t\t 2. S2" << endl;
    cout << "\t\t 3. S3" << endl;
    cout << "\t\t 4. Persyaratan Umum" << endl;
    cout << "\t\t 5. Kembali" << endl;
    cout << "\tPilih : ";
    cin >> jenjang;
    switch (jenjang) {
    case 1:
      cout << "=====================================================" << endl;
      cout << "||                   BEASISWA S1/D4                ||" << endl;
      cout << "=====================================================" << endl;
      cout << "-----------------------------------------------------" << endl;
      cout << "No     Jenis Beasiswa      PT Tujuan        Skema    " << endl;
      cout << "-----------------------------------------------------" << endl;
      cout << "1.   Calon guru Sekolah       DN        Single Degree" << endl;
      cout << "     Menengah Kejuruan                               " << endl;
      cout << "-----------------------------------------------------" << endl;
      cout << "2.   Beasiswa Indonesia     DN & LN     Single Degree" << endl;
      cout << "          Maju                                       " << endl;
      cout << "-----------------------------------------------------" << endl;
      cout << "=====================================================" << endl;
      cout << "Baca Persyaratan / back(n) : ";
      cin >> pilSyarat;
      cout << "=====================================================" << endl;
      if (pilSyarat != 'n') {
        persyaratan();
        persyaratanKhususS1(pilSyarat);
      }
      break;
    case 2:
      cout << "=====================================================" << endl;
      cout << "||                    BEASISWA S2                  ||" << endl;
      cout << "=====================================================" << endl;
      cout << "-----------------------------------------------------" << endl;
      cout << "No     Jenis Beasiswa      PT Tujuan        Skema    " << endl;
      cout << "-----------------------------------------------------" << endl;
      cout << "1.  Pendidikan Perguruan    DN & LN      Single Degree" << endl;
      cout << "      Tinggi Akademik                    Joint Degree" << endl;
      cout << "                                         Double Degree" << endl;
      cout << "-----------------------------------------------------" << endl;
      cout << "2.  Pendidikan Perguruan       DN        Single Degree" << endl;
      cout << "      Tinggi Vokasi                                   " << endl;
      cout << "-----------------------------------------------------" << endl;
      cout << "3.   Beasiswa Indonesia        LN        Single Degree" << endl;
      cout << "           Maju                                       " << endl;
      cout << "-----------------------------------------------------" << endl;
      cout << "=====================================================" << endl;
      cout << "Baca Persyaratan / back(n) : ";
      cin >> pilSyarat;
      cout << "=====================================================" << endl;
      if (pilSyarat != 'n') {
        persyaratan();
        persyaratanKhususS2(pilSyarat);
      }
      break;
    case 3:
      cout << "=====================================================" << endl;
      cout << "||                    BEASISWA S3                  ||" << endl;
      cout << "=====================================================" << endl;
      cout << "-----------------------------------------------------" << endl;
      cout << "No     Jenis Beasiswa      PT Tujuan        Skema    " << endl;
      cout << "-----------------------------------------------------" << endl;
      cout << "1.  Pendidikan Perguruan    DN & LN      Single Degree" << endl;
      cout << "      Tinggi Akademik                    Joint Degree" << endl;
      cout << "                                         Double Degree" << endl;
      cout << "-----------------------------------------------------" << endl;
      cout << "2.  Pendidikan Perguruan       DN        Single Degree" << endl;
      cout << "      Tinggi Vokasi                                   " << endl;
      cout << "-----------------------------------------------------" << endl;
      cout << "3.  Dosen LPTK/Pendidikan      LN        Single Degree" << endl;
      cout << "        Profesi Guru                                  " << endl;
      cout << "-----------------------------------------------------" << endl;
      cout << "4.  Beasiswa University        LN        Single Degree" << endl;
      cout << "         of Oxford                                    " << endl;
      cout << "-----------------------------------------------------" << endl;
      cout << "=====================================================" << endl;
      cout << "Baca Persyaratan / back(n) : ";
      cin >> pilSyarat;
      cout << "=====================================================" << endl;
      if (pilSyarat != 'n') {
        persyaratan();
        persyaratanKhususS3(pilSyarat);
      }
      break;
    case 4:
      persyaratan();
      break;
    case 5:
      Beasiswa();
      break;
    default:
      cout << " \nTidak ada dimenu\n" << endl;
      break;
    }
  } while (jenjang != 5);
}
void Beasiswa::persyaratan() {
  cout << "===================================================================="
          "====="
       << endl;
  cout << "||                          PERSYARATAN UMUM                        "
          "   ||"
       << endl;
  cout << "===================================================================="
          "====="
       << endl;
  cout << "--------------------------------------------------------------------"
          "-----"
       << endl;
  cout << "  a. Warga Negara Indonesia" << endl;
  cout << "--------------------------------------------------------------------"
          "-----"
       << endl;
  cout << "  b. Diterima pada Perguruan Tinggi di dalam atau di \n";
  cout << "     luar negeri yang telah ditetapkan oleh Kementerian\n";
  cout << "      yang dibuktikan LoA Unconditional atau surat tanda\n";
  cout << "      diterima tanpa syarat sesuai program studi pada\n";
  cout << "      Perguruan Tinggi yang ditetapkan oleh Puslapdik;" << endl;
  cout << "--------------------------------------------------------------------"
          "-----"
       << endl;
  cout << "  c. Telah menyelesaikan SMA/SMK/yang sederajat (bagi\n";
  cout << "     mahasiswa semester 1 tahun akademik 2022/2023) untuk\n";
  cout << "     studi program beasiswa D4 atau S1 dengan ketentuan\n";
  cout << "     sebagai berikut:\n";
  cout << "     1) sekolah di dalam negeri atau Sekolah Indonesia\n";
  cout << "        Luar Negeri (SILN) yang terakreditasi oleh Badan\n";
  cout << "        Akreditasi Nasional Sekolah/ Madrasah; atau\n";
  cout << "     2) sekolah di luar negeri yang telah memperoleh penyetaraan\n";
  cout << "        dengan sekolah dalam negeri oleh Sekretariat\n";
  cout << "        Direktorat Jenderal Pendidikan Anak Usia Dini, Pendidikan\n";
  cout << "         Direktorat Jenderal Pendidikan Anak Usia Dini, Pendidikan"
       << endl;
  cout << "--------------------------------------------------------------------"
          "-----"
       << endl;
  cout << "  d. telah menyelesaikan studi program D4 atau S1\n";
  cout << "     untuk beasiswa S2, atau program S2 untuk beasiswa S3,\n";
  cout << "     dengan ketentuan sebagai berikut:\n";
  cout << "     1) Perguruan Tinggi di dalam negeri yang terakreditasi\n";
  cout << "        oleh Badan Akreditasi Nasional Perguruan Tinggi (BAN-PT),\n";
  cout << "     2) Perguruan Tinggi kedinasan dalam negeri, atau\n";
  cout << "     3) Perguruan Tinggi di luar negeri yang diakui oleh\n";
  cout << "        Direktorat Jenderal Pendidikan Tinggi Kementerian atau\n";
  cout << "        Kedutaan Besar Republik Indonesia di negara asal\n";
  cout << "        Perguruan Tinggi;" << endl;
  cout << "--------------------------------------------------------------------"
          "-----"
       << endl;
  cout << "  e. tidak sedang (on going) atau telah menempuh studi\n";
  cout << "     studi program S1, S2, S3 atau Non-Gelar(Non-degree),\n";
  cout << "     baik pada Perguruan Tinggi di dalam negeri maupun Perguruan\n";
  cout << "     Tinggi di luar negeri, kecuali bagi penerima beasiswa\n";
  cout << "     S1/ 44 Calon Guru SMK dan penerima beasiswa Program\n";
  cout << "     S3 PTA Dalam Negeri;" << endl;
  cout << "--------------------------------------------------------------------"
          "-----"
       << endl;
  cout << "  f. tidak sedang menerima atau akan menerima beasiswa dari\n";
  cout << "     sumber lain selama menjadi penerima BPI Kemendikbudristek;"
       << endl;
  cout << "--------------------------------------------------------------------"
          "-----"
       << endl;
  cout << "  g. beasiswa hanya diperuntukkan untuk kelas reguler dan\n";
  cout << "     tidak diperuntukkan untuk kelas-kelas sebagai berikut:\n";
  cout << "     1) kelas eksekutif;\n";
  cout << "     2) kelas khusus;\n";
  cout << "     3) kelas karyawan;\n";
  cout << "     4) kelas jarak jauh;\n";
  cout
      << "     5) kelas yang diselenggrakan bukan di perguruan tinggi induk;\n";
  cout << "     6) kelas yang diselenggarakan di lebih dari 1(satu)\n";
  cout << "        negara(kecuali untuk program joint degree/double degree);\n";
  cout << "     7) kelas internasional khusus tujuan dalam negeri; dan\n";
  cout << "     8) kelas lainnya yang tidak memenuhi ketentuan kementrian"
       << endl;
  cout << "--------------------------------------------------------------------"
          "-----"
       << endl;
  cout << "  h. Memenuhi ketentuan usia, skor bahasa, IPK/IP/Rapor\n";
  cout << "--------------------------------------------------------------------"
          "-----"
       << endl;
  cout << "===================================================================="
          "====="
       << endl;
}

void Beasiswa::persyaratanKhususS1(char &pilSyarat) {
  switch (pilSyarat) {
  case '1':
    cout << "=================================================================="
            "======="
         << endl;
    cout << "||                 PERSYARATAN KHUSUS S1/D4 CALON GURU SMK        "
            "     ||"
         << endl;
    cout << "=================================================================="
            "======="
         << endl;
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << " a) Memiliki surat rekomendasi dari:\n";
    cout << "    (1) kepala sekolah dan dinas pendidikan bagi Tenaga "
            "Kependidikan\n";
    cout << "        yang berstatus sebagai Aparatur Sipil Negara (ASN);\n";
    cout << "    (2) kepala sekolah bagi Guru dan Tenaga Kependidikan diluar "
            "ASN; atau\n";
    cout << "    (3) Perguruan Tinggi bagi bukan Guru atau bukan Tenaga "
            "Kependidikan;"
         << endl;
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << " b) menandatangi surat pernyataan komitmen menjadi Guru kejuruan "
            "di satuan\n";
    cout << "    pendidikan administrasi pangkalnya bagi pandaftar Guru dan "
            "surat\n";
    cout << "    pernyataan bersedia menjadi Guru kejuruan bagi pendaftar yang "
            "belum guru; dan\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << " c) lulusan SMK yang telah diterima atau Mahasiswa di "
            "LPTK/Universitas/Institut\n";
    cout << "    paling tinggi berada pada semester 3 (tiga) pada tahun "
            "akademik 2022/2023\n";
    cout << "    (on going) di Lembaga Pendidikan Tenaga Kependidikan\n";
    cout << "    (LPTK)/Universitas/Institut pada jurusan sesuai dengan "
            "program keahlian\n";
    cout << "    yang menjadi sektor prioritas nasional yaitu:\n";
    cout << "    (1) sektor hospitality\n";
    cout << "    (2) ekonomi kreatif\n";
    cout << "    (3) permesinan dan konstruksi\n";
    cout << "    (4) pekerja migran\n";
    cout << "    (5) kemaritiman\n";
    cout << "    (6) pertanian" << endl;
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "=================================================================="
            "======="
         << endl;
    break;

  case '2':
    cout << "=================================================================="
            "======="
         << endl;
    cout << "||            PERSYARATAN KHUSUS S1 BEASISWA INDONESIA MAJU       "
            "     ||"
         << endl;
    cout << "=================================================================="
            "======="
         << endl;
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << " a) Memiliki\n";
    cout << "    (1) surat rekomendasi sebagai calon penerima BIM dari "
            "Puspresnas\n";
    cout << "        berdasarkan program persiapan BIM; dan/atau\n";
    cout << "    (2) prestasi dalam tiga (3) tahun terakhir:\n";
    cout << "        (a) pada ajang yang diselenggarakan dan/atau difasilitasi "
            "oleh\n";
    cout << "            Puspresnas dengan ketentuan:\n";
    cout << "            i.   tingkat nasional setara juara 1 (emas), 2 "
            "(perak), dan 3 (perunggu);\n";
    cout << "            ii.  tingkat internasional setara juara 1 (emas), 2 "
            "(perak), dan 3 (perunggu);\n";
    cout << "            iii. penghargaan khusus di tingkat internasional yang "
            "diperoleh;\n";
    cout << "        (b) pada ajang yang diselenggarakan dan/atau difasilitasi "
            "oleh pihak\n";
    cout << "            lain selain Puspresnas yang telah dikurasi oleh "
            "Puspresnas dengan\n";
    cout << "            ketentuan:\n";
    cout << "            i.   tingkat nasional setara juara 1 (emas), 2 "
            "(perak), dan 3 (perunggu);\n";
    cout << "            ii.  tingkat internasional setara juara 1 (emas), 2 "
            "(perak), dan 3 (perunggu);\n";
    cout << "            iii. penghargaan khusus di tingkat internasional yang "
            "diperoleh; dan/atau\n";
    cout << "        (c) pada non-ajang yang diselenggarakan dan/atau "
            "difasilitasi oleh\n";
    cout << "            pihak lain selain Puspresnas yang telah dikurasi oleh "
            "Puspresnas; dan\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << " b) diterima pada Perguruan Tinggi di dalam negeri pada program "
            "studi dengan\n";
    cout << "    akreditasi paling rendah B atau Baik Sekali atau Perguruan "
            "Tinggi tujuan di luar negeri\n";
    cout << "    yang ditetapkan oleh Kementerian.\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    break;
  default:
    cout << "\nTidak ada di menu\n" << endl;
    break;
  }
}

void Beasiswa::persyaratanKhususS2(char &pilSyarat) {
  switch (pilSyarat) {
  case '1':
    cout << "=================================================================="
            "======="
         << endl;
    cout << "||                 PERSYARATAN KHUSUS S2 PENDIDIKAN PTA           "
            "     ||"
         << endl;
    cout << "=================================================================="
            "======="
         << endl;
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  a) berusia paling tinggi sesuai dengan ketentuan pemberian "
            "tugas belajar\n";
    cout << "     berdasarkan Surat Edaran Sekretaris Jenderal Kementerian "
            "Pendidikan,\n";
    cout << "     Kebudayaan, Riset, dan Teknologi Nomor 1 Tahun 2022 tentang "
            "Pemberian\n";
    cout << "     Tugas Belajar Kementerian Pendidikan, Kebudayaan, Riset, dan "
            "Teknologi baik\n";
    cout << "     yang berstatus ASN maupun di luar ASN;\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  b) memiliki:\n";
    cout << "     (1) Nomor Urut Pendidik (NUP) bagi dosen;\n";
    cout << "     (2) surat perjanjian kerja dengan Perguruan Tinggi terkait "
            "bagi calon dosen dari\n";
    cout << "         Perguruan Tinggi Negeri Baru(PTNB)\n";
    cout << "     (3) Nomor Induk Tenaga Kependidikan (NITK) atau surat "
            "rekomendasi dari\n";
    cout << "         pemimpin Perguruan Tinggi tempat bekerja bagi Tenaga "
            "Kependidikan\n";
    cout << "         pada Perguruan Tinggi negeri pendidikan akademik; atau\n";
    cout << "     (4) surat izin dari pimpinan yang membidangi kepegawaian "
            "bagi Tenaga\n";
    cout << "         Kependidikan pada Direktorat Jenderal Pendidikan Tinggi, "
            "Riset, dan\n";
    cout << "         Teknologi, Kementerian; dan\n";
    cout << "     (5) paling sedikit satu surat rekomendasi dari akademisi;\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  c) bagi calon dosen PTNB menandatangi surat pernyataan komitmen "
            "menjadi\n";
    cout << "     dosen pada perguruan tinggi asal; dan\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  d) bagi pendaftar yang melaksanakan pendidikan S2 melalui "
            "program magister\n";
    cout << "     joint degree/dual/degree menyertakan surat perjanjian kerja "
            "sama/nota\n";
    cout << "     kesepahaman joint degree/dual degree" << endl;
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "=================================================================="
            "======="
         << endl;
    break;

  case '2':
    cout << "=================================================================="
            "======="
         << endl;
    cout << "||                 PERSYARATAN KHUSUS S2 PENDIDIKAN PTV           "
            "     ||"
         << endl;
    cout << "=================================================================="
            "======="
         << endl;
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  a) berusia paling tinggi sesuai dengan ketentuan pemberian "
            "tugas belajar\n";
    cout << "     berdasarkan Surat Edaran Sekretaris Jenderal Kementerian "
            "Pendidikan,\n";
    cout << "     Kebudayaan, Riset, dan Teknologi Nomor 1 Tahun 2022 tentang "
            "Pemberian\n";
    cout << "     Tugas Belajar Kementerian Pendidikan, Kebudayaan, Riset, dan "
            "Teknologi baik\n";
    cout << "     yang berstatus ASN maupun di luar ASN;\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  b) memiliki:\n";
    cout << "     (1) Nomor Induk Dosen Nasional (NIDN) atau NUP bagi dosen "
            "tetap dan aktif\n";
    cout << "         mengajar di Perguruan Tinggi vokasi;\n";
    cout << "     (2) Nomor Induk Tenaga Kependidikan (NITK) atau surat "
            "rekomendasi dari\n";
    cout << "         pemimpin Perguruan Tinggi tempat bekerja bagi Tenaga "
            "Kependidikan\n";
    cout << "         yang berstatus ASN pada Perguruan Tinggi negeri "
            "pendidikan vokasi; atau\n";
    cout << "     (3) surat izin dari pimpinan yang membidangi kepegawaian "
            "bagi Tenaga\n";
    cout << "         Kependidikan yang berstatus ASN pada Direktorat Jenderal "
            "Pendidikan\n";
    cout << "         Vokasi, Kementerian; dan\n";
    cout << "     (4) paling sedikit satu surat rekomendasi dari akademisi;\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  c) diterima pada bidang:\n";
    cout << "     (1) manufaktur, konstruksi, permesinan, sipil, pertanian, "
            "peternakan, farmasi,\n";
    cout << "         ekonomi kreatif, pariwisata, atau hospitality bagi "
            "dosen;\n";
    cout << "     (2) manufaktur, konstruksi, permesinan, sipil, pertanian, "
            "peternakan, farmasi,\n";
    cout << "         ekonomi kreatif, pariwisata, hospitality, manajemen "
            "Perguruan Tinggi,\n";
    cout << "         administrasi publik, akuntansi, evaluasi pendidikan, "
            "atau hubungan internasional\n";
    cout << "         bagi tenaga kependidikan" << endl;
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    break;

  case '3':
    cout << "=================================================================="
            "======="
         << endl;
    cout << "||              PERSYARATAN KHUSUS S2 BEASISWA INDONESIA MAJU     "
            "     ||"
         << endl;
    cout << "=================================================================="
            "======="
         << endl;
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  a) Memiliki surat izin mengikuti pendaftaran dan seleksi dari "
            "pimpinan yang\n";
    cout << "     berwenang bagi pendaftar yang bekerja pada instansi "
            "tertentu;\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  b) memiliki prestasi dalam 10 (sepuluh) tahun terakhir:\n";
    cout << "     (1) pada ajang yang diselenggarakan dan/atau difasilitasi "
            "oleh Puspresnas\n";
    cout << "         dengan ketentuan: \n";
    cout << "         (a) tingkat nasional setara juara 1 (emas), 2 (perak), "
            "dan 3 (perunggu);\n";
    cout << "         (b) tingkat internasional setara juara 1 (emas), 2 "
            "(perak), 3 (perunggu); dan/atau\n";
    cout << "         (c) penghargaan khusus di tingkat internasional yang "
            "diperoleh;\n";
    cout << "     (2) pada ajang yang diselenggarakan dan/atau difasilitasi "
            "oleh pihak lain selain\n";
    cout << "         Puspresnas yang telah dikurasi oleh Puspresnas dengan "
            "ketentuan:\n";
    cout << "         (a) tingkat nasional setara juara 1 (emas), 2 (perak), "
            "dan 3 (perunggu);\n";
    cout << "         (b) tingkat internasional setara juara 1 (emas), 2 "
            "(perak), 3 (perunggu); dan/atau\n";
    cout << "         (c) penghargaan khusus di tingkat internasional yang "
            "diperoleh;\n";
    cout << "     (3) pada non-ajang yang diselenggarakan dan/atau "
            "difasilitasi oleh pihak lain\n";
    cout << "         selain Puspresnas yang telah dikurasi oleh Puspresnas;";
    cout << "     (4) diterima pada Perguruan Tinggi tujuan di luar negeri "
            "yang ditetapkan oleh kementrian"
         << endl;
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "=================================================================="
            "======="
         << endl;
    break;

  default:
    cout << " \nTidak ada dimenu\n" << endl;
    break;
  }
}

void Beasiswa::persyaratanKhususS3(char &pilSyarat) {
  switch (pilSyarat) {
  case '1':
    cout << "=================================================================="
            "======="
         << endl;
    cout << "||                 PERSYARATAN KHUSUS S3 PENDIDIKAN PTA           "
            "     ||"
         << endl;
    cout << "=================================================================="
            "======="
         << endl;
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  a) berusia paling tinggi sesuai dengan ketentuan pemberian "
            "tugas belajar\n";
    cout << "     berdasarkan Surat Edaran Sekretaris Jenderal Kementerian "
            "Pendidikan,\n";
    cout << "     Kebudayaan, Riset, dan Teknologi Nomor 1 Tahun 2022 tentang "
            "Pemberian\n";
    cout << "     Tugas Belajar Kementerian Pendidikan, Kebudayaan, Riset, dan "
            "Teknologi baik\n";
    cout << "     yang berstatus ASN maupun di luar ASN;\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  b) memiliki:\n";
    cout << "     (1) NIDN atau Nomor Induk Dosen Khusus(NIDK) bagi dosen "
            "tetap\n";
    cout << "         mengajar di Perguruan Tinggi vokasi;\n";
    cout << "     (2) Nomor Induk Tenaga Kependidikan (NITK) atau surat "
            "rekomendasi dari\n";
    cout << "         pemimpin Perguruan Tinggi tempat bekerja bagi Tenaga "
            "Kependidikan\n";
    cout << "         pada Perguruan Tinggi negeri pendidikan akademik; atau\n";
    cout << "     (3) surat izin dari pimpinan yang membidangi kepegawaian "
            "bagi Tenaga\n";
    cout << "         Kependidikan pada Direktorat Jenderal Pendidikan Tinggi, "
            "Riset, dan\n";
    cout << "         Teknologi, Kementeriani; dan\n";
    cout << "     (4) paling sedikit satu surat rekomendasi dari akademisi;\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  c) menyertakan surat perjanjian kerjasama/MoU program joint "
            "degree/dual\n";
    cout
        << "     degree bagi pendaftar program joint degree/dual degree; dan\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  d) menyertakan Kartu Rencana Studi (KRS) semester berjalan "
            "khusus pendaftar\n";
    cout << "     Program S3 Dalam Negeri yang telah terdaftar sebagai "
            "mahasiswa on going\n";
    cout << "     yang semester 1 nya terhitung dimulai pada tahun 2022.\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  e) menyertakan Kartu Hasil Studi (KHS) khusus pendaftar Program "
            "S3 PTA Dalam\n";
    cout << "     Negeri bagi mahasiswa on going yang memulai perkuliahan "
            "semester 1 (satu)\n";
    cout << "     bulan Januari s.d. Juli tahun 2022;\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  f) apabila program doktor joint degree/dual degree berdurasi 4 "
            "tahun maka dapat\n";
    cout << "     mengikuti pilihan pola sebagai berikut:\n";
    cout << "     (1) pola 2+2 (tahun ke-1 dan ke-2 ditempuh di perguruan "
            "tinggi dalam negeri,\n";
    cout << "         sedangkan tahun ke-3 dan ke-4 ditempuh di perguruan "
            "tinggi luar negeri); atau\n";
    cout << "     (2) pola 1+2+1 (tahun ke-1 ditempuh di perguruan tinggi "
            "dalam negeri, tahun\n";
    cout << "         ke-2 dan ke-3 ditempuh di perguruan tinggi luar negeri, "
            "dan tahun ke-4\n";
    cout << "         ditempuh di perguruan tinggi dalam negeri);\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  g) apabila program doktor joint degree/dual degree berdurasi "
            "kurang dari 4 tahun\n";
    cout << "     maka pola dapat disesuaikan berdasarkan kesepakatan antara 2 "
            "perguruan \n";
    cout << "     tinggi penyelenggara." << endl;
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    break;

  case '2':
    cout << "=================================================================="
            "======="
         << endl;
    cout << "||                 PERSYARATAN KHUSUS S3 PENDIDIKAN PTV           "
            "     ||"
         << endl;
    cout << "=================================================================="
            "======="
         << endl;
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  a) berusia paling tinggi sesuai dengan ketentuan pemberian "
            "tugas belajar\n";
    cout << "     berdasarkan Surat Edaran Sekretaris Jenderal Kementerian "
            "Pendidikan,\n";
    cout << "     Kebudayaan, Riset, dan Teknologi Nomor 1 Tahun 2022 tentang "
            "Pemberian\n";
    cout << "     Tugas Belajar Kementerian Pendidikan, Kebudayaan, Riset, dan "
            "Teknologi baik\n";
    cout << "     yang berstatus ASN maupun di luar ASN;\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  b) memiliki:\n";
    cout << "     (1) Nomor Induk Dosen Nasional (NIDN) atau NUP bagi dosen "
            "tetap dan aktif\n";
    cout << "         mengajar di Perguruan Tinggi vokasi;\n";
    cout << "     (2) Nomor Induk Tenaga Kependidikan (NITK) atau surat "
            "rekomendasi dari\n";
    cout << "         pemimpin Perguruan Tinggi tempat bekerja bagi Tenaga "
            "Kependidikan\n";
    cout << "         yang berstatus ASN pada Perguruan Tinggi negeri "
            "pendidikan vokasi; atau\n";
    cout << "     (3) surat izin dari pimpinan yang membidangi kepegawaian "
            "bagi Tenaga\n";
    cout << "         Kependidikan yang berstatus ASN pada Direktorat Jenderal "
            "Pendidikan\n";
    cout << "         Vokasi, Kementerian;\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  c) melampirkan surat rekomendasi dari akademisi; dan\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  d) diterima pada bidang:\n";
    cout << "     (1) manufaktur, konstruksi, permesinan, sipil, pertanian, "
            "peternakan, farmasi,\n";
    cout << "         ekonomi kreatif, pariwisata, atau hospitality bagi "
            "dosen;\n";
    cout << "     (2) manufaktur, konstruksi, permesinan, sipil, pertanian, "
            "peternakan, farmasi,\n";
    cout << "         ekonomi kreatif, pariwisata, hospitality, manajemen "
            "Perguruan Tinggi,\n";
    cout << "         administrasi publik, akuntansi, evaluasi pendidikan, "
            "atau hubungan internasional\n";
    cout << "         bagi tenaga kependidikan" << endl;
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    break;

  case '3':
    cout << "=================================================================="
            "======="
         << endl;
    cout << "||       PERSYARATAN KHUSUS S3 DOSEN LPTK/PENDIDIKAN PROFESI GURU "
            "     ||"
         << endl;
    cout << "=================================================================="
            "======="
         << endl;
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  a) memiliki Nomor Induk Dosen Nasional (NIDN) bagi dosen tetap "
            "pada\n";
    cout << "     Perguruan Tinggi negeri dan swasta di bawah binaan "
            "Kementerian yang\n";
    cout << "     melaksanakan program Pendidikan Profesi Guru;\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  b) memiliki paling sedikit satu surat rekomendasi dari "
            "akademisi; dan\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  c) diterima pada salah satu dari 30 (tiga puluh) Perguruan "
            "Tinggi luar negeri yang\n";
    cout << "     ditetapkan oleh Kementerian dengan bidang Pendidikan Profesi "
            "Guru prioritas\n";
    cout << "     sebagai berikut:\n";
    cout << "     (1) Literacy Education, Literacy Specialist;\n";
    cout << "     (2) Mathematics Education, atau Mathematics Teacher "
            "Education;\n";
    cout << "     (3) Elementary Education, atau Elementary Teacher "
            "Education;\n";
    cout << "     (4) Early Childhood Education, atau Early Childhood Teacher "
            "Education;\n";
    cout << "     (5) School Leadership; \n";
    cout << "     (6) Special Education;\n";
    cout << "     (7) Educational Technology, atau Learning Technologies; \n";
    cout << "     (8) Science Education, atau Science Teacher Education\n";
    cout << "     (9) Social Studies Education, atau Social Studies Teacher "
            "Education;\n";
    cout << "     (10) Secondary Teacher Education;\n";
    cout << "     (11) Teacher Education; \n";
    cout << "     (12) Curriculum and Instruction, atau Curriculum and "
            "Teaching; atau\n";
    cout << "     (13) Sport Science / Physical Education.\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    break;

  case '4':
    cout << "=================================================================="
            "======="
         << endl;
    cout << "||     PERSYARATAN KHUSUS S3 PROGRAM BEASISWA UNIVERSITY OF "
            "OXFORD     ||"
         << endl;
    cout << "=================================================================="
            "======="
         << endl;
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  a) Program beasiswa University of Oxford (Medical Sciences "
            "Division) pada 16\n";
    cout << "     departeme:\n";
    cout << "     (1) Nuffield Department of Clinical Medicine;\n";
    cout << "     (2) Nuffield Department of Clinical Neurosciences;\n";
    cout << "     (3) Department of Paediatrics;\n";
    cout << "     (4) Sir William Dunn School of Pathology;\n";
    cout << "     (5) Nuffield Department of Population Health;\n";
    cout << "     (6) Department of Primary Care Health Sciences;\n";
    cout << "     (7) Nuffield Department of Surgical Sciences;\n";
    cout << "     (8) Nuffield Department of Women’s & Reproductive Health;\n";
    cout << "     (9) Department of Biochemistry;\n";
    cout << "     (10) Department of Experimental Psychology;\n";
    cout << "     (11) Department of Oncology;\n";
    cout << "     (12) Department of Orthopaedics, Rheumatology, and "
            "Musculoskeletal Sciences;\n";
    cout << "     (13) Department of Pharmacology;\n";
    cout << "     (14) Department of Physiology, Anatomy, and Genetics;\n";
    cout << "     (15) Department of Psychiatry;\n";
    cout << "     (16) Radcliffe Department of Medicine;\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  b) pendaftaran dan seleksi dilakukan oleh 4 (empat) fakultas "
            "kedokteran pada 4\n";
    cout << "     (empat) Perguruan Tinggi yang ditunjuk sebagai pelaksana "
            "oleh Direktorat\n";
    cout << "     Jenderal Pendidikan Tinggi, Riset, dan Teknologi, dengan "
            "ketentuan sebagai berikut:\n";
    cout << "     "
            "=================================================================="
            "===\n";
    cout << "     | No     Asal Fakultas      Koordinator            e-mail    "
            "       |\n";
    cout << "     |      Kedokteran Calon     Program                          "
            "       |\n";
    cout << "     "
            "=================================================================="
            "===\n";
    cout << "     "
            "------------------------------------------------------------------"
            "---\n";
    cout << "       1    AIPKI Wilayah 1&2   Universitas   "
            "beasiswaoxford.ui@gmail.com\n";
    cout << "                                Indonesia\n";
    cout << "     "
            "------------------------------------------------------------------"
            "---\n";
    cout << "       2    AIPKI Wilayah 3&4   Universitas   "
            "admission.fkkmk@ugm.ac.id\n";
    cout << "                                Gadjah Mada\n";
    cout << "     "
            "------------------------------------------------------------------"
            "---\n";
    cout << "       3    AIPKI Wilayah 5     Universitas   "
            "S2S3oxford@fk.unai.ac.id\n";
    cout << "                                Airlangga\n";
    cout << "     "
            "------------------------------------------------------------------"
            "---\n";
    cout << "       4    AIPKI Wilayah 6     Universitas   "
            "mfkasim@med.unhas.co.id\n";
    cout << "                                Hasanuddin\n";
    cout << "     "
            "------------------------------------------------------------------"
            "---\n";
    cout << "     "
            "=================================================================="
            "===\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    cout << "  c) persyaratan pendaftar dan prosedur pengusulan beasiswa;\n";
    cout << "     (1) Persyaratan dokumen:";
    cout << "         (a) portfolio publikasi terkait riset;\n";
    cout << "         (b) proposal riset atau Statement of Interest (untuk "
            "proyek penelitian yang sudah berjalan);\n";
    cout << "         (c) Letter of motivation / letter of intent/ Personal "
            "Statement;\n";
    cout << "     (2) dokumen dikirimkan ke tiap koordinator dengan subject "
            "email: Oxford\n";
    cout << "         Postgraduate Scholarship-Kemendikbudristek 2022;\n";
    cout << "     (3) wawancara secara daring oleh tiap koordinator;\n";
    cout << "     (4) koordinator FK (Fakultas Kedokteran) akan menyeleksi "
            "shortlisted\n";
    cout << "         candidates dari seluruh FK untuk mendapatkan 80 - 100 "
            "calon;\n";
    cout << "     (5) Ditjen Diktiristek akan mengusulkan shortlisted "
            "candidates kepada pihak\n";
    cout << "         Oxford untuk proses evaluasi awal;\n";
    cout << "         (a) jika berdasarkan hasil evaluasi awal calon "
            "berpotensi diterima, calon\n";
    cout << "             selanjutnya dibantu oleh pihak Oxford dalam "
            "menyelesaikan proses \n";
    cout << "             lamaran formal;\n";
    cout << "         (b) calon mendapatkan akses untuk berkomunikasi dengan "
            "para dosen di\n";
    cout << "             Oxford untuk membahas proposal riset yang "
            "diusulkan;\n";
    cout << "         (c) calon melakukan pendaftaran beasiswa melalui laman\n";
    cout << "             www.beasiswakemdikbud.go.id;\n";
    cout << "     (6) Puslapdik bekerjasama dengan Ditjen Diktiristek akan "
            "melakukan seleksi\n";
    cout << "         administrasi dan dilanjutkan dengan seleksi wawancara;\n";
    cout << "------------------------------------------------------------------"
            "-------"
         << endl;
    break;
  default:
    cout << " \nTidak ada dimenu\n" << endl;
    break;
  }
}

void Beasiswa::PendaftaranBeasiswa() {
  cout << "\n=================================" << endl;
  cout << "=================================" << endl;
  cout << "=====      PENDAFTARAN      =====" << endl;
  cout << "=====      BEASISWA         =====" << endl;
  cout << "=================================" << endl;
  cout << "=================================\n" << endl;
  cout << "\tSelamat datang di portal pendaftaran beasiswa.";
  cout << "\n\tSebelum melanjutkan harap sudah membacar jenis dan syarat "
          "beasisiswa\n";
  cout << "\t\t1. Sudah Membaca \n";
  cout << "\t\t2. Belum membaca \n";
  cout << "\tMasukkan Pilihan Anda : ";
  cin >> pil;
  if (pil == 1) {
    dlinklist_enqueu();
  } else if (pil == 2) {
    JenisBeasiswa();
  }
}

void Beasiswa::dlinklist_enqueu() {
  node tmp;
  cout << "========================================\n";
  cout << "======    MASUKKAN DATA DIRI ANDA  =====\n";
  cout << "========================================\n";
  while (true) {
    cout << "NIK\t\t : ";
    cin >> tmp.data.NIK;
    switch (tmp.data.NIK.length()) {
    case 0 ... 15:
      cout << "NIK yang anda masukkan kurang dari 16 digit\n";
      continue;
    case 17 ... 100:
      cout << "NIK yang anda masukkan lebih dari 16 digit\n";
      continue;
    default:
      break;
    }
    break;
  }

  cout << "Nama\t\t : ";
  cin.ignore();
  getline(cin, tmp.data.nama);
  cout << "Tempat\t\t : ";
  getline(cin, tmp.data.tempat);
  cout << "Tanggal\t\t : ";
  cin >> tmp.data.tanggal;
  cout << "Bulan\t\t : ";
  cin >> tmp.data.bulan;
  cout << "Tahun\t\t : ";
  cin >> tmp.data.tahun;
  while (true) {
    cout << "Jenis Kelamin:\n0. Laki - Laki\n1. Perempuan\n";
    cout << "Pilih : ";
    cin >> tmp.data.jenis_kelamin;
    switch (tmp.data.jenis_kelamin) {
    case false:
      tmp.data.jenis = "LAKI-LAKI";
      break;
    case true:
      tmp.data.jenis = "PEREMPUAN";
      break;
    default:
      cout << "Pilihan tidak valid\n";
      continue;
    }
    break;
  }

  while (true) {
    cout << "Golongan Darah:\n1. A\n2. B\n3. AB\n4. O\n";
    cout << "Pilih : ";
    cin >> pil;
    switch (pil) {
    case 1:
      tmp.data.goldar = "A";
      break;
    case 2:
      tmp.data.goldar = "B";
      break;
    case 3:
      tmp.data.goldar = "AB";
      break;
    case 4:
      tmp.data.goldar = "O";
      break;
    default:
      cout << "Pilihan tidak valid\n";
      continue;
    }
    break;
  }

 // string temp_almt = "";
  cout << "Alamat\t\t : ";
  cin.ignore();
  getline(cin, tmp.data.alamatt);
  //temp_almt = tmp.data.alamatt+", ";
  cout << "RT\t\t : ";
  cin >> tmp.data.rt;
  //temp_almt = temp_almt + to_string(tmp.data.rt) + "/";
  cout << "RW\t\t : ";
  cin >> tmp.data.rw;
  cout << "Kel/Desa\t : ";
  cin.ignore();
  getline(cin, tmp.data.kel);
  cout << "Kecamatan\t : ";
  getline(cin, tmp.data.kec);

  while (true) {
    cout << "Agama:\n";
    cout << "1. Islam\n";
    cout << "2. Protestan\n";
    cout << "3. Katolik\n";
    cout << "4. Hindu\n";
    cout << "5. Konghucu\n";
    cout << "6. Buddha\n";
    cout << "Pilih : ";
    cin >> pil;
    switch (pil) {
    case 1:
      tmp.data.agama = "ISLAM";
      break;
    case 2:
      tmp.data.agama = "PROTESTAN";
      break;
    case 3:
      tmp.data.agama = "KATOLIK";
      break;
    case 4:
      tmp.data.agama = "HINDU";
      break;
    case 5:
      tmp.data.agama = "KONGHUCU";
      break;
    case 6:
      tmp.data.agama = "BUDDHA";
      break;
    default:
      cout << "Pilihan tidak valid\n";
      continue;
    }
    break;
  }

  while (true) {
    cout << "Status Perkawinan :\n0. KAWIN\n1. BELUM KAWIN\n";
    cout << "Pilih : ";
    cin >> tmp.data.status;
    switch (tmp.data.status) {
    case 0:
      tmp.data.sta = "KAWIN";
      break;
    case 1:
      tmp.data.sta = "BELUM KAWIN";
      break;
    default:
      cout << "Pilihan tidak valid\n";
      continue;
    }
    break;
  }

  cout << "Pekerjaan\t : ";
  cin.ignore();
  getline(cin, tmp.data.pekerjaan);

  while (true) {
    cout << "Kewarganegaraan:\n0. WNI\n1. WNA\n";
    cout << "Pilih : ";
    cin >> tmp.data.kewarganegaraan;
    switch (tmp.data.kewarganegaraan) {
    case 0:
      tmp.data.kew = "WNI";
      break;
    case 1:
      tmp.data.kew = "WNA";
      break;
    default:
      cout << "Pilihan tidak valid\n";
      continue;
    }
    break;
  }

  cout << "Jenis Beasiswa :\n";
    cout << "\t\t 1. S1/D4" << endl;
    cout << "\t\t 2. S2" << endl;
    cout << "\t\t 3. S3" << endl;
  cout << "Pilih : ";
  int pilbeasiswa;
        cin >> pilbeasiswa;
        if (pilbeasiswa == 1) {
                tmp.data.jenis_beasiswa = "S1/D4";
        } else if (pilbeasiswa == 2) {
                tmp.data.jenis_beasiswa = "S2";
        } else if (pilbeasiswa == 3) {
                tmp.data.jenis_beasiswa = "S3";
        } else {
                cout << "Pilihan tidak valid" << endl;
        }
   ofstream kefilebeasiswa;
   kefilebeasiswa.open("Beasiswa/pendaftar_beasiswa.txt", ios::app);
        kefilebeasiswa << tmp.data.nama << endl;
        kefilebeasiswa << tmp.data.NIK << endl;
        kefilebeasiswa << tmp.data.jenis_beasiswa << endl;
        kefilebeasiswa << tmp.data.tahun << endl;
   kefilebeasiswa.close();

  dlinklist_insert(tmp.data);
}

void Beasiswa::dlinklist_insert(data_beasiswa data_masuk) {
        //cout << "Test masuk ga nih? di dlinklist_insert" << endl;
  //	current = new dlist;
  struct node *current;
  current = new node;
  current->data = data_masuk;
  if (dlinklist_counter == 0) {
        //cout << "Masuk element pertama nih" << endl;
    previos = current;
    first = current;
    current->prev = NULL;
    current->next = NULL;
    //first = current;
  } else {
        cout << "Masuk element selanjutnya nih" << endl;
    previos->next = current;
    current->prev = previos;
    previos = current;
  }
  current->next = NULL;
  dlinklist_counter++;
  ofstream indexseleksi;
  indexseleksi.open("Beasiswa/indexseleksi.txt");
        indexseleksi << dlinklist_counter;
  indexseleksi.close();
  //cout << "dlink countrn skrg : " << dlinklist_counter << endl;
}
void Beasiswa::tampilkan() {
  cout << "\n=================================" << endl;
  cout << "=================================" << endl;
  cout << "=====      DAFTAR DATA      =====" << endl;
  cout << "=====      YANG TELAH       =====" << endl;
  cout << "=====      DI MASUKKKAN       =====" << endl;
  cout << "=================================" << endl;
  cout << "=================================\n" << endl;
  if (dlinklist_counter == 0) {
    cout << "\tData Masih Kosong";
  } else {
    tamp = first;
    while (tamp!= NULL) {
      cout << "=======================================================\n";
      cout << "\t\tPROVINSI DKI JAKARTA\n";
      cout << "\t\t   JAKARTA PUSAT\n";
      cout << "=======================================================\n";
      cout << "NIK\t\t\t: " << tamp->data.NIK << "\n\n";
      cout << "Nama\t\t\t: " << tamp->data.nama << endl;
      cout << "Tampat/Tgl Lahir\t: " << tamp->data.tempat << " / "
           << tamp->data.tanggal << "- " << tamp->data.bulan << " - "
           << tamp->data.tahun << endl;
      cout << "Jenis Kelamin\t\t: " << tamp->data.jenis
           << "\tGol. Darah : " << tamp->data.goldar << endl;
      cout << "Alamat\t\t\t: " << tamp->data.alamatt << endl;
      cout << "\tRT/RW\t\t: " << tamp->data.rt << " / " << tamp->data.rw
           << endl;
      cout << "\tKel/Desa\t: " << tamp->data.kel << endl;
      cout << "\tKecamatan\t: " << tamp->data.kec << endl;
      cout << "Agama\t\t\t: " << tamp->data.agama << endl;
      cout << "Status Perkawinan\t: " << tamp->data.sta << endl;
      cout << "Pekerjaan\t\t: " << tamp->data.pekerjaan << endl;
      cout << "Kewarganegaraan\t\t: " << tamp->data.kew << endl;
      cout << "Berlaku Hingga\t\t: " << tamp->data.berlaku << endl;
      cout << "=======================================================\n";
      cout << "Beasiswa yang diambil\t: " << tamp->data.jenis_beasiswa << endl;
      cout << "\n\n ";
      tamp = tamp->next;
    }
    /*
    cout << "=======================================================\n";
    cout << "\t\tPROVINSI DKI JAKARTA\n";
    cout << "\t\t   JAKARTA PUSAT\n";
    cout << "=======================================================\n";
    cout << "NIK\t\t\t: " << tamp->data.NIK << "\n\n";
    cout << "Nama\t\t\t: " << tamp->data.nama << endl;
    cout << "Tampat/Tgl Lahir\t: " << tamp->data.tempat << " / "
         << tamp->data.tanggal << "- " << tamp->data.bulan << " - "
         << tamp->data.tahun << endl;
    cout << "Jenis Kelamin\t\t: " << tamp->data.jenis
         << "\tGol. Darah : " << tamp->data.goldar << endl;
    cout << "Alamat\t\t\t: " << tamp->data.alamatt << endl;
    cout << "\tRT/RW\t\t: " << tamp->data.rt << " / " << tamp->data.rw << endl;
    cout << "\tKel/Desa\t: " << tamp->data.kel << endl;
    cout << "\tKecamatan\t: " << tamp->data.kec << endl;
    cout << "Agama\t\t\t: " << tamp->data.agama << endl;
    cout << "Status Perkawinan\t: " << tamp->data.sta << endl;
    cout << "Pekerjaan\t\t: " << tamp->data.pekerjaan << endl;
    cout << "Kewarganegaraan\t\t: " << tamp->data.kew << endl;
    cout << "Berlaku Hingga\t\t: " << tamp->data.berlaku << endl;
    cout << "=======================================================\n";
    cout << "Beasiswa yang diambil\t: " << tamp->data.jenis_beasiswa << endl;
    cout << "\n\n ";*/
    tamp = first;
  }
  cout << endl;
  cout << "\nUntuk Kembali Masukkan (1)\nUntuk memproses pendaftaran beasiswa Anda Masukkan (2)\nPilih: ";
  cin >> pil; getchar();
  if (pil == 1) {
    Beasiswa();
  }
  else {
        prosesSeleksi();
  }
}

void Beasiswa::prosesSeleksi() {
        bool state_login = false;
        string temp_pendaftar;
        string temp_nik;
        //string thn_lhr;
        struct pendaftarbeasisawa {
                string nama;
                string nik;
                string jenis_beasiswa;
                string thn_lhr;
        };
        pendaftarbeasisawa pendaftarbeasiswa[50];

        time_t t = time(NULL);
        tm *const pTInfo = localtime(&t);
        int current_year = pTInfo->tm_year + 1900;

        ifstream bacafilebeasiswa;
        bacafilebeasiswa.open("Beasiswa/pendaftar_beasiswa.txt");
        int i = 0;
        while (!bacafilebeasiswa.eof()) {
                bacafilebeasiswa >> pendaftarbeasiswa[i].nama;
                bacafilebeasiswa >> pendaftarbeasiswa[i].nik;
                bacafilebeasiswa >> pendaftarbeasiswa[i].jenis_beasiswa;
                bacafilebeasiswa >> pendaftarbeasiswa[i].thn_lhr;
                i++;
        }
        bacafilebeasiswa.close();

        cout << "\n";
        cout << "Proses Seleksi Beasiswa\n";
        cout << "=======================\n";
        cout << "[Silakan login dulu untuk memproses seleksi beasiswa Anda]\n";

        int j;
        while (true) {
                cout << "\n";
                cout << "Nama Pendafatar\t\t: ";
                getline(cin, temp_pendaftar);
                cout << "NIK Pendafatar\t\t: ";
                getline(cin, temp_nik);

                for (j = 0; j < i; j++) {
                        if (temp_pendaftar == pendaftarbeasiswa[j].nama && temp_nik == pendaftarbeasiswa[j].nik) {
                                cout << "\n\e[1;32mSelamat Datang " << pendaftarbeasiswa[j].nama << "\e[0m" << endl;
                                state_login = true;
                                break;
                        }
                }
                if (state_login == true) {
                        break;
                }
                else {
                        cout << "\n\e[1;31mNama atau NIK yang Anda masukkan salah, silakan coba lagi\e[0m\n";
                }
        }

        int umur = current_year - stoi(pendaftarbeasiswa[j].thn_lhr);
        cout << "\n=====================================\n";
        cout << "Nama\t\t\t: " << pendaftarbeasiswa[j].nama << endl;
        cout << "NIK\t\t\t: " << pendaftarbeasiswa[j].nik << endl;
        cout << "Beasiswa yang dipilih\t: " << pendaftarbeasiswa[j].jenis_beasiswa << endl;
        cout << "=======================================\n";
        if (pendaftarbeasiswa[j].jenis_beasiswa=="S1/D4") {
                if (umur >= 17 && umur <= 25) prosesSeleksiS1D4();
                else {
                        cout << "Mohon maaf, Umur Anda tidak memenuhi syarat untuk beasiswa ini\n";
                        cout << "Syarat umur beasiswa S1/D4 adalah 17 - 25 tahun\n";
                }
        }
        else if (pendaftarbeasiswa[j].jenis_beasiswa=="S2") {
                if (umur >= 25 && umur <= 35) prosesSeleksiS2();
                else {
                        cout << "Mohon maaf, Umur Anda tidak memenuhi syarat untuk beasiswa ini\n";
                        cout << "Syarat umur beasiswa S2 adalah 25 - 35 tahun\n";
                }
        }
        else if (pendaftarbeasiswa[j].jenis_beasiswa=="S3") {
                if (umur >= 25 && umur <= 35) prosesSeleksiS3();
                else {
                        cout << "Mohon maaf, Umur Anda tidak memenuhi syarat untuk beasiswa ini\n";
                        cout << "Syarat umur beasiswa S3 adalah 25 - 37 tahun\n";
                }
        }


}

void Beasiswa::prosesSeleksiS1D4() {
        cout << "\n>> Syarat Usia\t: Lolos\n";
        cout << "Input nilai raport\t: ";
        nilai_raport;
        cin >> nilai_raport; getchar();
        if (nilai_raport >= 90) {
                cout << ">> Syarat nilai raport\t: Lolos\n";
                if (wawancara()) {
                        cout << ">> Syarat wawancara\t: Lolos\n";
                        cout << ">> Selamat Anda dinyatakan lolos seleksi beasiswa\n";
                        cout << "Silakan lengkapi data dibawah untuk tahap selanjutnya\n";
                        cout << "Input NISN\t\t: ";
                        string nisn;
                        getline(cin, nisn);
                        cout << "Input No.HP\t\t: ";
                        string no_hp;
                        getline(cin, no_hp);
                        cout << "Input nama Ayah\t\t: ";
                        string nama_ayah;
                        getline(cin, nama_ayah);
                        cout << "Input nama Ibu\t\t: ";
                        string nama_ibu;
                        getline(cin, nama_ibu);
                        cout << "Kabupaten Anda tinggal\t: ";
                        string kabupaten;
                        getline(cin, kabupaten);
                        cout << "Provinsi Anda tinggal\t: ";
                        string provinsi;
                        getline(cin, provinsi);
                        queuektp_arr->enqueue(to_string(nilai_raport));
                        queuektp_arr->enqueue(nisn);
                        queuektp_arr->enqueue(no_hp);
                        queuektp_arr->enqueue(nama_ayah);
                        queuektp_arr->enqueue(nama_ibu);
                        queuektp_arr->enqueue(provinsi+", "+kabupaten);
                        cout << "\nCek sampai enqueue selesai gk? \n";
                        simpanHasilSeleksi();
                }
                else {
                        cout << ">> Syarat wawancara\t: Tidak Lolos\n";
                        cout << ">> Mohon maaf Anda dinyatakan tidak lolos seleksi beasiswa\n";
                }
        }
}

void Beasiswa::prosesSeleksiS2() {
        cout << "\n>> Syarat Usia\t: Lolos\n";
        cout << "Input nilai raport\t: ";
        nilai_raport;
        cin >> nilai_raport; getchar();
        if (nilai_raport >= 90) {
                cout << ">> Syarat nilai raport\t: Lolos\n";
                if (wawancara()) {
                        cout << ">> Syarat wawancara\t: Lolos\n";
                        cout << ">> Selamat Anda dinyatakan lolos seleksi beasiswa\n";  
                        cout << "Silakan lengkapi data dibawah untuk tahap selanjutnya\n";
                        cout << "Input NISN\t\t: ";
                        string nisn;
                        getline(cin, nisn);
                        cout << "Input No.HP\t\t: ";
                        string no_hp;
                        getline(cin, no_hp);
                        cout << "Input nama Ayah\t\t: ";
                        string nama_ayah;
                        getline(cin, nama_ayah);
                        cout << "Input nama Ibu\t\t: ";
                        string nama_ibu;
                        getline(cin, nama_ibu);
                        cout << "Kabupaten Anda tinggal\t: ";
                        string kabupaten;
                        getline(cin, kabupaten);
                        cout << "Provinsi Anda tinggal\t: ";
                        string provinsi;
                        getline(cin, provinsi);
                        queuektp_arr->enqueue(to_string(nilai_raport));
                        queuektp_arr->enqueue(nisn);
                        queuektp_arr->enqueue(no_hp);
                        queuektp_arr->enqueue(nama_ayah);
                        queuektp_arr->enqueue(nama_ibu);
                        queuektp_arr->enqueue(provinsi+", "+kabupaten);  

                        simpanHasilSeleksi();                   
                }
                else {
                        cout << ">> Syarat wawancara\t: Tidak Lolos\n";
                        cout << ">> Mohon maaf Anda dinyatakan tidak lolos seleksi beasiswa\n";
                }
        }
}

void Beasiswa::prosesSeleksiS3() {
        cout << "\n>> Syarat Usia\t: Lolos\n";
        cout << "Input nilai raport\t: ";
        nilai_raport;
        cin >> nilai_raport; getchar();
        if (nilai_raport >= 90) {
                cout << ">> Syarat nilai raport\t: Lolos\n";
                if (wawancara()) {
                        cout << ">> Syarat wawancara\t: Lolos\n";
                        cout << ">> Selamat Anda dinyatakan lolos seleksi beasiswa\n";   
                        cout << "Silakan lengkapi data dibawah untuk tahap selanjutnya\n";
                        cout << "Input NISN\t\t: ";
                        string nisn;
                        getline(cin, nisn);
                        cout << "Input No.HP\t\t: ";
                        string no_hp;
                        getline(cin, no_hp);
                        cout << "Input nama Ayah\t\t: ";
                        string nama_ayah;
                        getline(cin, nama_ayah);
                        cout << "Input nama Ibu\t\t: ";
                        string nama_ibu;
                        getline(cin, nama_ibu);
                        cout << "Kabupaten Anda tinggal\t: ";
                        string kabupaten;
                        getline(cin, kabupaten);
                        cout << "Provinsi Anda tinggal\t: ";
                        string provinsi;
                        getline(cin, provinsi);
                        queuektp_arr->enqueue(to_string(nilai_raport));
                        queuektp_arr->enqueue(nisn);
                        queuektp_arr->enqueue(no_hp);
                        queuektp_arr->enqueue(nama_ayah);
                        queuektp_arr->enqueue(nama_ibu);
                        queuektp_arr->enqueue(provinsi+", "+kabupaten);

                        simpanHasilSeleksi();
                }
                else {
                        cout << ">> Syarat wawancara\t: Tidak Lolos\n";
                        cout << ">> Mohon maaf Anda dinyatakan tidak lolos seleksi beasiswa\n";                        
                }
        }
        else {
                cout << ">> Syarat nilai raport\t: Tidak Lolos\n";
                cout << ">> Mohon maaf Anda dinyatakan tidak lolos seleksi beasiswa\n";
        }
}


bool Beasiswa::wawancara() {
        bool hasilwawancara = false;
        string jawaban = "";
        cout << "\n=================================" << endl;
        cout << "Tes Wawancara" << endl;
        cout << "1. Apa yang Anda ketahui tentang Universitas B? (jawab dengan singkat dan jelas)" << endl;
        cout << "Jawaban : ";
        getline(cin, jawaban);
        cout << "2. Mengapa Anda memilih Universitas B? (jawab dengan singkat dan jelas)" << endl;
        cout << "Jawaban : ";
        string jwb;
        getline(cin, jwb);

        jawaban = jawaban + jwb;
        if (jawaban.find("jelek") != string::npos || jawaban.find("tidak bagus") 
        != string::npos || jawaban.find("tidak baik") != string::npos) {
                hasilwawancara = false;
        }
        else {
                hasilwawancara = true;
        }
        return hasilwawancara;
        
}

void Beasiswa::simpanHasilSeleksi() {
        string x;
        int jml = 0;
        ofstream saveseleksi;
        saveseleksi.open("Beasiswa/hasilseleksi.txt", ios::app);
        tamp = first;
        while (tamp!=NULL) {
                queuektp_arr->dequeue(x); //nilai_raport
                saveseleksi << nilai_raport << "\t";
                saveseleksi << tamp->data.nama << "\t";
                queuektp_arr->dequeue(x); //nisn
                saveseleksi << x << "\t";
                saveseleksi << tamp->data.NIK << "\t";
                queuektp_arr->dequeue(x); //no_hp
                saveseleksi << x << "\t";
                queuektp_arr->dequeue(x); //nama_ayah
                saveseleksi << x << "\t";
                queuektp_arr->dequeue(x); //nama_ibu
                saveseleksi << x << "\t";
                queuektp_arr->dequeue(x); //provinsi, kabupaten
                saveseleksi << x << ", ";
                saveseleksi << tamp->data.kec << ", ";
                saveseleksi << tamp->data.kel << ", ";
                saveseleksi << "RT. " << tamp->data.rt << ",";
                saveseleksi << "RW. " << tamp->data.rw << endl;
                tamp = tamp->next;
                first = tamp;
                break;
        }
        saveseleksi.close();
        
}

/*void Beasiswa::aturAntrian() {
        node* temp_str = new node;
        ifstream readhasil;
        readhasil.open("Beasiswa/hasilseleksi.txt");
        vector<string> data[8];
        string line;

        int i = 0;
        while(!readhasil.eof()) {
                getline(readhasil, line);
                data[i] = explode(line, '\t');
                i++;
                if (readhasil.eof()) {
                        break;
                }
        }
        readhasil.close();

        for (int j=1;j<i;j++) {

        }

        



        






}*/


void Beasiswa::HasilSeleksi() {
  cout << "\n=================================" << endl;
  cout << "=================================" << endl;
  cout << "=====      HASIL DAFTAR     =====" << endl;
  cout << "=====      BEASISWA         =====" << endl;
  cout << "=================================" << endl;
  cout << "=================================\n" << endl;
  string line;
  ifstream hsl;
  hsl.open("Beasiswa/hasilseleksi.txt");
  cout << "Nilai Raport :\tNama :\t\tNISN :\t\tNIK :\t\tNo HP :\t\tNama Ayah :\tNama Ibu :\tAlamat Lengkap : " << endl;
  cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        while(!hsl.eof()) {
                getline(hsl, line);
                cout << line << endl;
                if (hsl.eof()) break;
        }
}
void Beasiswa::FAQ() {
  cout << "\n=================================" << endl;
  cout << "=================================" << endl;
  cout << "=====         FORUM         =====" << endl;
  cout << "=====         FAQ           =====" << endl;
  cout << "=================================" << endl;
  cout << "=================================\n" << endl;

  cout << "Daftar FAQ \n";
  cout << "1. FAQ Per Jenis Beasiswa ?\n";
  cout << "2. FAQ Umum \n";
  cout << "\nPilih Pertanyaan : ";
  cin >> pil;

  if (pil == 1) {
    cout << "\n\tFAQ Per Jenis Mahasiswa : \n";
    cout << "1. FAQ Calon Guru SMK \n";
    cout << "2. FAQ (PTA) Perguruan Tinggi Akademik PTA \n";
    cout << "3. FAQ Dosen LPTK /Pendidikan Profesi Guru\n";
    cout << "4. FAQ Pelaku Budaya \n";
    cout << "5. FAQ Beasiswa Indonesia Maju (BIM) \n";
    cout << "6. FAQ (PTV) Perguruan Tinggi Vokasi \n";
    cout << "\nPilih Jenis : ";
    cin >> pil;
    if (pil == 1) {
      cout << "\n\tCalon Guru SMK \n\n";
      cout << "Daftar Pertanyaan : \n";
      cout << "1. Saya tidak memiliki NUPTK apakah bisa mendaftar Beasiswa "
              "Calon Guru SMK?\n";
      cout << "2. Saya merupakan mahasiswa baru, apakah wajib melampirkan KRS? "
              "\n";
      cout << "3. Saya mahasiswa on Going, apakah perlu melampirkan Ijazah SMK "
              "dan nilai Raport SMK? \n";
      cout << "4. Saya telah diterima/ lolos seleksi di salah satu Program "
              "Studi yang menjadi sektor prioritas Nasional, namun ternyata "
              "Perguruan Tinggi dan Program Studinya tidak ada dalam List \n";
      cout << "5. Saya Guru SMK namun lulusan SMA apakah boleh mendaftar? \n";
      cout << "6. Saya merupakan mahasiswa baru dan bukan Guru atau tenaga "
              "kependidikan, untuk surat rekomendasi bisa saya dapatkan dari "
              "mana? \n";
      cout << "\nPilih Pertanyaan : ";
      cin >> pil;
      if (pil == 1) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Saya tidak memiliki NUPTK apakah bisa mendaftar Beasiswa "
                "Calon Guru SMK?\n";
        cout << "\n\tJawaban : \n \n";
        cout << "Pendaftar Beasiswa Calon Guru SMK tidak wajib memiliki NUPTK, "
                "silahkan mendaftar meski belum memiliki NUPTK \n";
      } else if (pil == 2) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Saya merupakan mahasiswa baru, apakah wajib melampirkan KRS? "
                "\n";
        cout << "\n\tJawaban : \n \n";
        cout << "Cukup melampirkan Ijazah SMK dan Nilai Raport tahun terakhir "
                "\n";
      } else if (pil == 3) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Saya mahasiswa on Going, apakah perlu melampirkan Ijazah SMK "
                "dan nilai Raport SMK? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "Perlu, lampirkan Ijazah SMK , Nilai Raport tahun terakhir, "
                "dan Transkrip nilai. \n";
      } else if (pil == 4) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Saya telah diterima/ lolos seleksi di salah satu Program "
                "Studi yang menjadi sektor prioritas Nasional, namun ternyata "
                "Perguruan Tinggi dan Program Studinya tidak ada dalam List \n";
        cout << "\n\tJawaban : \n \n";
        cout << "Untuk mendaftar Beasiswa Pendidikan Indonesia wajib telah "
                "diterima pada Program Studi dan Perguruan Tinggi yang "
                "terdaftar pada List masing-masing Jenis Beasiswa. \n";
      } else if (pil == 5) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Saya Guru SMK namun lulusan SMA apakah boleh mendaftar? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "Diperbolehkan, salah satu sasaran Beasiswa Calon Guru SMK "
                "adalah Guru dan tenaga kependidikan pada satuan pendidikan "
                "SMK \n";
      } else if (pil == 6) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Saya merupakan mahasiswa baru dan bukan Guru atau tenaga "
                "kependidikan, untuk surat rekomendasi bisa saya dapatkan dari "
                "mana? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "Bagi Non Guru dan tenaga kependidikan, Surat Rekomendasi dari "
                "Perguruan Tinggi (baik Mahasiswa Baru atau on Going) \n";
      }

    } else if (pil == 2) {
      cout << "\n\tPerguruan Tinggi Akademik PTA (PTA)\n\n";
      cout << "Daftar Pertanyaan : \n";
      cout << "1. Bagaimana jika NIK tidak terdaftar di PDDIKTI?\n";
      cout << "2. Jika saya alumni S2 tanpa penelitian,unggahan dokumen apa "
              "yang harus saya upload pada bagian transkrip? \n";
      cout << "3. Apakah pendaftar beasiswa S3 PTA bisa berasal dari Non-Dosen "
              "yang hendak menjadi Dosen?\n";
      cout << "4. Apakah dosen yang belum memiliki NUP di perbolehkan "
              "mendaftar beaasiswa PTA?\n";
      cout << "5. Apakah dosen yang hombase nya bertalar belakang Kampus "
              "Muhammadiyah bisa mendaftar beasiswa PTA?\n";
      cout << "6. Mengapa NIK tidak sesuai dengan PDDIKTI?\n";
      cout << "7. Jika PT tujuan belum ada pengumuman apakah saya tetap bisa "
              "mendaftar?\n";
      cout << "8. Mengapa prodi tidak terdaftar dalam list padahal sudah "
              "terakreditasi A?\n";
      cout << "9. Program studi tujuan saya di universitas tujuan "
              "terakreditasi A oleh BAN-PT,mengapa tidak termasuk dalam list "
              "prodi beasiswa PTA?\n";
      cout << "10. Apakah surat izin belajar harus dari LLDIKTI atau dari "
              "pimpinan Yayasan saja?\n";
      cout << "11. Dosen dibawah PTV tetapi prodinya bisa di PTA, apakah bisa "
              "mendaftar?\n";
      cout << "12. apakah toefl bukan ITP (accept) yang di keluarkan PT tujuan "
              "dapat digunakan untuk mendaftar beasiswa ini?\n";
      cout << "13. Di daerah saya tidak ada yang menyediakan test toefl IBT, "
              "apakah saya dapat menggunakan sertifkat bahasa dari toefl ITP "
              "saja untuk dapat melamar beasiswa PTA LN? \n";
      cout << "14. Apakah karya ilmiah seperti artikel terindek dan juga HKI "
              "akan di perhitungkan juga seleksi beasiswa PTA ini? \n";
      cout << "15. untuk beasiswa Joint Degree apakah PT dan Prodi DN LN, "
              "dua2nya harus ada pada List PT dan Prodi tujuan?\n";
      cout << "\nPilih Pertanyaan : ";
      cin >> pil;
      if (pil == 1) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Bagaimana jika NIK tidak terdaftar di PDDIKTI? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "Data PDDIKTI sudah disingkronkan dengan API terbaru dan sudah "
                "bisa mengakomodir perubahan data di PDDIKTI dan di sister \n";

      } else if (pil == 2) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Data PDDIKTI sudah disingkronkan dengan API terbaru dan sudah "
                "bisa mengakomodir perubahan data di PDDIKTI dan di sister \n";
        cout << "\n\tJawaban : \n \n";
        cout << "Dibagaian transkip tidak di wajibkan mengunggah dokumen \n";
      } else if (pil == 3) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Apakah pendaftar beasiswa S3 PTA bisa berasal dari Non-Dosen "
                "yang hendak menjadi Dosen? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "untuk Non-Dosen dapat mendaftar selama memiliki NITK dari PT "
                "Hombase \n";
      } else if (pil == 4) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Apakah dosen yang belum memiliki NUP di perbolehkan mendaftar "
                "beaasiswa PTA? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "tidak bisa mendaftar \n";
      } else if (pil == 5) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Apakah dosen yang hombase nya bertalar belakang Kampus "
                "Muhammadiyah bisa mendaftar beasiswa PTA? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "selama PT yang di maksud dibawah kemendikbudristek masih bisa "
                "mendaftar, jika memenuhi kualifikasi \n";
      } else if (pil == 6) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Mengapa NIK tidak sesuai dengan PDDIKTI? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "Data PDDIKTI sudah disingkronkan dengan API terbaru dan sudah "
                "bisa mengakomodir perubahan data di PDDIKTI dan di sister \n";
      } else if (pil == 7) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Jika PT tujuan belum ada pengumuman apakah saya tetap bisa "
                "mendaftar? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "tidak bisa mendaftar, Puslapdik sudah mempertimbangkan "
                "penutupan pendaftaran mengakomodasi pengumuman kelulusan PT "
                "DN \n";
      } else if (pil == 8) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Mengapa prodi tidak terdaftar dalam list padahal sudah "
                "terakreditasi A? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "sesuai dengan perjanjian kerjasama LPDP, maka program ini "
                "menggunakan list yang sama dengan LPDP dengan beberapa "
                "penyesuaian sesuai kebutuhan dengan unit utama \n";
      } else if (pil == 9) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Program studi tujuan saya di universitas tujuan terakreditasi "
                "A oleh BAN-PT,mengapa tidak termasuk dalam list prodi "
                "beasiswa PTA? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "sesuai dengan perjanjian kerjasama LPDP, maka program ini "
                "menggunakan list yang sama dengan LPDP dengan beberapa "
                "penyesuaian sesuai kebutuhan dengan unit utama \n";
      } else if (pil == 10) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Apakah surat izin belajar harus dari LLDIKTI atau dari "
                "pimpinan Yayasan saja? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "surat izin belajar dikeluarkan oleh LLDIKTI, untuk dosen dan "
                "tendik PTS surat izin belajar di keluarkan oleh satuan kerja "
                "yang membawahi SDM \n";
      } else if (pil == 11) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Dosen dibawah PTV tetapi prodinya bisa di PTA, apakah bisa "
                "mendaftar? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "sama dengan PTV \n";
      } else if (pil == 12) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "apakah toefl bukan ITP (accept) yang di keluarkan PT tujuan "
                "dapat digunakan untuk mendaftar beasiswa ini? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "bisa \n";
      } else if (pil == 13) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Di daerah saya tidak ada yang menyediakan test toefl IBT, "
                "apakah saya dapat menggunakan sertifkat bahasa dari toefl ITP "
                "saja untuk dapat melamar beasiswa PTA LN? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "tidak bisa, selain IBT bisa di gunakan IELTS, PTE \n";
      } else if (pil == 14) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Apakah karya ilmiah seperti artikel terindek dan juga HKI "
                "akan di perhitungkan juga seleksi beasiswa PTA ini? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "akan menjadi pertimbangan dan di explore lebih jauh pada saat "
                "wawancara\n";
      } else if (pil == 15) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "untuk beasiswa Joint Degree apakah PT dan Prodi DN LN, "
                "dua2nya harus ada pada List PT dan Prodi tujuan? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "Selama Perguruan Tinggi Dalam Negeri dan Prodinya terdapat "
                "dalam List, dan ada MoU antara PTDN (terdaftar dalam list) "
                "dengan PTLN maka diperbolehkan. \n";
      }
    } else if (pil == 3) {
      cout << "\n\tGTK & LPTK \n\n";
      cout << "Daftar Pertanyaan : \n";
      cout << "1. Apakah pada program GTK, guru honorer diperbolehkan "
              "mengikuti program ini? \n";
      cout << "2. Apakah surat izin pimpinan bagi guru diperbolehkan dari "
              "Kepala Sekolah atau harus dari Kepala Dinas?\n";
      cout << "3. Untuk tenaga pendidik yang belum memiliki NUPTK apakah bisa "
              "untuk mendaftar program beasiswa ini ?\n";
      cout << "4. Saya ingin mengikuti program beasiswa S2 GTK dalam negeri "
              "dan genap berusia 35 tahun pada bulan Juni tahun ini. Apakah "
              "saya masih bisa mengikuti seleksi BPI kategori GTK, kebetulan "
              "saya pegawai ASN. (Intinya batas usia)\n";
      cout
          << "5. Apakah boleh surat rekomendasi akademisi dan surat keterangan "
             "masa kerja untuk guru PNS dari Kepala Sekolah tempat bekerja?\n";
      cout << "6. Apakah boleh LoA berupa surat keterangan lulus yang "
              "ditandatangani oleh ketua panitia PMB Pascasarjana? \n";
      cout << "\nPilih Pertanyaan : ";
      cin >> pil;
      if (pil == 1) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Apakah pada program GTK, guru honorer diperbolehkan mengikuti "
                "program ini? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "boleh, selama memiliki NUPTK \n";
      } else if (pil == 2) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Apakah surat izin pimpinan bagi guru diperbolehkan dari "
                "Kepala Sekolah atau harus dari Kepala Dinas? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "surat izin pimpinan seleksi boleh dari Kepala Sekolah \n";
      } else if (pil == 3) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Untuk tenaga pendidik yang belum memiliki NUPTK apakah bisa "
                "untuk mendaftar program beasiswa ini ? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "tidak bisa, harus mempunyai NUPTK \n";
      } else if (pil == 4) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Saya ingin mengikuti program beasiswa S2 GTK dalam negeri dan "
                "genap berusia 35 tahun pada bulan Juni tahun ini. Apakah saya "
                "masih bisa mengikuti seleksi BPI kategori GTK, kebetulan saya "
                "pegawai ASN. (Intinya batas usia) \n";
        cout << "\n\tJawaban : \n \n";
        cout << "tidak diperkenankan melewati batas usia yang telah ditentukan "
                "dalam buku panduan \n";
      } else if (pil == 5) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Apakah boleh surat rekomendasi akademisi dan surat keterangan "
                "masa kerja untuk guru PNS dari Kepala Sekolah tempat bekerja? "
                "\n";
        cout << "\n\tJawaban : \n \n";
        cout << "surat rekomendasi akademisi dan surat keterangan masa kerja "
                "utk guru PNS diperbolehkan dari Kepala Sekolah tempat bekerja "
                "\n";
      } else if (pil == 6) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Apakah boleh LoA berupa surat keterangan lulus yang "
                "ditandatangani oleh ketua panitia PMB Pascasarjana? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "diperbolehkan \n";
      }
    } else if (pil == 4) {
      cout << "\n\tPelaku Budaya\n\n";
      cout << "Daftar Pertanyaan : \n";
      cout << "1. Siapa saja yang dapat mendaftar program beasiswa program "
              "pelaku budaya? \n";
      cout << "2. Apakah ada kemungkinan penambahan Perguruan Tinggi (PT) yang "
              "berbentuk Institusi pada Jenis Beasiswa Pelaku Budaya?\n";
      cout << "3. Untuk surat Izin Pimpinan diperbolehkan dari siapa saja? Dan "
              "bagaimana jika yang tidak bekerja?\n";
      cout << "4. Apakah freshgraduate S1 bisa mendaftar beasiswa S2 Pelaku "
              "Budaya?\n";
      cout << "5. Apakah ada format surat keterangan masa kerja pengajuan BPI "
              "program pelaku budaya ?\n";
      cout << "6. Untuk jenjang S1, apakah mungkin mendaftar tanpa memiliki "
              "ijazah SMA di Indonesia, karena lulusan luar negeri ?\n";
      cout << "7. salah unggah dokumen, dan sudah submit, apakah bisa "
              "mengajukan pembatalan submit? \n";
      cout << "8. boleh kan mengajukan beasiswa memakai Loa Conditional? \n";
      cout << "9. NISN saya masih saja belum ditemukan, sehingga sampai saat "
              "ini saya masih terkendala untuk mendaftar dan NISN yang saya "
              "masukan sudah benar. Apa yang harus saya lakukan? \n";
      cout << "10. gagal upload berkas surat keterangan sehat dan surat "
              "rekomendasi dan muncul keterangan setelah saya upload the fale "
              "failed to upload . Apa yang harus saya lakukan?\n";
      cout << "11. Sebelumnya sudah bisa login namun saat akan login ulang "
              "terdapata peringaan the given data was invalid. These "
              "credentials do not match our records,. Artinya bagaimana? \n";
      cout << "\nPilih Pertanyaan : ";
      cin >> pil;
      if (pil == 1) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Siapa saja yang dapat mendaftar program beasiswa program "
                "pelaku budaya? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "Sesuai panduan pendaftaran \n";
      } else if (pil == 2) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Apakah ada kemungkinan penambahan Perguruan Tinggi (PT) yang "
                "berbentuk Institusi pada Jenis Beasiswa Pelaku Budaya? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "tidak \n";
      } else if (pil == 3) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Untuk surat Izin Pimpinan diperbolehkan dari siapa saja? Dan "
                "bagaimana jika yang tidak bekerja? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "Tidak wajib bagi yg belum bekerja \n";
      } else if (pil == 4) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Apakah freshgraduate S1 bisa mendaftar beasiswa S2 Pelaku "
                "Budaya? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "bisa mendaftar jika sesuai dengan sasaran program pelaku "
                "budaya \n";
      } else if (pil == 5) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Apakah ada format surat keterangan masa kerja pengajuan BPI "
                "program pelaku budaya ? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "tidak ada format khusus \n";
      } else if (pil == 6) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Untuk jenjang S1, apakah mungkin mendaftar tanpa memiliki "
                "ijazah SMA di Indonesia, karena lulusan luar negeri ? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "Ijazah disetarakan terlebihdahulu ke Sekretarit Jendral "
                "Dikdasmen \n";
      } else if (pil == 7) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "salah unggah dokumen, dan sudah submit, apakah bisa "
                "mengajukan pembatalan submit? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "sampai tanggal 16 mei dapat melakukan pembatalan submit \n";
      } else if (pil == 8) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "boleh kan mengajukan beasiswa memakai Loa Conditional? \n";
        cout << "\n\tJawaban : \n \n";
        cout
            << "LoA yang harus di unggah adalah LoA Unconditioan kecuali "
               "persyaratan sponsor pendanaan, dokumen fisik ijazah, dan "
               "transkrip nilai , jenjang studi sebelumnya dan atau "
               "persyaratan tambahan yang tidak mengandung resiko mengubah "
               "status mahasiswa tersebut pada program studi yang dituju serta "
               "memuat nama lengkap , jenjang studi, program studi, serta "
               "durasi lama studi, permulaan studi dan atau akhir studi. \n";
      } else if (pil == 9) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "NISN saya masih saja belum ditemukan, sehingga sampai saat "
                "ini saya masih terkendala untuk mendaftar dan NISN yang saya "
                "masukan sudah benar. Apa yang harus saya lakukan? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "silakan mendaftar menggunakan NIK \n";
      } else if (pil == 10) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "gagal upload berkas surat keterangan sehat dan surat "
                "rekomendasi dan muncul keterangan setelah saya upload the "
                "fale failed to upload . Apa yang harus saya lakukan? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "cek kembali secara berkala (file yang di upload "
                "maksimal/tidak lebih dari 2 MB) \n";
      } else if (pil == 11) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Sebelumnya sudah bisa login namun saat akan login ulang "
                "terdapata peringaan the given data was invalid. These "
                "credentials do not match our records,. Artinya bagaimana? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "username : Masukan NIK anda password : Masukan passward yang "
                "anda buat captcha : masukan hasil penjumlahan dari gambar "
                "captcha \n";
      }
    } else if (pil == 5) {
      cout << "\n\tBIM\n\n";
      cout << "Daftar Pertanyaan : \n";
      cout << "1. Apa itu Beasiswa Indonesia Maju (BIM)?\n";
      cout << "2. Jenjang apa saja yang ada di Beasiswa Indonesia Maju (BIM)? "
              "\n";
      cout << "3. Siapa sasaran Beasiswa Indonesia Maju (BIM)? \n";
      cout << "4. Bantuk prestasi apa saja yang bisa saya ajukan untuk "
              "mendaftar Beasiswa Indonesia Maju (BIM)? \n";
      cout << "5. Apa itu ajang talenta dan non ajang talenta? \n";
      cout << "6. saya memiliki sertifikat atau piagam diluar dari puspresnas, "
              "apakah saya bisa mendaftar? \n";
      cout << "7. Apa sih kurasi talenta itu? \n";
      cout << "8. Jika saya ingin melakukan kurasi bagai mana caranya? \n";
      cout << "9. Apakah perlu sertfikat toefl IBT/IELTS? \n";
      cout << "10. berapa standart minimal IPK untuk pendaftar S2 DN dan LN "
              "disetiap bidang ?\n";
      cout << "\nPilih Pertanyaan : ";
      cin >> pil;
      if (pil == 1) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Apa itu Beasiswa Indonesia Maju (BIM)? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "adalah program beasiswa yang bertujuan memberikan bantuan "
                "pembiayaan pendidikan sarjana (S1 dan S2) sebagai bentuk "
                "penghargaan kepada peserta didik berprestasi sesuai dengan "
                "pengertian dan indikator tentang presetasi yang ditentukan "
                "dalam kebijakan manajemen talenta Pusat Prestasi Nasional "
                "(PUSPRESNAS), dalam rangka pemberian fasilitas karir belajar "
                "talenta \n";
      } else if (pil == 2) {
        cout << "\n\tPertanyaan : \n\n";
        cout
            << "Jenjang apa saja yang ada di Beasiswa Indonesia Maju (BIM)? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "jenjang S1 dan S2 \n";
      } else if (pil == 3) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Siapa sasaran Beasiswa Indonesia Maju (BIM)? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "peserta didik dan lulusan berprestasi \n";
      } else if (pil == 4) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Bantuk prestasi apa saja yang bisa saya ajukan untuk "
                "mendaftar Beasiswa Indonesia Maju (BIM)? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "bentuk prestasi akademis dan non akademis \n";
      } else if (pil == 5) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Apa itu ajang talenta dan non ajang talenta? \n";
        cout << "\n\tJawaban : \n \n";
        cout
            << "ajang talenta yang diselenggarakan atau difasilitasi oleh "
               "Puspresnas sedangkan Non ajang talenta luar Puspresnas yang "
               "telah diakui melalui proses kurasi talenta oleh puspresnas. \n";
      } else if (pil == 6) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "saya memiliki sertifikat atau piagam diluar dari puspresnas, "
                "apakah saya bisa mendaftar? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "bisa, jika telah dilakukan kurasi terlebih dahulu oleh "
                "Puspresnas, untuk lebih jelasnya silakan kunjungi Website "
                "Puspresnas \n";
      } else if (pil == 7) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Apa sih kurasi talenta itu? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "kurasi talenta merupakan proses mengidentifikasi, menilai, "
                "menyimpulkan, dan memberikan pengakuan resmi dari "
                "Kemendikbudristek kepada suatu ajang talenta maupun peserta "
                "didik berprestasi. Hasil kurasi akan masuk pencatatan "
                "Puspresnas dan menjadi bagian dari program Manajemen Talenta. "
                "\n";
      } else if (pil == 8) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Jika saya ingin melakukan kurasi bagai mana caranya? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "silakan kunjungi Website Puspresnas \n";
      } else if (pil == 9) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Apakah perlu sertfikat toefl IBT/IELTS? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "perlu bagi S1 Luar Negeri dan S2 Luar Negeri (umum) \n";
      } else if (pil == 10) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "berapa standart minimal IPK untuk pendaftar S2 DN dan LN "
                "disetiap bidang ? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "3,25 untuk bidang Riset, Teknologi, dan Inovasi dan 2,75 "
                "bidang lainnya \n";
      }
    } else if (pil == 6) {
      cout << "\n\tPTV\n\n";
      cout << "Daftar Pertanyaan : \n";
      cout << "1. Yang belum mempunyai NIDN, NUPN, apakah diperbolehkan "
              "mendaftar pada beasiswa PTV? \n";
      cout << "2. siapa yang mendatangani untuk surat izin pimpinan dan surat "
              "akademik ? \n";
      cout << "3. Jurusan yang saya tuju tidak ada dalam lis PTV, apakah saya "
              "boleh mendaftar melalui program lain ? \n";
      cout << "4. Apakah calon dosen PTV yang belum mempunyai NUP boleh "
              "menggunakan SK saja ? \n";
      cout << "5. Mengapa NIK tidak sesuai dengan PDDIKTI? \n";
      cout << "\nPilih Pertanyaan : ";
      cin >> pil;
      if (pil == 1) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Yang belum mempunyai NIDN, NUPN, apakah diperbolehkan "
                "mendaftar pada beasiswa PTV? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "Harap di daftarkan terlebih dahulu NIDN atau NUP ke pegawaian "
                "perguruan tinggi home base, (tidak mempunyai NIDN dan NUPN "
                "belum bisa mendaftar). \n";
      } else if (pil == 2) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "siapa yang mendatangani untuk surat izin pimpinan dan surat "
                "akademik ? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "a. Untuk politeknik piminan tertinggi direktur b. Untuk "
                "sekolah vokasi boleh dari dekan atau direktur \n";
      } else if (pil == 3) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Jurusan yang saya tuju tidak ada dalam lis PTV, apakah saya "
                "boleh mendaftar melalui program lain ? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "Tidak boleh \n";
      } else if (pil == 4) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Apakah calon dosen PTV yang belum mempunyai NUP boleh "
                "menggunakan SK saja ? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "Tidak boleh, Harap didaftarkan terlebih dahulu NUP "
                "kepegawaian Perguruan Tinggi Homebase \n";
      } else if (pil == 5) {
        cout << "\n\tPertanyaan : \n\n";
        cout << "Mengapa NIK tidak sesuai dengan PDDIKTI? \n";
        cout << "\n\tJawaban : \n \n";
        cout << "Data PDDIKTI sudah disingkron dengan API terbaru dan sudah "
                "bisa mengakomodir perubahan data di PDDIKTI dan di sister \n";
      }
    }
  }

  else if (pil == 2) {
    cout << "\n\tFAQ Umum : \n";
    cout << "Daftar Pertanyaan : \n";
    cout << "1. Apa Itu BPI Kemendikbudristek \n";
    cout << "2. Siapakah Pengelola Program Ini \n";
    cout << "3. Apa saja program yang dapat didanai oleh BPI Kemendikbudristek "
            "\n";
    cout << "4. Program Degree apa saja yang dapat dididanai oleh BPI "
            "Kemendikbudristek \n";
    cout << "5. Program Non Degree apa saja yang dapat dididanai oleh BPI "
            "Kemendikbudristek \n";
    cout << "6. Siapa saja yang berhak untuk mendaftar Beasiswa BPI \n";
    cout << "7. Siapakah sasaran penerima beasiswa Degree S1 \n";
    cout << "8. Siapakah sasaran penerima beasiswa S2  \n";
    cout << "9. Siapakah sasaran penerima beasiswa S3  \n";
    cout << "10. Untuk dapat mendaftar BPI Kemendikbudristek apakah calon "
            "penerima beasiswa harus sudah mendapat LoA terlebih dahulu \n";
    cout << "11. Apakah itu LoA \n";
    cout << "12. LoA seperti apa yang dapat digunakan untuk menaftar Beasiswa "
            "BPI \n";
    cout << "13. LoA Unconditioal sepertia apa yang dianggap valid untuk "
            "mendaftar BPI \n";
    cout << "14. Berapa lamalkah durasi pembiayaan BPI Kemendikbudristek \n";
    cout << "15. Apa saja yang menjadi komponen pendanaan yang diatnggung "
            "dalam BPI\n";
    cout << "16. Untuk penerima beasiswa dengan kebutuhan khusus(disabilitas) "
            "apakah ada dana dukungan lainnya \n";
    cout << "17. Apakah sudah mengunggah LoA Unconditional apakah penerima "
            "beasiswa diperbolehkan untuk mengajukan perpindahan universitas "
            "dan program studi tujuan \n";
    cout << "18. Apakah pendaftaran program beasiswa BPI S2 dan S3 harus "
            "berasal dari Peguruan tinggi dan program studi terakrediatsi \n";
    cout << "19. Apakah mahasiswa On Going yang telah menempuh S1, S2 dan S3 "
            "bisa menerima beasiswa BPI \n";
    cout << "20. Dimanakah saya bisa mendapatkan informasi lebih lanjut "
            "mengenai syarat beasiswa beserta petunjuk pendaftarannya  \n";
    cout << "21. Saya sudah mendaftar namun saya belum bisa login \n";
    cout << "22. NISN tidak terdaftar, padahal di Dapodik sudah Update \n";
    cout << "23. Setelah diabtu aktifasi, saya tetap tidak bisa login \n";
    cout << "24. Saya sudah memilih jenis beasiswa namun perguruan tinggi dan "
            "program studi tujuan tidak ada pada pilihan, padahal tertera pada "
            "list perguruan tunggi dan program studi \n";
    cout << "25. Tidak bisa mengajukan usulan Beasiswa karena data tidak sama "
            "dengan PDDikti/Dapodik \n";
    cout << "26. Ketika melakukan save atau submit terjadi erroe \n";
    cout << "27. Bagaimana jika saya tidak bisa loguin karena lupa password \n";
    cout << "\nPilih Pertanyaan : ";
    cin >> pil;
    if (pil == 1) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Apa Itu BPI Kemendikbudristek \n";
      cout << "\n\tJawaban : \n \n";
      cout << "Beasiswa Pendidikan Indonesia atau disingkat BPI "
              "Kemendikbudristek adalah program beasiswa Kerjasama antara "
              "Lembaga Pengelola Dana Pendidikan (LPDP) dan Kementerian "
              "Pendidikan, Kebudayaan, Riset dan Teknologi melalui program "
              "Perluasan Program LPDP. \n";
    } else if (pil == 2) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Siapakah Pengelola Program Ini \n";
      cout << "\n\tJawaban : \n \n";
      cout
          << "BPI Kemendikbudristek terdiri dari Program Bergelar (Degree) dan "
             "Program Non Gelar (Non Degree). Program Bergelar S1, S2, dan S3 "
             "dikelola oleh Pusat Layanan Pembiayaan Pendidikan (Puslapdik). "
             "Program Non Gelar dikelola oleh masing-masing Unit Pengampu ( "
             "Direktorat dan Pusat yang ada di Lingkungan Kemendikbudristek) "
             "Pengelola Program ini adalah Pusat Layanan Pembiayaan Pendidikan "
             "(PLPP) Sekretariat Jenderal Kemdikbudristek. \n";
    } else if (pil == 3) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Apa saja program yang dapat didanai oleh BPI Kemendikbudristek "
              "\n";
      cout << "\n\tJawaban : \n \n";
      cout << "Melalui Perluasan Program LPDP, BPI mendanai baik Program "
              "Bergelar (Degree) dan Program Non Gelar (Non Degree). \n";
    } else if (pil == 4) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Program Degree apa saja yang dapat dididanai oleh BPI "
              "Kemendikbudristek \n";
      cout << "\n\tJawaban : \n \n";
      cout << "BPI Program Bergelar (Degree) yang dikelola oleh Puslapdik "
              "mendanai Pembiayaan Beasiswa untuk S1/D4, S2 single degree, S2 "
              "Double/Joint Degree, S3 Single Degree, dan S3 Double/Joint "
              "Degree \n";
    } else if (pil == 5) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Program Non Degree apa saja yang dapat dididanai oleh BPI "
              "Kemendikbudristek \n";
      cout << "\n\tJawaban : \n \n";
      cout << "Untuk Program Non Gelar (Non Degree) silahkan kunjungi laman "
              "informasi pada masing-masing Unit Pengampu ( Direktorat dan "
              "Pusat yang ada di Lingkungan Kemendikbudristek) Bermacam macam "
              "program non degree didanai melalui perluasan program LPDP, "
              "mulai dari kampus mengajar, magang bersertifikat, pertukaran "
              "mahasiswa, peningkatan kompetensi untuk guru, dosen dan "
              "mahasiswa melalui berbagai macam shortcourse, serta berbagai "
              "macam program untuk dosen dan tenaga pendidik melalui "
              "pertukaran dosen. Adapun program non degree tersebut tidak "
              "dikelola oleh Puslapdik namun dikelola dan disalurkan melalui "
              "masing masing unit pengampu yaitu Direktorat Jenderal "
              "Pendidikan Tinggi (DIKTI), Direktorat Jenderal Guru dan Tenaga "
              "Pendidikan (GTK), Direktorat Jenderal Pendidikan Vokasi, dan "
              "Direktorat Jenderal Kebudayaan. \n";
    } else if (pil == 6) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Siapa saja yang berhak untuk mendaftar Beasiswa BPI \n";
      cout << "\n\tJawaban : \n \n";
      cout << "Semua Warga Negara Indonesia yang memenuhi ketentuan "
              "persyaratan BPI, terutama untuk siswa Calon Guru SMK, siswa dan "
              "Mahasiswa Berprestasi, Guru, Dosen, Tenaga Kependidikan dan "
              "Pelaku Budaya \n";
    } else if (pil == 7) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Siapakah sasaran penerima beasiswa Degree S1 \n";
      cout << "\n\tJawaban : \n \n";
      cout << "Calon Guru SMK, Pelaku Budaya dan Siswa berprestasi. \n";
    } else if (pil == 8) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Siapakah sasaran penerima beasiswa S2  \n";
      cout << "\n\tJawaban : \n \n";
      cout
          << "Dosen yang memiliki NUP (Nomer Urut Pendidik), Calon Dosen pada "
             "PTNB (Perguruan Tinggi Negeri Baru), Tenaga kependidikan pada "
             "Perguruan Tinggi Negeri Pendidikan Akademik/ Vokasi dan Tenaga "
             "Kependidikan pada Direktorat Jenderal Pendidikan Tinggi, Riset, "
             "dan Teknologi, Direktorat Jenderal Pendidikan Vokasi di "
             "Lingkungan Kemendikbudristek, Pelaku Budaya, Guru/ Pendidik dan "
             "Tenaga Kependidikan pada satuan pendidikan formal dan non formal "
             "di lingkungan Kemendikbudristek, dan mahasiswa berprestasi. \n";
    } else if (pil == 9) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Siapakah sasaran penerima beasiswa S3  \n";
      cout << "\n\tJawaban : \n \n";
      cout << "Dosen perguruan tinggi akademik, Dosen perguruan tinggi vokasi, "
              "Tenaga kependidikan pada Perguruan Tinggi Negeri Pendidikan "
              "Akademik/ Vokasi dan Tenaga Kependidikan pada Direktorat "
              "Jenderal Pendidikan Tinggi, Riset, dan Teknologi, Direktorat "
              "Jenderal Pendidikan Vokasi di Lingkungan Kemendikbudristek, "
              "Guru/ Pendidik dan Tenaga Kependidikan pada satuan pendidikan "
              "formal dan non formal di lingkungan Kemendikbudristek, Dosen "
              "pendidikan profesi Guru, Pelaku Budaya dan dosen/peneliti atau "
              "calon dosen/peneliti fakultas kedokteran di Indonesia. \n";
    } else if (pil == 10) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Untuk dapat mendaftar BPI Kemendikbudristek apakah calon "
              "penerima beasiswa harus sudah mendapat LoA terlebih dahulu \n";
      cout << "\n\tJawaban : \n \n";
      cout << "Betul, untuk dapat mendaftar BPI, calon penerima beasiswa wajib "
              "mendapatka LoA/ Surat diterima pada Perguruan Tinggi tujuan "
              "studi terlebih dahulu. \n";
    } else if (pil == 11) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Apakah itu LoA \n";
      cout << "\n\tJawaban : \n \n";
      cout << "LoA adalah Letter of Acceptance yaitu surat resmi dari "
              "Perguruan Tinggi yang menyatakan bahwa seseorang telah diterima "
              "di Perguruan Tinggi\n";
    } else if (pil == 12) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "LoA seperti apa yang dapat digunakan untuk menaftar Beasiswa "
              "BPI \n";
      cout << "\n\tJawaban : \n \n";
      cout << "LoA yang dapat digunakan untuk mendaftar Beasiswa BPI adalah "
              "sebagai berikut:";
      cout << "\nLoA Unconditional\n";
      cout << "Untuk Luar Negeri, LoA Unconditional adalah Surat resmi yang "
              "dikeluarkan oleh Universitas yang menyatakan bahwa calon "
              "mahasiswa telah memenuhi kriteria dan dinyatakan lulus diterima "
              "di perguruan tinggi tersebut tanpa ada syarat tambahan apapun "
              "lagi. Pada umumnya LoA Unconditional mencantumkan informasi "
              "mengenai Universitas, program studi (school), dan durasi studi "
              "Untuk Dalam Negeri, LoA Uncoditional berupa Surat Keputusan "
              "Rektor, Surat Keputusan Panita Seleksi Penerimaan Mahasiswa "
              "Baru atau Surat Keputusan Direktur Pasca Sarjana Universitas";
      cout << "\nLoA Conditional\n";
      cout << "LoA Conditional adalah Surat resmi yang dikeluarkan oleh "
              "Universitas yang menyatakan bahwa calon mahasiswa diterima di "
              "Perguruan Tinggi tersebut pada fakultas/jurusan/prodi tertentu "
              "dengan syarat harus segera memenuhi beberapa persyaratan yang "
              "ditentukan. Pada umumnya persyaratan yang disebutkan di LoA "
              "Conditional adalah persyaratan kompetensi Bahasa (IELTS, TOEFL, "
              "CEFR, dll), syarat pemenuhan/keikutsertaan dan lulus kelas "
              "matrikulasi, syarat submission dokumen fisik ijazah akademik "
              "pada jenjang sebelumnya dan atau syarat pemenuhan ketersediaan "
              "dana (sponsor dana) Dalam hal LoA Conditional, BPI dapat "
              "menerima LoA Conditional untuk persyaratan sponsor pendanaan, "
              "submission dokumen fisik ijazah dan transkrip jenjang "
              "sebelumnya dan atau persyaratan tambahan yang tidak beresiko "
              "mengubah status diterimanya calon tersebut sebagai mahasiswa "
              "pada program studi yang dituju serta memuat nama lengkap, "
              "jenjang studi, program studi, serta durasi studi, permulaan "
              "studi dan/atau akhir studi.\n";
    } else if (pil == 13) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "LoA Unconditioal sepertia apa yang dianggap valid untuk "
              "mendaftar BPI \n";
      cout << "\n\tJawaban : \n \n";
      cout << "Perguruan Tinggi dan Program Studi harus sesuai dengan salah "
              "satu pilihan pada aplikasi pendaftaran\n ";
      cout << "Intake studi harus memenuhi ketentuan yang ditetapkan oleh BPI "
              "terkait waktu perkuliahan yang diizinkan\n";
      cout << "Jika intake perkuliahan yang terncantum pada LoA Unconditional "
              "yang diunggah tidak sesuai ketentuan maka wajib melampirkan "
              "Surat Defeer (Penundaan Studi) pada Perguruan Tinggi yang "
              "menerbitkan LoA \n";
      cout << "Jika pendaftar mengunggah LoA Unconditional yang tidak sesuai "
              "ketentuan BPI, maka dianggap tidak memenuhi kriteria "
              "pendaftaran \n";
    } else if (pil == 14) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Berapa lamalkah durasi pembiayaan BPI Kemendikbudristek \n";
      cout << "\n\tJawaban : \n \n";
      cout << "Durasi maksimal pembiayaan beasiswa untuk masing masing jenjang "
              "adalah sebagai berikut: \n";
      cout << "D4/S1 maksimal 48 bulan atau 4 tahun \n";
      cout << "S2 (Magister) maksimal 24 bulan atau 2 tahun \n ";
      cout << "S3 (Doktoral) maksimal 48 bulan atau 4 tahun\n";
    } else if (pil == 15) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Apa saja yang menjadi komponen pendanaan yang diatnggung dalam "
              "BPI\n";
      cout << "\n\tJawaban : \n \n";
      cout << "   Dana Pendidikan \n";
      cout << "Dana SPP (Tuition Fee) \n";
      cout << "Dana Pendaftaran \n";
      cout << "Dana Tunjangan Buku \n";
      cout << "Dana Tunjangan Buku \n";
      cout << "Dana Bantuan Seminar Internasional \n";
      cout << "Dana Bantuan Seminar Internasional \n";
      cout << "   Biaya Pendukung \n";
      cout << "Dana Transportasi \n";
      cout << "Dana Aplikasi Visa \n";
      cout << "Dana Asuransi Kesehatan \n";
      cout << "Dana Kedatangan \n";
      cout << "Dana Hidup Bulanan \n";
      cout << "Dana Keadaan Darurat (Force Majeure) \n";
      cout << "Dana Tunjangan Keluarga \n";
    } else if (pil == 16) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Untuk penerima beasiswa dengan kebutuhan khusus(disabilitas) "
              "apakah ada dana dukungan lainnya \n";
      cout << "\n\tJawaban : \n \n";
      cout
          << "Ada, penerima beasiswa dengan kebutuhan khusus (disabilitas) "
             "dapat memperoleh tambahan biaya pendukung sebagai berikut: Dana "
             "Aplikasi Visa Pendamping, Dana Transportasi Pendamping, Dana "
             "Asuransi Kesehatan Pendamping, Dana Tunjangan bagi Pendamping \n";
    } else if (pil == 17) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Apakah sudah mengunggah LoA Unconditional apakah penerima "
              "beasiswa diperbolehkan untuk mengajukan perpindahan universitas "
              "dan program studi tujuan \n";
      cout << "\n\tJawaban : \n \n";
      cout << "Perubahan Universitas dan Program tujuan studi diperkenankan "
              "apabilan memenuhi beberapa persyaratan force majeur sebagai "
              "berikut: \n";
      cout << "a) Sudah dinyatakan sebagai penerima beasiswa \n";
      cout << "b) Belum dilakukan pembayaran apapun atas universitas/prodi "
              "tujuan sebelumnya \n";
      cout << "c) Penerima beasiswa belum memulai studi di universitas/prodi "
              "sebelumnya \n ";
      cout << "d) Penerima beasiswa tidak berhasil mendapatkan visa "
              "dikarenakan alasan Kesehatan \n";
      cout << "e) Negara tujuan studi belum membuka border untuk mahasiswa "
              "internasional dengan alasan pandemic ataupun alasan lainnya \n";
      cout << "f) Penerima beasiswa mengalami sakit yang atas pertimbangan "
              "dokter disarankan untuk studi di dalam negeri agar perawatan "
              "lebih intensif dan dukungan keluarga lebih dekat \n";
    } else if (pil == 18) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Apakah pendaftaran program beasiswa BPI S2 dan S3 harus berasal "
              "dari Peguruan tinggi dan program studi terakrediatsi \n";
      cout << "\n\tJawaban : \n \n";
      cout << "Iya, minimal program studi dan perguruan tinggi asal "
              "terakreditasi B atau Baik Sekali. \n";
    } else if (pil == 19) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Apakah mahasiswa On Going yang telah menempuh S1, S2 dan S3 "
              "bisa menerima beasiswa BPI \n";
      cout << "\n\tJawaban : \n \n";
      cout << "Tidak bisa, kecuali penerima beasiswa Calon Guru SMK dan S3 "
              "Dosen Perguruan Tinggi Akademik (Dalam Negeri) yang telah "
              "diterima pada semester genap tahun ajaran 2021/2022. \n";
    } else if (pil == 20) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Dimanakah saya bisa mendapatkan informasi lebih lanjut mengenai "
              "syarat beasiswa beserta petunjuk pendaftarannya  \n";
      cout << "\n\tJawaban : \n \n";
      cout << "Silahkan mengakses beasiswa.kemdikbud.go.id/informasi \n";
    } else if (pil == 21) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Saya sudah mendaftar namun saya belum bisa login \n";
      cout << "\n\tJawaban : \n \n";
      cout << "Pastikan saudara telah mendapatkan email aktifasi, jika tidak "
              "mendapat email aktifasi, Saudara dapat menghubungi helpdesk "
              "(chat pada laman) untuk dibantu aktifasi dengan menginfokan NIK "
              "dan alamat email. \n";
    } else if (pil == 22) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "NISN tidak terdaftar, padahal di Dapodik sudah Update \n";
      cout << "\n\tJawaban : \n \n";
      cout << "Untuk NISN sedang dalam pengembangan silahkan dicoba secara "
              "berkala. \n";
    } else if (pil == 23) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Setelah dibantu aktifasi, saya tetap tidak bisa login \n";
      cout << "\n\tJawaban : \n \n";
      cout << "Pastikan Saudara Log in menggunakan NIK dikolom username, dan "
              "masukkan password yang Saudara buat di kolom password, pastikan "
              "pengisian captcha sudah benar dengan masukan hasil pertambahan "
              "capcha. \n";
    } else if (pil == 24) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Saya sudah memilih jenis beasiswa namun perguruan tinggi dan "
              "program studi tujuan tidak ada pada pilihan, padahal tertera "
              "pada list perguruan tunggi dan program studi \n";
      cout << "\n\tJawaban : \n \n";
      cout
          << "Silahkan melapor melalui Email helpdesk-beasiswa@kemdikbud.go.id "
             "dengan menginformasikan Nama Lengkap, NIK, Jenis Beasiswa yang "
             "dipilih, Nama Perguruan Tinggi, dan Progran Studi tujuan, serta "
             "dapat dilengkapi dengan Screenshot sistem. \n";
    } else if (pil == 25) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Tidak bisa mengajukan usulan Beasiswa karena data tidak sama "
              "dengan PDDikti/Dapodik \n";
      cout << "\n\tJawaban : \n \n";
      cout << "Harap diperhatikan data yang diisi pada aplikasi BPI diharapkan "
              "sudah sesuai dengan PDDIKTI/ Dapodik. \n";
    } else if (pil == 26) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Ketika melakukan save atau submit terjadi error \n";
      cout << "\n\tJawaban : \n \n";
      cout
          << "Silahkan melapor melalui Email helpdesk-beasiswa@kemdikbud.go.id "
             "dengan menginformasikan Nama Lengkap, penjelasan permasalahan, "
             "serta dilengkapi dengan Screenshot sistem. \n";
    } else if (pil == 27) {
      cout << "\n\tPertanyaan : \n\n";
      cout << "Bagaimana jika saya tidak bisa loguin karena lupa password \n";
      cout << "\n\tJawaban : \n \n";
      cout << "Silahkan melapor melalui helpdesk (chat pada laman) atau Email "
              "helpdesk-beasiswa@kemdikbud.go.id dengan menginformasikan Nama "
              "Lengkap, NIK, alamat email, dan password terbaru. \n";
    }
  }
}