#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

class Garage 
{
	private:
		string NamaGarasi;
		int LuasGarasi;
		vector<Vehicle*> listKendaraan;
		ParkingLot* parking;
	public:
	
		// konstruktor secara langsung di parameter
		Garage(ParkingLot* parking = new ParkingLot(), string nama = "", int luas = 0, vector<Vehicle*> kendaraan = {}) : parking(parking), NamaGarasi(nama), LuasGarasi(luas) 
		{
            if (kendaraan.empty()) 
			{
                this->listKendaraan = {};
            } 
			else 
			{
                this->listKendaraan = kendaraan;
            }
        }
		// getter
		string getNama() 
		{
			return this->NamaGarasi;
		}
		int getLuas() 
		{
			return this->LuasGarasi;
		}
		// setter
		void setNama(string nama) 
		{
			this->NamaGarasi = nama;
		}
		void setLuas(int luas) 
		{
			this->LuasGarasi = luas;
		}
	
		bool tambahKendaraan(Vehicle* kendaraan) 
		{
			if (this->parking->getParkir(kendaraan)) // jika di tempat parkir masih ada
			{
				this->listKendaraan.push_back(kendaraan); // menambah kendaraan
				return true; // jika iya masih ada tempat parkir
			} 
			else 
			{
				return false; // jika penuh
			}
		}
		
		void tampil(vector<Vehicle*> vehicle_list) 
		{
			if (!vehicle_list.empty()) // jika terdapat kendaraan
			{
				// inisalisasi string nama label
				int maxMerkLength = 4, maxJenisLength = 5, maxPlatLength = 4, maxWarnaLength = 5, maxTangkiLength = 6, maxTahunLength = 5, maxKursiLength = 5, maxPintuLength = 5, maxTipeLength = 4;
				for (Vehicle* ll : vehicle_list) 
				{
					/*secara singkat hampir sama seperti isinstance dalam python agar tidak error ketika menampilkan data kendaraan*/
					Motorcycle* motor = dynamic_cast<Motorcycle*>(ll); // secara singkat hampir sama seperti isinstance dalam python
					Car* car = dynamic_cast<Car*>(ll); // secara singkat hampir sama seperti isinstance dalam python
					/* inisalisasi label nama tabel untuk perbandingan nanti (fungsi max untuk mendapatkan string paling panjang) */
					maxMerkLength = max(maxMerkLength, (int)ll->getMerk().length());
					maxPlatLength = max(maxPlatLength, (int)ll->getPlat().length());
					maxWarnaLength = max(maxWarnaLength, (int)ll->getWarna().length());
					maxTipeLength = max(maxTipeLength, (int)ll->getType().length());
					maxTahunLength = max(maxTahunLength, (int)to_string(ll->getTahun()).length());
					if(motor != nullptr) // jika terdapat list motor
					{
						/* maka inisalisasi label nama tabel khusus motor untuk perbandingan nanti */
						maxJenisLength = max(maxJenisLength, (int)motor->getJenis().length());
						maxTangkiLength = max(maxTangkiLength, (int)to_string(motor->getKapasitasTangki()).length());	
					}
					if(car != nullptr) // jika terdapat list mobil
					{
						/* inisalisasi label nama tabel khusus mobil untuk perbandingan nanti */
						maxKursiLength = max(maxKursiLength, (int)to_string(car->getJumKursi()).length());
						maxPintuLength = max(maxPintuLength, (int)to_string(car->getJumPintu()).length());						
					}
					
				}
				// memasukkan string terpanjang dan label nama tabel ke dalam array
				vector<string> headers = {"Merk", "Jenis", "Plat", "Warna", "Tangki", "Tahun", "Kursi", "Pintu", "Tipe"};
				vector<int> maxLengths = {maxMerkLength, maxJenisLength, maxPlatLength, maxWarnaLength, maxTangkiLength, maxTahunLength, maxKursiLength, maxPintuLength, maxTipeLength};
				cout << "|| ";
				for (int i = 0; i < headers.size(); i++) // print header
				{
					cout << left << setw(maxLengths[i] + 1) << headers[i] << "|| ";
				}
				cout << "\n";
				
				for (Vehicle* ll : vehicle_list) {
					string jenis = "-", tangki = "-", kursi = "-", pintu = "-"; // inisalisasi jika tidak terdapat untuk kendaraan khusus
					Motorcycle* motor = dynamic_cast<Motorcycle*>(ll); // secara singkat hampir sama seperti isinstance dalam python
					Car* car = dynamic_cast<Car*>(ll); // secara singkat hampir sama seperti isinstance dalam python
					if(motor != nullptr) // jika terdapat list motor
					{
						jenis = motor->getJenis();
						tangki = to_string(motor->getKapasitasTangki());						
					}
					if(car != nullptr) // jika terdapat list mobil
					{
						kursi = to_string(car->getJumKursi());						
						pintu = to_string(car->getJumPintu());
					}
					// memasukkan data ke dalam array data
					vector<string> data = {ll->getMerk(), jenis, ll->getPlat(), ll->getWarna(), tangki, to_string(ll->getTahun()), kursi, pintu, ll->getType()};
					cout << "|| ";
					for (int i = 0; i < data.size(); i++) // print data
					{
						cout << left << setw(maxLengths[i] + 1) << data[i] << "|| ";
					}
					cout << "\n";
				}
			} 
			else // jika tidak terdapat kendaraan
			{
				cout << "KOSONG!\n";
			}
		}
};
