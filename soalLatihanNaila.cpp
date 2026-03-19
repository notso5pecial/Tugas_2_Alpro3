#include <iostream>
using namespace std;
int main () {
    float berat, biaya = 0, diskon = 0, total = 0;
    int tujuan, ekspedisi;
    string namaExp, keterangan = "";
    
    cout << "Berat barang (Kg): ";          cin >> berat;
    cout << "Tujuan (1=Dalam Kota, 2=Luar Kota): "; cin >> tujuan;
    cout << "Ekspedisi (1=JNE, 2=SiCepat, 3=Gojek): "; cin >> ekspedisi;
    cout << endl;
    
    switch(ekspedisi) {
        case 1:
            namaExp = "JNE";
            if (tujuan == 1) biaya = berat * 10000;
            else             biaya = berat * 20000;
            if (berat > 10) {
                diskon = biaya * 0.5;
                keterangan = "(Diskon 50% dari Rp." + to_string((long long)biaya) + " karena berat > 10Kg)";
            }
        break;
        
        case 2:
            namaExp = "SiCepat";
            if (tujuan == 1) biaya = berat * 8000;
            else             biaya = berat * 18000;
            if (berat > 15) {
                diskon = biaya;
                keterangan = "(Gratis ongkir karena berat > 15Kg)";
            }
        break;
        
        case 3:
            namaExp = "Gojek";
            if (tujuan == 2) {
                cout << "[!] Gojek hanya melayani pengiriman dalam kota." << endl;
                return 0;
            }
            biaya = berat * 12000;
            if (berat > 5) {
                diskon = 10000;
                keterangan = "(Diskon Rp.10000 dari Rp." + to_string((long long)biaya) + " karena berat > 5Kg)";
            }
        break;
        
        default:
            cout << "Ekspedisi tidak valid!" << endl;
            return 0;
    }
    total = biaya - diskon; 
    cout << "Berat barang          : " << berat << " Kg" << endl;
    cout << "Tujuan                : " << (tujuan == 1 ? "Dalam Kota" : "Luar Kota") << endl;
    cout << "Ekspedisi yang dipilih: " << namaExp << endl;
    cout << "Total biaya           : Rp." << (long long)total << endl;
    if (keterangan != "") cout << keterangan << endl;
    return 0;
}

/*
Penjelasan Logika:

1. Deklarasi Variabel
   - berat, biaya, diskon, total → float karena bisa mengandung desimal (misal 2.5 Kg)
   - biaya, diskon, total diinisialisasi = 0 supaya tidak berisi nilai sampah dari memori
   - keterangan = "" supaya bisa dicek di akhir apakah ada diskon atau tidak

2. Input
   - Pengguna memasukkan berat, tujuan, dan pilihan ekspedisi
   - tujuan: 1 = dalam kota, 2 = luar kota
   - ekspedisi: 1 = JNE, 2 = SiCepat, 3 = Gojek

3. Switch (ekspedisi)
   - Memilih blok kode yang dijalankan berdasarkan nilai ekspedisi
   - Setiap case diakhiri break supaya tidak "jatuh" ke case berikutnya

   CASE 1 - JNE:
   - Dalam kota : Rp10.000/Kg
   - Luar kota  : Rp20.000/Kg
   - Jika berat > 10Kg → diskon 50% dari biaya
   - to_string((long long)biaya) → mengubah biaya ke string tanpa desimal
     agar bisa digabung ke teks keterangan

   CASE 2 - SiCepat:
   - Dalam kota : Rp8.000/Kg
   - Luar kota  : Rp18.000/Kg
   - Jika berat > 15Kg → gratis ongkir (diskon = biaya penuh)

   CASE 3 - Gojek:
   - Hanya melayani dalam kota
   - Jika tujuan == 2 (luar kota) → tampilkan pesan lalu return 0 (program berhenti)
     Tidak ada gunanya lanjut hitung karena pengiriman tidak bisa dilakukan
   - Dalam kota : Rp12.000/Kg
   - Jika berat > 5Kg → potongan flat Rp10.000 (bukan persentase)

   DEFAULT:
   - Dijalankan jika ekspedisi bukan 1, 2, atau 3
   - Program langsung berhenti dengan return 0

4. Hitung total
   - total = biaya - diskon
   - Ditulis di LUAR switch supaya selalu dieksekusi setelah case manapun
   - Jika tidak ada diskon, diskon tetap 0 sehingga total = biaya

5. Output
   - (long long)total → cast ke bilangan bulat agar tidak tampil desimal di layar
   - Operator ternary (tujuan == 1 ? "Dalam Kota" : "Luar Kota") adalah
     singkatan dari if-else untuk memilih teks tujuan
   - keterangan hanya dicetak jika tidak kosong (ada diskon)
*/
