#include <iostream>
using namespace std;

int main(){
    int jam_berangkat, jam_pulang; // deklarasi variabel untuk menyimpan jam dan biaya
    float biaya;

    cout<<"moda irit tranportasi \n"; // output judul program
    cout<<"input jam beranangkat anda (24jam): \n";// input jam berangkat dari user
    cin>>jam_berangkat;
    cout<<"input jam pulang anda (24 jam): \n"; // input jam pulang dari user
    cin>>jam_pulang;

    if (jam_berangkat > 5 && jam_berangkat < 9 && jam_pulang > 14 && jam_pulang < 18){
        cout<<"anda bisa bertranportasi bus linus";
        biaya = 0;
        cout<< "biaya Rp"<<biaya; // kondisi: berangkat pagi (6-8) dan pulang sore (15-17)
    }
    else if (jam_berangkat > 5 && jam_berangkat < 9 && jam_pulang <= 18){
        cout<<"anda bisa berangkat dengan bus linus & pulang dengan bus hijau";
        biaya = 5000;
        cout<< " biaya Rp"<<biaya; // kondisi: berangkat pagi, pulang maksimal jam 18
    }
    else if (jam_berangkat > 5 && jam_berangkat < 9 && jam_pulang > 18){
        cout<<"anda bisa berangkat dengan bus linus & pulang dengan angkot";
        biaya = 10000;
        cout<< " biaya Rp"<<biaya; //berangkat pagi, pulang malam (>18)
    }
    else if (jam_berangkat > 8 && jam_pulang <= 18){
        cout<<"anda bisa bertransportasi bus hijau";
        biaya = 5000;
        cout<<" biaya Rp"<<biaya; // kondisi: berangkat agak siang (>8) dan pulang <=18
    }
    else if (jam_berangkat > 8 && jam_pulang > 18){
        cout<<"anda bisa berangkat dengan bus hijau & pulang dengan angkot";
        biaya = 15000;
        cout<<" biaya Rp"<<biaya;} //berangkat siang dan pulang malam
    else{
        cout<<"anda bisa bertransportasi angkot";
        biaya = 20000;
        cout<<" biaya Rp"<<biaya; // kondisi lainnya
    }
    system ("pause");//menahan layar console supaya tidak langsung tertutup
}
