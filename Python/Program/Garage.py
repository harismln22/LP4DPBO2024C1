class Garage:
    __NamaGarasi = ""
    __LuasGarasi = 0
    
    def __init__(self, nama="", luas=0, kendaraan=None):
        self.NamaGarasi = nama
        self.LuasGarasi = luas
        if kendaraan is None:
            self.listKendaraan = []
        else:
            self.listKendaraan = kendaraan

    def getNama(self):
        return self.NamaGarasi

    def getLuas(self):
        return self.LuasGarasi

    def getDaftarKendaraan(self):
        return self.listKendaraan

    def setNama(self, nama):
        self.NamaGarasi = nama

    def setLuas(self, luas):
        self.LuasGarasi = luas
        
    
