class Vehicle:
    def __init__(self, plat="", merk="", warna="", tahun=0):
        self.plat = plat
        self.merk = merk
        self.warna = warna
        self.tahun = tahun

    def getPlat(self):
        return self.plat

    def getMerk(self):
        return self.merk

    def getWarna(self):
        return self.warna

    def getTahun(self):
        return self.tahun

    def setPlat(self, plat):
        self.plat = plat

    def setMerk(self, merk):
        self.merk = merk

    def setWarna(self, warna):
        self.warna = warna

    def setTahun(self, tahun):
        self.tahun = tahun
    
    def ketemu(self,llist, platt): # mencari id anggota
        for kendaraan in llist:
            if kendaraan.getPlat() == platt:
                return 1
        return 0
