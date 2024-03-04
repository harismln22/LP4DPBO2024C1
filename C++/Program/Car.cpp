#include <iostream>
#include <string>

using namespace std;

class Car : public Vehicle 
{
	private:
		int jum_kursi;
		int jum_pintu;
	public:
		
		Car(int kursi = 0, int pintu = 0, string plat = "", string merk = "", string warna = "", int tahun = 0) : Vehicle(plat, merk, warna, tahun), jum_kursi(kursi), jum_pintu(pintu) 
		{
			
		}
		// getter
		int getJumKursi() {
			return this->jum_kursi;
		}

		int getJumPintu() {
			return this->jum_pintu;
		}
		// setter
		void setJumKursi(int kursi) {
			this->jum_kursi = kursi;
		}

		void setJumPintu(int pintu) {
			this->jum_pintu = pintu;
		}
		
		~Car()
		{
			
		}
};
