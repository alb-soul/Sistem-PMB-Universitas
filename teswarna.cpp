#include <iostream>
#include "065.h"
#include "069.h"
#include "076.h"


#define red "\e[1;31m"
#define green "\e[1;32m"
#define endcolor "\e[0m"

BinaryTree<string> leaf, ketua, anggota1, anggota2;

int main() {
    string str = "Hello";
    ketua.MakeTree(red+str+endcolor, anggota1, anggota2);
    ketua.InOutput();

    return 0;
}