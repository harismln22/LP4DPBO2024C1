#include <iostream>
#include <vector>

using namespace std;

class ParkingLot 
{
	private:
		int kapasitas;
		int jum_kendaraan;
		vector<Vehicle*> listKendaraan;
	public:
		ParkingLot(int kapasitas = 0, vector<Vehicle*> kendaraan = {}) : kapasitas(kapasitas), jum_kendaraan(0), listKendaraan(kendaraan) 
		{
			
		}
			
		// setter
		void setKapasitas(int kapasitas) {
			this->kapasitas = kapasitas;
		}
		
		// getter
		int getKapasitas() 
		{
			return this->kapasitas;
		}
		int getKendaraan() 
		{
			return this->jum_kendaraan;
		}
		
		void removeKendaraan(vector<Vehicle*>& garasi_list) // pass by reference untuk ke main.cpp
		{
			if(this->jum_kendaraan >= 1) // jika terdapat kendaraan
			{
				int tanda = 0; // tanda jika plat tidak ditemukan
				string cari;
				cout << "Masukkan plat yang akan dihapus: ";
				cin >> cari;
				for (auto it = garasi_list.begin(); it != garasi_list.end(); ) 
				{
					if ((*it)->getPlat() == cari) {
						cout << "kendaraan " << (*it)->getMerk() << " dengan plat " << (*it)->getPlat() << " Berhasil dihapus!" << endl;
						it = garasi_list.erase(it);
						tanda = 1; // plat ada
						this->jum_kendaraan--; // mengunrangi kendaraan
					} 
					else 
					{
						++it;
					}
				}
				if(tanda == 0)
				{
					cout << "Plat tersebut tidak ditemukan!" << endl;
				}
			}
			else
			{
				cout << "Tidak ada kendaraan di garasi!" << endl;
			}
		}

		bool getParkir(Vehicle* kendaraan) // jika terdapat lahan parkir
		{
			if (this->jum_kendaraan < this->kapasitas) // selama kendaraan tidak melebihi kapasitas parkir
			{
				this->jum_kendaraan++; // menambah
				return true; // hasil masih ada lahan
			} 
			else 
			{
				cout << "Garasi penuh!" << endl;
				return false; // penuh
			}
		}
		
		
		~ParkingLot()
		{
			
		}
};
