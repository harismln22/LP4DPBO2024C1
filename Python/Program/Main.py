from Car import Car
from ParkingLot import ParkingLot
from Motorcycle import Motorcycle
from Garage import Garage

motor = Motorcycle()
car = Car()
motor_list = []
car_list = []
garasi_list = motor_list + car_list
park = ParkingLot()
garasi = Garage()

park.setKapasitas(5)
print("Selamat datang di Tempat membuat kendaraan!")
nama_garasi = input("Masukkan nama garasi: ")
luas_garasi = int(input("Masukkan luas garasi: "))
garasi.setNama(nama_garasi)
garasi.setLuas(luas_garasi)
print("Garasi berhasil dibuat, silahkan buat kendaraan anda!")

stop = 0

while stop == 0:
    print("========================");
    print("1. Menambah");
    print("2. Hapus");
    print("3. Mengubah");
    print("4. Tampil");
    print("5. Keluar");
    print("========================");

    milih = int(input("Pilih: "))
    if milih == 1:
        print("Pilih kendaraan yang mau dibuat!");
        print("1. Mobil || 2. Motor");
        milih = int(input("Pilih: "))
        if milih == 2:
            isi_merk = input("Masukkan merk motor: ")
            motor.setMerk(isi_merk)
            
            isi_plat = input("Masukkan plat motor: ")
            motor.setPlat(isi_plat)
            
            isi_warna = input("Masukkan Warna motor: ")
            motor.setWarna(isi_warna)
            
            isi_tahun = input("Masukkan tahun: ")
            motor.setTahun(isi_tahun)
            
            isi_jenis = input("Masukkan Jenis motor: ")
            motor.setJenis(isi_jenis)
            
            isi_tangki = input("Masukkan Kapasitas tangki: ")
            motor.setKapasitasTangki(isi_tangki)
            
            motor_list.append(motor)
            garasi_list.append(motor)
            
            print("berhasil membuat Motor!")
            
        elif milih == 1:
            isi_merk = input("Masukkan merk mobil: ")
            car.setMerk(isi_merk)
            
            isi_plat = input("Masukkan plat mobil: ")
            car.setPlat(isi_plat)
            
            isi_warna = input("Masukkan Warna mobil: ")
            car.setWarna(isi_warna)
            
            isi_tahun = input("Masukkan tahun: ")
            car.setTahun(isi_tahun)
            
            isi_kursi = input("Masukkan berapa kursi: ")
            car.setJumKursi(isi_kursi)
            
            isi_pintu = input("Masukkan berapa pintu: ")
            car.setJumPintu(isi_pintu)
            
            car_list.append(car)
            garasi_list.append(car)
            
            print("berhasil membuat Mobil!")
            
    elif milih == 2:
            cari = input("Masukkan plat yang akan dihapus: ")
            for search in garasi_list[:]:
                if search.getPlat() == cari:
                    print("motor " + search.getMerk() + " dengan plat " + search.getPlat() + " Berhasil dihapus!")
                    motor_list.remove(search)
                else:
                    print("TIDAK DITEMUKAN")
        
    elif milih == 3:
            print("pilih fitur dibawah ini yang akan diubah")
            print("1. Merk")
            print("2. Warna")
            print("3. Plat")
            mengubah = int(input("Pilih: "))
            if mengubah == 2:
                ubah = input("Masukkan plat: ")
                if motor.ketemu(garasi_list, ubah) == 1:
                    color = input("Masukkan warna baru untuk kendaraan: ")
                    for ll in garasi_list:
                        if ll.getPlat() == ubah:
                            print("warna "+ ll.getWarna()+" diubah menjadi " + color)
                            ll.setWarna(color)
                        else:
                            print("Plat tersebut tidak ditemukan!")
            elif mengubah == 1:
                ubah = input("Masukkan plat: ")
                if motor.ketemu(garasi_list, ubah) == 1:
                    merkk = input("Masukkan merk baru untuk kendaraan: ")
                    for ll in garasi_list:
                        if ll.getPlat() == ubah:
                            print("merk "+ ll.getMerk()+" diubah menjadi " + merkk)
                            ll.setMerk(merkk)
                        else:
                            print("Plat tersebut tidak ditemukan!")
            elif mengubah == 3:
                ubah = input("Masukkan plat: ")
                if motor.ketemu(garasi_list, ubah) == 1:
                    Platt = input("Masukkan Plat baru untuk kendaraan: ")
                    for ll in garasi_list:
                        if ll.getPlat() == ubah:
                            print("Plat "+ ll.getPlat()+" diubah menjadi " + Platt)
                            ll.setPlat(Platt)
                        else:
                            print("Plat tersebut tidak ditemukan!")
                
    elif milih == 4:
        motor.tampil(motor_list)
    else:
        stop = 1
    
    
