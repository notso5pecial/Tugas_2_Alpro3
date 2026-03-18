#include <iostream>
using namespace std;

int main() {
    int bilangan;

    cout << "Masukkan bilangan 4 digit: ";
    cin >> bilangan;

    if (bilangan < 1000 || bilangan > 9999) {
        cout << "Input harus bilangan 4 digit!" << endl;
        return 0;
    }

    int d1 = bilangan / 1000;           
    int d2 = (bilangan / 100) % 10;     
    int d3 = (bilangan / 10) % 10;      
    int d4 = bilangan % 10;             

    bool naikTerus  = (d1 < d2) && (d2 < d3) && (d3 < d4);
    bool turunTerus = (d1 > d2) && (d2 > d3) && (d3 > d4);
    bool isAlfa     = naikTerus || turunTerus;

    int duaDepan    = d1 * 10 + d2;
    int duaBelakang = d3 * 10 + d4;
    int selisih     = duaDepan - duaBelakang;
    if (selisih < 0) selisih = -selisih;
    bool isBeta = (selisih >= 30);

    string tipe;
    if      (isAlfa && isBeta) tipe = "Gamma";
    else if (isAlfa)           tipe = "Alfa";
    else if (isBeta)           tipe = "Beta";
    else                       tipe = "Delta";

    cout << "\nBilangan  : " << bilangan << endl;
    cout << "Digit     : " << d1 << " " << d2 << " " << d3 << " " << d4 << endl;
    cout << "Tipe      : " << tipe << endl;

    return 0;
}

/*
Pisah Digit
   Cara motong digit dari bilangan bulat pakai pembagian dan modulo.
   Misal bilangan = 5823:
   - 5823 / 1000 = 5          → digit ribuan
   - 5823 / 100  = 58, 58%10 = 8  → digit ratusan
   - 5823 / 10   = 582, 582%10 = 2 → digit puluhan
   - 5823 % 10   = 3          → digit satuan

Cek Alfa
   Tinggal bandingin digit satu-satu.
   Naik  : d1 < d2 && d2 < d3 && d3 < d4  (misal 1234)
   Turun : d1 > d2 && d2 > d3 && d3 > d4  (misal 9631)
   Salah satu terpenuhi → isAlfa = true

Cek Beta
   Dua digit depan dijadiin satu angka: d1*10 + d2
   Dua digit belakang juga: d3*10 + d4
   Terus dihitung selisihnya. Karena selisih bisa negatif
   (kalau depan lebih kecil dari belakang), dikasih kondisi
   manual buat bikin nilainya positif — pengganti abs().

Klasifikasi
   Gamma dicek duluan karena dia gabungan alfa+beta.
   Kalau dicek belakangan, bilangan gamma bakal nyangkut
   di if alfa atau beta duluan dan tidak pernah sampai ke gamma.
   Delta itu kondisi sisa — tidak masuk ketiganya.
*/
