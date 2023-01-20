#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <ctime>
#include "splashScreeen.cpp"

int b[25], c[25], d[25], e[25];
int N = 0;

bool tepat(std::string a){
    if(a == "A" || a == "2" || a == "3" || a == "4" || a == "5" || a == "6" || a == "7" || a == "8" || a == "9" || a == "10" || a == "J" || a == "Q"|| a == "K"){
        return true;
    }
    else{
        return false;
    }
}

int ubah(std::string a){
    if (a == "A"){
        return 1;
    }
    else if (a == "J"){
        return 11;
    }
    else if (a == "Q"){
        return 12;
    }
    else if (a == "K"){
        return 13;
    }
    else{
        std::stoi(a);
    }
    return 0;
}

int randomGenerator(){
    // std::srand(std::time(0));
    int random = std::rand() % 13 + 1;
    return random;
}

void addArray(int k, int l, int m, int n){
    int i;
    bool found;
    found = false;
    i = 1;
    while (i <= N && found == false){
        if (k == b[i] && l == c[i] && m == d[i] && n == e[i]){
            found = true;
        }
        else{
            i++;
        }
    }
    if (found == false){
        N = N+1;
        b[N] = k;
        c[N] = l;
        d[N] = m;
        e[N] = n;
    }
}

int count = 0;



int main(){
    int pilihan;
    splashScreen();
    std::cout <<"Anda dapat memasukkan 4 angka (2-10) dan huruf (A,J,K,Q) atau membuatnya secara random" << std::endl;
    // std::cout <<"" << std::endl;
    std::cout <<"1. memasukkan angka/huruf" << std::endl;
    std::cout <<"2. membuat angka/huruf secara random" << std::endl;
    std::cout <<"" << std::endl;
    std::cout <<"Masukkan pilihan anda : ";
    std::cin >> pilihan;
    while (pilihan != 1 && pilihan != 2){
        std::cout << "Masukkan angka 1 atau 2" << std::endl;
        std::cin >> pilihan;
    }
    std::string a1, a2, a3, a4;
    int w,x,y,z;
    if(pilihan == 1){
        std::cout << "Masukkan 4 angka/huruf" << std::endl;
        std::cin >> a1 >> a2 >> a3 >> a4;
        while(tepat(a1) == false || tepat(a2) == false || tepat(a3) == false || tepat(a4) == false){
            std::cout << "Masukkan 4 angka/huruf" << std::endl;
            std::cin >> a1 >> a2 >> a3 >> a4;
        }
        w = ubah(a1);
        x = ubah(a2);
        y = ubah(a3);
        z = ubah(a4);
        
    }
    else if(pilihan == 2){
        std::srand(std::time(0));
        w = std::rand() % 13 + 1;
        x = std::rand() % 13 + 1;
        y = std::rand() % 13 + 1;
        z = std::rand() % 13 + 1;
    }
    std::cout << "anda memasukkan angka " << w << " " << x << " " << y << " " << z << std::endl;

    addArray(w, x, y, z);
    addArray(w, x, z, y);
    addArray(w, y, x, z);
    addArray(w, y, z, x);
    addArray(w, z, x, y);
    addArray(w, z, y, x);
    addArray(x, w, y, z);
    addArray(x, w, z, y);
    addArray(x, y, w, z);
    addArray(x, y, z, w);
    addArray(x, z, w, y);
    addArray(x, z, y, w);
    addArray(y, w, x, z);
    addArray(y, w, z, x);
    addArray(y, x, w, z);
    addArray(y, x, z, w);
    addArray(y, z, w, x);
    addArray(y, z, x, w);
    addArray(z, w, x, y);
    addArray(z, w, y, x);
    addArray(z, x, w, y);
    addArray(z, x, y, w);
    addArray(z, y, w, x);
    addArray(z, y, x, w);

    for (size_t i = 0; i < N; i++) {
        std::cout << b[i] << "" << c[i] << "" << d[i] << "" << e[i] << ' ' << std::endl;
    }
    std::cout<< N << std::endl;


    std::cout << count << std::endl;
}