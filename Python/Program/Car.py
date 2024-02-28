from Vehicle import Vehicle 

class Car(Vehicle):
    __jum_kursi = 0
    __jum_pintu = 0
    
    def __init__(self, kursi=0, pintu=0, plat="", merk="", warna="", tahun=0):
        super().__init__(plat, merk, warna, tahun)
        self.__jum_kursi = kursi
        self.__jum_pintu = pintu

    def getJumKursi(self):
        return self.__jum_kursi

    def getJumPintu(self):
        return self.__jum_pintu

    def setJumKursi(self, kursi):
        self.__jum_kursi = kursi

    def setJumPintu(self, pintu):
        self.__jum_pintu = pintu
        
    def tampil (self,llistt):
        if llistt: # inisialisasi semua nama label tabel untuk perbandingan nanti
            maxMerkLength = len("Merk")
            maxJenisLength = len("Tahun")
            maxPlatLength = len("Plat")
            maxWarnaLength = len("Warna")
            maxTangkiLength = len("Kursi")
            maxTahunLength = len("Pintu")

            for ll in llistt: # mengambil string terpanjang jika ada
                if len(ll.getMerk()) > maxMerkLength:maxMerkLength = len(ll.getMerk())
                if len(ll.getTahun()) > maxJenisLength: maxJenisLength = len(ll.getTahun())
                if len(ll.getPlat()) > maxPlatLength: maxPlatLength = len(ll.getPlat())
                if len(ll.getWarna()) > maxWarnaLength: maxWarnaLength = len(ll.getWarna())
                if len(ll.getJumKursi()) > maxTangkiLength: maxTangkiLength = len(ll.getJumKursi())
                if len(ll.getJumPintu()) > maxTahunLength : maxTahunLength = len(ll.getJumPintu())
            # memasukkan semua ke array
            headers = ["Merk", "Tahun", "Plat", "Warna", "Kursi", "Pintu"]
            maxLengths = [maxMerkLength,maxJenisLength, maxPlatLength, maxWarnaLength, maxTangkiLength, maxTahunLength]

            print("|| ", end="")
            for i in range(len(headers)): # loop dan print header label tabel 
                print(headers[i] + " " * (maxLengths[i] - len(headers[i]) + 1) + "|| ", end="")
            print()

            for ll in llistt: # loop semua isi listShirt
                data = [ll.getMerk(), ll.getTahun(), ll.getPlat(), ll.getWarna(), str(ll.getJumKursi()), str(ll.getJumPintu())]
                print("|| ", end="")
                for i in range(len(data)): # loop dan print semua data input baju
                    print(data[i] + " " * (maxLengths[i] - len(data[i]) + 1) + "|| ", end="")
                print()
        else:
            print("KOSONG!")