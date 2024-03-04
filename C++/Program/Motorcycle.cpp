#include <iostream>
#include <string>

using namespace std;

class Motorcycle: public Vehicle
{
	private:
        string jenis;
        int kapasitas_tangki;
		
    public:
		// konstrukt default
		Motorcycle()
		{
			
		}
        // konstrukt overloading
		Motorcycle(string jenis, string plat, string merk, string warna, int tahun): Vehicle(plat,merk,warna,tahun)
		{
			this->jenis = jenis;
			kapasitas_tangki = 0;
		}
		// konstrukt overloading
		Motorcycle(string jenis, int capacity, string plat, string merk, string warna, int tahun): Vehicle(plat,merk,warna,tahun)
		{
			this->jenis = jenis;
			this->kapasitas_tangki = capacity;
		}
		
		// getter
        string getJenis() 
		{
			return jenis;
		}
        int getKapasitasTangki() 
		{ 
			return kapasitas_tangki; 
		}

        // setter
        void setJenis(string jenis) 
		{
			this->jenis = jenis;
		}
        void setKapasitasTangki(int kapasitas_tangki) 
		{ 
			this->kapasitas_tangki = kapasitas_tangki; 
		}
		
		~Motorcycle()
		{
			
		}
	
};