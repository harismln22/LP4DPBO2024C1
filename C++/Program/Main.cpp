#include <iostream>
#include <vector>
#include <string>
#include "Vehicle.cpp"
#include "Car.cpp"
#include "Motorcycle.cpp"
#include "ParkingLot.cpp"
#include "Garage.cpp"

using namespace std;

int main() {
    vector<Vehicle*> garasi_list; // membuat list
    Vehicle* kendaraann = new Vehicle(); // instance
    ParkingLot* park = new ParkingLot(); // instance

    int stop = 0; // marking
    cout << "Selamat datang di Tempat membuat kendaraan!" << endl;
    string nama_garasi;
    cout << "Masukkan nama garasi: ";
    cin >> nama_garasi;
    int luas_garasi;
    cout << "Masukkan luas garasi: ";
    cin >> luas_garasi;

    if (luas_garasi < 0)  // jika luas garasi negatif
	{
        stop = 1;
        cout << "Garasi gagal dibuat! (jangan membuat luas garasi bernilai negatif)" << endl;
    }
	else // jika tidak negatif
	{
        if (luas_garasi >= 1 && luas_garasi <= 29) 
		{
            park->setKapasitas(3);
            cout << "Kapasitas 3 parkir!" << endl;
        } 
		else if (luas_garasi >= 30 && luas_garasi <= 80) 
		{
            park->setKapasitas(15);
            cout << "Kapasitas 15 parkir!" << endl;
        } 
		else 
		{
            park->setKapasitas(30);
            cout << "Kapasitas 30 parkir!" << endl;
        }
    }

    Garage* garasi = new Garage(park); // membuat instance dengan pass by reference lahan parkir
    garasi->setNama(nama_garasi);
    garasi->setLuas(luas_garasi);
    if (stop == 0) // jika luas tidak negatif
	{
        cout << "Garasi berhasil dibuat, silahkan buat kendaraan anda!" << endl;
    }
	string cari, ubah;
    string isi_merk, isi_plat, isi_warna, isi_jenis, color, merkk, Platt;
    int isi_tahun, isi_tangki, isi_kursi, isi_pintu, mengubah;
	
    while (stop == 0) 
	{
        cout << "Garasi " << garasi->getNama() << endl;
        cout << "========================" << endl;
        cout << "1. Menambah" << endl;
        cout << "2. Hapus" << endl;
        cout << "3. Mengubah" << endl;
        cout << "4. Tampil" << endl;
        cout << "5. Keluar" << endl;
        cout << "========================" << endl;

        int milih;
        cout << "Pilih: ";
        cin >> milih;
        if (milih == 1) {
            cout << "Pilih kendaraan yang mau dibuat!" << endl;
            cout << "1. Mobil || 2. Motor" << endl;
            cout << "Pilih: ";
            cin >> milih;
            if (milih == 2) // input motor
			{
				Motorcycle* motor = new Motorcycle(); // instance
                if (garasi->tambahKendaraan(motor)) // menambahkan dan parkir kendaraan (jika masih ada lahan)
				{
					string isi_merk;
					cout << "Masukkan merk motor: ";
					cin >> isi_merk;
					motor->setMerk(isi_merk);

					string isi_plat;
					cout << "Masukkan plat motor: ";
					cin >> isi_plat;
					motor->setPlat(isi_plat);

					string isi_warna;
					cout << "Masukkan Warna motor: ";
					cin >> isi_warna;
					motor->setWarna(isi_warna);

					int isi_tahun;
					cout << "Masukkan tahun: ";
					cin >> isi_tahun;
					motor->setTahun(isi_tahun);

					string isi_jenis;
					cout << "Masukkan Jenis motor: ";
					cin >> isi_jenis;
					motor->setJenis(isi_jenis);

					int isi_tangki;
					cout << "Masukkan Kapasitas tangki: ";
					cin >> isi_tangki;
					motor->setKapasitasTangki(isi_tangki);
					motor->setType("Motor");
					
                    garasi_list.push_back(motor);
					cout << "Kendaraan ditambah ke garasi dan diparkir!" << endl;
                }

            } 
			else if (milih == 1) // input mobil
			{
				Car* car = new Car(); // instance
                if (garasi->tambahKendaraan(car)) // menambahkan dan parkir kendaraan (jika masih ada lahan)
				{
					string isi_merk;
					cout << "Masukkan merk mobil: ";
					cin >> isi_merk;
					car->setMerk(isi_merk);

					string isi_plat;
					cout << "Masukkan plat mobil: ";
					cin >> isi_plat;
					car->setPlat(isi_plat);

					string isi_warna;
					cout << "Masukkan Warna mobil: ";
					cin >> isi_warna;
					car->setWarna(isi_warna);

					int isi_tahun;
					cout << "Masukkan tahun: ";
					cin >> isi_tahun;
					car->setTahun(isi_tahun);

					int isi_kursi;
					cout << "Masukkan berapa kursi: ";
					cin >> isi_kursi;
					car->setJumKursi(isi_kursi);
					
					int isi_pintu;
					cout << "Masukkan berapa pintu: ";
					cin >> isi_pintu;
					car->setJumPintu(isi_pintu);
					car->setType("Mobil");
					
                    garasi_list.push_back(car);
					cout << "Kendaraan ditambah ke garasi dan diparkir!" << endl;
                }
            }
        }
		else if (milih == 2) // memilih hapus kendaraan
		{
            park->removeKendaraan(garasi_list);
        } 
		else if (milih == 3) // mengedit data kendaraan
		{
            cout << "pilih fitur dibawah ini yang akan diubah" << endl;
            cout << "1. Merk" << endl;
            cout << "2. Warna" << endl;
            cout << "3. Plat" << endl;
            cout << "Pilih: ";
            cin >> mengubah;
            if (mengubah == 2) // edit warna
			{
                cout << "Masukkan plat: ";
                cin >> ubah;
                if (kendaraann->ketemu(garasi_list, ubah)) // jika plat ada
				{
                    cout << "Masukkan warna baru untuk kendaraan: ";
                    cin >> color;
                    for (auto& ll : garasi_list) 
					{
                        if (ll->getPlat() == ubah) 
						{
                            cout << "warna " << ll->getWarna() << " diubah menjadi " << color << endl;
                            ll->setWarna(color);
                        }
                    }
                }
				else // jika tidak
				{
                    cout << "Plat tersebut tidak ditemukan!" << endl;
                }
            } 
			else if (mengubah == 1) // edit merk
			{
                cout << "Masukkan plat: ";
                cin >> ubah;
                if (kendaraann->ketemu(garasi_list, ubah)) // jika ada plat
				{
                    cout << "Masukkan merk baru untuk kendaraan: ";
                    cin >> merkk;
                    for (auto& ll : garasi_list) 
					{
                        if (ll->getPlat() == ubah) 
						{
                            cout << "merk " << ll->getMerk() << " diubah menjadi " << merkk << endl;
                            ll->setMerk(merkk);
                        }
                    }
                } 
				else // jika tidak
				{
                    cout << "Plat tersebut tidak ditemukan!" << endl;
                }
            } 
			else if (mengubah == 3) // edit plat
			{
                cout << "Masukkan plat yang akan diubah: ";
                cin >> ubah;
                if (kendaraann->ketemu(garasi_list, ubah)) // jika ada plat
				{
                    cout << "Masukkan Plat baru untuk kendaraan: ";
                    cin >> Platt;
                    for (auto& ll : garasi_list) 
					{
                        if (ll->getPlat() == ubah) 
						{
                            cout << "Plat " << ll->getPlat() << " diubah menjadi " << Platt << endl;
                            ll->setPlat(Platt);
                        }
                    }
                } 
				else // jika tidak
				{
                    cout << "Plat tersebut tidak ditemukan!" << endl;
                }
            }
        } 
		else if (milih == 4) // menampilkan kendaraan
		{
            garasi->tampil(garasi_list);
            cout << "Jumlah kendaraan: " << park->getKendaraan() << endl;
        }
		else // keluar loop
		{
            stop = 1;
        }
    }

    return 0;
}