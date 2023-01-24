#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include "splashScreeen.cpp"
#include <vector>
#include <bits/stdc++.h>
using namespace std;

float b[25], c[25], d[25], e[25];
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
    float random = rand() % 13 + 1;
    return random;
}

void addArray(float k, float l, float m, float n, int &N){
    int i;
    bool found;
    found = false;
    i = 0;
    if (k==l && k==m && k==n){
        found = false;
    }
    while (i <= N && found == false){
        if (k == b[i] && l == c[i] && m == d[i] && n == e[i]){
            found = true;
        }
        else{
            i += 1;
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

void writeFile(vector <string> forPrint, string nama, int w, int x, int y, int z, double waktu, int count){
    ofstream file("./test/"+ nama + ".txt");
    file << "Daftar kartu : " << w << " " << x << " " << y << " " << z << endl;
    file << "________________________________" << endl;
    file << count << " Solution(s) found." << endl;
    file << "Time required: " << waktu << " seconds" << endl;
    file << "________________________________" << endl;
    file << "Jawaban: " << endl;
    if (count > 0){
        for (int i = 0; i < forPrint.size(); i++){
            file << forPrint[i] << endl;
        }
    }
    file.close();
}

void buatKombinasi(float w, float x, float y, float z, int &N){
    float siapPermutasi[] = {w, x, y, z};
    int ukuran = 4;
    for (int i=0; i<ukuran; i++){
        for (int j=0; j<ukuran; j++){
            for (int k=0; k<ukuran; k++){
                for (int l=0; l<ukuran; l++){
                    if (i != j && i != k && i != l && j != k && j != l && k != l){
                        addArray(siapPermutasi[i], siapPermutasi[j], siapPermutasi[k], siapPermutasi[l], N);
                    }
                }
            }
        }
    }
}


void menu(){
    int N = 0;
    int pilihan;
    cout <<"Anda dapat memasukkan 4 angka (2-10) dan huruf (A,J,K,Q) atau membuatnya secara random" << endl;
    cout <<"1. memasukkan angka/huruf" << endl;
    cout <<"2. membuat angka/huruf secara random" << endl;
    cout <<"___________________________________________" << endl;
    cout <<"Masukkan pilihan anda : ";
    cin >> pilihan;
    while (pilihan != 1 && pilihan != 2){
        cout << "_______________________" << endl;
        cout << "Masukkan angka 1 atau 2" << endl;
        cout <<"Masukkan pilihan anda : ";
        cin >> pilihan;
    }
    string a1, a2, a3, a4;
    float w,x,y,z;
    if(pilihan == 1){
        cout << "Masukkan 4 angka/huruf" << endl;
        cin >> a1 >> a2 >> a3 >> a4;
        while(tepat(a1) == false || tepat(a2) == false || tepat(a3) == false || tepat(a4) == false){
            cout << "_______________________" << endl;
            cout << "Masukan salah!" << endl;
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
    cout << "anda memasukkan angka [" << w << " " << x << " " << y << " " << z << "]" << endl;
    buatKombinasi(w,x,y,z,N);


    string ops[64] = {"+++", "++-", "++*", "++/", "+-+", "+--", "+-*", "+-/", "+*+", "+*-", "+**", "+*/", "+/+", "+/-", "+/*", "+//", "-++", "-+-", "-+*", "-+/", "--+", "---", "--*", "--/", "-*+", "-*-", "-**", "-*/", "-/+", "-/-", "-/*", "-//", "*++", "*+-", "*+*", "*+/", "*-+", "*--", "*-*", "*-/", "**+", "**-", "***", "**/", "*/+", "*/-", "*/*", "*//", "/++", "/+-", "/+*", "/+/", "/-+", "/--", "/-*", "/-/", "/*+", "/*-", "/**", "/*/", "//+", "//-", "//*", "///"};
    //pewaktu
    auto start = chrono::high_resolution_clock::now();
    int count = 0;
    //kita mulai algoritmanya
    for (int i=1;i<=N;i++){
        for (int j=0; j<64;j++){
            //((b+c)+d)+e
            float uji1 = operasi(operasi(operasi(b[i], ops[j][0], c[i]), ops[j][1], d[i]), ops[j][2], e[i]);
            if(abs(uji1-24) == 0){
                hasil = "((" + to_string(int(b[i])) + ops[j][0] + to_string(int(c[i])) + ")" + ops[j][1] + to_string(int(d[i])) + ")" + ops[j][2] + to_string(int(e[i])) + "";
                forPrint.push_back(hasil);
                count += 1;}
            // (b+(c+d))+e
            float uji2 = operasi(operasi(b[i], ops[j][0], operasi(c[i], ops[j][1], d[i])), ops[j][2], e[i]);
            if(abs(uji2-24) == 0){
                hasil = "(" + to_string(int(b[i])) + ops[j][0] + "(" + to_string(int(c[i])) + ops[j][1] + to_string(int(d[i])) + "))" + ops[j][2] + to_string(int(e[i])) + "";
                forPrint.push_back(hasil);
                count += 1;}
            // b+((c+d)+e)
            float uji3 = operasi(b[i], ops[j][0], operasi(operasi(c[i], ops[j][1], d[i]), ops[j][2], e[i]));
            if(abs(uji3-24) == 0){
                hasil =  to_string(int(b[i])) + ops[j][0] + "((" + to_string(int(c[i])) + ops[j][1] + to_string(int(d[i])) + ")" + ops[j][2] + to_string(int(e[i])) + ")";
                forPrint.push_back(hasil);
                count += 1;}
            // b+(c+(d+e))
            float uji4 = operasi(b[i], ops[j][0], operasi(c[i], ops[j][1], operasi(d[i], ops[j][2], e[i])));
            if(abs(uji4-24) == 0){
                hasil =  to_string(int(b[i])) + ops[j][0] + "(" + to_string(int(c[i])) + ops[j][1] + "(" + to_string(int(d[i])) + ops[j][2] + to_string(int(e[i])) + "))";
                forPrint.push_back(hasil);
                count += 1;}
            // (b+c)+(d+e)
            float uji5 = operasi(operasi(b[i], ops[j][0], c[i]), ops[j][1], operasi(d[i], ops[j][2], e[i]));
            if(abs(uji5-24) == 0){
                hasil =  "(" + to_string(int(b[i])) + ops[j][0] + to_string(int(c[i])) + ")" + ops[j][1] + "(" + to_string(int(d[i])) + ops[j][2] + to_string(int(e[i])) + ")";
                forPrint.push_back(hasil);
                count += 1;}
            
        }
    }
    //print hasil
    cout << "___________________________________________" << endl;

    if (count == 0) {
        cout << "Tidak ada solusi" << endl;
    }
    else{
        cout << "Telah ditemukan " << count << " solusi" << endl;
        cout << "___________________________________________" << endl;
        cout << "Hasil pencarian: " << endl;
        for (size_t i = 0; i < forPrint.size(); i++) {
            cout << forPrint[i] << endl;
        }
    }

    cout <<"___________________________________________" << endl;


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
        writeFile(forPrint, namaFile, w, x, y, z, time_taken, count);
        cout << "File " << namaFile << ".txt berhasil disimpan!" << endl;
        
    }

    //pewaktu
    auto end2 = chrono::high_resolution_clock::now();
    double time_taken2 = chrono::duration_cast<chrono::nanoseconds>(end2 - start).count();
    time_taken2 *= 1e-9;
    cout << "Waktu eksekusi program : " << time_taken2 << setprecision(9);
    cout << " detik" << endl;
}

int main(){
    system("CLS");
    char restart;
    auto mulai = chrono::high_resolution_clock::now();
    do{
        forPrint.clear();
        splashScreen();
        menu();
        cout << "Apakah anda ingin mencoba kembali? (y/n): ";
        cin >> restart;
        system("CLS");
    } while(restart == 'y');
    splashScreen();
    auto selesai = chrono::high_resolution_clock::now();
    double waktu = chrono::duration_cast<chrono::nanoseconds>(selesai - mulai).count();
    waktu *= 1e-9;
    cout << "Waktu program berjalan : " << waktu << setprecision(9);
    cout << " detik" << endl;
    cout << "Terima kasih telah menggunakan program ini" << endl;
    cout << "__________________________________________" << endl;
    getchar();
    return 0;
    }