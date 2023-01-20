#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include "splashScreeen.cpp"
#include <vector>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

float b[25], c[25], d[25], e[25];
int N = 0;
vector <string> forPrint;
string hasil;

bool tepat(string a){
    if(a == "A" || a == "2" || a == "3" || a == "4" || a == "5" || a == "6" || a == "7" || a == "8" || a == "9" || a == "10" || a == "J" || a == "Q"|| a == "K"){
        return true;
    }
    else{
        return false;
    }
}

float ubah(string a){
    if (a == "A"){
        return 1.0;
    }
    else if (a == "J"){
        return 11.0;
    }
    else if (a == "Q"){
        return 12.0;
    }
    else if (a == "K"){
        return 13.0;
    }
    else{
        return stof(a);
    }
    return 0;

}

int randomGenerator(){
    // srand(time(0));
    float random = rand() % 13 + 1;
    return random;
}

void addArray(float k, float l, float m, float n){
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

float operasi(float a, char ops, float b){
    if (ops == '+'){
        return a+b;
    }
    else if (ops == '-'){
        return a-b;
    }
    else if (ops == '*'){
        return a*b;
    }
    else if (ops == '/'){
        return a/b;
    }
    return 0;
}

void writeFile(vector <string> forPrint, string nama, int w, int x, int y, int z){
    ofstream file("./test/"+ nama + ".txt");
    file << "Daftar kartu : " << w << " " << x << " " << y << " " << z << endl;
    file << "____________________________" << endl;
    file << forPrint.size() << " Solution(s) found." << endl;
    file << "____________________________" << endl;
    file << "Jawaban: " << endl;
    for (int i = 0; i < forPrint.size(); i++){
        file << forPrint[i] << endl;
    }
    file.close();
}

void buatKombinasi(int w, int x, int y, int z){
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
}


int main(){
    int pilihan;
    splashScreen();
    cout <<"Anda dapat memasukkan 4 angka (2-10) dan huruf (A,J,K,Q) atau membuatnya secara random" << endl;
    // cout <<"" << endl;
    cout <<"1. memasukkan angka/huruf" << endl;
    cout <<"2. membuat angka/huruf secara random" << endl;
    cout <<"___________________________________________" << endl;
    cout <<"Masukkan pilihan anda : ";
    cin >> pilihan;
    while (pilihan != 1 && pilihan != 2){
        cout << "Masukkan angka 1 atau 2" << endl;
        cin >> pilihan;
    }
    string a1, a2, a3, a4;
    float w,x,y,z;
    if(pilihan == 1){
        cout << "Masukkan 4 angka/huruf" << endl;
        cin >> a1 >> a2 >> a3 >> a4;
        while(tepat(a1) == false || tepat(a2) == false || tepat(a3) == false || tepat(a4) == false){
            cout << "Masukkan 4 angka/huruf" << endl;
            cin >> a1 >> a2 >> a3 >> a4;
        }
        w = ubah(a1);
        x = ubah(a2);
        y = ubah(a3);
        z = ubah(a4);
        
    }
    else if(pilihan == 2){
        srand(time(0));
        w = rand() % 13 + 1;
        x = rand() % 13 + 1;
        y = rand() % 13 + 1;
        z = rand() % 13 + 1;
    }
    cout << "anda memasukkan angka " << w << " " << x << " " << y << " " << z << endl;

    buatKombinasi(w,x,y,z);

    string ops[64] = {"+++", "++-", "++*", "++/", "+-+", "+--", "+-*", "+-/", "+*+", "+*-", "+**", "+*/", "+/+", "+/-", "+/*", "+//", "-++", "-+-", "-+*", "-+/", "--+", "---", "--*", "--/", "-*+", "-*-", "-**", "-*/", "-/+", "-/-", "-/*", "-//", "*++", "*+-", "*+*", "*+/", "*-+", "*--", "*-*", "*-/", "**+", "**-", "***", "**/", "*/+", "*/-", "*/*", "*//", "/++", "/+-", "/+*", "/+/", "/-+", "/--", "/-*", "/-/", "/*+", "/*-", "/**", "/*/", "//+", "//-", "//*", "///"};

    //pewaktu
    auto start = chrono::high_resolution_clock::now();

    int count = 0;
    //kita mulai algoritmanya
    for (size_t i=1;i<N;i++){
        for (int j=0; j<64;j++){
            //((b+c)+d)+e
            int uji1 = operasi(operasi(operasi(b[i], ops[j][0], c[i]), ops[j][1], d[i]), ops[j][2], e[i]);
            if(abs(uji1-24) == 0){
                hasil = "((" + to_string(int(b[i])) + ops[j][0] + to_string(int(c[i])) + ")" + ops[j][1] + to_string(int(d[i])) + ")" + ops[j][2] + to_string(int(e[i])) + "";
                forPrint.push_back(hasil);
                count += 1;}
            // (b+(c+d))+e
            int uji2 = operasi(operasi(b[i], ops[j][0], operasi(c[i], ops[j][1], d[i])), ops[j][2], e[i]);
            if(abs(uji2-24) == 0){
                hasil = "(" + to_string(int(b[i])) + ops[j][0] + "(" + to_string(int(c[i])) + ops[j][1] + to_string(int(d[i])) + "))" + ops[j][2] + to_string(int(e[i])) + "";
                forPrint.push_back(hasil);
                count += 1;}
            // b+((c+d)+e)
            int uji3 = operasi(b[i], ops[j][0], operasi(operasi(c[i], ops[j][1], d[i]), ops[j][2], e[i]));
            if(abs(uji3-24) == 0){
                hasil =  to_string(int(b[i])) + ops[j][0] + "((" + to_string(int(c[i])) + ops[j][1] + to_string(int(d[i])) + ")" + ops[j][2] + to_string(int(e[i])) + ")";
                forPrint.push_back(hasil);
                count += 1;}
            // b+(c+(d+e))
            int uji4 = operasi(b[i], ops[j][0], operasi(c[i], ops[j][1], operasi(d[i], ops[j][2], e[i])));
            if(abs(uji4-24) == 0){
                hasil =  to_string(int(b[i])) + ops[j][0] + "(" + to_string(int(c[i])) + ops[j][1] + "(" + to_string(int(d[i])) + ops[j][2] + to_string(int(e[i])) + "))";
                forPrint.push_back(hasil);
                count += 1;}
            // (b+c)+(d+e)
            int uji5 = operasi(operasi(b[i], ops[j][0], c[i]), ops[j][1], operasi(d[i], ops[j][2], e[i]));
            if(abs(uji5-24) == 0){
                hasil =  "(" + to_string(int(b[i])) + ops[j][0] + to_string(int(c[i])) + ")" + ops[j][1] + "(" + to_string(int(d[i])) + ops[j][2] + to_string(int(e[i])) + ")";
                forPrint.push_back(hasil);
                count += 1;}
            
        }
    }

    //print hasil
    for (size_t i = 0; i < forPrint.size(); i++) {
        cout << forPrint[i] << endl;
    }
    cout <<"___________________________________________" << endl;
    if (count == 0) {
        cout << "Tidak ada solusi" << endl;
    }
    else{
        cout << "Telah ditemukan " << count << " solusi" << endl;
    }

    //pewaktu
    auto end1 = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end1 - start).count();
    time_taken *= 1e-9;
    cout << "Waktu pencarian jawaban : " << time_taken << setprecision(9);
    cout << " detik" << endl;

    char pil; 
    cout << "" << endl;
    cout << "Apakah anda ingin menyimpan hasil pencarian ke dalam file? (y/n): ";
    cin >> pil;

    if (pil == 'y') {
        cout << "Masukkan nama file: ";
        string namaFile;
        cin >> namaFile;
        writeFile(forPrint, namaFile, w, x, y, z);
        cout << "File berhasil disimpan" << endl;
        
    }

    //pewaktu
    auto end2 = chrono::high_resolution_clock::now();
    double time_taken2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start).count();
    time_taken2 *= 1e-9;
    cout << "Waktu eksekusi program : " << time_taken2 << setprecision(9);
    cout << " detik" << endl;

    cout << "Terima kasih telah menggunakan program ini" << endl;
}