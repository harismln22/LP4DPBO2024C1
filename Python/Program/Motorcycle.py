from Vehicle import Vehicle

class Motorcycle(Vehicle):
    __jenis = ""
    __kapasitas_tangkin = 0
    
    def __init__(self, jenis="", kapasitas_tangki=0, plat="", merk="", warna="", tahun=0):
        super().__init__(plat, merk, warna, tahun)
        self.__jenis = jenis
        self.__kapasitas_tangki = kapasitas_tangki

    def getJenis(self):
        return self.__jenis

    def getKapasitasTangki(self):
        return self.__kapasitas_tangki

    def setJenis(self, jenis):
        self.__jenis = jenis

    def setKapasitasTangki(self, kapasitas_tangki):
        self.__kapasitas_tangki = kapasitas_tangki
       
      # print semua input kendaraan yang sudah dibuat
    def tampil (self,llistt):
        if llistt: # inisialisasi semua nama label tabel untuk perbandingan nanti
            maxMerkLength = len("Merk")
            maxJenisLength = len("Jenis")
            maxPlatLength = len("Plat")
            maxWarnaLength = len("Warna")
            maxTangkiLength = len("Tangki")
            maxTahunLength = len("Tahun")

            for ll in llistt: # mengambil string terpanjang jika ada
                if len(ll.getMerk()) > maxMerkLength:maxMerkLength = len(ll.getMerk())
                if len(ll.getJenis()) > maxJenisLength: maxJenisLength = len(ll.getJenis())
                if len(ll.getPlat()) > maxPlatLength: maxPlatLength = len(ll.getPlat())
                if len(ll.getWarna()) > maxWarnaLength: maxWarnaLength = len(ll.getWarna())
                if len(ll.getKapasitasTangki()) > maxTangkiLength: maxTangkiLength = len(ll.getKapasitasTangki())
                if len(ll.getTahun()) > maxTahunLength : maxTahunLength = len(ll.getTahun())
            # memasukkan semua ke array
            headers = ["Merk", "Jenis", "Plat", "Warna", "Tangki", "Tahun"]
            maxLengths = [maxMerkLength,maxJenisLength, maxPlatLength, maxWarnaLength, maxTangkiLength, maxTahunLength]

            print("|| ", end="")
            for i in range(len(headers)): # loop dan print header label tabel 
                print(headers[i] + " " * (maxLengths[i] - len(headers[i]) + 1) + "|| ", end="")
            print()

            for ll in llistt: # loop semua isi listShirt
                data = [ll.getMerk(), ll.getJenis(), ll.getPlat(), ll.getWarna(), str(ll.getKapasitasTangki()), str(ll.getTahun())]
                print("|| ", end="")
                for i in range(len(data)): # loop dan print semua data input baju
                    print(data[i] + " " * (maxLengths[i] - len(data[i]) + 1) + "|| ", end="")
                print()
        else:
            print("KOSONG!")
