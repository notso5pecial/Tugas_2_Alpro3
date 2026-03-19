nih nai
#include <iostream>
using namespace std;

int main(){
    int ekspedisi, berat_barang, harga; // deklarasi variabel
    char y; // untuk input tujuan (dalam kota atau tidak)
    float total_biaya, diskon;// deklarasi variabel
    cout<<"pilih ekspedisi: "<<endl;// menampilkan pilihan ekspedisi
    cout<<"1. JNE"<<endl;
    cout<<"2. Sicepat"<<endl;
    cout<<"3. GoJek"<<endl;
    cin>>ekspedisi;// input pilihan ekspedisi
    cout<<"masukkan berat barang (dalam kg): "; cin>>berat_barang;// input berat barang
    cout<<"tujuan pengiriman dalam kota? (y/n): ";// input tujuan pengiriman (y/n)
    cin>> y;

    switch(ekspedisi){// percabangan berdasarkan ekspedisi
        case 1:
            cout<<" ekspedisi yg dipilih: JNE \n";
            if (y == 'y'|| y == 'Y')// menentukan harga berdasarkan tujuan
                harga = 10000;
            else{
                harga = 20000;}

            if (berat_barang >= 10) {// jika berat >= 10 kg, dapat diskon 50%
                diskon = berat_barang * harga * 0.5;
                cout<<"total belanja "<< diskon <<endl;
                total_biaya = berat_barang * harga; // total sebelum diskon
                cout<<" diskon 50 persen dari "<<total_biaya<<" karena berat > 10 kg";
            }
            else {// tanpa diskon
                total_biaya = berat_barang * harga;
                cout<<"total biaya "<<total_biaya;
            }
            break;
        case 2:
            cout<<"ekspedisi yg dipilih: SiCepat \n";
            if (y == 'y'|| y == 'Y') // menentukan harga
                harga = 8000;
            else{
                harga = 18000;}

            if (berat_barang > 15) {// jika berat > 15 kg, gratis ongkir
                total_biaya = berat_barang * harga * 0;// total jadi 0
                cout<<"total belanja "<< total_biaya <<endl;
                cout<<" gratis ongkir karena berat > 15 kg";
            }
            else {
                total_biaya = berat_barang * harga;
                cout<<"total biaya "<<total_biaya;
            }
            break;
        case 3:
            cout<<"ekspedisi yg dipilih: Gojek \n";
            if (y == 'y'|| y == 'Y') // Gojek hanya untuk dalam kota
                harga = 12000;
            else{
                cout<<"pengiriman hanya dalam kota ";}

            if (berat_barang > 5) {// jika berat > 5 kg, dapat potongan 10000
                total_biaya = berat_barang * harga;
                diskon = total_biaya - 10000;// bukan diskon, tapi total setelah potongan
                cout<<"total biaya "<< total_biaya <<endl;
                cout<<" diskon 10000 dari "<<total_biaya<< "karena berat > 5 kg";
            }
            else {
                total_biaya = berat_barang * harga;
                cout<<"total biaya "<<total_biaya;
            }
            break;
       
        default: // jika input tidak sesuai pilihan
            cout<<" input yg bener!";

    }
    return 0;
}
