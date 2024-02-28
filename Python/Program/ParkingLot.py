class ParkingLot:
    def __init__(self, kapasitas=0):
        self.kapasitas = kapasitas
        self.kendaraan = []
        self.jum_kendaraan = 0

    def setKapasitas(self, kapasitas):
        self.kapasitas = kapasitas

    def getKapasitas(self):
        return self.kapasitas

    def getParkir(self, kendaraan):
        if len(self.kendaraan) < self.kapasitas:
            self.kendaraan.append(self.kendaraan)
            print("Kendaraan diparkir!")
            self.jum_kendaraan += 1
        else:
            print("Parkir penuh!")
            
    def getKendaraan(self):
        return self.jum_kendaraan