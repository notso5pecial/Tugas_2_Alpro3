#include <iostream>
using namespace std;

int main(){
    float gaji_ortu, ipk; // deklarasi variabel untuk menyimpan gaji orang tua dan IPK

    cout<<"kelayakan menerima beasiswa"<<endl;  // menampilkan judul program
    cout<<"masukkan gaji orang tua: "<<endl;  // input gaji orang tua
    cin>> gaji_ortu;
    cout<<"masukkan ipk anda: "<<endl; //input ipk mahasiswa
    cin>> ipk;

    if (ipk >= 3.5){
        cout<<"anda berhak atas beasiswa kategori 4"; // jika IPK sangat tinggi, langsung dapat kategori 4
    }
    else if (gaji_ortu < 1000000 && ipk < 3.5){
        cout<<"anda berhak atas beasiswa kategori 1";// jika gaji sangat rendah dan IPK < 3.5 → kategori 1
    }
    else if (gaji_ortu <= 5000000 && ipk >= 2.0){
        cout<<"anda berhak atas beasiswa kategori 3";// jika gaji menengah dan IPK cukup (>=2.0) → kategori 3
    }
    else if (gaji_ortu <=5000000 && ipk < 2.0){
        cout<<"anda berhak atas beasiswa kategori 2";// jika gaji menengah tapi IPK rendah → kategori 2
    }
    else{
        cout<<"tidak berhak mendapatkan beasiswa";// selain kondisi di atas → tidak dapat beasiswa
    }
    system ("pause");//menahan layar console supaya tidak langsung tertutup

}
