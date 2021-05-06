import itertools
from .script import *


class Bus:
    busid = itertools.count()

    def __init__(self, nama, supir, jalur, ongkos):
        self.id = next(self.busid)
        self.nama = nama
        self.supir = supir
        self.jalur = jalur
        self.ongkos = ongkos
        self.penumpang = []
        self.penumpangFlag = []
        self.kas = 0

    def __del__(self):
        print("{} telah dijual".format(self.nama))

    def hitungOngkos(self, penumpang):
        j = 0
        for i in self.penumpang:
            if penumpang.lower() == i.lower():
                start = int(self.penumpangFlag[j])
                end = var.pos
                if start > end:
                    start, end = end, start
                ongkos = sum(self.ongkos[start:end])
            j += 1

        return ongkos

    def naik(self, penumpang):
        if (len(self.penumpang)+1 > self.kursi):
            print("Bus", self.id, "full", penumpang, "Tidak bisa naik")
        elif penumpang in self.penumpang:
            print("Penumpang dengan nama {} sudah ada".format(penumpang))
        else:
            self.penumpangFlag.append(var.pos)
            self.penumpang.append(penumpang)
            print(penumpang, "Naik")

        #print("Sisa kursi pada bus {} = {}".format(self.id, self.sisaKursi()))

    def turun(self, penumpang, all=False):
        if all:
            for nama in self.penumpang:
                self.turun(nama)
        else:
            j = 0
            for i in self.penumpang:
                if penumpang.lower() == i.lower():
                    ongkos = self.hitungOngkos(penumpang)

                    self.penumpang.remove(i)
                    self.penumpangFlag.pop(j)
                    self.kas += ongkos

                    print(penumpang, "Turun dari bus",
                          self.nama,  "- Ongkos: ", printUang(ongkos))
                    return
                j += 1

            print(penumpang, "tidak ditemukan di Bus", self.id)


class CyberBus(Bus):
    model = "Tesla Cyber Bus X12"
    manufacture = "Tesla"
    harga = 15000000
    kursi = 30

    def __init__(self, nama, supir, jalur, ongkos):
        super().__init__(nama, supir, jalur, ongkos)
        print("CyberBus dengan ID", self.id,
              "telah diibeli dengan harga", printUang(self.harga))
        print("Sisa kas sejumlah", hitungKas()-self.harga)


class VolvoBus(Bus):
    model = "Volvo Bus V13E"
    manufacture = "Volvo"
    harga = 13000000
    kursi = 25

    def __init__(self, nama, supir, jalur, ongkos):
        super().__init__(nama, supir, jalur, ongkos)
        print("VolvoBus dengan ID", self.id,
              "telah diibeli dengan harga", printUang(self.harga))
        print("Sisa kas sejumlah", hitungKas()-self.harga)


class HinoBus(Bus):
    model = "Hino Bus H73Y"
    manufacture = "Hino"
    harga = 17000000
    kursi = 35

    def __init__(self, nama, supir, jalur, ongkos):
        super().__init__(nama, supir, jalur, ongkos)
        print("HinoBus dengan ID", self.id,
              "telah diibeli dengan harga", printUang(self.harga))
        print("Sisa kas sejumlah", hitungKas()-self.harga)


busDealer = {
    "Cyber Bus": CyberBus,
    "Hino Bus": HinoBus,
    "Volvo Bus": VolvoBus
}
