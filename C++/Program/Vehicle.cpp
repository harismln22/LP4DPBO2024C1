#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vehicle {
	private:
		string plat;
		string merk;
		string warna;
		int tahun;
		string tipe;
		
	public:
		// konstrukt secara langsung di parameter
		Vehicle(string plat = "", string merk = "", string warna = "", int tahun = 0, string tipe = "") : plat(plat), merk(merk), warna(warna), tahun(tahun), tipe(tipe) 
		{
			
		}
		// getter
		string getPlat() {
			return this->plat;
		}

		string getMerk() {
			return this->merk;
		}

		string getWarna() {
			return this->warna;
		}

		int getTahun() {
			return this->tahun;
		}

		string getType() {
			return this->tipe;
		}
		// setter
		void setPlat(string plat) {
			this->plat = plat;
		}

		void setMerk(string merk) {
			this->merk = merk;
		}

		void setWarna(string warna) {
			this->warna = warna;
		}

		void setTahun(int tahun) {
			this->tahun = tahun;
		}

		void setType(string tipe) {
			this->tipe = tipe;
		}
		
		// mencari plat yang sama
		bool ketemu(vector<Vehicle*> llist, string platt) 
		{
			for (Vehicle* kendaraan : llist) 
			{
				if (kendaraan->getPlat() == platt) 
				{
					return true;
				}
			}
			return false;
		}
		
		virtual ~Vehicle() // virtual ini agar dynamic_cast nya berjalan lancar di car dan motorcycle
		{
			
		}
};
