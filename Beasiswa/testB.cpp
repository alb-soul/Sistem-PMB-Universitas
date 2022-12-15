#include <iostream>
#include "../array1d.h"

int main() {

  Array1D<string> antrian(5);

  string x;

  try {
  antrian.enqueue("Si Anat");
  antrian.cetakAntrian();
  antrian.enqueue("si Dul");
  antrian.cetakAntrian();
  antrian.enqueue("si Lipo");
  antrian.cetakAntrian();
  antrian.enqueue("si Mbah");
  antrian.cetakAntrian();
  antrian.enqueue("si Kamee");
  antrian.cetakAntrian();
  antrian.enqueue("si Hima");
  antrian.cetakAntrian();
  antrian.enqueue("si Siap");
  antrian.cetakAntrian();
  } catch(NoMem) {
    cout << "\n\e[1;31mAntrian penuh!\e[0m\n";
  }

  //3 orang keluar antrian
  for (int i=1;i<=3;i++) {
    antrian.dequeue(x);
    cout << "\n" << x << " keluar antrian\n";
    antrian.cetakAntrian();
  }

  antrian.enqueue("Si Sombul");
  antrian.cetakAntrian();

  //semua orang keluar antrian
  try {
    for (int i=1;i<=7;i++) {
      antrian.dequeue(x);
      cout << "\n" << x << " keluar antrian\n";
      antrian.cetakAntrian();
    }
  } catch(OutOfBounds) {
    cout << "\n\e[1;31mAntrian sudah kosong!\e[0m\n";
  }

  cout << "Kosong? " << antrian.isEmptyQueue() << endl;
  return 0;
}